#pragma once
#include"tabulate.hpp"
using namespace std;
void abrir_conexion();
void cerrar_conexion();
struct Db_usuarios {
	string
		id,
		usuario,
		nombre,
		apellido,
		contraseña,
		edad,
		saldo;
};
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
struct Db_ventas {
	string
		id,
		usuario_id,
		empresa_id,
		cantidad_acciones,
		fecha_compra,
		precio;
};
struct Db_compras {
	string
		id,
		usuario_id,
		empresa_id,
		cantidad_acciones,
		fecha_compra,
		precio;
};
struct Db_acciones {
	string
		id,
		usuario_id,
		empresa_id,
		cantidad;
};

void obtener_valores(vector<Db_tabla>& tabla_res);
void obtener_usuarios(vector<Db_usuarios>& res);
void obtener_acciones(vector<Db_acciones>& res);
void obtener_ventas(vector<Db_ventas>& res);
void obtener_compras(vector<Db_compras>& res);
void insertar_monto(int a, float value);
void imprimir();