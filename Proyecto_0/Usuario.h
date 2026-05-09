//Clase que define los atributos y métodos de un Área.
//Las funcionalidades de esta clase son: Crear un usuario y agregar tiquetes atendidos.
//Creadores: Jose Alberto Bulgarelli e Ignacio Castillo.
#pragma once

#include <string>
#include <ostream>

using std::string;
using std::ostream;

class Usuario {
public:
    string descripcion;
    int cantidadTiquetes;

    Usuario(string descripcion) {
        this->descripcion = descripcion;
        cantidadTiquetes = 0;
    }

    Usuario() {

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

    void setCantidadTiquetes(int cantidad) {
        cantidadTiquetes = cantidad;
    }

    friend ostream& operator <<(ostream& os, const Usuario& usuario) {
        os << usuario.descripcion;
        return os;
    }
};