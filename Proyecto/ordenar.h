#ifndef _ORDENAR_
#define _ORDENAR_

#include "Conexion.h"

void menuOrdenar();
void ordenarNUM(std::vector<Db_tabla>&,char);
bool alphabeticalOrder(string str1, string str2);
void ordenarSTR(std::vector<Db_tabla>& str_vec);

#endif // !_ORDENAR_

