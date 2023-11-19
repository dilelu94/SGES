#ifndef MENUVENTAKIOSCO_H_INCLUDED
#define MENUVENTAKIOSCO_H_INCLUDED

#include "../clases/VentaKioscoClase.h"
void cargarVentaKiosco();
void mostrarVentaKiosco();
void mostrarVentasKiosco();
void modificarVentaKiosco();
void borrarVentaKiosco();


void menuVentasKiosco();

void menuVentasKiosco()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t MENU VENTAS DEL KIOSCO" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;

        cout << "1- Cargar" << endl;
        cout << "2- Mostrar Venta en Especifico" << endl;
        cout << "3- Mostrar todas las ventas" << endl;
        cout << "4- Modificar una Venta" << endl;
        cout << "5- Borrar una Venta" << endl;

        cout << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();

        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cargarVentaKiosco();
            break;
        case 2:
            mostrarVentaKiosco();
            break;
        case 3:
            mostrarVentasKiosco();
            break;
        case 4:
            modificarVentaKiosco();
            break;
        case 5:
            borrarVentaKiosco();
            break;
        case 0:
            return;
            break;
        }
        system("pause>nul");
    }
}

void cargarVentaKiosco()
{
    system("cls");
    Kiosco ventaNueva;
    ArchivoKiosco file;

    if (ventaNueva.cargar() == 1)
    {
        file.agregarRegistro(ventaNueva);
    }
}

void mostrarVentaKiosco(){
    system("cls");
    ArchivoKiosco file;

    int nVenta;
    cout<<"INGRESE UN NUMERO DE VENTA: ";
    cin>>nVenta;

    file.leerRegistro(nVenta);
}

void mostrarVentasKiosco(){
    system("cls");
    ArchivoKiosco file;

    file.leerRegistros();
    file.stadistiaVentasDeKiosco();
}

void modificarVentaKiosco(){
    system("cls");
    ArchivoKiosco file;

    int nVenta;
    cout<<"INGRESE UN NUMERO DE VENTA: ";
    cin>>nVenta;

    file.modificarRegistro(nVenta);
}

void borrarVentaKiosco(){
    system("cls");
    ArchivoKiosco file;

    int nVenta;
    cout<<"INGRESE UN NUMERO DE VENTA: ";
    cin>>nVenta;

    file.borrarVentaKiosco(nVenta);
}

#endif // MENUVENTAKIOSCO_H_INCLUDED
