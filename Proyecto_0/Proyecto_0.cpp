#include <iostream>
#include <stdexcept>
#include <string>
#include "PriorityQueue.h"
#include "HeapPriorityQueue.h"
#include "Pair.h"
#include "LinkedStack.h"

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::runtime_error;
using std::string;
using std::to_string;

bool revisarOpcionPrincipal(string opcion) {
    return opcion == "1" || opcion == "2" || opcion == "3" || opcion == "4" || 
    opcion == "5" || opcion == "6";
}

bool revisarOpcionSecundaria(string opcion, int cantidadOpciones) {
    for (int i = 1; i <= cantidadOpciones; i++)
        if (opcion == to_string(i))
            return true;
    return false;
}

string sacaMete(LinkedStack<string>& lista1, LinkedStack<string>& lista2) {
    string s = lista1.pop();
    lista2.push(s);
    return s;
}

void sacaMeteVoid(LinkedStack<string>& lista1, LinkedStack<string>& lista2) {
    string s = lista1.pop();
    lista2.push(s);
}

void printUsuarios(LinkedStack<string>& usuarios) {
    LinkedStack<string> temp;
    string nombre;
    int contador = usuarios.getSize();
    for (int i = 0; i < contador; i++) {
        nombre = sacaMete(usuarios, temp);
        cout << nombre << endl;
    }
    contador = temp.getSize();
    for (int i = 0; i < contador; i++)
        sacaMeteVoid(temp, usuarios);
}

int main() {
    try {
        string opcionPrincipal = "0", opcionSecundaria = "0";
        PriorityQueue<string>* usuarios = new HeapPriorityQueue<string>();
        LinkedStack<string> listaUsuarios;
        // Elegir una opcion:
        while (opcionPrincipal != "6") {
            cout << "Escoja una opcion:" << endl;
            cout << "\t1. Ver estado de las colas." << endl;
            cout << "\t2. Crear tiquete." << endl;
            cout << "\t3. Atender tiquete." << endl;
            cout << "\t4. Administracion." << endl;
            cout << "\t5. Estadisticas del sistema." << endl;
            cout << "\t6. Salir del sistema." << endl;
            cout << "Opcion: ";
            getline(cin, opcionPrincipal);
            while (!revisarOpcionPrincipal(opcionPrincipal)) {
                cout << "Escriba una opcion valida: ";
                getline(cin, opcionPrincipal);
            }
            // 1. Estado de colas
            // Mostrar areas existentes, cantidad de ventanillas en cada area y codigos de los tiquetes presentes en las diferentes colas
            // Cada ventanilla muestra el ultimo tiquete atendido
            if (opcionPrincipal == "1") {

            }

            // 2. Tiquetes
                // 1. Seleccionar tipo de cliente y servicio
                // 2. Regresar
            if (opcionPrincipal == "2") {
                cout << "Escoja una opcion:" << endl;
                cout << "\t1. Seleccionar usuario y servicio." << endl;
                cout << "\t2. Regresar." << endl;
                cout << "Opcion: ";
                getline(cin, opcionSecundaria);
                while (!revisarOpcionSecundaria(opcionSecundaria, 2)) {
                    cout << "Escriba una opcion valida: ";
                    getline(cin, opcionSecundaria);
                }
            }

            // 3. Atender
            if (opcionPrincipal == "3") {
                
            }

            // 4. Administracion
                // 1. Tipos de usuario
                    // 1. Agregar

                    // 2. Eliminar
                    
                    // 3. Regresar
                    
                // 2. Areas
                    // 1. Agregar

                    // 2. Modificar cantidad de ventanillas

                    // 3. Eliminar

                    // 4. Regresar

                // 3. Servicios disponibles
                    // 1. Agregar

                    // 2. Eliminar

                    // 3. Reordenar

                    // 4. Regresar

                // 4. Limpiar colas y estadisticas

                // 5. Regresar
            if (opcionPrincipal == "4") {
                cout << "Escoja una opcion:" << endl;
                cout << "\t1. Tipos de usuario." << endl;
                cout << "\t2. Areas";
                cout << "\t3. Servicios disponibles." << endl;
                cout << "\t4. Limpiar colas y estadisticas." << endl;
                cout << "\t5. Regresar." << endl;
                cout << "Opcion: ";
                getline(cin, opcionSecundaria);
                while (!revisarOpcionSecundaria(opcionSecundaria, 5)) {
                    cout << "Escriba una opcion valida: ";
                    getline(cin, opcionSecundaria);
                }

                if (opcionSecundaria == "1") {
                    cout << "Escoja una opcion:" << endl;
                    cout << "\t1. Agregar." << endl;
                    cout << "\t2. Eliminar." << endl;
                    cout << "\t3. Regresar." << endl;
                    cout << "Opcion: ";
                    getline(cin, opcionSecundaria);
                    while (!revisarOpcionSecundaria(opcionSecundaria, 3)) {
                        cout << "Escriba una opcion valida: ";
                        getline(cin, opcionSecundaria);
                    }
                }
                if (opcionSecundaria == "2") {
                    cout << "Escoja una opcion:" << endl;
                    cout << "\t1. Agregar." << endl;
                    cout << "\t2. Modificar cantidad de ventanillas." << endl;
                    cout << "\t3. Eliminar." << endl;
                    cout << "\t4. Regresar." << endl;
                    cout << "Opcion: ";
                    getline(cin, opcionSecundaria);
                    while (!revisarOpcionSecundaria(opcionSecundaria, 4)) {
                        cout << "Escriba una opcion valida: ";
                        getline(cin, opcionSecundaria);
                    }
                }
                if (opcionSecundaria == "3") {
                    cout << "Escoja una opcion:" << endl;
                    cout << "\t1. Agregar." << endl;
                    cout << "\t2. Eliminar." << endl;
                    cout << "\t3. Reordenar." << endl;
                    cout << "\t4. Regresar." << endl;
                    cout << "Opcion: ";
                    getline(cin, opcionSecundaria);
                    while (!revisarOpcionSecundaria(opcionSecundaria, 4)) {
                        cout << "Escriba una opcion valida: ";
                        getline(cin, opcionSecundaria);
                    }
                }
                if (opcionSecundaria == "4") {

                }
                if (opcionSecundaria == "5") {

                }
            }

            // 5. Estadisticas del sistema
            if (opcionPrincipal == "5") {
                
            }
            // 6. Salir
            if (opcionPrincipal == "6") {
                break;
            }
        }
    }
    catch (const runtime_error& e) {
	    cout << e.what() << endl;
    }
};



// Me voy a volar la cabeza
//Confirmo