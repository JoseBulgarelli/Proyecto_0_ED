#include <iostream>
#include <stdexcept>
#include <string>
#include "PriorityQueue.h"
#include "HeapPriorityQueue.h"
#include "Pair.h"
#include "LinkedStack.h"
#include "List.h"
#include "LinkedList.h"
#include "Area.h"

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::runtime_error;
using std::string;
using std::to_string;
using std::stoi;

bool revisarOpcion(string opcion, int cantidadOpciones) {
    for (int i = 1; i <= cantidadOpciones; i++)
        if (opcion == to_string(i))
            return true;
    return false;
}

string sacaMete(List<string>* lista1, List<string>* lista2) {
    string s = lista1->remove();
    lista2->append(s);
    return s;
}

void sacaMeteVoid(List<string>* lista1, List<string>* lista2) {
    string s = lista1->remove();
    lista2->append(s);
}

void printUsuarios(LinkedList<string>* usuarios) {
    List<string>* temp = new LinkedList<string>();
    string nombre;
    int contador = usuarios->getSize();
    for (int i = 0; i < contador; i++) {
        nombre = sacaMete(usuarios, temp);
        cout << nombre << endl;
    }
    contador = temp->getSize();
    for (int i = 0; i < contador; i++)
        sacaMeteVoid(temp, usuarios);
    delete temp;
}

