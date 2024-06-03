#pragma once
#include <string>
using namespace std;
void comprar(int usuario);
void enviar_compra(int id_usuario, int id_empresa, int cantidad, string precio_actual);
void enviar_venta(int id_usuario, int id_empresa, int cantidad, string precio_actual);
void vender(int usuario);
