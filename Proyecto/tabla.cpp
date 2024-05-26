#include "tabulate.hpp"
#include "tabla.h"
#include <iostream>
#include <conio.h>

using namespace tabulate;

void mostrarEmpresasEnTabla(int filas)
{

	Table listaEmpresas;

	listaEmpresas.add_row({ "ID", "Empresa","Apertura","Ultima","Var%","Compra","Venta","Monto","Cant. Neg.","#N Op." });
	listaEmpresas[0].format()
		.font_color(Color::blue)
		.width(20)
		.font_align(FontAlign::center)
		.border_top("=")
		.font_style({ FontStyle::bold });

	for (int i{ 0 }; i < filas; ++i)
	{
		listaEmpresas.add_row(RowStream{} << i + 1 << "Empresa" << 1 << 1 << 1 << 1 << 1 << 1 << 2 << 10);
	}

	listaEmpresas[1].format()
		.border_top("=");

	listaEmpresas.column(0).format()
		.font_style({FontStyle::bold})
		.font_color(Color::yellow)
		.width(4)
		.font_align(FontAlign::center);

	for (int i{ 1 }; i <= 9; ++i)
	{
		listaEmpresas.column(i).format()
			.width(12)
			.border_left("");
	}

	listaEmpresas.column(1).format()
		.width(30);
	
	std::cout << listaEmpresas << '\n';

}

void menuOperaciones()
{
	Table Operaciones;

	Operaciones.add_row({ "[1] Comprar","[2] Vender","[3] Analizar","[4] Mi Portafolio","[5] Ordenar","[6] Terminar"});
	Operaciones.format()
		.font_color(Color::green)
		.width(22)
		.font_align(FontAlign::center)
		.border_top("=")
		.border_bottom("=")
		.font_style({ FontStyle::bold });

	for (int i{ 1 }; i <= 5; ++i)
	{
		Operaciones[0][i].format()
			.border_left("");
	}

	std::cout << " -> OPERACIONES: \n\n";
	std::cout << Operaciones << "\n\n";

}

char inputOperacion()
{
	
	std::cout << " - Comando: ";
	std::fflush(stdin);
	char operacion{static_cast<char>(_getch()) };

	return operacion;
}


void menuComprar()
{
	std::cout << "\n\n INTERFAZ DE COMPRAS\n";
	std::cout << "=============================================";
	std::cout << "\n Ingrese el ID de la empresa en la que desea comprar: ";
	int ID_empresa{ 0 };
	std::cin >> ID_empresa;
	std::cout << "\n Ingrese el numero de acciones a adquirir: ";
	int num_acciones{ 0 };
	std::cin >> num_acciones;

	std::cout << "[PLACEHOLDER] Compra adquirida...\n";

	_getch();

	// Cleanup
	std::cout << "\033[2J\033[1;1H";

	std::cout << "\tMOVIMIENTOS DIARIOS\n";
	mostrarEmpresasEnTabla(10);

	menuOperaciones();

}

void menuVender()
{
	std::cout << "\n\n INTERFAZ DE VENTAS\n";
	std::cout << "=============================================";
	std::cout << "\n Ingrese el ID de la empresa en la que desea vender: ";
	int ID_empresa{ 0 };
	std::cin >> ID_empresa;
	std::cout << "\n Ingrese el numero de acciones a vender: ";
	int num_acciones{ 0 };
	std::cin >> num_acciones;

	std::cout << "[PLACEHOLDER] Venta Realizada...\n";

	_getch();

	// Cleanup
	std::cout << "\033[2J\033[1;1H";

	std::cout << "\tMOVIMIENTOS DIARIOS\n";
	mostrarEmpresasEnTabla(10);

	menuOperaciones();
}

void menuAnalizar()
{
	std::cout << "\n\n INTERFAZ DE ANALISIS\n";
	std::cout << "=============================================";
	std::cout << "\n Ingrese el ID de la empresa en que desea analizar: ";
	int ID_empresa{ 0 };
	std::cin >> ID_empresa;

	std::cout << "[PLACEHOLDER] Informacion de la empresa...\n";

	_getch();

	// Cleanup
	std::cout << "\033[2J\033[1;1H";

	std::cout << "\tMOVIMIENTOS DIARIOS\n";
	mostrarEmpresasEnTabla(10);

	menuOperaciones();
}

void menuMiPortafolio()
{
	std::cout << "\n\n MI PORTAFOLIO\n";
	std::cout << "=============================================";

	std::cout << "\n\n[PLACEHOLDER] Informacion del Portafolio...\n";

	_getch();

	// Cleanup
	std::cout << "\033[2J\033[1;1H";

	std::cout << "\tMOVIMIENTOS DIARIOS\n";
	mostrarEmpresasEnTabla(10);

	menuOperaciones();
}