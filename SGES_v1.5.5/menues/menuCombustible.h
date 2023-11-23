#ifndef MENUCOMBUSTIBLE_H_INCLUDED
#define MENUCOMBUSTIBLE_H_INCLUDED

#include "../clases/CombustibleClase.h"

void cargarCombustible();
void mostrarCombustible();
void mostrarCombustibles();
void modificarCombustible();
void borrarCombustible();

void menuTiposCombustible()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t MENU TIPOS DE COMBUSTIBLE" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;

        cout << "1- Cargar" << endl;
        cout << "2- Buscar Combustible" << endl;
        cout << "3- Mostrar todos los Combustibles" << endl;
        cout << "4- Modificar Combustible" << endl;
        cout << "5- Borrar Combustible" << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cargarCombustible();
            break;
        case 2:
            mostrarCombustible();
            break;
        case 3:
            system("cls");
            textColor(14, 0);
            divisorDoble();
            cout << "\t LISTADO DE COMBUSTIBLES:" << endl;
            divisorDoble();
            textColor(15, 0);

            mostrarCombustibles();
            break;
        case 4:
            modificarCombustible();
            break;
        case 5:
            borrarCombustible();
            break;
        case 0:
            return;
            break;
        }
        system("pause>nul");
    }
}

void cargarCombustible()
{
    system("cls");
    Combustible nuevoCombustible;
    ArchivoCombustible archivo;

    if (nuevoCombustible.cargar())
    {
        archivo.agregarRegistro(nuevoCombustible);
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

void mostrarCombustible()
{
    system("cls");
    ArchivoCombustible archivo;
    int codCombustible;

    cout << "Ingrese el codigo del combustible que desea buscar" << endl;
    cin >> codCombustible;
    archivo.leerRegistro(codCombustible);
}

void mostrarCombustibles()
{
    ArchivoCombustible archivo;

    archivo.leerRegistros();
}

void modificarCombustible()
{
    system("cls");
    ArchivoCombustible archivo;
    int codCombustible;

    cout << "Ingrese el codigo del combustible que desea modificar" << endl;
    cin >> codCombustible;
    archivo.modificarRegistro(codCombustible);
}

void borrarCombustible()
{
    system("cls");
    ArchivoCombustible archivo;
    int codCombustible;

    cout << "Ingrese el codigo del combustible que desea borrar" << endl;
    cin >> codCombustible;
    archivo.borrarCombustible(codCombustible);
}

#endif // MENUCOMBUSTIBLE_H_INCLUDED
