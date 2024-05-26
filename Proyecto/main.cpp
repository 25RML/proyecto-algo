#include <iostream>
#include "tabla.h"
#include <iostream>

int main()
{
	// Mostrar Movimientos Diarios en Forma de Menu
	std::cout << "\tMOVIMIENTOS DIARIOS\n";
	mostrarEmpresasEnTabla(12);

	char comandoMovDiarios{};
	menuOperaciones();
	// Nombres[10]
	// Costos
	// P Compra

	do
	{
		comandoMovDiarios = inputOperacion();
		std::cout << "\r\t\t\t\t\t\t\r";

		switch (comandoMovDiarios)
		{
		case '1':
			menuComprar();
			break;
		case '2':
			menuVender();
			break;
		case '3':
			menuAnalizar();
			break;
		case '4':
			menuMiPortafolio();
			break;
		case '6':
			return 0;
		default:
			//std::cout << "\r\t\t\t\t\t\t\r";
			break;
		}


	} while (true);


	

	return 0;
}