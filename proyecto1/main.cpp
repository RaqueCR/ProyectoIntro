#include <iostream>
#include <vector>
#include <locale.h> //caracteres sin problemas en espa�ol
#include <limits> //limpiar entrada

using namespace std;

struct Pokemon { //estructura pokemon
    string nombre;
    int id;
    string tipo;
    int nivel_poder;
};

vector<Pokemon> equipoPokemon; //vector para almacenar al equipo pokemon

void mostrarMenu();
void registrarPokemon(); //prototipo de la funci�n para registrar un Pok�mon
void entrenarPokemon(); //prototipo de la funci�n para entrenar un Pok�mon
void mostrarEquipoPokemon(); //prototipo de la funci�n para mostrar el equipo Pok�mon
void mostrarPokemonMasFuerte(); //prototipo de la funci�n para mostrar el Pok�mon m�s fuerte
bool idExiste(int id); //prototipo de la funci�n para validar ID existente
string obtenerTipoPokemon(int opcion); //prototipo para obtener el tipo de Pok�mon
string obtenerTipoEntrenamiento(int opcion); //prototipo para obtener el tipo de entrenamiento
int obtenerEntero(string mensaje, int minimo, int maximo); //prototipo para validar entrada de enteros

int main() {
    setlocale(LC_ALL, "");//caracteres en espa�ol
    int opcion;

    //bucle
    do {
        mostrarMenu();
        opcion = obtenerEntero("Seleccione una opci�n: ", 1, 5);

        //menu
        switch (opcion) {
            case 1:
                registrarPokemon(); //llamada a la funci�n de registro
                break;
            case 2:
                entrenarPokemon(); //llamada a la funci�n de entrenamiento
                break;
            case 3:
                mostrarEquipoPokemon(); //llamada a la funci�n para mostrar el equipo
                break;
            case 4:
                mostrarPokemonMasFuerte(); //llamada a la funci�n para mostrar el Pok�mon m�s fuerte
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

void mostrarMenu() { //funci�n para mostrar el men� principal
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

bool idExiste(int id) { //funci�n para verificar si el ID ya existe
    for (const auto& pokemon : equipoPokemon) {
        if (pokemon.id == id) {
            return true;
        }
    }
    return false;
}

string obtenerTipoPokemon(int opcion) { //funci�n para obtener el tipo de Pok�mon
    switch (opcion) {
        case 1: return "Fuego";
        case 2: return "Agua";
        case 3: return "Planta";
        case 4: return "El�ctrico";
        default: return "Inv�lido";
    }
}

string obtenerTipoEntrenamiento(int opcion) { //funci�n para obtener el tipo de entrenamiento
    switch (opcion) {
        case 1: return "Combate en gimnasio";
        case 2: return "Batalla con otro entrenador";
        case 3: return "Pr�ctica de habilidades";
        default: return "Inv�lido";
    }
}

int obtenerEntero(string mensaje, int minimo, int maximo) { // Validaci�n de entrada entera
    int numero;
    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail() || numero < minimo || numero > maximo) {
            cin.clear(); // limpiar estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar el buffer
            cout << "Entrada no v�lida. Intente de nuevo.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar el buffer
            return numero;
        }
    }
}

void registrarPokemon() { //funci�n para registrar un Pok�mon
    Pokemon nuevoPokemon;
    int tipoOpcion;

    //ingreso del nombre
    do {
        cout << "Ingrese el nombre del Pok�mon: ";
        getline(cin, nuevoPokemon.nombre);
        if (nuevoPokemon.nombre.empty()) {
            cout << "El nombre no puede estar vac�o. Intente de nuevo.\n";
        }
    } while (nuevoPokemon.nombre.empty());

    //ingreso del ID
    do {
        nuevoPokemon.id = obtenerEntero("Ingrese el n�mero de identificaci�n (6 d�gitos): ", 100000, 999999);
        if (idExiste(nuevoPokemon.id)) {
            cout << "El ID ya existe. Intente con uno diferente.\n";
        }
    } while (idExiste(nuevoPokemon.id));

    //selecci�n del tipo de Pok�mon
    do {
        tipoOpcion = obtenerEntero("Seleccione el tipo de Pok�mon:\n1. Fuego\n2. Agua\n3. Planta\n4. El�ctrico\nIngrese una opci�n v�lida: ", 1, 4);
        nuevoPokemon.tipo = obtenerTipoPokemon(tipoOpcion);
    } while (nuevoPokemon.tipo == "Inv�lido");

    //ingreso del nivel de poder inicial
    nuevoPokemon.nivel_poder = obtenerEntero("Ingrese el nivel de poder inicial (1-100): ", 1, 100);

    //agregar el Pok�mon al vector
    equipoPokemon.push_back(nuevoPokemon);
    cout << "�Pok�mon registrado exitosamente!\n";
}

void entrenarPokemon() { //funci�n para entrenar un Pok�mon
    int id, tipoEntrenamiento, dificultad;
    bool encontrado = false;

    //ingreso del ID
    id = obtenerEntero("Ingrese el ID del Pok�mon a entrenar: ", 100000, 999999);

    //buscar el Pok�mon por ID
    for (auto& pokemon : equipoPokemon) {
        if (pokemon.id == id) {
            encontrado = true;

            //selecci�n del tipo de entrenamiento
            tipoEntrenamiento = obtenerEntero("Seleccione el tipo de entrenamiento:\n1. Combate en gimnasio\n2. Batalla con otro entrenador\n3. Pr�ctica de habilidades\nIngrese una opci�n v�lida: ", 1, 3);

            //ingreso de la dificultad
            dificultad = obtenerEntero("Ingrese la dificultad del entrenamiento (1-100): ", 1, 100);

            //evaluaci�n del entrenamiento
            if (pokemon.nivel_poder >= dificultad) {
                pokemon.nivel_poder += 10;
                cout << "�Entrenamiento exitoso! " << pokemon.nombre << " ha ganado +10 puntos de poder.\n";
            } else {
                cout << "Entrenamiento fallido. " << pokemon.nombre << " necesita m�s pr�ctica antes de intentarlo de nuevo.\n";
            }

            break;
        }
    }

    //mensaje si el ID no existe
    if (!encontrado) {
        cout << "No se encontr� un Pok�mon con el ID ingresado.\n";
    }
}

void mostrarEquipoPokemon() { //funci�n para mostrar el equipo Pok�mon
    if (equipoPokemon.empty()) {
        cout << "No hay Pok�mon registrados a�n.\n";
    } else {
        cout << "\n=========================\n";
        cout << "EQUIPO POK�MON\n";
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

void mostrarPokemonMasFuerte() { //funcion que muestra el pok�mon mas fuerte de los que hay registrados
    if (equipoPokemon.empty()) {
        cout << "No hay Pok�mon registrados a�n.\n";
    } else {
        Pokemon masFuerte = equipoPokemon[0];

        for (const auto& pokemon : equipoPokemon) {
            if (pokemon.nivel_poder > masFuerte.nivel_poder) {
                masFuerte = pokemon;
            }
        }

        cout << "\n=========================\n";
        cout << "POK�MON M�S FUERTE\n";
        cout << "=========================\n";
        cout << "Nombre: " << masFuerte.nombre << "\n";
        cout << "Tipo: " << masFuerte.tipo << "\n";
        cout << "Nivel de Poder: " << masFuerte.nivel_poder << "\n";
        cout << "=========================\n";
    }
}
