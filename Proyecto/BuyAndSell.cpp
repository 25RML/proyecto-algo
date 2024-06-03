#include "BuyAndSell.h"
#include <mysql.h>
#include "Conexion.h"
#include<iostream>
#include<string>
#include"tabulate.hpp"
#include<conio.h>
#include<thread>
#include<iomanip>
#include<sstream>
#include<cmath>
#include"tabla.h"

using namespace tabulate;
using namespace std;

//VARIABLES GLOBALES

MYSQL* conectar1;

static void abrir_conexion1() {

	conectar1 = mysql_init(0);
	conectar1 = mysql_real_connect(conectar1, "roundhouse.proxy.rlwy.net", "root", "LRzBRogGeTTgGxcGvPrxUpcEczRzzDAQ", "railway", 24103, NULL, 0);
	if (conectar1) {
		cout << "Conexion exitosa...";
		this_thread::sleep_for(std::chrono::seconds(1));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << "error en la conexion...\n";
	}

}

static void cerrar_conexion1() {
	mysql_close(conectar1);
}

static string round_to_string(float a) {
	stringstream stream;
	stream << fixed << setprecision(2) << a;
	string total1 = stream.str();
	return total1;
}

static void borrar_linea() {
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "\r";
	cout << "                                      " << flush;
	cout << "\r";
}

void comprar(int usuario_id) {

	vector<Db_tabla> resultados;

	obtener_valores(resultados);

	vector<Db_usuarios> ucer;
	
	obtener_usuarios(ucer);

	usuario_id=usuario_id-1;

	string saldo = ucer[usuario_id].saldo;

	string usuario = ucer[usuario_id].nombre;

	int id_empresa = 0, cant = 0;

	Table welcome;

	welcome.add_row({ "SALDO ACTUAL " + saldo });

	welcome.add_row({ "Bienvenido " + usuario + "," });

	do {

		cout << welcome;

		cout << "\nIngrese el ID de la empresa a comprar: ";

		cin >> id_empresa; (id_empresa < 1 || id_empresa>12) ?

		cout << "\nID fuera de rango, ingrese un valor de empresa valido\n" : cout << "";

	} while (id_empresa < 1 || id_empresa>12);

	id_empresa = id_empresa - 1;

	float valor_compra = stof(resultados[id_empresa].compra);

	do {
		cout << "\nIngrese la cantidad de acciones a comprar: ";

		cin >> cant; (cant < 1) ? cout << "\nLa cantidad a comprar debe ser mayor a 0..." : cout << "";
	} while (cant < 1);

	valor_compra = valor_compra * cant;

	Table tabla;

	stringstream stream;

	float adicional = 50;
	float total = valor_compra + adicional;
	if (total > stof(saldo)) 
	{	
		cout << "\nEl valor total de la cantidad solicitado excede a su saldo actual\n\nVolviendo al menu principal...\n";
		this_thread::sleep_for(chrono::seconds(2));
		system("cls");
		mostrarEmpresasEnTabla(12);
		menuOperaciones();
		return ;
	};
	//añadiendo caracteristicas a la boleta de compra
	tabla.add_row({ "Nombre de la empresa ",resultados[id_empresa].nombre });
	tabla.add_row({ "Precio unitario de la acción ",resultados[id_empresa].compra });
	tabla.add_row({ "Cantidad solicitada ",to_string(cant) });
	tabla.add_row({ "Subtotal de compra ",round_to_string(valor_compra) });
	tabla.add_row({ "Adicional por operacion ",round_to_string(adicional) });
	tabla.add_row({ "Total de la compra ",round_to_string(total) });

	tabla.format()
		.border("=")
		.border_left("|")
		.border_right("|")
		.corner("+");

	tabla.column(1).format().width(30);
	tabla.column(1).format().width(20);
	tabla.column(0).format().font_background_color(Color::red).font_style({ FontStyle::bold });

	system("cls");

	//Creando boleta de  confirmacion
	cout << "\nBOLETA DE CONFIRMACION" << endl;

	cout << tabla;

	cout << "\nSALDO RESTANTE -->" << round_to_string(stof(saldo) - (valor_compra + adicional));

	char opcion;

	cout << "\nDESEA EFECTUAR LA OPERACION?\n" << endl;

	do { cout << "y: si / n: no --> "; opcion = _getch(); if (opcion != 'y' && opcion != 'n') { borrar_linea(); } } while (opcion != 'y' && opcion != 'n');

	float saldo_actual = stof(saldo) - (valor_compra + adicional);
	//id del usuario de tipo int
	usuario_id = usuario_id + 1;
	//precio actual de tipo string
	string actual = resultados[id_empresa].compra;	
	//id de la empresa de tipo int
	id_empresa = id_empresa + 1;
	//cantidad de acciones de tipo int
	cant;


	if (opcion == 'y')
	{
		enviar_compra(usuario_id, id_empresa, cant, actual);
		insertar_monto(usuario_id,saldo_actual);

		cout << "La operacion se realizó con éxito" << "\n NUEVO SALDO: ";
		cout << round_to_string(saldo_actual) << endl;
	}
	
	else { cout << "Se ha cancelado el pedido\n"; }

	cout << "\nVOLVIENDO AL MENU...";

	this_thread::sleep_for(std::chrono::seconds(2));

	system("cls");

	mostrarEmpresasEnTabla(12);

	menuOperaciones();
	
}