//template <typename E>
int main() {
    try {
        string opcionPrincipal = "0", opcionSecundaria = "0";
        List<string>* listaUsuarios = new LinkedList<string>();
        List<string>* codigoUsuarios = new LinkedList<string>();
        List<Area<string>()>* areas = new LinkedList<Area<string>()>();
        HeapPriorityQueue<string>* tiposUsuario = new HeapPriorityQueue<string>;
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
            while (!revisarOpcion(opcionPrincipal, 6)) {
                cout << "Escriba una opcion valida: ";
                getline(cin, opcionPrincipal);
            }
            // 1. Estado de colas
            // Mostrar areas existentes, cantidad de ventanillas en cada area y codigos de los tiquetes presentes en las diferentes colas
            // Cada ventanilla muestra el ultimo tiquete atendido
            if (opcionPrincipal == "1") {
                
            }

            // 2. Tiquetes
            if (opcionPrincipal == "2") {
                cout << "Escoja una opcion:" << endl;
                cout << "\t1. Seleccionar usuario y servicio." << endl;
                cout << "\t2. Regresar." << endl;
                cout << "Opcion: ";
                getline(cin, opcionSecundaria);
                while (!revisarOpcion(opcionSecundaria, 2)) {
                    cout << "Escriba una opcion valida: ";
                    getline(cin, opcionSecundaria);
                }

                // 1. Seleccionar tipo de cliente y servicio
                if (opcionSecundaria == "1") {
                
                }

                // 2. Regresar
                if (opcionSecundaria == "2") {
                    opcionPrincipal = "0";
                    opcionSecundaria = "0";
                }

            }

            // 3. Atender
            if (opcionPrincipal == "3") {
                
            }

            // 4. Administracion
            if (opcionPrincipal == "4") {
                cout << "Escoja una opcion:" << endl;
                cout << "\t1. Tipos de usuario." << endl;
                cout << "\t2. Areas";
                cout << "\t3. Servicios disponibles." << endl;
                cout << "\t4. Limpiar colas y estadisticas." << endl;
                cout << "\t5. Regresar." << endl;
                cout << "Opcion: ";
                getline(cin, opcionSecundaria);
                while (!revisarOpcion(opcionSecundaria, 5)) {
                    cout << "Escriba una opcion valida: ";
                    getline(cin, opcionSecundaria);
                }

                // 1. Tipos de usuario
                if (opcionSecundaria == "1") {
                    cout << "Escoja una opcion:" << endl;
                    cout << "\t1. Agregar." << endl;
                    cout << "\t2. Eliminar." << endl;
                    cout << "\t3. Regresar." << endl;
                    cout << "Opcion: ";
                    getline(cin, opcionSecundaria);
                    while (!revisarOpcion(opcionSecundaria, 3)) {
                        cout << "Escriba una opcion valida: ";
                        getline(cin, opcionSecundaria);
                    }

                    // 1. Agregar
                    if (opcionSecundaria == "1") {
                        string nuevoTipo;
                        string nuevaPrioridad;
                        cout << "Elija un nombre para el tipo de usuario:";
                        getline(cin, nuevoTipo);
                        cout << "Elija una prioridad para" << nuevoTipo;
                        getline(cin, nuevaPrioridad);
                        for (int i = 0; i < nuevaPrioridad.length() ; i++) {  // Aca revisa elemento por elemento que si sean numeros, sino hace q escribas la opcion de nuevo
                            if (!isdigit(nuevaPrioridad[i])) {
                                i = 0;
                                cout << "Escriba una prioridad valida: ";
                                getline(cin, nuevaPrioridad);
                            }
                        }
                        tiposUsuario->insert(nuevoTipo, stoi(nuevaPrioridad)); // Se inserta el nuevo tipo de usuario con el nombre y prioridad que elija el usuario
                        listaUsuarios->insert(nuevoTipo);
                    }
                    
                    // 2. Eliminar
                    if (opcionSecundaria == "2") {  // La lista de tipos esta ordenada por orden de entrada entonces el usuario te va a dar ese numerito, luego del numerito vez el nomble porque en la otra si esta ordenado bien, y ese nombre lo buscas UNO POR UNO en el heap y lo borras
                        int indiceBorrar = 0;
                        for (int i = 0; i < listaUsuarios->getSize(); i++) {
                            cout << i << ". " << listaUsuarios->trueGetElement(i) << endl;
                        }
                        cout << "Elija una opcion a eliminar: ";
                        getline(cin, opcionSecundaria);
                        while (indiceBorrar <= 0 || indiceBorrar > listaUsuarios->getSize()) {
                            for (int i = 0 ; i < opcionSecundaria.length() ; i++) {
                                if (!isdigit(opcionSecundaria[i])) {
                                    i = 0;
                                    cout << "Escriba una opcion valida: ";
                                    getline(cin, opcionSecundaria);
                                }
                            }
                            indiceBorrar = stoi(opcionSecundaria);
                            if (indiceBorrar > listaUsuarios->getSize() || indiceBorrar <= 0) {
                                cout << "Escriba una opcion valida: ";
                                getline(cin, opcionSecundaria);
                            }
                        }
                        // Aca el borrar action como tal
                    }

                    // 3. Regresar
                    if (opcionSecundaria == "3") {

                    }
                }

                // 2. Areas
                if (opcionSecundaria == "2") {
                    cout << "Escoja una opcion:" << endl;
                    cout << "\t1. Agregar." << endl;
                    cout << "\t2. Modificar cantidad de ventanillas." << endl;
                    cout << "\t3. Eliminar." << endl;
                    cout << "\t4. Regresar." << endl;
                    cout << "Opcion: ";
                    getline(cin, opcionSecundaria);
                    while (!revisarOpcion(opcionSecundaria, 4)) {
                        cout << "Escriba una opcion valida: ";
                        getline(cin, opcionSecundaria);
                    }

                    // 1. Agregar
                    if (opcionSecundaria == "1") {

                    }

                    // 2. Modificar cantidad de ventanillas
                    if (opcionSecundaria == "2") {

                    }

                    // 3. Eliminar
                    if (opcionSecundaria == "3") {

                    }

                    // 4. Regresar
                    if (opcionSecundaria == "4") {

                    }
                }
                
                // 3. Servicios disponibles
                if (opcionSecundaria == "3") {
                    cout << "Escoja una opcion:" << endl;
                    cout << "\t1. Agregar." << endl;
                    cout << "\t2. Eliminar." << endl;
                    cout << "\t3. Reordenar." << endl;
                    cout << "\t4. Regresar." << endl;
                    cout << "Opcion: ";
                    getline(cin, opcionSecundaria);
                    while (!revisarOpcion(opcionSecundaria, 4)) {
                        cout << "Escriba una opcion valida: ";
                        getline(cin, opcionSecundaria);
                    }

                    // 1. Agregar
                    if (opcionSecundaria == "1") {

                    }

                    // 2. Eliminar
                    if (opcionSecundaria == "2") {

                    }

                    // 3. Reordenar
                    if (opcionSecundaria == "3") {

                    }

                    // 4. Regresar
                    if (opcionSecundaria == "4") {

                    }
                }

                // 4. Limpiar colas y estadisticas
                if (opcionSecundaria == "4") {

                }

                // 5. Regresar
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

// We are so fucking cooked