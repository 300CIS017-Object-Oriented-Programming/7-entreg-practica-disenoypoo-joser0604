//
// Created by Richi on 10/16/2025.
//
#include <iostream>
#include "Tienda.h"

using std::cout;
using std::endl;
using std::cin;

Tienda::Tienda() {
    cout << "Inicializando EcoTienda Verde...\n";
    nombreTienda = "EcoTienda Verde";
    contadorVentas = 1;
    inicializarDatos();
    cout << "EcoTienda Verde lista para operar.\n\n";
}

void Tienda::inicializarDatos() {
    // Crear productos iniciales
    Producto *prod1 = new Producto("P001", "Bolsas Reutilizables", 15000, 50);
    Producto *prod2 = new Producto("P002", "Botellas Ecológicas", 25000, 30);
    Producto *prod3 = new Producto("P003", "Champú Orgánico", 18000, 25);
    Producto *prod4 = new Producto("P004", "Jabón Natural", 8000, 60);
    Producto *prod5 = new Producto("P005", "Desodorante Ecológico", 12000, 40);

    inventario.push_back(prod1);
    inventario.push_back(prod2);
    inventario.push_back(prod3);
    inventario.push_back(prod4);
    inventario.push_back(prod5);

    // Crear clientes iniciales
    Cliente *cliente1 = new Cliente(1088888888, "Carlos Rodríguez", "carlos@email.com");
    Cliente *cliente2 = new Cliente(1077777777, "María García", "maria@email.com");
    Cliente *cliente3 = new Cliente(1066666666, "Juan Pérez", "juan@email.com");
    Cliente *cliente4 = new Cliente(1055555555, "Ana López", "ana@email.com");

    clientes.push_back(cliente1);
    clientes.push_back(cliente2);
    clientes.push_back(cliente3);
    clientes.push_back(cliente4);

    // Crear ventas iniciales de ejemplo
    Venta *venta1 = new Venta(contadorVentas++, "2025-10-16", prod1, 5);
    Venta *venta2 = new Venta(contadorVentas++, "2025-10-15", prod2, 3);
    Venta *venta3 = new Venta(contadorVentas++, "2025-10-14", prod3, 2);

    cliente1->agregarVenta(venta1);
    cliente2->agregarVenta(venta2);
    cliente3->agregarVenta(venta3);

    ventas.push_back(venta1);
    ventas.push_back(venta2);
    ventas.push_back(venta3);

    // Actualizar inventario
    prod1->actualizarStock(-5);
    prod2->actualizarStock(-3);
    prod3->actualizarStock(-2);
}

void Tienda::agregarProducto() {
    string codigo, nombre;
    float precio;
    int cantidad;

    cout << "   AGREGAR NUEVO PRODUCTO      \n";

    cout << "Ingrese el código del producto: ";
    cin.ignore();
    getline(cin, codigo);

    cout << "Ingrese el nombre del producto: ";
    getline(cin, nombre);

    cout << "Ingrese el precio del producto: $";
    cin >> precio;

    cout << "Ingrese la cantidad inicial en stock: ";
    cin >> cantidad;

    Producto *nuevoProducto = new Producto(codigo, nombre, precio, cantidad);
    inventario.push_back(nuevoProducto);

    cout << "\n Producto agregado exitosamente.\n";
}

void Tienda::agregarCliente() {
    long identificacion;
    string nombre, email;

    cout << "   AGREGAR NUEVO CLIENTE      \n";

    cout << "Ingrese la identificación: ";
    cin >> identificacion;

    cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el email del cliente: ";
    getline(cin, email);

    Cliente *nuevoCliente = new Cliente(identificacion, nombre, email);
    clientes.push_back(nuevoCliente);

    cout << "\n Cliente agregado exitosamente.\n";
}

