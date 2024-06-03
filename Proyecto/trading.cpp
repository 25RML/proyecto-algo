#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h>
#include "trading.h"

using namespace std;


void borrarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarExplicacionesYPreguntas() {
    int respuesta;

    borrarPantalla();
    cout << "===========================================\n";
    cout << "|       1. ENTENDIENDO EL TRADING         |\n";
    cout << "===========================================\n";
    cout << "El trading es la actividad de comprar y vender activos financieros, como\n";
    cout << "acciones, divisas o criptomonedas, con el objetivo de obtener una ganancia.\n";
    cout << "Los traders buscan aprovechar las fluctuaciones de precios en el mercado\n";
    cout << "para comprar a un precio bajo y vender a un precio mas alto.\n";
    cout << "===========================================\n";
    cout << "Pregunta: Que es el trading?\n";
    cout << "1. Comprar y vender activos financieros\n";
    cout << "2. Guardar dinero en el banco\n";
    cout << "3. Prestar dinero a amigos\n";
    cout << "Seleccione la opcion correcta: ";
    cin >> respuesta;
    while (respuesta != 1) {
        cout << "Respuesta incorrecta. Intente nuevamente: ";
        cin >> respuesta;
    }
    cout << "Correcto. El trading implica comprar y vender activos financieros para obtener ganancias.\n\n";
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

  

    borrarPantalla();
    cout << "===========================================\n";
    cout << "|       2. CATEGORIAS DE TRADING          |\n";
    cout << "===========================================\n";
    cout << "Existen diferentes estilos de trading, cada uno con sus propias estrategias\n";
    cout << "y horizontes temporales. Algunos ejemplos incluyen:\n";
    cout << "- Day trading: Compras y ventas dentro del mismo dia.\n";
    cout << "- Swing trading: Mantener posiciones por varios dias o semanas.\n";
    cout << "- Position trading: Mantener posiciones por meses o anos.\n";
    cout << "- Scalping: Realizar muchas operaciones en cortos periodos para\n";
    cout << "  obtener pequenas ganancias en cada una.\n";
    cout << "===========================================\n";
    cout << "Pregunta: Cual de los siguientes es un estilo de trading?\n";
    cout << "1. Prestar a corto plazo\n";
    cout << "2. Guardar dinero\n";
    cout << "3. Day trading\n";
    cout << "Seleccione la opcion correcta: ";
    cin >> respuesta;
    while (respuesta != 3) {
        cout << "Respuesta incorrecta. Intente nuevamente: ";
        cin >> respuesta;
    }
    cout << "Correcto. El day trading es un estilo de trading.\n\n";
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();


    borrarPantalla();
    cout << "===========================================\n";
    cout << "|      3. ENTENDIENDO LOS MERCADOS        |\n";
    cout << "===========================================\n";
    cout << "En el trading, se opera en diferentes tipos de mercados financieros, entre los que se incluyen:\n";
    cout << "- Acciones: Participaciones en empresas que cotizan en bolsa.\n";
    cout << "- Forex: Mercado de divisas, donde se intercambian diferentes monedas.\n";
    cout << "- Commodities: Materias primas como el oro, petroleo y productos agricolas.\n";
    cout << "- Criptomonedas: Activos digitales como Bitcoin y Ethereum.\n";
    cout << "===========================================\n";
    cout << "Pregunta: Cual de los siguientes es un tipo de mercado financiero?\n";
    cout << "1. Tienda de comestibles\n";
    cout << "2. Forex\n";
    cout << "3. Mercado de pulgas\n";
    cout << "Seleccione la opcion correcta: ";
    cin >> respuesta;
    while (respuesta != 2) {
        cout << "Respuesta incorrecta. Intente nuevamente: ";
        cin >> respuesta;
    }
    cout << "Correcto. Forex es un tipo de mercado financiero.\n\n";
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

   
    borrarPantalla();
    cout << "===========================================\n";
    cout << "|       4. HERRAMIENTAS DEL TRADER        |\n";
    cout << "===========================================\n";
    cout << "Los traders utilizan diversas herramientas para tomar decisiones informadas:\n";
    cout << "- Software de analisis: Programas que ayudan a analizar datos del mercado.\n";
    cout << "- Plataformas de trading: Aplicaciones donde se pueden ejecutar operaciones.\n";
    cout << "- Recursos educativos: Libros, cursos y webinars para mejorar el conocimiento.\n";
    cout << "===========================================\n";
    cout << "Pregunta: Cual de las siguientes es una herramienta del trader?\n";
    cout << "1. Software de analisis\n";
    cout << "2. Calculadora simple\n";
    cout << "3. Libreta de apuntes\n";
    cout << "Seleccione la opcion correcta: ";
    cin >> respuesta;
    while (respuesta != 1) {
        cout << "Respuesta incorrecta. Intente nuevamente: ";
        cin >> respuesta;
    }
    cout << "Correcto. El software de analisis es una herramienta del trader.\n\n";
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

   
    borrarPantalla();
    cout << "===========================================\n";
    cout << "|             5. GRAFICOS                 |\n";
    cout << "===========================================\n";
    cout << "Los graficos son herramientas visuales que muestran el comportamiento\n";
    cout << "historico de los precios. Algunos tipos comunes de graficos son:\n";
    cout << "- Grafico de lineas: Muestra la evolucion del precio a lo largo del tiempo.\n";
    cout << "- Grafico de barras: Presenta el precio de apertura, maximo, minimo y cierre.\n";
    cout << "- Velas Japonesas: Similar al grafico de barras pero con mayor enfasis\n";
    cout << "  en la psicologia del mercado.\n";
    cout << "===========================================\n";
    cout << "Pregunta: Cual de los siguientes es un tipo de grafico usado en el trading?\n";
    cout << "1. Grafico de lineas\n";
    cout << "2. Grafico de barras\n";
    cout << "3. Velas Japonesas\n";
    cout << "4. Todas las anteriores\n";
    cout << "Seleccione la opcion correcta: ";
    cin >> respuesta;
    while (respuesta != 4) {
        cout << "Respuesta incorrecta. Intente nuevamente: ";
        cin >> respuesta;
    }
    cout << "Correcto. Todos estos son tipos de graficos utilizados en el trading.\n\n";
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

    borrarPantalla();
    cout << "===========================================\n";
    cout << "|       6. VELAS JAPONESAS (CANDLESTICKS) |\n";
    cout << "===========================================\n";
    cout << "Las velas japonesas son una herramienta fundamental en el analisis tecnico.\n";
    cout << "Cada vela representa un periodo de tiempo especifico y contiene cuatro puntos clave:\n";
    cout << "- Precio de apertura: Donde comienza la vela.\n";
    cout << "- Precio de cierre: Donde termina la vela.\n";
    cout << "- Maximo: El precio mas alto alcanzado durante el periodo.\n";
    cout << "- Minimo: El precio mas bajo alcanzado durante el periodo.\n";
    cout << "El cuerpo de la vela muestra la diferencia entre el precio de apertura y cierre,\n";
    cout << "mientras que las mechas (sombras) indican los puntos maximos y minimos.\n";
    cout << "===========================================\n";
    cout << "Pregunta: Que parte de una vela japonesa indica el precio de apertura y cierre?\n";
    cout << "1. El cuerpo\n";
    cout << "2. La mecha\n";
    cout << "3. La sombra\n";
    cout << "Seleccione la opcion correcta: ";
    cin >> respuesta;
    while (respuesta != 1) {
        cout << "Respuesta incorrecta. Intente nuevamente: ";
        cin >> respuesta;
    }
    cout << "Correcto. El cuerpo de una vela japonesa indica el precio de apertura y cierre.\n\n";
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

    borrarPantalla();
    cout << "===========================================\n";
    cout << "|   7. SOPORTE Y RESISTENCIA               |\n";
    cout << "===========================================\n";
    cout << "Los niveles de soporte y resistencia son fundamentales en el analisis tecnico:\n";
    cout << "- Soporte: Un nivel donde la demanda es fuerte y puede detener la caida del precio.\n";
    cout << "- Resistencia: Un nivel donde la oferta es fuerte y puede detener la subida del precio.\n";
    cout << "===========================================\n";
    cout << "Pregunta: Que es un nivel de soporte?\n";
    cout << "1. Un nivel donde el precio se mantiene constante\n";
    cout << "2. Un nivel donde la oferta es fuerte y puede detener la subida del precio\n";
    cout << "3. Un nivel donde la demanda es fuerte y puede detener la caida del precio\n";
    cout << "Seleccione la opcion correcta: ";
    cin >> respuesta;
    while (respuesta != 2) {
        cout << "Respuesta incorrecta. Intente nuevamente: ";
        cin >> respuesta;
    }
    cout << "Correcto. Un nivel de soporte es donde la demanda es fuerte y puede detener la caida del precio.\n\n";
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

    borrarPantalla();
    cout << "===========================================\n";
    cout << "|   8. PATRONES DE REVERSAL Y CONTINUACION |\n";
    cout << "===========================================\n";
    cout << "En el analisis tecnico, los traders buscan patrones que indican posibles\n";
    cout << "cambios en la direccion del precio (patrones de reversal) o la continuacion\n";
    cout << "de una tendencia existente (patrones de continuacion). Ejemplos incluyen:\n";
    cout << "- Patrones de reversal: Hombro-Cabeza-Hombro, Doble Techo/Doble Suelo.\n";
    cout << "- Patrones de continuacion: Banderas, Banderines, Rectangulos.\n";
    cout << "===========================================\n";
    cout << "Pregunta: Cual de los siguientes es un patron de continuacion de tendencia?\n";
    cout << "1. Banderas\n";
    cout << "2. Banderines\n";
    cout << "3. Rectangulos\n";
    cout << "4. Todas las anteriores\n";
    cout << "Seleccione la opcion correcta: ";
    cin >> respuesta;
    while (respuesta != 4) {
        cout << "Respuesta incorrecta. Intente nuevamente: ";
        cin >> respuesta;
    }
    cout << "Correcto. Banderas, banderines y rectangulos son patrones de continuacion de tendencia.\n\n";
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
    borrarPantalla();
}

