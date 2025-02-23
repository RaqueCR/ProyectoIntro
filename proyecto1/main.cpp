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
    setlocale(LC_ALL, "");//caracteres en español
    int opcion;

    //bucle
    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        //menu
        switch (opcion) {
            case 1:
                cout << "Opción 1: Registrar un Pokémon\n";
                break;
            case 2:
                cout << "Opción 2: Entrenar un Pokémon\n";
                break;
            case 3:
                cout << "Opción 3: Mostrar equipo Pokémon\n";
                break;
            case 4:
                cout << "Opción 4: Mostrar el Pokémon más fuerte\n";
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}

void mostrarMenu() {
    cout << "\n=============================\n";
    cout << "SISTEMA DE ENTRENAMIENTO POKÉMON\n";
    cout << "=============================\n";
    cout << "1. Registrar un Pokémon\n";
    cout << "2. Entrenar un Pokémon\n";
    cout << "3. Mostrar el equipo Pokémon\n";
    cout << "4. Mostrar el Pokémon más fuerte\n";
    cout << "5. Salir del programa\n";
    cout << "=============================\n";
}
