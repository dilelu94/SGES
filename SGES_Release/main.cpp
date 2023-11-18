#include <iostream>
#include <cstdlib>
using namespace std;

#include "funciones/funcionesGlobales.h"
#include "menues/menuEmpleados.h"
#include "menues/menuCombustible.h"
#include "menues/menuCargaCombustible.h"
#include "menues/menuTipoServicios.h"
#include "menues/menuVentaServicios.h"
#include "menues/menuStockList.h"
#include "menues/menuVentaKiosco.h"
#include "menues/menuClientes.h"
#include "menues/menuConfiguracion.h"

int main()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t Bienvenido a SGES" << endl;
        divisorDoble();
        cout << endl;
        textColor(15, 0);

        cout << "MENU PRINCIPAL" << endl;
        cout << endl;

        cout << "1- Seccion Empleados" << endl;
        cout << "2- Seccion Combustibles" << endl;
        cout << "3- Seccion Cargas de Combustible" << endl;
        cout << "4- Seccion Tipos de Servicios" << endl;
        cout << "5- Seccion Ventas de Servicio" << endl;
        cout << "6- Seccion Stock Kiosco" << endl;
        cout << "7- Seccion Ventas de Kiosco" << endl;
        cout << "8- Seccion Clientes" << endl;
        cout << "9- Seccion configuracion" << endl;

        cout << endl;
        divisorSimple();
        cout << "0- Salir del programa" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            menuEmpleados();
            break;
        case 2:
            menuTiposCombustible();
            break;
        case 3:
            menuCargaCombustible();
            break;
        case 4:
            menuTiposServicios();
            break;
        case 5:
            menuVentaServicio();
            break;
        case 6:
            menuStockList();
            break;
        case 7:
            menuVentasKiosco();
            break;
        case 8:
            menuClientes();
            break;
        case 9:
            menuConfiguracion();
            break;
        case 0:
            return 0;
            break;
        }
    }
}
