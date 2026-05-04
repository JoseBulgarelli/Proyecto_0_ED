#pragma once

#include <string>

using std::string;

class Servicio {
private:
    string descripcion;
    int prioridad;
    string area; // Ahorita pienso que tipo deberia ser

public:
    Servicio(string descripcion, int prioridad, string area) {
        this->descripcion = descripcion;
        this->prioridad = prioridad;
        this->area = area;
    }

    ~Servicio() {}
};