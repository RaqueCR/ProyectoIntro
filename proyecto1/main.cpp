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
void registrarPokemon(); //prototipo de la funci�n para registrar un Pok�mon
bool idExiste(int id); //prototipo de la funci�n para validar ID existente
string obtenerTipoPokemon(int opcion); //prototipo para obtener el tipo de Pok�mon

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
                registrarPokemon(); //llamada a la funci�n de registro
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

void registrarPokemon() { //funci�n para registrar un Pok�mon
    Pokemon nuevoPokemon;
    int tipoOpcion;

    cin.ignore(); //limpiar

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
        cout << "Ingrese el n�mero de identificaci�n (6 d�gitos): ";
        cin >> nuevoPokemon.id;
        if (to_string(nuevoPokemon.id).length() != 6) {
            cout << "El ID debe tener exactamente 6 d�gitos.\n";
        } else if (idExiste(nuevoPokemon.id)) {
            cout << "El ID ya existe. Intente con uno diferente.\n";
        }
    } while (to_string(nuevoPokemon.id).length() != 6 || idExiste(nuevoPokemon.id));

    //selecci�n del tipo de Pok�mon
    do {
        cout << "Seleccione el tipo de Pok�mon:\n";
        cout << "1. Fuego\n2. Agua\n3. Planta\n4. El�ctrico\n";
        cout << "Ingrese una opci�n v�lida: ";
        cin >> tipoOpcion;
        nuevoPokemon.tipo = obtenerTipoPokemon(tipoOpcion);
        if (nuevoPokemon.tipo == "Inv�lido") {
            cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (nuevoPokemon.tipo == "Inv�lido");

    //ingreso del nivel de poder inicial
    do {
        cout << "Ingrese el nivel de poder inicial (1-100): ";
        cin >> nuevoPokemon.nivel_poder;
        if (nuevoPokemon.nivel_poder < 1 || nuevoPokemon.nivel_poder > 100) {
            cout << "El nivel de poder debe estar entre 1 y 100.\n";
        }
    } while (nuevoPokemon.nivel_poder < 1 || nuevoPokemon.nivel_poder > 100);

    //agregar el Pok�mon al vector
    equipoPokemon.push_back(nuevoPokemon);
    cout << "�Pok�mon registrado exitosamente!\n";
}
