#pragma once
#include"tabulate.hpp"
using namespace std;
void abrir_conexion();
void cerrar_conexion();
struct Db_tabla {
	string
		id,
		nombre,
		apertura,
		ultima,
		var,
		compra,
		venta,
		monto,
		cantidad,
		operaciones;
};
void obtener_valores(vector<Db_tabla>& tabla_res);
void insertar_apertura(int a, float b);
void insertar_operaciones(int a, int value);
void insertar_cantidad(int a, float b);
void insertar_monto(int a, float value);