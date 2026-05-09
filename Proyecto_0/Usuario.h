//Clase que define los atributos y métodos de un Área.
//Las funcionalidades de esta clase son: Crear un usuario y agregar tiquetes atendidos.
//Creadores: Jose Alberto Bulgarelli e Ignacio Castillo.
#pragma once

#include <string>

using std::string;

class Usuario {
private:
    string descripcion;
    int cantidadTiquetes;
public:
    Usuario(string descripcion) {
        this->descripcion = descripcion;
        cantidadTiquetes = 0;
    }

    ~Usuario() {}

    void agregarTiquete() {
        cantidadTiquetes++;
    }

    string getDescripcion() {
        return descripcion;
    }

    int getCantidadTiquetes() {
        return cantidadTiquetes;
    }
};