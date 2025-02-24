/****************************************************
 * Proyecto 1: Introducción a la Programación - 00831
 * Autor: Raquel Maria Fernandez Fernandez
 * Cedula: 208300391
 * Descripción: Programa que permite registrar, entrenar y mostrar
 * Pokemones usando estructuras, vectores y diversas validaciones.
 ****************************************************/

#include <iostream>
#include <vector>//para trabajar con vectores
#include <locale.h> //caracteres en español
#include <limits> //limpiar entrada

using namespace std;

//estructura pokemon
struct Pokemon {
    string nombre;
    int id;
    string tipo;
    int nivel_poder;
};

//vector para almacenar al equipo pokemon
vector<Pokemon> equipoPokemon;

//inicializacion
void mostrarMenu(); //prototipo para mostrar el menú principal
void registrarPokemon(); //prototipo de la función para registrar un Pokémon
void entrenarPokemon(); //prototipo de la función para entrenar un Pokémon
void mostrarEquipoPokemon(); //prototipo de la función para mostrar el equipo Pokémon
void mostrarPokemonMasFuerte(); //prototipo de la función para mostrar el Pokémon más fuerte
bool idExiste(int id); //prototipo de la función para validar ID existente
string obtenerTipoPokemon(int opcion); //prototipo para obtener el tipo de Pokémon
string obtenerTipoEntrenamiento(int opcion); //prototipo para obtener el tipo de entrenamiento
int obtenerEntero(string mensaje, int minimo, int maximo); //prototipo para validar entrada de enteros

