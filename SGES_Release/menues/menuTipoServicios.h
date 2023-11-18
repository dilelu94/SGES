#ifndef MENUTIPOSERVICIOS_H_INCLUDED
#define MENUTIPOSERVICIOS_H_INCLUDED

#include "../clases/TipoServicioClase.h"
void cargarTipoDeServicio();
void BuscarYMostrarTipoDeServicio();
void mostrarTiposDeServicios();
void modificarTipoDeServicio();
void borrarTipoDeServicio();

void menuTiposServicios();

void menuTiposServicios()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t MENU TIPOS DE SERVICIO" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;

        cout << "1- Cargar" << endl;
        cout << "2- Buscar Servicio" << endl;
        cout << "3- Mostrar Todos Los Servicios" << endl;
        cout << "4- Modificar" << endl;
        cout << "5- Borrar" << endl;

        cout << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cargarTipoDeServicio();
            break;
        case 2:
            BuscarYMostrarTipoDeServicio();
            break;
        case 3:
            system("cls");
            textColor(14, 0);
            divisorDoble();
            cout << "\t LISTADO DE SEVICIOS: " << endl;
            divisorDoble();
            textColor(15, 0);

            mostrarTiposDeServicios();
            break;
        case 4:
            modificarTipoDeServicio();
            break;
        case 5:
            borrarTipoDeServicio();
            break;
        case 0:
            return;
            break;
        }
        system("pause>nul");
    }
}

void cargarTipoDeServicio()
{
    system("cls");
    TipoDeServicio nuevoTipoDeServicio;
    ArchivoTipoServicio archivo;

    if (nuevoTipoDeServicio.cargar())
    {
        archivo.agregarRegistro(nuevoTipoDeServicio);
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

void BuscarYMostrarTipoDeServicio()
{
    system("cls");
    ArchivoTipoServicio archivo;
    int codTipoServ;

    cout << "Ingrese el numero del tipo de servicio que desea buscar" << endl;
    cin >> codTipoServ;
    system("cls");
    textColor(14, 0);
    divisorDoble();
    cout << "\t SERVICIO ENCONTRADO:" << endl;
    divisorDoble();
    textColor(15, 0);
    archivo.leerRegistro(codTipoServ);
}

void mostrarTiposDeServicios()
{
    ArchivoTipoServicio archivo;

    archivo.leerRegistros();
}

void modificarTipoDeServicio()
{
    system("cls");
    ArchivoTipoServicio archivo;
    int codTipoServ;

    cout << "Ingrese el numero del tipo de servicio que desea modificar" << endl;
    cin >> codTipoServ;
    archivo.modificarRegistro(codTipoServ);
}

void borrarTipoDeServicio()
{
    system("cls");
    ArchivoTipoServicio archivo;
    int codTipoServ;

    cout << "Ingrese el numero del tipo de servicio que desea borrar" << endl;
    cin >> codTipoServ;
    archivo.borrarTipoDeServicio(codTipoServ);
}

#endif // MENUTIPOSERVICIOS_H_INCLUDED