void enviar_compra(int id_usuario,int id_empresa,int cantidad, string precio_actual) {

	int q_estado;

	abrir_conexion1();
	
	//modificando la tabla registro_compras para registrar la compra
	string consulta = "INSERT INTO registro_compras (usuario_id, empresa_id, cantidad_acciones, precio) VALUES (" +
		to_string(id_usuario) + ", " +
		to_string(id_empresa) + ", " +
		to_string(cantidad) + ", '" +
		precio_actual + "')";

	const char* p1 = consulta.c_str();
	q_estado = mysql_query(conectar1, p1);
	if (!q_estado) {
		cout << "Ingreso de compra exitoso...";
		this_thread::sleep_for(std::chrono::milliseconds(100));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << " xxx Error al Consultar registro_compras xxx" << endl;
	}
	
	//modificando la tabla accionesTabla para registrar la cantidad de acciones
	string consulta1 = "CALL UpdateAcciones(" +
			to_string(id_usuario) + "," +
			to_string(id_empresa) + "," +
			to_string(cantidad) + ")";

	const char* r1 = consulta1.c_str();
	q_estado = mysql_query(conectar1, r1);
	if (!q_estado) {
		cout << "Ingreso de compra exitoso...";
		this_thread::sleep_for(std::chrono::milliseconds(100));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << " xxx Error al Consultar acctiones_tabla xxx" << endl;
	}

	cerrar_conexion1();

}

void enviar_venta(int id_usuario, int id_empresa, int cantidad, string precio_actual) {

	int q_estado;

	abrir_conexion1();

	//modificando la tabla registro_compras para registrar la compra
	string consulta = "INSERT INTO registro_ventas (usuario_id, empresa_id, cantidad_acciones, precio) VALUES (" +
		to_string(id_usuario) + ", " +
		to_string(id_empresa) + ", " +
		to_string(cantidad) + ", '" +
		precio_actual + "')";

	const char* p2 = consulta.c_str();
	q_estado = mysql_query(conectar1, p2);
	if (!q_estado) {
		cout << "Ingreso de venta exitoso...";
		this_thread::sleep_for(std::chrono::milliseconds(100));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << " xxx Error al Consultar registro_compras xxx" << endl;
	}

	//modificando la tabla accionesTabla para registrar la cantidad de acciones
	string consulta1 = "CALL UpdateLessAcciones(" +
		to_string(id_usuario) + "," +
		to_string(id_empresa) + "," +
		to_string(cantidad) + ")";

	const char* r21 = consulta1.c_str();
	q_estado = mysql_query(conectar1, r21);
	if (!q_estado) {
		cout << "Ingreso de compra exitoso...";
		this_thread::sleep_for(std::chrono::milliseconds(100));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << " xxx Error al Consultar acctiones_tabla xxx" << endl;
	}

	cerrar_conexion1();

}

