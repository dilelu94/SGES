#ifndef MENUVENTASERVICIOS_H_INCLUDED
#define MENUVENTASERVICIOS_H_INCLUDED

#include "../clases/VentaServicioClase.h"
void menuVentaServicio();

void cargarVentaServicio();
void buscarYMostrarVentaServicio();
void mostrarVentasServicios();
void modificarVentaServicio();
void borrarVentaServicio();

void menuVentaServicio()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t MENU VENTAS DE SERVICIOS" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;

        cout << "1- Cargar" << endl;
        cout << "2- Buscar Venta de Servicio" << endl;
        cout << "3- Mostrar Todas las Ventas" << endl;
        cout << "4- Modificar Venta" << endl;
        cout << "5- Borrar Venta" << endl;

        cout << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cargarVentaServicio();
            break;
        case 2:
            buscarYMostrarVentaServicio();
            break;
        case 3:
            system("cls");
            textColor(14, 0);
            divisorDoble();
            cout << "\t LISTADO DE VENTAS: " << endl;
            divisorDoble();
            textColor(15, 0);

            mostrarVentasServicios();
            break;
        case 4:
            modificarVentaServicio();
            break;
        case 5:
            borrarVentaServicio();
            break;
        case 0:
            return;
            break;
        }
        system("pause>nul");
    }
}

void cargarVentaServicio()
{
    system("cls");
    VentaServicio nuevaVentaServicio;
    ArchivoVentaServicio archivoVenta;

    if (nuevaVentaServicio.cargar())
    {
        archivoVenta.agregarRegistro(nuevaVentaServicio);
    }
    else
    {
        system("cls");
        textColor(12, 0);
        divisorSimple();
        cout << "\t Intente nuevamente" << endl;
        divisorSimple();
        textColor(15, 0);
    }
}

void buscarYMostrarVentaServicio()
{
    system("cls");
    ArchivoVentaServicio archivoVenta;
    int codVenta;

    cout << "INGRESE EL CODIGO DE VENTA A BUSCAR: ";
    cin >> codVenta;
    system("cls");
    textColor(14, 0);
    divisorDoble();
    cout << "\t VENTA ENCONTRADA:" << endl;
    divisorDoble();
    textColor(15, 0);
    archivoVenta.leerRegistro(codVenta);
}

void mostrarVentasServicios()
{
    ArchivoVentaServicio archivoVenta;

    archivoVenta.leerRegistros();
    archivoVenta.estadisticaDeVentas();
}

void modificarVentaServicio()
{

    system("cls");
    ArchivoVentaServicio archivoVenta;
    int codVenta;

    cout << "INGRESE EL CODIGO DE VENTA A MODIFICAR: ";
    cin >> codVenta;
    archivoVenta.modificarRegistro(codVenta);
}

void borrarVentaServicio()
{
    system("cls");
    ArchivoVentaServicio archivoVenta;
    int codVenta;

    cout << "INGRESE EL CODIGO DE VENTA A ELIMINAR: ";
    cin >> codVenta;
    archivoVenta.borrarVentaServicio(codVenta);
}

#endif // MENUVENTASERVICIOS_H_INCLUDED
