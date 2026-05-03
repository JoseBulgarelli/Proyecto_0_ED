#pragma once

#include "LinkedStack.h"
#include "PriorityQueue.h"
#include "HeapPriorityQueue.h"
#include "Ventanilla.h"

#include <string>

using std::string;
using std::to_string;

template <typename E>
class Area {
private:
    PriorityQueue<E>* servicios = new HeapPriorityQueue<E>();
    LinkedStack<Ventanilla> ventanillas;
    string descripcion;
    string codigo;

public:
    Area(string descripcion, string codigo) {
        this->descripcion = descripcion;
        this->codigo = codigo;
    }

    ~Area() {
        ventanillas.clear();
    }

    void mostrarVentanillas() {
        ventanillas.print();
    }

    void agregarVentanillas(int cantidad) {
        ventanillas.clear();
        string ventanilla;
        char c = descripcion[0];
        for (int i = 1; i <= cantidad; i++) {
            ventanilla = codigo + to_string(i);
            ventanillas.push(ventanilla);
        }
    }
};