#include "user_name.h"
#include "Conexion.h"
#include<thread>
#include<conio.h>
#include "tabla.h"
#include "tabulate.hpp"
#include <mysql.h>
#include<string>
#include<windows.h>
using namespace std;
int verify_user()
{
	vector<Db_usuarios> base;
	
	string asciiArt = R"(
 
__/\\\___________________/\\\\\__________/\\\\\\\\\\\\__/\\\\\\\\\\\__/\\\\\_____/\\\_        
 _\/\\\_________________/\\\///\\\______/\\\//////////__\/////\\\///__\/\\\\\\___\/\\\_       
  _\/\\\_______________/\\\/__\///\\\___/\\\_________________\/\\\_____\/\\\/\\\__\/\\\_      
   _\/\\\______________/\\\______\//\\\_\/\\\____/\\\\\\\_____\/\\\_____\/\\\//\\\_\/\\\_     
    _\/\\\_____________\/\\\_______\/\\\_\/\\\___\/////\\\_____\/\\\_____\/\\\\//\\\\/\\\_    
     _\/\\\_____________\//\\\______/\\\__\/\\\_______\/\\\_____\/\\\_____\/\\\_\//\\\/\\\_   
      _\/\\\______________\///\\\__/\\\____\/\\\_______\/\\\_____\/\\\_____\/\\\__\//\\\\\\_  
       _\/\\\\\\\\\\\\\\\____\///\\\\\/_____\//\\\\\\\\\\\\/___/\\\\\\\\\\\_\/\\\___\//\\\\\_ 
        _\///////////////_______\/////________\////////////____\///////////__\///_____\/////__
                                                                                                                                              
)";
	
	string bienvenido = R"(

	$$$$$$$\  $$\                                                   $$\       $$\           
	$$  __$$\ \__|                                                  \__|      $$ |          
	$$ |  $$ |$$\  $$$$$$\  $$$$$$$\ $$\    $$\  $$$$$$\  $$$$$$$\  $$\  $$$$$$$ | $$$$$$\  
	$$$$$$$\ |$$ |$$  __$$\ $$  __$$\\$$\  $$  |$$  __$$\ $$  __$$\ $$ |$$  __$$ |$$  __$$\ 
	$$  __$$\ $$ |$$$$$$$$ |$$ |  $$ |\$$\$$  / $$$$$$$$ |$$ |  $$ |$$ |$$ /  $$ |$$ /  $$ |
	$$ |  $$ |$$ |$$   ____|$$ |  $$ | \$$$  /  $$   ____|$$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |
	$$$$$$$  |$$ |\$$$$$$$\ $$ |  $$ |  \$  /   \$$$$$$$\ $$ |  $$ |$$ |\$$$$$$$ |\$$$$$$  |
	\_______/ \__| \_______|\__|  \__|   \_/     \_______|\__|  \__|\__| \_______| \______/ 
                                                                                                                                                                                                                                                        
)";
	string punto = R"(
	 /$$
	|__/
)";

	obtener_usuarios(base);
	do
	{
		colorear(asciiArt);
		string usuario, contraseña; char ch;
		cout << "\n\t\t\tUSUARIO: "; getline(cin, usuario);
		cout << "\n\t\t\tCONTRASENA: "; 

		while ((ch = _getch()) != 13) { // 13 es el código ASCII para Enter
			if (ch != 8) { // 8 es el código ASCII para Backspace
				contraseña.push_back(ch);
				std::cout << '*'; // Mostrar '*' en lugar del caracter real
			}
			else if (!contraseña.empty()) {
				contraseña.pop_back();
				std::cout << "\b \b"; // Retroceder y borrar el último '*'
			}
		}


		for (int i = 0; i < 10; i++) {
			if (base[i].usuario == usuario && base[i].contraseña == contraseña) {
				int id_new = stoi(base[i].id);
				system("cls");
				//colorear(bienvenido);
				return id_new;
				break;
			}			
		}
		cout << endl<<"\nDatos incorrectos";
		this_thread::sleep_for(chrono::seconds(1));

		system("cls");
	} while (true);
			
}

static void colorear(string texto) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Establece el color a rojo brillante
	cout << texto;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); // Restaura el color original

}