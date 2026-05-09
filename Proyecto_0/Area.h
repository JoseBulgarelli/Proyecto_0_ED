//Clase que define los atributos y métodos de un Área.
//Las funcionalidades de esta clase son: Agregar ventanas, tiquetes y servicios al área 
//y ver sus ventanas.
//Creadores: Jose Alberto Bulgarelli e Ignacio Castillo.
#pragma once

#include <stdexcept>
#include <string>
#include "List.h"
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "HeapPriorityQueue.h"
#include "Ventanilla.h"
#include "Tiquete.h"

using std::string;
using std::to_string;
using std::runtime_error;

template <typename E>
class Area {
private:
    PriorityQueue<E>* servicios;
    List<Ventanilla>* ventanillas;
    PriorityQueue<Tiquete>* tiquetes;
    List<Tiquete>* tiquetesAtendidos;
    int cantidadVentanillas;
    int cantidadTiquetesAtendidos;
    int cantidadTiquetes;
    string descripcion;
    string codigo;

public:
    Area(string descripcion, string codigo, int cantidadVentanillas) { //Crea un objeto Area con su descripción y el código para el tiquete.
        this->descripcion = descripcion;
        this->codigo = codigo;
        this->cantidadVentanillas = cantidadVentanillas;
        tiquetesAtendidos = 0;
        ventanillas = new LinkedList<Ventanilla>();
        tiquetes = new HeapPriorityQueue<Tiquete>();
        tiquetesAtendidos = new LinkedList<Tiquete>();
        servicios = new HeapPriorityQueue<E>();
    }

    Area() {} //Crea un objeto vacío.

    ~Area() { //Destrulle el objeto Area.
        servicios->clear();
        ventanillas->clear();
        delete servicios;
        delete ventanillas;
    }

    void mostrarVentanillas() { //Muestra todas las ventanas de un Area.
        ventanillas->print();
    }

    void cambiarCantidadVentanillas(int cantidad) { //Agrega la cantidad de ventanas escogidas.
        if (cantidad <= 0)
            throw runtime_error("Cantidad de ventanas fuera de rango.");
        cantidadVentanillas = cantidad;
        ventanillas->clear();
        Ventanilla ventanilla;
        for (int i = 1; i <= cantidad; i++) {
            ventanilla = Ventanilla(0, codigo + to_string(i));
            ventanillas->append(ventanilla);
        }
    } //Cambiar el codigo de aqui para que primero copie las ventanillas de la lista y luego agregue nuevas (Asi no se pierden los atendidos)

    E getDescripcion() {
        return descripcion;
    }

    int getCantidadVentanillas() {
        return cantidadVentanillas;
    }

    bool ventanillaExiste(string nombre) {
        ventanillas->goToStart();
        for (int i = 0; i < cantidadVentanillas; i++)
            if (ventanillas->getElement().nombre = nombre)
                return true;
    return false;
    }

    int posicionVentanilla(string nombre) {
        ventanillas->goToStart();
        for (int i = 0; i < cantidadVentanillas; i++)
            if (ventanillas->getElement().nombre = nombre)
                return i;
    }

    void agregarTiquete(Tiquete tiquete, int prioridad) {
        cantidadTiquetes++;
        tiquetes->insert(tiquete, prioridad);
    }

    void atenderTiquete(string ventanilla) {
        cantidadTiquetesAtendidos++;
        tiquetes->goToStart();
        ventanillas->goToStart();
        for (int i = 0; i < ventanillas->getSize(); i++) {
            if (ventanillas->getElement().nombre == ventanilla) {
                ventanillas->getElement().setUltimoAtendido(tiquetes->min().nombre);
                break;
            }
            ventanillas->next();
        }
        tiquetesAtendidos->append(tiquetes->removeMin().atender());
    }
};