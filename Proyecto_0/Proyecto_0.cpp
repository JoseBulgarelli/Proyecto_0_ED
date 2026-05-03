#include <iostream>
#include <stdexcept>
#include <string>
#include "PriorityQueue.h"
#include "HeapPriorityQueue.h"
#include "Pair.h"
#include "LinkedStack.h"

using std::cout;
using std::endl;
using std::runtime_error;
using std::string;

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
        PriorityQueue<string>* usuarios = new HeapPriorityQueue<string>();
        LinkedStack<string> listaUsuarios;
        // Elegir una opcion:
        // 1. Estado de colas
        // Mostrar areas existentes, cantidad de ventanillas en cada area y codigos de los tiquetes presentes en las diferentes colas
        // Cada ventanilla muestra el ultimo tiquete atendido

        // 2. Tiquetes
            // 1. Seleccionar tipo de cliente y servicio
            // 2. Regresar

        // 3. Atender
        
        // 4. Administracion
            // 1. Tipos de usuario
                // 1. Agregar
                // Guardar 

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

        // 5. Estadisticas del sistema

        // 6. Salir
    }
    catch (const runtime_error& e) {
	    cout << e.what() << endl;
    }
};



// Me voy a volar la cabeza
//Confirmo