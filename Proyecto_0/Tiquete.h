//Clase que define los atributos y métodos de un Tiquete.
//Las funcionalidades de esta clase son: Crear un tiquete y atender ese tiquete.
//Creadores: Jose Alberto Bulgarelli e Ignacio Castillo.
#pragma once

#include <string>
#include <time.h>

using std::string;

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