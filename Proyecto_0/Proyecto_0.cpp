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
#include "Servicio.h"
#include "Usuario.h"
#include "Ventanilla.h"

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

int comprobarIndice(string eleccion, int cantidadOpciones) {  // Repeti esto dos veces entonces, wabam, funcion
    int indice = 0;                                           // Revisa que una entrada 1. Sean numeros y 2. Este en el rango de  opciones aceptadas
    while (indice <= 0 || indice > cantidadOpciones) {
        for (int i = 0; i < eleccion.length(); i++) {
            if (!isdigit(eleccion[i])) { 
                i = -1;
                cout << "Escriba una opcion valida: ";
                getline(cin, eleccion);
            }
        }
        indice = stoi(eleccion);
        if (indice > cantidadOpciones || indice <= 0) {
            cout << "Escriba una opcion valida: ";
            getline(cin, eleccion);
        }
    }
    return indice-1;
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

template <typename E>
int main() {
    try {
        string opcionPrincipal = "0", opcionSecundaria = "0";
        List<Usuario>* listaUsuarios = new LinkedList<Usuario>();
        List<string>* codigoUsuarios = new LinkedList<string>();
        List<E>* areas = new LinkedList<E>();
        HeapPriorityQueue<string>* tiposUsuario = new HeapPriorityQueue<string>;
        List<E>* servicios = new LinkedList<E>();
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
                cout << "Areas existentes:" << endl;
                areas->goToStart();
                for (int i = 0; i < areas->getSize(); i++) {
                    Area a = areas->getElement();
                    cout << "\t" << a << endl;
                    cout << "\tVentanillas del area y sus ultimos atendidos:" << endl;
                    a.ventanillas->goToStart();
                    for (int j = 0; j < a.ventanillas->getSize(); j++) {
                        Ventanilla v = a.ventanillas->getElement();
                        cout << "\t\t" << v << ": ";
                        if (v.ultimoAtendido != "N")
                            cout << v.ultimoAtendido << "." << endl;
                        else
                            cout << "No hay un ultimo atendido.";
                    }
                }
            }

            // 2. Tiquetes
            if (opcionPrincipal == "2") {
                opcionSecundaria = "1";
                while (opcionSecundaria == "1") {
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
                        string usuarioTiquete, servicioTiquete;
                        bool existeUsuario = false;
                        bool existeServicio = false;
                        cout << "Escriba el tipo de usuario: ";
                        getline(cin, usuarioTiquete);
                        listaUsuarios->goToStart();
                        for (int i = 0; i < listaUsuarios->getSize(); i++) {
                            if (usuarioTiquete == listaUsuarios->getElement().getDescripcion()) {
                                existeUsuario = true;
                                break;
                            }
                            listaUsuarios->next();
                        }
                        if (existeUsuario) {
                            cout << "Escoja el servicio: ";
                            getline(cin, servicioTiquete);
                            servicios->goToStart();
                            for (int i = 0; i < servicios->getSize(); i++) {
                                if (servicioTiquete == servicios->getElement()) {
                                    existeServicio = true;
                                    break;
                                }
                                listaUsuarios->next();
                            }
                            if (existeServicio) {
                                Area actual = servicios->getElement().area;
                                Area objetivo;
                                areas->goToStart();
                                for (int i = 0; i < areas->getSize(); i++) {
                                    if (areas->getElement() == actual) {
                                        objetivo = areas->getElement();
                                        break;
                                    }
                                }
                            }
                            else
                                cout << "El servicio no existe." << endl;
                        }
                        else
                            cout << "El usuario no existe." << endl;
                    }
                }

                    // 2. Regresar
                

            }

            // 3. Atender
            if (opcionPrincipal == "3") {
                string areaAtender, ventanillaAtender;
                int posicionArea;
                cout << "Escoja el area a atender: ";
                getline(cin, areaAtender);
                bool areaExiste = false;
                areas->goToStart();
                for (int i = 0; i < areas->getSize(); i++) {
                    if (areas->getElement().getDescripcion() == areaAtender) {
                        areaExiste = true;
                        posicionArea = i;
                        break;
                    }
                    areas->next();
                }
                if (areaExiste && areas->getElement().getCantidadVentanillas() == 0)
                    cout << "No hay ventanillas en esta area." << endl;
                else if (areaExiste && areas->getElement().tiquetes.getSize() == 0)
                    cout << "No hay tiquetes en esta area." << endl;
                else if (areaExiste) {
                    Area<string> areaActual = areas->getElement();
                    cout << "Escoja la ventanilla a atender:" << endl;
                    areaActual.mostrarVentanillas();
                    getline(cin, ventanillaAtender);
                    if (!areaActual.ventanillaExiste(ventanillaAtender))
                        cout << "La ventanilla no existe." << endl;
                    else {
                        //Atiende el tiquete quitandolo del heap al que pertenece.
                        int posicionVentanilla = areaActual.posicionVentanilla();
                        areaActual.ventanillas.trueGetElement(posicionVentanilla).agregarAtendido();
                        areaActual.atenderTiquete();
                    }
                }
                else {
                    cout << "El area no existe." << endl;
                }
            }
            
            // 4. Administracion
            while (opcionPrincipal == "4") {
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
                while (opcionSecundaria == "1") {
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
                        int indiceBorrar = 0;       // Big brain time
                        for (int i = 0; i < listaUsuarios->getSize(); i++) {
                            cout << i << ". " << listaUsuarios->trueGetElement(i).getDescripcion() << endl;
                        }
                        cout << "Elija una opcion a eliminar: ";
                        getline(cin, opcionSecundaria);
                        indiceBorrar = comprobarIndice(opcionSecundaria, listaUsuarios->getSize());
                        string hayQueBorrar = listaUsuarios->trueRemove(indiceBorrar);  // Eso ya no puede ser un string si tipo de usuario se hace su propia clase
                        string buscandoANemo = "Es imposible que pongas un tipo de usuario que sea ASI de forma que NUNCA va a fallar esto, osea tiene quwe hitear todos los caracteres INCLUSO los typos, mira pongo cosas aleatorias para que de FIJO no lo pegues, SJKHSFUISGFYUIHWJFASHGFJHSAVDIBJFKHAHOIFW, wabam";
                        for (int i = 0; buscandoANemo != hayQueBorrar; i++) {
                            if (tiposUsuario->getElement(i) == hayQueBorrar) {
                                buscandoANemo = tiposUsuario->remove(i);
                            }
                        }
                    }

                    // 3. Regresar
                    if (opcionSecundaria == "3") {
                        opcionSecundaria = "0";
                    }

                    else
                        opcionSecundaria = "1";
                }

                // 2. Areas
                while (opcionSecundaria == "2") {
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
                    if (opcionSecundaria == "1") {  // El area debe tener descripcion, codigo y cantidad de ventanillas
                        string newAreaDesc;
                        string newAreaCode;
                        string newAreaWindCount; // Asi bien gringo
                        cout << "Nombre del area: ";
                        getline(cin, newAreaDesc);
                        cout << "Cantidad de ventanillas en el area: ";
                        getline(cin, newAreaWindCount);
                        for (int i = 0; i < newAreaWindCount.length() ; i++) {
                            if (!isdigit(newAreaWindCount[i])) {
                                i = 0;
                                cout << "Escriba una cantidad valida: ";
                                getline(cin, newAreaWindCount);
                            }
                        }
                        string newAreaCode = newAreaDesc[0]; //bleh
                        areas->insert(Area<E>(newAreaDesc, newAreaCode, stoi(newAreaWindCount)));
                    }

                    // 2. Modificar cantidad de ventanillas
                    if (opcionSecundaria == "2") {
                        int indiceEleccion; // A falta de mejores nombres
                        string areaNewWindCount;
                        for (int i = 0; i < areas->getSize(); i++) {
                            cout << "\t" << i+1 << ". " << areas->trueGetElement(i).descripcion << endl;
                        }
                        cout << "Elija el area a modificar: ";
                        getline(cin, opcionSecundaria);
                        indiceEleccion = comprobarIndice(opcionSecundaria, areas->getSize());
                        cout << "Cantidad de ventanillas en " << areas->trueGetElement(indiceEleccion).descripcion << ": " << areas->trueGetElement(indiceEleccion).ventanillas << endl;
                        cout << "Cantidad nueva de ventanillas: ";
                        getline(cin, opcionSecundaria);
                        for (int i = 0; i < opcionSecundaria.length(); i++) {
                            if (!isdigit(opcionSecundaria[i])) {
                                i = -1;
                                cout << "Escriba una opcion valida: ";
                                getline(cin, opcionSecundaria);
                            }
                        }
                        areas->trueGetElement(indiceEleccion).cambiarCantidadVentanillas(stoi(opcionSecundaria));
                        opcionSecundaria = "2";
                    }

                    // 3. Eliminar
                    if (opcionSecundaria == "3") {
                        for (int i = 0; i < areas->getSize(); i++) {
                            cout << "\t" << i+1 << ". " << areas->trueGetElement(i).descripcion << endl;
                        }
                        cout << "Elija el area a eliminar: ";
                        getline(cin, opcionSecundaria);
                        int indiceBorrar = comprobarIndice(opcionSecundaria, areas->getSize());
                        areas->trueRemove(indiceBorrar);
                    }

                    // 4. Regresar
                    if (opcionSecundaria == "4") {
                        opcionSecundaria = "0";
                    }
                    
                    else
                        opcionSecundaria = "2";

                }
                
                // 3. Servicios disponibles
                while (opcionSecundaria == "3") {
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
                        string newSerDesc;
                        Area newSerArea;                // Ser = Servicio
                        cout << "Elija un nombre para el servicio: ";
                        getline(cin, newSerDesc);
                        for (int i = 0; i < areas->getSize(); i++) {
                            cout << "\t" << i+1 << ". " << areas->trueGetElement(i).descripcion << endl;
                        }
                        cout << "Elija a que area pertenece el servicio: ";
                        getline(cin, opcionSecundaria);
                        opcionSecundaria = comprobarIndice(opcionSecundaria, areas->getSize());
                        newSerArea = areas->trueGetElement(opcionSecundaria);
                        cout << "Elija la prioridad de " << newSerDesc << ": ";
                        getline(cin, opcionSecundaria);
                        for (int i = 0; i < opcionSecundaria.length(); i++) {
                            if (!isdigit(opcionSecundaria[i])) {
                                i = -1;
                                cout << "Escriba una opcion valida: ";
                                getline(cin, opcionSecundaria);
                            }
                        }
                        servicios->insert(Servicio(newSerDesc, stoi(opcionSecundaria), newSerArea));
                        newSerArea->servicios->insert(servicios->trueGetElement(servicios->getSize()-1)); // Ojito, podria echar error por (bullshit motivo)
                    }

                    // 2. Eliminar
                    if (opcionSecundaria == "2") {  // Hay q quitar el servicio de la lista de servicios y del area donde esta
                        for (int i = 0; i < servicios->getSize(); i++) {
                            cout << "\t" << i+1 << ". " << servicios->trueGetElement(i).descripcion << endl;
                        }
                        cout << "Elija el servicio a eliminar";
                        int indiceBorrar = comprobarIndice(opcionSecundaria, servicios->getSize());
                        Servicio serBorrar = servicios->trueRemove(indiceBorrar);
                        Servicio buscandoANemo;
                        for (int i = 0; buscandoANemo != serBorrar; i++) {
                            if (areas->servicios->getElement(i) == serBorrar) {
                                buscandoANemo = areas->servicios->remove(i);
                            }
                        }
                        // Gracias por todo Nemo
                        //y virgulilla
                    }

                    // 3. Reordenar
                    if (opcionSecundaria == "3") {
                        if (servicios->getSize() == 0) {
                            cout << "No hay servicios para reordenar." << endl;
                        }
                        else {
                            string pos1, pos2;
                            cout << "Escriba la primera posicion (1-" << servicios->getSize() << "): ";
                            getline(cin, pos1);
                            while (!revisarOpcion(pos1, servicios->getSize())) {
                                cout << "Escriba una opcion valida: ";
                                getline(cin, pos1);
                            }
                            cout << "Escriba la segunda posicion (1-" << servicios->getSize() << "): ";
                            getline(cin, pos2);
                            while (!revisarOpcion(pos1, servicios->getSize() || pos1 == pos2)) {
                                cout << "Escriba una opcion valida: ";
                                getline(cin, pos2);
                            }
                            servicios->swap(stoi(pos1) - 1, stoi(pos2) - 1);
                        }
                    }

                    // 4. Regresar
                    if (opcionSecundaria == "4") {
                        opcionSecundaria = "0";
                    }

                    else
                        opcionSecundaria = "3";
                }

                // 4. Limpiar colas y estadisticas
                if (opcionSecundaria == "4") {
                    areas->goToStart();
                    for (int i = 0; i < areas->getSize(); i++) {
                        Area actual = areas->getElement();
                        actual.tiquetes->clear();
                        actual.servicios->clear();
                        actual.tiquetesAtendidos->clear();
                        actual.cantidadTiquetes = 0;
                        actual.cantidadTiquetesAtendidos = 0;
                    }
                    listaUsuarios->goToStart();
                    for (int i = 0; i < listaUsuarios->getSize(); i++) {
                        listaUsuarios->getElement().cantidadTiquetes = 0;
                    }
                    servicios->goToStart();
                    for (int i = 0; i < servicios->getSize(); i++) {
                        servicios->getElement().cantidadTiquetes = 0;
                    }
                }

                // 5. Regresar
                if (opcionSecundaria == "5") {

                }
            }

            // 5. Estadisticas del sistema
            if (opcionPrincipal == "5") {
                cout << "Tiempo promedio por cada area:" << endl;
                areas->goToStart();
                for (int i = 0; i < areas->getSize(); i++) {
                    int tiempo = 0;
                    Area actual = areas->getElement();
                    actual.tiquetesAtendidos->goToStart();
                    for (int j = 0; j < actual.tiquetesAtendidos; j++) {
                        tiempo += actual.tiquetesAtendidos->getElement().atendido;
                        actual->tiquetesAtendidos->next();
                    }
                    cout << "\tArea: " << actual.descripcion << "." << endl;
                    cout << "\tTiempo promedio: " << tiempo / actual.cantidadTiquetesAtendidos
                    << "." << endl;
                    areas->next();
                }
                cout << endl;
                cout << "Cantidad de tiquetes por area: " << endl;
                areas->goToStart();
                for (int i = 0; i < areas->getSize(); i++) {
                    cout << "\tArea: " << areas->getElement().descripcion;
                    cout << "\tTiquetes " << areas->getElement().cantidadTiquetes;
                }
                cout << endl;
                cout << "Cantidad de tiquetes atendidos por ventanilla: " << endl;
                areas->goToStart();
                for (int i = 0; i < areas->getSize(); i++) {
                    Area actual = areas->getElement();
                    actual->ventanillas->goToStart();
                    cout << "\tArea: " << actual.descripcion << "." << endl;
                    for (int j = 0; j < actual.cantidadVentanillas; j++) {
                        Ventanilla ventanillaActual = actual->ventanillas->getElement();
                        cout << "\t\tVentanilla: " << ventanillaActual << "." << endl;
                        cout << "\t\tAtendidos: " << ventanillaActual.cantidadAtendidos << "." << endl;
                        actual->ventanillas->next();
                    }
                    areas->next();
                }
                cout << endl;
                cout << "Cantidad de tiquetes por usuario: " << endl;
                listaUsuarios->goToStart();
                for (int i = 0; i < listaUsuarios->getSize(); i++) {
                    cout << listaUsuarios->getElement().getDescripcion() << ": " <<
                    listaUsuarios->getElement().getCantidadTiquetes() << "." << endl;
                    listaUsuarios->next();
                }
                cout << endl;
            }
            
            // 6. Salir
            if (opcionPrincipal == "6") {
                break;
            }
            opcionPrincipal = "0";
            opcionSecundaria = "0";
        }
    }
    catch (const runtime_error& e) {
	    cout << e.what() << endl;
    }
    return 0;
};


// Me voy a volar la cabeza
//Confirmo

// We are so fucking cooked

// We are so back