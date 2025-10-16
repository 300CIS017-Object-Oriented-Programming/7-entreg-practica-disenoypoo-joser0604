//
// Created by Richi on 10/16/2025.
//
#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <vector>
#include "Venta.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Cliente {
private:
    long identificacion;
    string nombre;
    string email;
    vector<Venta *> historialCompras;

public:
    Cliente();
    Cliente(long identificacion, const string &nombre, const string &email);
    virtual ~Cliente();

    void mostrarDatos();
    void agregarVenta(Venta *venta);
    void mostrarHistorial();
    float calcularTotalCompras();

    long getIdentificacion() const;
    void setIdentificacion(long identificacion);
    const string &getNombre() const;
    void setNombre(const string &nombre);
    const string &getEmail() const;
    void setEmail(const string &email);
};

#endif