void actualizarPrecio(Accion& accion) {
    accion.indice = (accion.indice + 1) % accion.precios.size();
    for (double& precio : accion.precios) {
        precio *= 1.1;
    }
}

void mostrarTabla(const Accion& apple, const Accion& tesla, const Accion& amazon, int appleShares, int teslaShares, int amazonShares, double balance, double meta) {
    cout << "===========================================\n";
    cout << "|            ESTADO ACTUAL                |\n";
    cout << "===========================================\n";
    cout << "Balance: " << fixed << setprecision(2) << balance << " soles (Meta: " << meta << " soles)\n";
    cout << "-------------------------------------------\n";
    cout << "| Accion | Precio | Stop Loss | Take Profit | Cantidad |\n";
    cout << "-------------------------------------------\n";
    cout << "| Apple  | " << setw(6) << apple.precios[apple.indice] << " | " << setw(9) << apple.stopLoss << " | " << setw(11) << apple.takeProfit << " | " << setw(8) << appleShares << " |\n";
    cout << "| Tesla  | " << setw(6) << tesla.precios[tesla.indice] << " | " << setw(9) << tesla.stopLoss << " | " << setw(11) << tesla.takeProfit << " | " << setw(8) << teslaShares << " |\n";
    cout << "| Amazon | " << setw(6) << amazon.precios[amazon.indice] << " | " << setw(9) << amazon.stopLoss << " | " << setw(11) << amazon.takeProfit << " | " << setw(8) << amazonShares << " |\n";
    cout << "===========================================\n\n";
}

