//Clase que define los atributos y métodos de un Servicio.
//Las funcionalidades de esta clase son: Crear un servicio y agregar tiquetes atendidos.
//Creadores: Jose Alberto Bulgarelli e Ignacio Castillo.
#pragma once

#include <string>
#include <ostream>
#include "Area.h"

using std::string;
using std::ostream;

class Servicio {
public:
    string descripcion;
    int prioridad;
    Area area;
    int cantidadTiquetes;

    Servicio(string descripcion, int prioridad, Area area) {
        this->descripcion = descripcion;
        this->prioridad = prioridad;
        this->area = area;
        cantidadTiquetes = 0;
    }

    Servicio() {

    }

    ~Servicio() {}

    void agregarTiquete() {
        cantidadTiquetes++;
    }

    string getDescripcion() {
        return descripcion;
    }

    Area getArea() {
        return area;
    }

    void setCantidadTiquetes(int cantidad) {
        cantidadTiquetes = cantidad;
    }

    friend ostream& operator <<(ostream& os, const Servicio& servicio) {
        os << servicio.descripcion;
        return os;
    }
};