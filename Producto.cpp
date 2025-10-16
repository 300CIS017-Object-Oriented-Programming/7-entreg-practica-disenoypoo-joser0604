//
// Created by Richi on 10/16/2025.
//
#include <iostream>
#include "Producto.h"

using std::cout;
using std::endl;

Producto::Producto() {
    codigo = "";
    nombre = "";
    precio = 0.0f;
    cantidadStock = 0;
}

Producto::Producto(const string &codigo, const string &nombre, float precio, int cantidadStock)
    : codigo(codigo), nombre(nombre), precio(precio), cantidadStock(cantidadStock) {}

Producto::~Producto() {
    cout << "Destructor de Producto: " << nombre << " eliminado\n";
}

void Producto::mostrarDatos() {
    cout << "COdigo: " << codigo << "\n";
    cout << "Nombre: " << nombre << "\n";
    cout << "Precio: $" << precio << "\n";
    cout << "Stock disponible: " << cantidadStock << " unidades\n";
    cout << "Valor total en stock: $" << calcularValorTotal() << "\n";
}

void Producto::actualizarStock(int cantidad) {
    cantidadStock += cantidad;
    if (cantidadStock < 0) {
        cantidadStock = 0;
    }
}

float Producto::calcularValorTotal() {
    return precio * cantidadStock;
}

const string &Producto::getCodigo() const {
    return codigo;
}

void Producto::setCodigo(const string &codigo) {
    Producto::codigo = codigo;
}

const string &Producto::getNombre() const {
    return nombre;
}

void Producto::setNombre(const string &nombre) {
    Producto::nombre = nombre;
}

float Producto::getPrecio() const {
    return precio;
}

void Producto::setPrecio(float precio) {
    Producto::precio = precio;
}

int Producto::getCantidadStock() const {
    return cantidadStock;
}

void Producto::setCantidadStock(int cantidadStock) {
    Producto::cantidadStock = cantidadStock;
}