void aplicarStopLossTakeProfit(Accion& accion, int& shares, double& balance) {
    double precioActual = accion.precios[accion.indice];
    if (precioActual <= accion.stopLoss && accion.stopLoss > 0) {
        balance += shares * accion.stopLoss; // Vender al precio de Stop Loss
        shares = 0;
        cout << "Se activó el Stop Loss para " << accion.nombre << ". Vendiendo todas las acciones.\n";
    }
    else if (precioActual >= accion.takeProfit && accion.takeProfit > 0) {
        balance += shares * accion.takeProfit; // Vender al precio de Take Profit
        shares = 0;
        cout << "Se activó el Take Profit para " << accion.nombre << ". Vendiendo todas las acciones.\n";
    }
}

void miniJuego() {
    srand(time(0));
    double balance = 1000;
    const double meta = 2000;

    Accion apple = { "Apple", {100, 120, 140, 160, 180}, 0, 1000, 0 };
    Accion tesla = { "Tesla", {300, 350, 400, 450, 500}, 0, 1000, 0 };
    Accion amazon = { "Amazon", {200, 250, 300, 350, 400}, 0, 1000, 0 };

    int appleShares = 0, teslaShares = 0, amazonShares = 0;

    int opcion;
    do {
        mostrarTabla(apple, tesla, amazon, appleShares, teslaShares, amazonShares, balance, meta);
        cout << "1. Comprar\n";
        cout << "2. Vender\n";
        cout << "3. Establecer Stop Loss / Take Profit\n";
        cout << "4. Esperar a que las acciones cambien\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: \n";
        cout << "------------------------------------------------\n";
        cout << "Recuerda que las acciones variaran de forma muy agresiva para jugar de una forma mas rapida y dinamica \n";
        cout << "----------------------------------------------------------------------------------------------------------\n";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "Comprar:\n";
            cout << "1. Apple\n";
            cout << "2. Tesla\n";
            cout << "3. Amazon\n";
            int compra;
            cout << "Seleccione la accion a comprar: ";
            cin >> compra;
            int cantidad;
            cout << "Ingrese la cantidad a comprar: ";
            cin >> cantidad;
            if (compra == 1 && balance >= cantidad * apple.precios[apple.indice]) {
                balance -= cantidad * apple.precios[apple.indice];
                appleShares += cantidad;
            }
            else if (compra == 2 && balance >= cantidad * tesla.precios[tesla.indice]) {
                balance -= cantidad * tesla.precios[tesla.indice];
                teslaShares += cantidad;
            }
            else if (compra == 3 && balance >= cantidad * amazon.precios[amazon.indice]) {
                balance -= cantidad * amazon.precios[amazon.indice];
                amazonShares += cantidad;
            }
            else {
                cout << "Fondos insuficientes o opcion invalida.\n";
            }
            borrarPantalla();
            break;
        }
        case 2: {
            cout << "Vender:\n";
            cout << "1. Apple\n";
            cout << "2. Tesla\n";
            cout << "3. Amazon\n";
            int venta;
            cout << "Seleccione la accion a vender: ";
            cin >> venta;
            int cantidad;
            cout << "Ingrese la cantidad a vender: ";
            cin >> cantidad;
            if (venta == 1 && appleShares >= cantidad) {
                balance += cantidad * apple.precios[apple.indice];
                appleShares -= cantidad;
            }
            else if (venta == 2 && teslaShares >= cantidad) {
                balance += cantidad * tesla.precios[tesla.indice];
                teslaShares -= cantidad;
            }
            else if (venta == 3 && amazonShares >= cantidad) {
                balance += cantidad * amazon.precios[amazon.indice];
                amazonShares -= cantidad;
            }
            else {
                cout << "Cantidad insuficiente o opcion invalida.\n";
            }
            borrarPantalla();
            break;
        }
        case 3: {
            cout << "Establecer Stop Loss / Take Profit:\n";
            cout << "1. Apple\n";
            cout << "2. Tesla\n";
            cout << "3. Amazon\n";
            int seleccion;
            cout << "Seleccione la acción: ";
            cin >> seleccion;
            double stopLoss, takeProfit;
            cout << "Ingrese el Stop Loss: ";
            cin >> stopLoss;
            cout << "Ingrese el Take Profit: ";
            cin >> takeProfit;
            if (seleccion == 1) {
                apple.stopLoss = stopLoss;
                apple.takeProfit = takeProfit;
            }
            else if (seleccion == 2) {
                tesla.stopLoss = stopLoss;
                tesla.takeProfit = takeProfit;
            }
            else if (seleccion == 3) {
                amazon.stopLoss = stopLoss;
                amazon.takeProfit = takeProfit;
            }
            else {
                cout << "Opcion invalida.\n";
            }
            borrarPantalla();
            break;
        }
        case 4: {
            cout << "Esperando a que las acciones cambien...\n";
            borrarPantalla();
            break;
        }
        case 5:
            cout << "Saliendo del juego.\n";
            break;
        default:
            cout << "Opcion invalida.\n";
            break;
        }


        if (opcion != 3) {
            actualizarPrecio(apple);
            actualizarPrecio(tesla);
            actualizarPrecio(amazon);
        }

        aplicarStopLossTakeProfit(apple, appleShares, balance);
        aplicarStopLossTakeProfit(tesla, teslaShares, balance);
        aplicarStopLossTakeProfit(amazon, amazonShares, balance);

        if (balance >= meta) {
            cout << "¡Felicidades! Has alcanzado la meta de " << meta << " soles.\n";
            opcion = 5;
        }
    } while (opcion != 5);
}



