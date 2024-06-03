#include <iostream>
#include "tabla.h"
#include <iostream>
#include "Conexion.h"
#include "ordenar.h" // Menu Ordenar
#include "trading.h" // Funciones Fran
int main()
{
	{
		int salir{ menuPrincipal() };
		if (salir == 0) return 0;
		std::cout << "\033[2J\033[1;1H";
	}
	

	//verificar conexion a la db
	abrir_conexion();	
	cerrar_conexion();

	insertar_apertura(3, 25);

	// Inicializar un vector Db_tabla (temporal o no, nose)
	std::vector<Db_tabla> _tablaEmpresas;
	obtener_valores(_tablaEmpresas);

	char comandoMovDiarios{};

	// Mostrar Movimientos Diarios en Forma de Menu
	std::cout << "\tMOVIMIENTOS DIARIOS\n";

	imprimirTablaEnMenu(_tablaEmpresas); // test
	//mostrarEmpresasEnTabla(12); // Original

	//obtener_valores();
	
	menuOperaciones();

	



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