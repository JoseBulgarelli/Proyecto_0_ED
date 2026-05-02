#pragma once

#include "PriorityQueue.h"
#include "HeapPriorityQueue.h"
#include "Ventanilla.h"

#include <string>

using std::string;

template <typename E>
class Area {
private:
    PriorityQueue<E>* servicios = new HeapPriorityQueue<E>();
    LinkedStack<Ventanilla> ventanillas;
    string descripcion;
    string codigo;

public:
    Area() {

    }

    ~Area() {

    }

    mostrarVentanillas() {

    }

};