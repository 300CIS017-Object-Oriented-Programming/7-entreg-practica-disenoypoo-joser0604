//
// Created by Richi on 10/16/2025.
//

#include <iostream>
#include "Venta.h"

using std::cout;
using std::endl;

Venta::Venta() {
    numeroVenta = 0;
    fecha = "";
    producto = nullptr;
    cantidad = 0;
    totalVenta = 0.0f;
}

Venta::Venta(int numeroVenta, const string &fecha, Producto *producto, int cantidad)
    : numeroVenta(numeroVenta), fecha(fecha), producto(producto), cantidad(cantidad) {
    calcularTotal();
}

Venta::~Venta() {
    // No eliminar el producto aquí porque es referencia al inventario
    cout << "Destructor de Venta #" << numeroVenta << " eliminada\n";
}

void Venta::calcularTotal() {
    if (producto != nullptr) {
        totalVenta = producto->getPrecio() * cantidad;
    } else {
        totalVenta = 0.0f;
    }
}

void Venta::mostrarDatos() {
    cout << "Número de venta: " << numeroVenta << "\n";
    cout << "Fecha: " << fecha << "\n";
    if (producto != nullptr) {
        cout << "Producto: " << producto->getNombre() << " (" << producto->getCodigo() << ")\n";
        cout << "Cantidad: " << cantidad << " unidades\n";
        cout << "Precio unitario: $" << producto->getPrecio() << "\n";
    }
    cout << "Total de la venta: $" << totalVenta << "\n";
}

int Venta::getNumeroVenta() const {
    return numeroVenta;
}

void Venta::setNumeroVenta(int numeroVenta) {
    Venta::numeroVenta = numeroVenta;
}

const string &Venta::getFecha() const {
    return fecha;
}

void Venta::setFecha(const string &fecha) {
    Venta::fecha = fecha;
}

Producto *Venta::getProducto() const {
    return producto;
}

void Venta::setProducto(Producto *producto) {
    Venta::producto = producto;
    calcularTotal();
}

int Venta::getCantidad() const {
    return cantidad;
}

void Venta::setCantidad(int cantidad) {
    Venta::cantidad = cantidad;
    calcularTotal();
}

float Venta::getTotalVenta() const {
    return totalVenta;
}