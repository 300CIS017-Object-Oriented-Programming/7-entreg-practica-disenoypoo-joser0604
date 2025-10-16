#include <iostream>
#include "Tienda.h"

using std::cin;
using std::cout;

void mostrarMenuProductos(Tienda &tienda) {
    int opc = 0;

    do {
        cout << "   MENÚ DE PRODUCTOS           \n";
        cout << "1. Ver inventario completo\n";
        cout << "2. Agregar nuevo producto\n";
        cout << "3. Actualizar stock de producto\n";
        cout << "4. Calcular valor total del inventario\n";
        cout << "-1. Volver al menú principal\n";
        cout << "\nSeleccione una opción: ";
        cin >> opc;

        switch (opc) {
            case 1:
                tienda.mostrarInventario();
                break;
            case 2:
                tienda.agregarProducto();
                break;
            case 3:
                tienda.actualizarInventario();
                break;
            case 4:
                cout << "\nValor total del inventario: $" << tienda.calcularValorTotalInventario() << "\n";
                break;
            case -1:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    } while (opc != -1);
}

void mostrarMenuClientes(Tienda &tienda) {
    int opc = 0;

    do {
        cout << "   MENU DE CLIENTES            \n";
        cout << "1. Ver todos los clientes\n";
        cout << "2. Agregar nuevo cliente\n";
        cout << "3. Ver historial de compras de un cliente\n";
        cout << "-1. Volver al menU principal\n";
        cout << "\nSeleccione una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                tienda.mostrarClientes();
                break;
            case 2:
                tienda.agregarCliente();
                break;
            case 3:
                tienda.mostrarVentasPorCliente();
                break;
            case -1:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion no válida.\n";
                break;
        }
    } while (opc != -1);
}

void mostrarMenuVentas(Tienda &tienda) {
    int opc = 0;

    do {
        cout << "   MENÚ DE VENTAS              \n";
        cout << "1. Realizar nueva venta\n";
        cout << "2. Ver todas las ventas\n";
        cout << "3. Ver ventas por cliente\n";
        cout << "-1. Volver al menú principal\n";
        cout << "\nSeleccione una opción: ";
        cin >> opc;

        switch (opc) {
            case 1:
                tienda.realizarVenta();
                break;
            case 2:
                tienda.mostrarVentas();
                break;
            case 3:
                tienda.mostrarVentasPorCliente();
                break;
            case -1:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    } while (opc != -1);
}

void menuPrincipal(Tienda &tienda) {
    int opc = 0;

    do {
        cout << "  SISTEMA DE GESTION - ECOTIENDA VERDE \n";
        cout << "1. Gestion de Productos\n";
        cout << "2. Gestion de Clientes\n";
        cout << "3. Gestion de Ventas\n";
        cout << "4. Ver resumen general\n";
        cout << "-1. Salir del sistema\n";
        cout << "\nSeleccione una opciOn: ";
        cin >> opc;

        switch (opc) {
            case 1:
                mostrarMenuProductos(tienda);
                break;
            case 2:
                mostrarMenuClientes(tienda);
                break;
            case 3:
                mostrarMenuVentas(tienda);
                break;
            case 4:
                cout << "   RESUMEN GENERAL DEL SISTEMA  \n";
                tienda.mostrarInventario();
                cout << "\n";
                tienda.mostrarClientes();
                cout << "\n";
                tienda.mostrarVentas();
                break;
            case -1:
                cout << "\n¡Gracias por usar EcoTienda Verde!\n";
                cout << "Cerrando sistema...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (opc != -1);
}

int main() {
    cout << "\n";
    cout << "     BIENVENIDO A ECOTIENDA VERDE             \n";
    cout << "   Sistema de Gestion de Ventas e Inventario  \n";


    Tienda tienda;
    menuPrincipal(tienda);

    return 0;
}