int menuPrincipal() {
    char opcion;
    bool preguntasTerminadas = false;

    mostrarTitulo();

    do {
        
        cout << "";
        //cin >> opcion;

        fflush(stdin);
        opcion = static_cast<char>(_getch());


        switch (opcion) {
        case '1':
            if (!preguntasTerminadas) {
                cout << "===========================================\n";
                cout << "|          INTRODUCCION AL TRADING        |\n";
                cout << "===========================================\n";
                cout << "Este programa le ensenara los conceptos basicos del trading y le permitira\n";
                cout << "practicar con un mini-juego.\n";
                cout << "===========================================\n\n";
                mostrarExplicacionesYPreguntas();
                preguntasTerminadas = true;
                cout << "Ya terminaste las preguntas, dirigete al mini-juego.\n";
            }
            else {
                cout << "Ya terminaste las preguntas, dirigete al mini-juego.\n";
            }
            mostrarTitulo();
            break;
        case '2':
            if (preguntasTerminadas) {
                miniJuego();
            }
            else {
                cout << "Debe completar las explicaciones y preguntas antes de acceder al mini-juego.\n";
            }
            mostrarTitulo();
            break;
        case '3':
            cout << "Iniciando Simulador...\r";
            return 1;
        case '0':
            cout << "\033[2J\033[1;1H\n\n\tGracias por usar el programa. Hasta luego!\n\n\n\n";
            return 0;
        default:
            cout << "\r\t\t\t\t\t\r";
            break;
        }
    } while (true);
}