void vender(int usuario_id) {

	vector<Db_usuarios> ucer;

	obtener_usuarios(ucer);
	
	vector<Db_acciones> acciones;

	obtener_acciones(acciones);

	vector<Db_tabla> resultados;

	obtener_valores(resultados);

	vector<Db_acciones> acciones_usuario;

	usuario_id = usuario_id - 1;

	for (int i = 0; i < acciones.size(); i++) {
		if (usuario_id+1 == (stoi(acciones[i].usuario_id))) {
			Db_acciones temp;
			temp.cantidad = acciones[i].cantidad;
			int id_empresa = stoi(acciones[i].empresa_id);
			temp.usuario_id = resultados[id_empresa-1].nombre;
			temp.empresa_id = acciones[i].empresa_id;
			acciones_usuario.push_back(temp);
		}
	}

	if (acciones_usuario.size()<1)
	{
		cout << "\nUsted no cuenta con acciones para vender" << endl;
		cout << "\nRegresando al menu pricipal..." << endl;
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
		mostrarEmpresasEnTabla(12);
		menuOperaciones();
		return;
	}

	string saldo = ucer[usuario_id].saldo;

	string usuario = ucer[usuario_id].nombre;

	int id_empresa = 0, cant = 0;

	Table welcome;

	welcome.add_row({ "SALDO ACTUAL " + saldo });

	welcome.add_row({ "Bienvenido " + usuario + "," });

	Table accioneson;

	accioneson.add_row({ "Cantidad " , "Empresa" , "Nombre de empresa"});

	for (int i = 0; i < acciones_usuario.size(); i++) {
		if (stoi(acciones_usuario[i].cantidad) > 0) {
			accioneson.add_row({ acciones_usuario[i].cantidad , acciones_usuario[i].empresa_id ,acciones_usuario[i].usuario_id });
		}
	}

	bool flag=false;
	//se verifica que las ids estén dentro de las que el usuario posee
	do {
		
		flag = false;

		system("cls");
		
		cout << accioneson ;

		cout << "\nIngrese el ID de la empresa a vender: ";
		cin >> id_empresa; 
		borrar_linea();
		for (int i = 0; i < acciones_usuario.size(); i++) {
			if ((stoi(acciones_usuario[i].empresa_id) == id_empresa)&&(stoi(acciones_usuario[i].cantidad)!=0)) {
				flag = true;
			}			
		}
		if (flag == false) {
			cout << "\nID de empresa no existente... ";
		}
		borrar_linea();

	} while (flag==false);
	//

	id_empresa = id_empresa - 1;

	float valor_venta = stof(resultados[id_empresa].venta);
	
	cout << endl;

	do {
		flag = false;

		cout << "Ingrese la cantidad de acciones a vender: ";

		cin >> cant; 

		if (cant < 1)
		{
			cout << "\nLa cantidad debe ser mayor a 0";
			this_thread::sleep_for(chrono::seconds(2));
			cout << "\r                                                   \r" << flush;
			cout << "\033[A" << "\033[A";
			cout << "\r                                                   \r" << flush;
		}
		else if (stoi(acciones_usuario[id_empresa].cantidad) < cant) {
			cout << "\nLa cantidad insertada es mayor a las que posee";
			this_thread::sleep_for(chrono::seconds(2));
			cout << "\r                                                   \r" << flush;
			cout << "\033[A" << "\033[A";
			cout << "\r                                                   \r" << flush;                                      
		}
		else if((cant > 0)&&(cant < stoi(acciones_usuario[id_empresa].cantidad)+1)){
			flag = true;
		}

	} while (flag==false);

	valor_venta = valor_venta * cant;

	Table tabla;

	stringstream stream;

	float adicional = 50;
	float total = valor_venta - adicional;

	//añadiendo caracteristicas a la boleta de compra
	tabla.add_row({ "Nombre de la empresa ",resultados[id_empresa].nombre });
	tabla.add_row({ "Precio unitario de la acción ",resultados[id_empresa].venta });
	tabla.add_row({ "Cantidad solicitada ",to_string(cant) });
	tabla.add_row({ "Subtotal de compra ",round_to_string(valor_venta) });
	tabla.add_row({ "Adicional por operacion ",round_to_string(adicional) });
	tabla.add_row({ "Total de la de la venta (se resta el adicional) ",round_to_string(total) });

	tabla.format()
		.border("=")
		.border_left("|")
		.border_right("|")
		.corner("+");

	tabla.column(1).format().width(30);
	tabla.column(1).format().width(20);
	tabla.column(0).format().font_background_color(Color::red).font_style({ FontStyle::bold });

	system("cls");

	//Creando boleta de  confirmacion
	cout << "\nBOLETA DE CONFIRMACION" << endl;

	cout << tabla;

	cout << "\nSALDO RESTANTE -->" << round_to_string(stof(saldo) + (valor_venta - adicional));

	char opcion;

	cout << "\nDESEA EFECTUAR LA OPERACION?\n" << endl;

	do { cout << "y: si / n: no --> "; opcion = _getch(); if (opcion != 'y' && opcion != 'n') { borrar_linea(); } } while (opcion != 'y' && opcion != 'n');

	float saldo_actual = stof(saldo) + (valor_venta - adicional);
	//id del usuario de tipo int
	usuario_id = usuario_id + 1;
	//precio actual de tipo string
	string actual = resultados[id_empresa].venta;
	//id de la empresa de tipo int
	id_empresa = id_empresa + 1;
	//cantidad de acciones de tipo int
	cant;


	if (opcion == 'y')
	{
		enviar_venta(usuario_id, id_empresa, cant, actual);
		insertar_monto(usuario_id, saldo_actual);

		cout << "La operacion se realizó con éxito" << "\n NUEVO SALDO: ";
		cout << round_to_string(saldo_actual) << endl;
	}

	else { cout << "Se ha cancelado el pedido\n"; }

	cout << "\nVOLVIENDO AL MENU...";

	this_thread::sleep_for(std::chrono::seconds(2));

	system("cls");

	mostrarEmpresasEnTabla(12);

	menuOperaciones();


}
