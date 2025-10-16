//
// Created by Richi on 10/16/2025.
//
#include <iostream>
#include <iomanip>
#include "Cliente.h"

using std::cout;
using std::endl;
using std::setprecision;

Cliente::Cliente() {
    identificacion = 0;
    nombre = "";
    email = "";
}

Cliente::Cliente(long identificacion, const string &nombre, const string &email)
    : identificacion(identificacion), nombre(nombre), email(email) {}

Cliente::~Cliente() {
    // Eliminar todas las ventas asociadas
    for (int i = 0; i < historialCompras.size(); i++) {
        delete historialCompras[i];
    }
    cout << "Destructor de Cliente: " << nombre << " eliminado\n";
}

void Cliente::mostrarDatos() {
    cout << "Identificacion: " << setprecision(20) << identificacion << "\n";
    cout << "Nombre: " << nombre << "\n";
    cout << "Email: " << email << "\n";
    cout << "Total de compras: " << historialCompras.size() << "\n";
    cout << "Monto total gastado: $" << calcularTotalCompras() << "\n";
}

void Cliente::agregarVenta(Venta *venta) {
    if (venta != nullptr) {
        historialCompras.push_back(venta);
    }
}

void Cliente::mostrarHistorial() {
    cout << "║  HISTORIAL DE COMPRAS - " << nombre << "\n";

    if (historialCompras.empty()) {
        cout << "No hay compras registradas.\n";
        return;
    }

    for (int i = 0; i < historialCompras.size(); i++) {
        cout << "\nCompra #" << (i + 1) << ":\n";
        historialCompras[i]->mostrarDatos();
    }
}

float Cliente::calcularTotalCompras() {
    float total = 0.0f;
    for (int i = 0; i < historialCompras.size(); i++) {
        total += historialCompras[i]->getTotalVenta();
    }
    return total;
}

long Cliente::getIdentificacion() const {
    return identificacion;
}

void Cliente::setIdentificacion(long identificacion) {
    Cliente::identificacion = identificacion;
}

const string &Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const string &nombre) {
    Cliente::nombre = nombre;
}

const string &Cliente::getEmail() const {
    return email;
}

void Cliente::setEmail(const string &email) {
    Cliente::email = email;
}