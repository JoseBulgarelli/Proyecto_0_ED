#pragma once

#include <string>
#include <time.h>

class Tiquete {
private:
    string nombre;
    time_t creacion;
    time_t espera;
    time_t atendido;

public:
    Tiquete(string nombre) {
        this->nombre = nombre;
        creacion = time(0);
    }
    
    ~Tiquete() {}

    void atender() {
        atendido = time(0);
        espera = atendido - creacion;
    }
};