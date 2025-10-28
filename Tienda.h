//
// Created by Richi on 10/16/2025.
//
#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <string>
#include <vector>
#include "Producto.h"
#include "Cliente.h"
#include "Venta.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

class Tienda {
private:
    string nombreTienda;
    vector<Producto *> inventario;
    vector<Cliente *> clientes;
    vector<Venta *> ventas;
    int contadorVentas;

    void inicializarDatos();

public:
    Tienda();
    virtual ~Tienda();

    void agregarProducto();
    void agregarCliente();
    void realizarVenta();
    void actualizarInventario();
    void mostrarInventario();
    void mostrarClientes();
    void mostrarVentas();
    void mostrarVentasPorCliente();
    float calcularValorTotalInventario();

    Producto *buscarProducto(const string &codigo);
    Cliente *buscarCliente(long identificacion);
};

#endif