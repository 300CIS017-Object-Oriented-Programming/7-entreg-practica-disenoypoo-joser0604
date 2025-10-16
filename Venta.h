//
// Created by Richi on 10/16/2025.
//

#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <string>
#include "Producto.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Venta {
private:
    int numeroVenta;
    string fecha;
    Producto *producto;
    int cantidad;
    float totalVenta;

    void calcularTotal();

public:
    Venta();
    Venta(int numeroVenta, const string &fecha, Producto *producto, int cantidad);
    virtual ~Venta();

    void mostrarDatos();

    int getNumeroVenta() const;
    void setNumeroVenta(int numeroVenta);
    const string &getFecha() const;
    void setFecha(const string &fecha);
    Producto *getProducto() const;
    void setProducto(Producto *producto);
    int getCantidad() const;
    void setCantidad(int cantidad);
    float getTotalVenta() const;
};

#endif