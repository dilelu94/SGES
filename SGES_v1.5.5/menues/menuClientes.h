#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED

#include "../clases/ClienteClase.h"
void cargarCliente();
void mostrarCliente();
void menuClientes();
void mostrarClientes();
void modificarCliente();
void borrarCliente();

void menuClientes()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t MENU CLIENTES" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;

        cout << "1- Cargar" << endl;
        cout << "2- Mostrar" << endl;
        cout << "3- Mostrar todos los clientes" << endl;
        cout << "4- Modificar cliente" << endl;
        cout << "5- Borrar cliente" << endl;

        cout << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cargarCliente();
            break;
        case 2:
            mostrarCliente();
            break;
        case 3:
            system("cls");
            textColor(14, 0);
            divisorDoble();
            cout << "\t LISTADO DE CLIENTES" << endl;
            divisorDoble();
            textColor(15, 0);

            mostrarClientes();
            break;
        case 4:
            modificarCliente();
            break;
        case 5:
            borrarCliente();
            break;
        case 0:
            return;
            break;
        }
        system("pause>nul");
    }
}

void cargarCliente()
{
    system("cls");
    Cliente clienteNuevo;
    ArchivoCliente file;

    clienteNuevo.cargar();
    file.agregarRegistro(clienteNuevo);
}

void mostrarCliente()
{
    system("cls");
    ArchivoCliente file;
    int numCliente;

    cout << "Ingrese el numero de cliente que desea buscar" << endl;
    cin >> numCliente;
    file.leerRegistro(numCliente);
}

void mostrarClientes()
{
    ArchivoCliente file;

    file.leerRegistros();
}

void modificarCliente()
{
    system("cls");
    ArchivoCliente file;
    int numCliente;

    cout << "Ingrese el numero de cliente que desea modificar" << endl;
    cin >> numCliente;
    file.modificarRegistro(numCliente);
}

void borrarCliente()
{
    system("cls");
    ArchivoCliente file;
    int numCliente;

    cout << "Ingrese el numero de cliente que desea borrar" << endl;
    cin >> numCliente;
    file.borrarCliente(numCliente);
}

#endif // MENUCLIENTES_H_INCLUDED
