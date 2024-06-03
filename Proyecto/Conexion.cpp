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
		this_thread::sleep_for(std::chrono::seconds(1));
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

	Table listaEmpresas;

	int q_estado;

	abrir_conexion();

	string consulta = "select * from empresasTabla";
	const char* c = consulta.c_str();
	int x = 0;
	q_estado = mysql_query(conectar, c);
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
		cout << " xxx Error al Consultar  xxx" << endl;
	}

	cerrar_conexion();

}

void insertar_apertura(int id,float value) {

	int q_estado;

	abrir_conexion();

	string consulta = "UPDATE empresasTabla SET apertura='" + to_string(value) + "' WHERE id=" + to_string(id);
	const char* p = consulta.c_str();
	q_estado = mysql_query(conectar, p);
	if (!q_estado) {
		cout << "Ingreso exitoso...";
		this_thread::sleep_for(std::chrono::seconds(1));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << " xxx Error al Consultar  xxx" << endl;
	}

	cerrar_conexion();

}

void insertar_monto(int id, float value) {

	int q_estado;

	abrir_conexion();

	string consulta = "UPDATE empresasTabla SET monto='" + to_string(value) + "' WHERE id=" + to_string(id);
	const char* p = consulta.c_str();
	q_estado = mysql_query(conectar, p);
	if (!q_estado) {
		cout << "Ingreso exitoso...";
		this_thread::sleep_for(std::chrono::seconds(1));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << " xxx Error al Consultar  xxx" << endl;
	}

	cerrar_conexion();

}

void insertar_cantidad(int id, float value) {

	int q_estado;

	abrir_conexion();

	string consulta = "UPDATE empresasTabla SET cantidad='" + to_string(value) + "' WHERE id=" + to_string(id);
	const char* p = consulta.c_str();
	q_estado = mysql_query(conectar, p);
	if (!q_estado) {
		cout << "Ingreso exitoso...";
		this_thread::sleep_for(std::chrono::seconds(1));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << " xxx Error al Consultar  xxx" << endl;
	}

	cerrar_conexion();

}

void insertar_operaciones(int id, int value) {

	int q_estado;

	abrir_conexion();

	string consulta = "UPDATE empresasTabla SET operaciones='" + to_string(value) + "' WHERE id=" + to_string(id);
	const char* p = consulta.c_str();
	q_estado = mysql_query(conectar, p);
	if (!q_estado) {
		cout << "Ingreso exitoso...";
		this_thread::sleep_for(std::chrono::seconds(1));
		cout << "\r";
		cout << "                                      " << flush;
		cout << "\r";
	}
	else {
		cout << " xxx Error al Consultar  xxx" << endl;
	}

	cerrar_conexion();

}
