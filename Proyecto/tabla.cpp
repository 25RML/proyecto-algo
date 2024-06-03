#include "tabulate.hpp"
#include "tabla.h"
#include <iostream>
#include <conio.h>
#include "Conexion.h"
#include<thread>
using namespace tabulate;

void mostrarEmpresasEnTabla(int filas)
{

	Table listaEmpresas;
	listaEmpresas.add_row({ "ID", "Empresa","Apertura","Ultima","Var%","Compra","Venta","Monto","Cant. Neg.","#N Op." });
	listaEmpresas[0].format()
		.font_color(Color::blue)
		.width(20)
		.font_align(FontAlign::center)
		.border_top("=")
		.font_style({ FontStyle::bold });
	
	vector<Db_tabla> resultado;

	obtener_valores(resultado);

	for (int i{0}; i < filas; ++i)
	{
		listaEmpresas.add_row(RowStream{}
			<<resultado[i].id
			<<resultado[i].nombre
			<<resultado[i].apertura
			<<resultado[i].ultima
			<<resultado[i].var
			<<resultado[i].compra
			<<resultado[i].venta
			<<resultado[i].monto
			<<resultado[i].cantidad
			<<resultado[i].operaciones
		);
	}
	
	listaEmpresas[1].format()
		.border_top("=");

	listaEmpresas.column(0).format()
		.font_style({FontStyle::bold})
		.font_color(Color::red)
		.width(4)
		.font_align(FontAlign::center);

	for (int i{ 1 }; i <= 9; ++i)
	{
		listaEmpresas.column(i).format()
			.width(12)
			.border_left("");
	}

	listaEmpresas.column(1).format()
		.width(30);
	
	std::cout << listaEmpresas << '\n';

}

void menuOperaciones()
{
	Table Operaciones;

	Operaciones.add_row({ "[1] Comprar","[2] Vender","[3] Analizar","[4] Mi Portafolio","[5] Ordenar","[6] Terminar"});
	Operaciones.format()
		.font_color(Color::green)
		.width(22)
		.font_align(FontAlign::center)
		.border_top("=")
		.border_bottom("=")
		.font_style({ FontStyle::bold });

	for (int i{ 1 }; i <= 5; ++i)
	{
		Operaciones[0][i].format()
			.border_left("");
	}

	std::cout << " -> OPERACIONES: \n\n";
	std::cout << Operaciones << "\n\n";

}

char inputOperacion()
{
	
	std::cout << " - Comando: ";
	std::fflush(stdin);
	char operacion{static_cast<char>(_getch()) };

	return operacion;
}


void menuComprar()
{
	std::cout << "\n\n INTERFAZ DE COMPRAS\n";
	std::cout << "=============================================";
	std::cout << "\n Ingrese el ID de la empresa en la que desea comprar: ";
	int ID_empresa{ 0 };
	std::cin >> ID_empresa;
	std::cout << "\n Ingrese el numero de acciones a adquirir: ";
	int num_acciones{ 0 };
	std::cin >> num_acciones;

	std::cout << "[PLACEHOLDER] Compra adquirida...\n";

	_getch();

	// Cleanup
	std::cout << "\033[2J\033[1;1H";

	std::cout << "\tMOVIMIENTOS DIARIOS\n";
	mostrarEmpresasEnTabla(12);

	menuOperaciones();

}

void menuVender()
{
	std::cout << "\n\n INTERFAZ DE VENTAS\n";
	std::cout << "=============================================";
	std::cout << "\n Ingrese el ID de la empresa en la que desea vender: ";
	int ID_empresa{ 0 };
	std::cin >> ID_empresa;
	std::cout << "\n Ingrese el numero de acciones a vender: ";
	int num_acciones{ 0 };
	std::cin >> num_acciones;

	std::cout << "[PLACEHOLDER] Venta Realizada...\n";

	_getch();

	// Cleanup
	std::cout << "\033[2J\033[1;1H";

	std::cout << "\tMOVIMIENTOS DIARIOS\n";
	mostrarEmpresasEnTabla(10);

	menuOperaciones();
}

void menuAnalizar()
{
	std::cout << "\n\n INTERFAZ DE ANALISIS\n";
	std::cout << "=============================================";
	std::cout << "\n Ingrese el ID de la empresa en que desea analizar: ";
	int ID_empresa{ 0 };
	std::cin >> ID_empresa;

	std::cout << "[PLACEHOLDER] Informacion de la empresa...\n";

	_getch();

	// Cleanup
	std::cout << "\033[2J\033[1;1H";

	std::cout << "\tMOVIMIENTOS DIARIOS\n";
	mostrarEmpresasEnTabla(10);

	menuOperaciones();
}

