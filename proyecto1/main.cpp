#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

struct Pokemon { //estructura pokemon
    string nombre;
    int id;
    string tipo;
    int nivel_poder;
};

vector<Pokemon> equipoPokemon; //vector para almacenar al equipo pokemon

void mostrarMenu();

int main() {
    setlocale(LC_ALL, "");//caracteres en espa�ol
    int opcion;

    //bucle
    do {
        mostrarMenu();
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        //menu
        switch (opcion) {
            case 1:
                cout << "Opci�n 1: Registrar un Pok�mon\n";
                break;
            case 2:
                cout << "Opci�n 2: Entrenar un Pok�mon\n";
                break;
            case 3:
                cout << "Opci�n 3: Mostrar equipo Pok�mon\n";
                break;
            case 4:
                cout << "Opci�n 4: Mostrar el Pok�mon m�s fuerte\n";
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opci�n no v�lida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}

void mostrarMenu() {
    cout << "\n=============================\n";
    cout << "SISTEMA DE ENTRENAMIENTO POK�MON\n";
    cout << "=============================\n";
    cout << "1. Registrar un Pok�mon\n";
    cout << "2. Entrenar un Pok�mon\n";
    cout << "3. Mostrar el equipo Pok�mon\n";
    cout << "4. Mostrar el Pok�mon m�s fuerte\n";
    cout << "5. Salir del programa\n";
    cout << "=============================\n";
}
