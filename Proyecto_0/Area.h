//Clase que define los atributos y métodos de un Área.
//Las funcionalidades de esta clase son: Agregar ventanas y servicios al área 
//y ver sus ventanas.
//Creadores: Jose Alberto Bulgarelli e Ignacio Castillo.
#pragma once

#include <stdexcept>
#include <string>
#include "LinkedStack.h"
#include "PriorityQueue.h"
#include "HeapPriorityQueue.h"
#include "Ventanilla.h"

using std::string;
using std::to_string;
using std::runtime_error;

template <typename E>
class Area {
private:
    PriorityQueue<E>* servicios = new HeapPriorityQueue<E>();
    LinkedStack<Ventanilla> ventanillas;
    string descripcion;
    string codigo;

public:
    Area(string descripcion, string codigo) { //Crea un objeto Area con su descripción y el código para el tiquete.
        this->descripcion = descripcion;
        this->codigo = codigo;
    }

    ~Area() { //Destrulle el objeto Area.
        servicios->clear();
        ventanillas.clear();
        delete servicios;
        delete ventanillas;
    }

    void mostrarVentanillas() { //Muestra todaas las ventanas de un Area.
        ventanillas.print();
    }

    void agregarVentanillas(int cantidad) { //Agrega la cantidad de ventanas escogidas.
        if (cantidad <= 0)
            throw runtime_error("Cantidad de ventanas fuera de rango.")
        ventanillas.clear();
        string ventanilla;
        char c = descripcion[0];
        for (int i = 1; i <= cantidad; i++) {
            ventanilla = codigo + to_string(i);
            ventanillas.push(ventanilla);
        }
    }
};