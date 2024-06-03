#pragma once

#include "Conexion.h" // para Db_tabla
#include "tabulate.hpp" // <vector>?

void mostrarEmpresasEnTabla(int);
void menuOperaciones();
char inputOperacion();

void menuComprar();
void menuVender();
void menuAnalizar();
void menuMiPortafolio();

// Display
void imprimirTablaEnMenu(std::vector<Db_tabla>);
void cleanupAndPrint(std::vector<Db_tabla>);