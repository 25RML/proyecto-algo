#pragma once
#include"tabulate.hpp"
#include"Conexion.h"
void mostrarEmpresasEnTabla(int);
void menuOperaciones();
char inputOperacion();

void menuComprar();
void menuVender();
void menuAnalizar();
void menuMiPortafolio(int ID_user);

//DIsplay
void imprimirTablaEnMenu(std::vector<Db_tabla>);
void cleanupAndPrint(std::vector<Db_tabla>);