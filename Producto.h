//
// Created by Richi on 10/16/2025.
//

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Producto {
private:
    string codigo;
    string nombre;
    float precio;
    int cantidadStock;

public:
    Producto();
    Producto(const string &codigo, const string &nombre, float precio, int cantidadStock);
    virtual ~Producto();

    void mostrarDatos();
    void actualizarStock(int cantidad);
    float calcularValorTotal();

    const string &getCodigo() const;
    void setCodigo(const string &codigo);
    const string &getNombre() const;
    void setNombre(const string &nombre);
    float getPrecio() const;
    void setPrecio(float precio);
    int getCantidadStock() const;
    void setCantidadStock(int cantidadStock);
};

#endif