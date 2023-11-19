#ifndef MENUCARGACOMBUSTIBLE_H_INCLUDED
#define MENUCARGACOMBUSTIBLE_H_INCLUDED

#include "../clases/CargaCombustibleClase.h"
void cargarVentaCombustible();
void BuscarYMostrarVentaCombustible();
void menuCargaCombustible();
void mostrarVentaCombustibles();
void modificarVentaCombustible();
void borrarVentaCombustible();

void menuCargaCombustible()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "    Venta Servicio Carga Combustible" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;

        cout << "1- Cargar" << endl;
        cout << "2- Buscar Carga de Combustible" << endl;
        cout << "3- Mostrar Todas las Cargas de Combustible" << endl;
        cout << "4- Modificar venta de Combustible" << endl;
        cout << "5- Borrar venta de Combustible" << endl;

        cout << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cargarVentaCombustible();
            break;
        case 2:
            BuscarYMostrarVentaCombustible();
            break;
        case 3:
            system("cls");
            textColor(14, 0);
            divisorDoble();
            cout << "   LISTADO DE VENTAS DE COMBUSTIBLE:" << endl;
            divisorDoble();
            textColor(15, 0);

            mostrarVentaCombustibles();
            break;
        case 4:
            modificarVentaCombustible();
            break;
        case 5:
            borrarVentaCombustible();
            break;
        case 0:
            return;
            break;
        }
        system("pause>nul");
    }
}

void cargarVentaCombustible()
{
    system("cls");
    CargaCombustible ventaCombustibleNueva;
    ArchivoCargaCombustible archivo;

    if (ventaCombustibleNueva.cargar())
    {
        archivo.agregarRegistro(ventaCombustibleNueva);
    }
}

void BuscarYMostrarVentaCombustible()
{
    system("cls");
    ArchivoCargaCombustible archivo;
    int numCodVenta;

    cout << "Ingrese el codigo de venta de combustible que desea buscar" << endl;
    cin >> numCodVenta;
    system("cls");
    textColor(14, 0);
    divisorDoble();
    cout << "\t COMBUSTIBLE ENCONTRADO:" << endl;
    divisorDoble();
    textColor(15, 0);
    archivo.leerRegistro(numCodVenta);
}

void mostrarVentaCombustibles()
{
    ArchivoCargaCombustible archivo;

    archivo.leerRegistros();
    archivo.estadisticaDeCargaCombustible();
}

void modificarVentaCombustible()
{
    system("cls");
    ArchivoCargaCombustible archivo;
    int numCodVenta;

    cout << "Ingrese el codigo de venta de combus que desea modificar" << endl;
    cin >> numCodVenta;
    archivo.modificarRegistro(numCodVenta);
}

void borrarVentaCombustible()
{
    system("cls");
    ArchivoCargaCombustible archivo;
    int numCodVenta;

    cout << "Ingrese el codigo de venta de la carga de combustible" << endl;
    cin >> numCodVenta;
    archivo.borrarCargaCombustible(numCodVenta);
}

#endif // MENUCARGACOMBUSTIBLE_H_INCLUDED
