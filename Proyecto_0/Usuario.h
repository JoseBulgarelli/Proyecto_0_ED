#pragma once

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
};