#pragma once

class Ventanilla {
private:
    int cantidadAtendidos;
    string nombre;

public:
    Ventanilla(int cantidadAtendidos, string nombre) {
        this->cantidadAtendidos = cantidadAtendidos;
        this->nombre = nombre;
    }

    ~Ventanilla() {}

    void agregarAtendido() {
        cantidadAtendidos++;
    }
}