int main() {
    setlocale(LC_ALL, ""); //caracteres en español, referencia: https://www.youtube.com/watch?v=yIoPQQA1j2Y&ab_channel=CertiJob
    int opcion;

    //bucle
    do {
        mostrarMenu();
        opcion = obtenerEntero("Seleccione una opción: ", 1, 5);

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
                mostrarPokemonMasFuerte(); //llamada a la función para mostrar el Pokémon más fuerte
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

//función para mostrar el menú principal
void mostrarMenu() {

    cout << "\n--------------------------------\n";
    cout << "SISTEMA DE ENTRENAMIENTO POKÉMON\n";
    cout << "--------------------------------\n";
    cout << "1. Registrar un Pokémon\n";
    cout << "2. Entrenar un Pokémon\n";
    cout << "3. Mostrar el equipo Pokémon\n";
    cout << "4. Mostrar el Pokémon más fuerte\n";
    cout << "5. Salir del programa\n";
    cout << "--------------------------------\n";
}

//función para verificar si el ID ya existe
bool idExiste(int id) {
    for (const auto& pokemon : equipoPokemon) {
        if (pokemon.id == id) {
            return true;
        }
    }
    return false;
}

//función para obtener el tipo de Pokémon
string obtenerTipoPokemon(int opcion) {
    switch (opcion) {
        case 1: return "Fuego";
        case 2: return "Agua";
        case 3: return "Planta";
        case 4: return "Eléctrico";
        default: return "Inválido";
    }
}

//función para obtener el tipo de entrenamiento
string obtenerTipoEntrenamiento(int opcion) {
    switch (opcion) {
        case 1: return "Combate en gimnasio";
        case 2: return "Batalla con otro entrenador";
        case 3: return "Práctica de habilidades";
        default: return "Inválido";
    }
}

//validación de entrada entera
int obtenerEntero(string mensaje, int minimo, int maximo) {
    int numero;

    while (true) {

        cout << mensaje;
        cin >> numero;

        if (cin.fail() || numero < minimo || numero > maximo) {
            cin.clear(); // limpiar estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar el buffer
            cout << "Entrada no válida. Intente de nuevo.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar el buffer
            return numero;
        }
    }
}

//función para registrar un Pokémon
void registrarPokemon() {
    Pokemon nuevoPokemon;
    int tipoOpcion;

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
        nuevoPokemon.id = obtenerEntero("Ingrese el número de identificación (6 dígitos): ", 100000, 999999);
        if (idExiste(nuevoPokemon.id)) {
            cout << "El ID ya existe. Intente con uno diferente.\n";
        }
    } while (idExiste(nuevoPokemon.id));

    //selección del tipo de Pokémon
    do {
        tipoOpcion = obtenerEntero("Seleccione el tipo de Pokémon:\n1. Fuego\n2. Agua\n3. Planta\n4. Eléctrico\nIngrese una opción válida: ", 1, 4);
        nuevoPokemon.tipo = obtenerTipoPokemon(tipoOpcion);
    } while (nuevoPokemon.tipo == "Inválido");

    //ingreso del nivel de poder inicial
    nuevoPokemon.nivel_poder = obtenerEntero("Ingrese el nivel de poder inicial (1-100): ", 1, 100);

    //agregar el Pokémon al vector
    equipoPokemon.push_back(nuevoPokemon);
    cout << "\n¡Pokémon registrado exitosamente!\n";
}

//función para entrenar un Pokémon
void entrenarPokemon() {
    int id, tipoEntrenamiento, dificultad;
    bool encontrado = false;

    //ingreso del ID
    id = obtenerEntero("Ingrese el ID del Pokémon a entrenar: ", 100000, 999999);

    //buscar el Pokémon por ID
    for (auto& pokemon : equipoPokemon) {
        if (pokemon.id == id) {
            encontrado = true;

            //selección del tipo de entrenamiento
            tipoEntrenamiento = obtenerEntero("Seleccione el tipo de entrenamiento:\n1. Combate en gimnasio\n2. Batalla con otro entrenador\n3. Práctica de habilidades\nIngrese una opción válida: ", 1, 3);

            //ingreso de la dificultad
            dificultad = obtenerEntero("Ingrese la dificultad del entrenamiento (1-100): ", 1, 100);

            //evaluación del entrenamiento
            if (pokemon.nivel_poder >= dificultad) {
                pokemon.nivel_poder += 10;
                cout << "\n¡Entrenamiento exitoso! " << pokemon.nombre << " ha ganado +10 puntos de poder.\n";
            } else {
                cout << "\nEntrenamiento fallido. " << pokemon.nombre << " necesita más práctica antes de intentarlo de nuevo.\n";
            }

            break;
        }
    }

    //mensaje si el ID no existe
    if (!encontrado) {
        cout << "No se encontró un Pokémon con el ID ingresado.\n";
    }
}


//función para mostrar el equipo Pokémon
void mostrarEquipoPokemon() {
    if (equipoPokemon.empty()) {

        cout << "No hay Pokémon registrados aún.\n";
    } else {

        cout << "\n-----------------------------\n";
        cout << "EQUIPO POKÉMON\n";
        cout << "-----------------------------\n";
        for (const auto& pokemon : equipoPokemon) {

            cout << "- Nombre: " << pokemon.nombre << "\n";
            cout << "  ID: " << pokemon.id << "\n";
            cout << "  Tipo: " << pokemon.tipo << "\n";
            cout << "  Nivel de Poder: " << pokemon.nivel_poder << "\n";
            cout << "-----------------------------\n";
        }
    }
}

//funcion que muestra el pokémon mas fuerte de los que hay registrados
void mostrarPokemonMasFuerte() {
    if (equipoPokemon.empty()) {

        cout << "No hay Pokémon registrados aún.\n";
    } else {
        Pokemon masFuerte = equipoPokemon[0];

        for (const auto& pokemon : equipoPokemon) {
            if (pokemon.nivel_poder > masFuerte.nivel_poder) {
                masFuerte = pokemon;
            }
        }

        cout << "\n---------------------------\n";
        cout << "POKÉMON MÁS FUERTE\n";
        cout << "---------------------------\n";
        cout << "Nombre: " << masFuerte.nombre << "\n";
        cout << "Tipo: " << masFuerte.tipo << "\n";
        cout << "Nivel de Poder: " << masFuerte.nivel_poder << "\n";
        cout << "--------------------------\n";
    }
}
