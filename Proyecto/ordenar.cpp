#include <iostream>
#include <conio.h>
#include <algorithm>
#include "tabulate.hpp"
#include "ordenar.h"
#include "tabla.h"


void menuOrdenar()
{

	vector<Db_tabla> listaEmpresa;
	obtener_valores(listaEmpresa);

	std::cout << "\n\n ORDENAR TABLA\n";
	std::cout << "=============================================";
	std::cout << "\n - Ordenar por: ";
	std::cout << "\n [0]: ID";
	std::cout << "\n [1]: Nombre";
	std::cout << "\n [2]: Apertura";
	std::cout << "\n [3]: Ultima";
	std::cout << "\n [4]: Varianza %";
	std::cout << "\n [5]: Compra";
	std::cout << "\n [6]: Venta";
	std::cout << "\n [7]: Monto";
	std::cout << "\n [8]: Cantidad Negociada";
	std::cout << "\n [9]: Numero de Operaciones\n\n";

	char operacionOrdenar{};
	bool operacionValid{ false };

	do
	{
		operacionOrdenar = inputOperacion();
		std::cout << "\r\t\t\t\t\t\t\r";

		switch (operacionOrdenar)
		{
		case '1':
			ordenarSTR(listaEmpresa);
			operacionValid = 1;
			break;
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			ordenarNUM(listaEmpresa,operacionOrdenar);
			operacionValid = 1;
			break;
		default:
			break;
		}
	} while (!operacionValid);

	std::cout << "\r - Redistribucion:";
	std::cout << "\n [1]: Ascendente (La primera fila para el mas bajo)";
	std::cout << "\n [2]: Descendente (La primera fila para el mas alto)\n\n";

	char operacionRedistribucion{};
	operacionValid = 0;

	do
	{
		operacionRedistribucion = inputOperacion();
		std::cout<< "\r\t\t\t\t\t\t\r";

		switch (operacionRedistribucion)
		{
		case '1':
			operacionValid = 1;
			break;
		case '2':
			std::reverse(listaEmpresa.begin(), listaEmpresa.end());
			operacionValid = 1;
			break;
		default:
			break;
		}
	} while (!operacionValid);

	// Ordenar

	cleanupAndPrint(listaEmpresa);
}

void ordenarNUM(std::vector<Db_tabla>& vec_struct, char modo)
{
	int size_vec{ static_cast<int>(vec_struct.size()) };
	for (int i{ 0 }; i <size_vec; ++i)
	{
		double dcompI{};
		double dcompF{};

		

		for (int j{ i+1 }; j < size_vec; ++j)
		{
			switch (modo)
			{
			case '0':
				dcompI = std::stod(vec_struct[i].id);
				dcompF = std::stod(vec_struct[j].id);
				break;
			case '2':
				dcompI = std::stod(vec_struct[i].apertura);
				dcompF = std::stod(vec_struct[j].apertura);
				break;
			case '3':
				dcompI = std::stod(vec_struct[i].ultima);
				dcompF = std::stod(vec_struct[j].ultima);
				break;
			case '4':
				dcompI = std::stod(vec_struct[i].var);
				dcompF = std::stod(vec_struct[j].var);
				break;
			case '5':
				dcompI = std::stod(vec_struct[i].compra);
				dcompF = std::stod(vec_struct[j].compra);
				break;
			case '6':
				dcompI = std::stod(vec_struct[i].venta);
				dcompF = std::stod(vec_struct[j].venta);
				break;
			case '7':
				dcompI = std::stod(vec_struct[i].monto);
				dcompF = std::stod(vec_struct[j].monto);
				break;
			case '8':
				dcompI = std::stod(vec_struct[i].cantidad);
				dcompF = std::stod(vec_struct[j].cantidad);
				break;
			case '9':
				dcompI = std::stod(vec_struct[i].operaciones);
				dcompF = std::stod(vec_struct[j].operaciones);
				break;
			}

			if (dcompI > dcompF)
			{
				Db_tabla temp{ vec_struct[i] };
				vec_struct[i] = vec_struct[j];
				vec_struct[j] = temp;
			}
			
		}
	}
}

void ordenarSTR(std::vector<Db_tabla>& str_vec)
{
	int size_vec{ static_cast<int>(str_vec.size()) };
	for (int i{ 0 }; i < size_vec; ++i)
	{
		for (int j{ i + 1 }; j < size_vec; ++j)
		{
			if (alphabeticalOrder(str_vec[i].nombre, str_vec[j].nombre))
			{
				Db_tabla temp{ str_vec[i] };
				str_vec[i] = str_vec[j];
				str_vec[j] = temp;
			}
		}
	}
}

bool alphabeticalOrder(string str1, string str2)
{
	int loop{ str1.length() < str2.length() ? static_cast<int>(str1.length()) : static_cast<int>(str2.length()) };

	for (int k{ 0 }; k < loop; ++k)
	{
		if (str1[k] > str2[k]) return true;
		else return false;
	}
	if (loop < static_cast<int>(str1.length())) return true;
	else return false;
}
