#include <iostream>
#include "tabla.h"
#include <iostream>
#include "Conexion.h"
#include"BuyAndSell.h"
#include"user_name.h"
#include<Windows.h>
#include"trading.h"
#include"ordenar.h"
int main()
{
	HWND hwnd = GetConsoleWindow();  // Obtener el identificador de la ventana de la consola
	ShowWindow(hwnd, SW_MAXIMIZE);	 // Mostrar la ventana de la consola en pantalla completa
	int user=verify_user();

	{
		int salir{ menuPrincipal() };
		if (salir == 0) return 0;
		std::cout << "\033[2J\033[1;1H";
	}

	std::cout << "\tMOVIMIENTOS DIARIOS\n";
	mostrarEmpresasEnTabla(12);
	//obtener_valores();
	char comandoMovDiarios{};
	menuOperaciones();
	do
	{
		comandoMovDiarios = inputOperacion();
		std::cout << "\r\t\t\t\t\t\t\r";

		switch (comandoMovDiarios)
		{
		case '1':
			//menuComprar();
			comprar(user);
			break;
		case '2':
			//menuVender();
			vender(user);
			break;
		case '3':
			//menuAnalizar();
			imprimir();
			break;
		case '4':
			menuMiPortafolio(user);
			break;
		case '5':
			menuOrdenar();
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