void Tienda::realizarVenta() {
    string codigo;
    long idCliente;
    int cantidad;
    string fecha;

    cout << "   REALIZAR NUEVA VENTA        \n";

    cout << "Ingrese la identificación del cliente: ";
    cin >> idCliente;

    Cliente *cliente = buscarCliente(idCliente);
    if (cliente == nullptr) {
        cout << " Cliente no encontrado.\n";
        return;
    }

    cout << "Ingrese el código del producto: ";
    cin.ignore();
    getline(cin, codigo);

    Producto *producto = buscarProducto(codigo);
    if (producto == nullptr) {
        cout << " Producto no encontrado.\n";
        return;
    }

    cout << "Ingrese la cantidad a comprar: ";
    cin >> cantidad;

    if (cantidad > producto->getCantidadStock()) {
        cout << " Stock insuficiente. Disponibles: " << producto->getCantidadStock() << "\n";
        return;
    }

    cout << "Ingrese la fecha de la venta (formato: YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, fecha);

    Venta *nuevaVenta = new Venta(contadorVentas++, fecha, producto, cantidad);
    cliente->agregarVenta(nuevaVenta);
    ventas.push_back(nuevaVenta);
    producto->actualizarStock(-cantidad);

    cout << "\n Venta realizada exitosamente.\n";
    cout << "Total de la venta: $" << nuevaVenta->getTotalVenta() << "\n";
}

void Tienda::actualizarInventario() {
    string codigo;
    int cantidad;

    cout << "   ACTUALIZAR STOCK            \n";

    cout << "Ingrese el código del producto: ";
    cin.ignore();
    getline(cin, codigo);

    Producto *producto = buscarProducto(codigo);
    if (producto == nullptr) {
        cout << " Producto no encontrado.\n";
        return;
    }

    cout << "Stock actual: " << producto->getCantidadStock() << " unidades\n";
    cout << "Ingrese la cantidad a agregar (negativo para restar): ";
    cin >> cantidad;

    producto->actualizarStock(cantidad);
    cout << "\n✓ Stock actualizado a: " << producto->getCantidadStock() << " unidades\n";
}

void Tienda::mostrarInventario() {
    cout << "   INVENTARIO COMPLETO         \n";

    if (inventario.empty()) {
        cout << "No hay productos en el inventario.\n";
        return;
    }

    for (int i = 0; i < inventario.size(); i++) {
        cout << "\n[Producto " << (i + 1) << "]\n";
        inventario[i]->mostrarDatos();
    }
}

void Tienda::mostrarClientes() {
    cout << "   LISTADO DE CLIENTES         \n";

    if (clientes.empty()) {
        cout << "No hay clientes registrados.\n";
        return;
    }

    for (int i = 0; i < clientes.size(); i++) {
        cout << "\n[Cliente " << (i + 1) << "]\n";
        clientes[i]->mostrarDatos();
    }
}

void Tienda::mostrarVentas() {
    cout << "   HISTORIAL DE TODAS LAS VENTAS\n";

    if (ventas.empty()) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    float totalRecaudado = 0.0f;
    for (int i = 0; i < ventas.size(); i++) {
        cout << "\n[Venta " << (i + 1) << "]\n";
        ventas[i]->mostrarDatos();
        totalRecaudado += ventas[i]->getTotalVenta();
    }

    cout << "Total recaudado: $" << totalRecaudado << "\n";
}

void Tienda::mostrarVentasPorCliente() {
    long idCliente;

    cout << " VENTAS POR CLIENTE            \n";

    cout << "Ingrese la identificación del cliente: ";
    cin >> idCliente;

    Cliente *cliente = buscarCliente(idCliente);
    if (cliente == nullptr) {
        cout << " Cliente no encontrado.\n";
        return;
    }

    cliente->mostrarHistorial();
}

float Tienda::calcularValorTotalInventario() {
    float total = 0.0f;
    for (int i = 0; i < inventario.size(); i++) {
        total += inventario[i]->calcularValorTotal();
    }
    return total;
}

Producto *Tienda::buscarProducto(const string &codigo) {
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i]->getCodigo() == codigo) {
            return inventario[i];
        }
    }
    return nullptr;
}

Cliente *Tienda::buscarCliente(long identificacion) {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i]->getIdentificacion() == identificacion) {
            return clientes[i];
        }
    }
    return nullptr;
}

Tienda::~Tienda() {
    cout << "\nEliminando todos los datos de la tienda...\n";

    // Eliminar inventario
    for (int i = 0; i < inventario.size(); i++) {
        delete inventario[i];
    }

    // Eliminar clientes (esto también elimina sus ventas)
    for (int i = 0; i < clientes.size(); i++) {
        delete clientes[i];
    }

    // Eliminar ventas adicionales no asociadas a clientes
    for (int i = 0; i < ventas.size(); i++) {
        delete ventas[i];
    }

    cout << " Todos los datos han sido eliminados correctamente.\n";
    cout << "¡Hasta luego!\n";
}