void mostrarTitulo()
{
    cout << "==============================================================================================================================\n\n";
    cout << "\t   .o888o.                                                                                                   \n";
    cout << "\t dP^^^^^^Yb                                 o.                   88                              88           \n";
    cout << "\t{8           888                            `8                   88                              88           \n";
    cout << "\t 8o.          8                              8                   88                              88           \n";
    cout << "\t  `88o.       8  ooooooooooooooo. 8o     o8  8   .ooooo.   .oooo888  .ooooo.  oooood8b     .oooo888  .oooooo.  \n";
    cout << "\t    `88o.     8  88    `8o    `88 88     88  8   ^    `88 d8'   `88 d8'   `8b `88' `8P    d8'   `88 d99'  `88b\n";
    cout << "\t      `88o.   8  88     88     88 88     88  8   .oooo888 88     88 88     88  88         88     88 888oooo88P\n";
    cout << "\to       `88   8  88     88     88 88     88  8  8P'   `Y8 88     88 88     88  88         88     88 88'       \n";
    cout << "\t88o.   .o88  .8. 88     88     88 88.   .88 .8. 8b.   .d8 Y8.   .88 Y8.   .8P  88         Y8.   .88 Y8o.   .oo\n";
    cout << "\t `8888888P   888 89     89     89 `Y88888P' 888  `888888P  `888888P  `88888'  d88b         `888888P  `888888P \n\n\n";
    cout << "\t                              .oooooooo.              o.                                                     \n";
    cout << "\t                              88'    `88b             `8                                                     \n";
    cout << "\t                              88      88P              8                                                     \n";
    cout << "\t                              88.   .o8'    .oooooo.   8  .oooooo.  .ooooo.                                   \n";
    cout << "\t                              8888888888.  .8'    '8.  8  88.   `^  ^    `88                                   \n";
    cout << "\t                              88'      '8b 88      88  8  `88o.     .oooo888                                   \n";
    cout << "\t                              88        88 88      88  8    `88o.  8P'   `Y8                                   \n";
    cout << "\t                              88.      .8P `8.    .8' .8. o.  `88b 8b.   .d8                                   \n";
    cout << "\t                              `888888888'   `888888'  888 `888888P  `888888P                                   \n\n";
    cout << "=============================================================================================================================\n";
    cout << "\t\t\t\t\t     [1] Explicaciones y Preguntas\n";
    cout << "\t\t\t\t\t       [2] Mini Juego de Trading\n";
    cout << "\t\t\t\t\t        [3] Entrar al Simulador\n";
    cout << "\t\t\t\t\t              [0] Salir\n";
}