#pragma once
#include "tabulate.hpp"

struct Accion {
    std::string nombre;
    std::vector<double> precios;
    double stopLoss;
    double takeProfit;
    int indice;
};

void borrarPantalla();
void mostrarExplicacionesYPreguntas();
void actualizarPrecio(Accion&);
void mostrarTabla(const Accion&, const Accion&, const Accion&, int, int, int, double, double);
void aplicarStopLossTakeProfit(Accion&, int&, double&);
void miniJuego();
int menuPrincipal();
void mostrarTitulo(); //agregado