void menuMiPortafolio(int ID_user)
{
	int opcion;

	vector<Db_acciones> resultado;
	obtener_acciones(resultado);
	vector<Db_compras> rescompras;
	obtener_compras(rescompras);
	vector<Db_ventas> resventas;
	obtener_ventas(resventas);
	vector<Db_compras> compras_usuario;
	vector<Db_ventas> ventas_usuario;
	vector<Db_tabla> empresas;
	obtener_valores(empresas);
	
	std::cout << "\n\n MI PORTAFOLIO\n";
	std::cout << "=============================================\n";
	std::cout << "Que datos desea visualizar:\n ";
	std::cout << "1. ACCIONES COMPRADAS\n ";
	std::cout << "2. ACCIONES VENDIDAS:\n ";
	do {
		cin>>opcion;
	} while (opcion != 1 && opcion != 2);
	if (opcion == 1) {
		//Acciones compradas
		for (int i = 0; i < rescompras.size(); i++) {
			if (ID_user == stoi(rescompras[i].usuario_id)) {
				Db_compras auxiliar;
				auxiliar.id = rescompras[i].id;
				auxiliar.usuario_id = empresas[stoi(rescompras[i].empresa_id)-1].nombre;
				auxiliar.empresa_id = rescompras[i].empresa_id;
				auxiliar.cantidad_acciones = rescompras[i].cantidad_acciones;
				auxiliar.fecha_compra = rescompras[i].fecha_compra;
				auxiliar.precio = rescompras[i].precio;
				compras_usuario.push_back(auxiliar);
			};
		}
		Table compras_tabla;
		compras_tabla.add_row({"ID EMPRESA","NOMBRE","CANTIDAD DE ACCIONES","FECHA DE COMPRA","PRECIO DE ACCION"});
		for (int i = 0; i < compras_usuario.size(); i++) {
			compras_tabla.add_row({ 
				//compras_usuario[i].id,
				compras_usuario[i].empresa_id,
				compras_usuario[i].usuario_id,
				compras_usuario[i].cantidad_acciones,
				compras_usuario[i].fecha_compra,
				compras_usuario[i].precio });
		}
		std::cout << endl << compras_tabla << endl;
	}
	else if (opcion == 2) {
		//Acciones vendidas
		for (int i = 0; i < resventas.size(); i++) {
			if (ID_user == stoi(resventas[i].usuario_id)) {
				Db_ventas auxiliar2;
				auxiliar2.id = resventas[i].id;
				auxiliar2.usuario_id = empresas[stoi(resventas[i].empresa_id) - 1].nombre;
				auxiliar2.empresa_id = resventas[i].empresa_id;
				auxiliar2.cantidad_acciones = resventas[i].cantidad_acciones;
				auxiliar2.fecha_compra = resventas[i].fecha_compra;
				auxiliar2.precio = resventas[i].precio;
				ventas_usuario.push_back(auxiliar2);
			};
		}
		Table ventas_tabla;
		ventas_tabla.add_row({ "ID EMPRESA","NOMBRE","CANTIDAD DE ACCIONES","FECHA DE VENTA","PRECIO DE ACCION"});
		for (int i = 0; i < ventas_usuario.size(); i++) {
			ventas_tabla.add_row({
				//ventas_usuario[i].id,
				ventas_usuario[i].empresa_id,
				ventas_usuario[i].usuario_id,
				ventas_usuario[i].cantidad_acciones,
				ventas_usuario[i].fecha_compra,
				ventas_usuario[i].precio });
		}
		std::cout << endl << ventas_tabla << endl;
	}

	


	int suma = 0,resta=0;
	for (int i = 0; i < rescompras.size(); i++) {
		if (ID_user == stoi(rescompras[i].usuario_id)) {
			Db_compras auxiliar;
			auxiliar.cantidad_acciones = rescompras[i].cantidad_acciones;
			suma += stoi(rescompras[i].cantidad_acciones);
		};
	}
	for (int i = 0; i < resventas.size(); i++) {
		if (ID_user == stoi(resventas[i].usuario_id)) {
			Db_compras auxiliar;
			auxiliar.cantidad_acciones = resventas[i].cantidad_acciones;
			resta += stoi(resventas[i].cantidad_acciones);
		};
	}
	std::cout << "\nTOTAL DE ACCIONES COMPRADAS: ";
	std::cout << suma;
	std::cout << "\nTOTAL DE ACCIONES VENDIDAS: ";
	std::cout << resta;
	std::cout << "\nTOTAL DE ACCIONES EN POSESION: ";
	std::cout << suma - resta;
	this_thread::sleep_for(chrono::seconds(2));
	_getch();

	vector<Db_tabla> actu_temp;
	obtener_valores(actu_temp);
	cleanupAndPrint(actu_temp);
}

void imprimirTablaEnMenu(std::vector<Db_tabla> listaEmpresa)
{
	using namespace tabulate;

	Table listaEmpresas;
	listaEmpresas.add_row({ "ID", "Empresa","Apertura","Ultima","Var%","Compra","Venta","Monto","Cant. Neg.","#N Op." });
	listaEmpresas[0].format()
		.font_color(Color::blue)
		.width(20)
		.font_align(FontAlign::center)
		.border_top("=")
		.font_style({ FontStyle::bold });

	for (int i{ 0 }; i < listaEmpresa.size(); ++i)
	{
		listaEmpresas.add_row(RowStream{}
			<< listaEmpresa[i].id
			<< listaEmpresa[i].nombre
			<< listaEmpresa[i].apertura
			<< listaEmpresa[i].ultima
			<< listaEmpresa[i].var
			<< listaEmpresa[i].compra
			<< listaEmpresa[i].venta
			<< listaEmpresa[i].monto
			<< listaEmpresa[i].cantidad
			<< listaEmpresa[i].operaciones
		);
	}

	listaEmpresas[1].format()
		.border_top("=");

	listaEmpresas.column(0).format()
		.font_style({ FontStyle::bold })
		.font_color(Color::red)
		.width(4)
		.font_align(FontAlign::center);

	for (int i{ 1 }; i <= 9; ++i)
	{
		listaEmpresas.column(i).format()
			.width(12)
			.border_left("");
	}

	listaEmpresas.column(1).format()
		.width(30);

	std::cout << listaEmpresas << '\n';

}

void cleanupAndPrint(std::vector<Db_tabla> listaImprimir)
{
	std::cout << "\033[2J\033[1;1H";

	std::cout << "\tMOVIMIENTOS DIARIOS\n";
	imprimirTablaEnMenu(listaImprimir);

	menuOperaciones();
}