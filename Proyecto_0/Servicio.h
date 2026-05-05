#pragma once

#include <string>
#include "Area.h"

using std::string;

template <typename E>
class Servicio {
private:
    string descripcion;
    int prioridad;
    Area area;

public:
    Servicio(string descripcion, int prioridad, Area area) {
        this->descripcion = descripcion;
        this->prioridad = prioridad;
        this->area = area;
    }

    ~Servicio() {}
};