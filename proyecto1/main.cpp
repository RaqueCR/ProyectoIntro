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
void entrenarPokemon(); //prototipo de la función para entrenar un Pokémon
void mostrarEquipoPokemon(); //prototipo de la función para mostrar el equipo Pokémon
bool idExiste(int id); //prototipo de la función para validar ID existente
string obtenerTipoPokemon(int opcion); //prototipo para obtener el tipo de Pokémon
string obtenerTipoEntrenamiento(int opcion); //prototipo para obtener el tipo de entrenamiento

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
                entrenarPokemon(); //llamada a la función de entrenamiento
                break;
            case 3:
                mostrarEquipoPokemon(); //llamada a la función para mostrar el equipo
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

string obtenerTipoEntrenamiento(int opcion) { //función para obtener el tipo de entrenamiento
    switch (opcion) {
        case 1: return "Combate en gimnasio";
        case 2: return "Batalla con otro entrenador";
        case 3: return "Práctica de habilidades";
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

void entrenarPokemon() { //función para entrenar un Pokémon
    int id, tipoEntrenamiento, dificultad;
    bool encontrado = false;

    //ingreso del ID
    cout << "Ingrese el ID del Pokémon a entrenar: ";
    cin >> id;

    //buscar el Pokémon por ID
    for (auto& pokemon : equipoPokemon) {
        if (pokemon.id == id) {
            encontrado = true;

            //selección del tipo de entrenamiento
            do {
                cout << "Seleccione el tipo de entrenamiento:\n";
                cout << "1. Combate en gimnasio\n2. Batalla con otro entrenador\n3. Práctica de habilidades\n";
                cout << "Ingrese una opción válida: ";
                cin >> tipoEntrenamiento;
                if (obtenerTipoEntrenamiento(tipoEntrenamiento) == "Inválido") {
                    cout << "Opción inválida. Intente de nuevo.\n";
                }
            } while (obtenerTipoEntrenamiento(tipoEntrenamiento) == "Inválido");

            //ingreso de la dificultad
            do {
                cout << "Ingrese la dificultad del entrenamiento (1-100): ";
                cin >> dificultad;
                if (dificultad < 1 || dificultad > 100) {
                    cout << "La dificultad debe estar entre 1 y 100.\n";
                }
            } while (dificultad < 1 || dificultad > 100);

            //evaluación del entrenamiento
            if (pokemon.nivel_poder >= dificultad) {
                pokemon.nivel_poder += 10;
                cout << "¡Entrenamiento exitoso! " << pokemon.nombre << " ha ganado +10 puntos de poder.\n";
            } else {
                cout << "Entrenamiento fallido. " << pokemon.nombre << " necesita más práctica antes de intentarlo de nuevo.\n";
            }

            break; //salir del ciclo después de encontrar el Pokémon
        }
    }

    //mensaje si el ID no existe
    if (!encontrado) {
        cout << "No se encontró un Pokémon con el ID ingresado.\n";
    }
}

void mostrarEquipoPokemon() { //función para mostrar el equipo Pokémon
    if (equipoPokemon.empty()) {
        cout << "No hay Pokémon registrados aún.\n";
    } else {
        cout << "\n=========================\n";
        cout << "EQUIPO POKÉMON\n";
        cout << "=========================\n";
        for (const auto& pokemon : equipoPokemon) {
            cout << "- Nombre: " << pokemon.nombre << "\n";
            cout << "  ID: " << pokemon.id << "\n";
            cout << "  Tipo: " << pokemon.tipo << "\n";
            cout << "  Nivel de Poder: " << pokemon.nivel_poder << "\n";
            cout << "-------------------------\n";
        }
    }
}
