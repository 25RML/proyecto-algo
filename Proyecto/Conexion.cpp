#include "Conexion.h"
#include<iostream>
#include<string>
#include<mysql.h>
#include"tabulate.hpp"
#include"tabla.h"
#include<thread>

using namespace std;
using namespace tabulate;

MYSQL* conectar;
MYSQL_RES* resultado;
MYSQL_ROW fila;

void abrir_conexion() {
	
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar,"roundhouse.proxy.rlwy.net","root","LRzBRogGeTTgGxcGvPrxUpcEczRzzDAQ","railway",24103,NULL,0);
	if (conectar) {
		cout << "Conexion exitosa...";
		this_thread::sleep_for(std::chrono::milliseconds(100));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << "error en la conexion...\n";
	}

}

void cerrar_conexion() {
	mysql_close(conectar);
}

void obtener_valores(vector<Db_tabla>& tabla_res) {

	//Table listaEmpresas;

	int q_estado;

	abrir_conexion();

	string consulta = "select * from empresasTabla";
	const char* c5 = consulta.c_str();
	int x = 0;
	q_estado = mysql_query(conectar, c5);
	if (!q_estado) {
		resultado = mysql_store_result(conectar);
		while (fila = mysql_fetch_row(resultado)) {
			Db_tabla nueva_fila;
			nueva_fila.id = fila[0];
			nueva_fila.nombre = fila[1];
			nueva_fila.apertura = fila[2];
			nueva_fila.ultima = fila[3];
			nueva_fila.var = fila[4];
			nueva_fila.compra = fila[5];
			nueva_fila.venta = fila[6];
			nueva_fila.monto = fila[7];
			nueva_fila.cantidad = fila[8];
			nueva_fila.operaciones = fila[9];
			tabla_res.push_back(nueva_fila);
		}
	}
	else {
		cout << " xxx Error al Consultar valores de la tabla xxx" << endl;
	}

	cerrar_conexion();

}

void obtener_usuarios(vector<Db_usuarios>& res) {

	int q_estado;

	abrir_conexion();

	string consulta = "select * from usuariosTabla";
	const char* c6 = consulta.c_str();
	int x = 0;
	q_estado = mysql_query(conectar, c6);
	if (!q_estado) {
		resultado = mysql_store_result(conectar);
		while (fila = mysql_fetch_row(resultado)) {
			Db_usuarios nueva;
			nueva.id = fila[0];
			nueva.usuario = fila[1];
			nueva.nombre = fila[2];
			nueva.apellido = fila[3];
			nueva.contraseña = fila[4];
			nueva.edad = fila[5];
			nueva.saldo = fila[6];
			res.push_back(nueva);
		}
	}
	else {
		cout << " xxx Error al Consultar  xxx" << endl;
	}

	cerrar_conexion();

}

void obtener_acciones(vector<Db_acciones>& res) {

	int q_estado;

	abrir_conexion();

	string consulta = "select * from accionesTabla";
	const char* f4 = consulta.c_str();
	int x = 0;
	q_estado = mysql_query(conectar, f4);
	if (!q_estado) {
		resultado = mysql_store_result(conectar);
		while (fila = mysql_fetch_row(resultado)) {
			Db_acciones nueva;
			nueva.id = fila[0];
			nueva.usuario_id = fila[1];
			nueva.empresa_id = fila[2];
			nueva.cantidad = fila[3];
			res.push_back(nueva);

		}
	}
	else {
		cout << " xxx Error al Consultar  xxx" << endl;
	}

	cerrar_conexion();

}

void obtener_ventas(vector<Db_ventas>& res) {

	int q_estado;

	abrir_conexion();

	string consulta = "select * from registro_ventas";
	const char* a2 = consulta.c_str();
	int x = 0;
	q_estado = mysql_query(conectar, a2);
	if (!q_estado) {
		resultado = mysql_store_result(conectar);
		while (fila = mysql_fetch_row(resultado)) {
			Db_ventas nueva;
			nueva.id = fila[0];
			nueva.usuario_id = fila[1];
			nueva.empresa_id = fila[2];
			nueva.cantidad_acciones = fila[3];
			nueva.fecha_compra = fila[4];
			nueva.precio = fila[5];
			res.push_back(nueva);
		}

	}
	else {
		cout << " xxx Error al Consultar  xxx" << endl;
	}

	cerrar_conexion();

}

void obtener_compras(vector<Db_compras>& res)
{

	int q_estado;

	abrir_conexion();

	string consulta = "select * from registro_compras";
	const char* z1 = consulta.c_str();
	int x = 0;
	q_estado = mysql_query(conectar, z1);
	if (!q_estado) {
		resultado = mysql_store_result(conectar);
		while (fila = mysql_fetch_row(resultado)) {
			Db_compras nueva;
			nueva.id = fila[0];
			nueva.usuario_id = fila[1];
			nueva.empresa_id = fila[2];
			nueva.cantidad_acciones = fila[3];
			nueva.fecha_compra = fila[4];
			nueva.precio = fila[5];
			res.push_back(nueva);
		}

	}
	else {
		cout << " xxx Error al Consultar xxx" << endl;
	}

	cerrar_conexion();

}


void insertar_monto(int id, float value) {

	int q_estado;

	abrir_conexion();

	string consulta = "UPDATE usuariosTabla SET saldo=" + to_string(value) + " WHERE usuario_id=" + to_string(id);
	const char* p = consulta.c_str();
	q_estado = mysql_query(conectar, p);
	if (!q_estado) {
		cout << "Ingreso exitoso...";
		this_thread::sleep_for(std::chrono::milliseconds(100));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << " xxx Error al Consultar  ingreso de montos xxx" << endl;
	}

	cerrar_conexion();

}

void imprimir()
{
	Table tablon;
	vector<Db_usuarios> usuario;
	obtener_usuarios(usuario);
	for (int i = 0; i < 10; i++) {
		tablon.add_row({ usuario[i].id,usuario[i].usuario,usuario[i].nombre,usuario[i].apellido ,usuario[i].contraseña,usuario[i].edad,usuario[i].saldo});
	}
	cout << tablon;
}
