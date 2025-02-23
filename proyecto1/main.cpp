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
void registrarPokemon(); //prototipo de la función para registrar un Pokémon
bool idExiste(int id); //prototipo de la función para validar ID existente
string obtenerTipoPokemon(int opcion); //prototipo para obtener el tipo de Pokémon

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
                registrarPokemon(); //llamada a la función de registro
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

void mostrarMenu() { //función para mostrar el menú principal
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

bool idExiste(int id) { //función para verificar si el ID ya existe
    for (const auto& pokemon : equipoPokemon) {
        if (pokemon.id == id) {
            return true;
        }
    }
    return false;
}

string obtenerTipoPokemon(int opcion) { //función para obtener el tipo de Pokémon
    switch (opcion) {
        case 1: return "Fuego";
        case 2: return "Agua";
        case 3: return "Planta";
        case 4: return "Eléctrico";
        default: return "Inválido";
    }
}

void registrarPokemon() { //función para registrar un Pokémon
    Pokemon nuevoPokemon;
    int tipoOpcion;

    cin.ignore(); //limpiar

    //ingreso del nombre
    do {
        cout << "Ingrese el nombre del Pokémon: ";
        getline(cin, nuevoPokemon.nombre);
        if (nuevoPokemon.nombre.empty()) {
            cout << "El nombre no puede estar vacío. Intente de nuevo.\n";
        }
    } while (nuevoPokemon.nombre.empty());

    //ingreso del ID
    do {
        cout << "Ingrese el número de identificación (6 dígitos): ";
        cin >> nuevoPokemon.id;
        if (to_string(nuevoPokemon.id).length() != 6) {
            cout << "El ID debe tener exactamente 6 dígitos.\n";
        } else if (idExiste(nuevoPokemon.id)) {
            cout << "El ID ya existe. Intente con uno diferente.\n";
        }
    } while (to_string(nuevoPokemon.id).length() != 6 || idExiste(nuevoPokemon.id));

    //selección del tipo de Pokémon
    do {
        cout << "Seleccione el tipo de Pokémon:\n";
        cout << "1. Fuego\n2. Agua\n3. Planta\n4. Eléctrico\n";
        cout << "Ingrese una opción válida: ";
        cin >> tipoOpcion;
        nuevoPokemon.tipo = obtenerTipoPokemon(tipoOpcion);
        if (nuevoPokemon.tipo == "Inválido") {
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (nuevoPokemon.tipo == "Inválido");

    //ingreso del nivel de poder inicial
    do {
        cout << "Ingrese el nivel de poder inicial (1-100): ";
        cin >> nuevoPokemon.nivel_poder;
        if (nuevoPokemon.nivel_poder < 1 || nuevoPokemon.nivel_poder > 100) {
            cout << "El nivel de poder debe estar entre 1 y 100.\n";
        }
    } while (nuevoPokemon.nivel_poder < 1 || nuevoPokemon.nivel_poder > 100);

    //agregar el Pokémon al vector
    equipoPokemon.push_back(nuevoPokemon);
    cout << "¡Pokémon registrado exitosamente!\n";
}
