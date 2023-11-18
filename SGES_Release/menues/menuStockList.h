#ifndef MENUSTOCKLIST_H_INCLUDED
#define MENUSTOCKLIST_H_INCLUDED

#include "../clases/StockListClase.h"
void cargarStockList();
void buscarYMostrarItem();
void mostrarStockList();
void modificarItem();
void borrarItem();

void menuStockList();

void menuStockList()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t MENU STOCK LIST" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;

        cout << "1- Cargar" << endl;
        cout << "2- Mostrar Item en Particular" << endl;
        cout << "3- Mostrar todo el stock list" << endl;
        cout << "4- Modificar Item" << endl;
        cout << "5- Eliminar item" << endl;

        cout << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cargarStockList();
            break;
        case 2:
            buscarYMostrarItem();
            break;
        case 3:
            system("cls");
            textColor(14, 0);
            divisorDoble();
            cout << "    LISTADO DE PRODUCTOS DISPONIBLES:" << endl;
            divisorDoble();
            textColor(15, 0);

            mostrarStockList();
            break;
        case 4:
            modificarItem();
            break;
        case 5:
            borrarItem();
            break;
        case 0:
            return;
            break;
        }
        system("pause>nul");
    }
}

void cargarStockList()
{
    system("cls");
    Stock artNuevo;
    ArchivoStock archivo;

    if (artNuevo.cargar())
    {
        archivo.agregarRegistro(artNuevo);
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

void buscarYMostrarItem()
{
    system("cls");
    ArchivoStock archivo;
    int codigoItem;

    cout << "INGRESE UN CODIGO DE ITEM: ";
    cin >> codigoItem;
    system("cls");
    textColor(14, 0);
    divisorDoble();
    cout << "\t PRODUCTO ENCONTRADO:" << endl;
    divisorDoble();
    textColor(15, 0);
    
    archivo.leerRegistro(codigoItem);
}

void mostrarStockList()
{
    ArchivoStock archivo;

    archivo.leerRegistros();
}

void modificarItem()
{
    system("cls");
    ArchivoStock archivo;
    int codigoItem;

    cout << "INGRESE UN CODIGO DE ITEM: ";
    cin >> codigoItem;

    archivo.modificarRegistro(codigoItem);
}

void borrarItem()
{
    system("cls");
    ArchivoStock archivo;
    int codigoItem;

    cout << "INGRESE UN CODIGO DE ITEM: ";
    cin >> codigoItem;

    archivo.borrarItemDelStock(codigoItem);
}

#endif // MENUSTOCKLIST_H_INCLUDED
