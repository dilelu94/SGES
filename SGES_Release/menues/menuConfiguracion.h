#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

#include "../clases/configuracion.h"
void menuCopiasDeSeguridad();
void menuRestauracion();
/// seprador----------
void backupEmpleados();
void restaurarEmpleados();
/// seprador----------
void backupCombustibles();
void restaurarCombustibles();
/// seprador----------
void backupCargaCombustibles();
void restaurarCargaCombustibles();
/// seprador----------
void backupTipoServicio();
void restaurarTipoServicio();
/// seprador----------
void backupVentaServicio();
void restaurarVentaServicio();
/// seprador----------
void backupStock();
void restaurarStock();
/// seprador----------
void backupVentaKiosco();
void restaurarVentaKiosco();
/// seprador----------
void backupCliente();
void restaurarCliente();
/// seprador----------

void menuConfiguracion()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "    MENU TIPOS DE CONFIGURACION" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;
        cout << "1- Crear Copias de Seguridad" << endl;
        cout << "2- Restaurar Copias de Seguridad" << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            menuCopiasDeSeguridad();
            break;
        case 2:
            menuRestauracion();
            break;
        case 0:
            return;
            break;
        default:
            cout << "Opcion incorrecta, vuelva a intentar" << endl;
            system("pause");
            break;
        }
        system("pause>nul");
    }
}

void menuCopiasDeSeguridad()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t COPIAS DE SEGURIDAD" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;
        cout << "1- Copia de seguridad Empleados" << endl;
        cout << "2- Copia de seguridad Combustible" << endl;
        cout << "3- Copia de seguridad Cargas de Combustible" << endl;
        cout << "4- Copia de seguridad Tipo de Servicios" << endl;
        cout << "5- Copia de seguridad Ventas de Servicio" << endl;
        cout << "6- Copia de seguridad Stock" << endl;
        cout << "7- Copia de seguridad Venta de Kiosco" << endl;
        cout << "8- Copia de seguridad Clientes" << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            backupEmpleados();
            break;
        case 2:
            backupCombustibles();
            break;
        case 3:
            backupCargaCombustibles();
            break;
        case 4:
            backupTipoServicio();
            break;
        case 5:
            backupVentaServicio();
            break;
        case 6:
            backupStock();
            break;
        case 7:
            backupVentaKiosco();
            break;
        case 8:
            backupCliente();
            break;
        case 0:
            return;
            break;
        default:
            cout << "Opcion incorrecta, vuelva a intentar" << endl;
            system("pause");
            break;
        }
        system("pause>nul");
    }
}

void menuRestauracion()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t RESTAURAR ARCHIVOS" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;
        cout << "1- Restaurar archivo Empleados" << endl;
        cout << "2- Restaurar archivo Combustible" << endl;
        cout << "3- Restaurar archivo Cargas de Combustible" << endl;
        cout << "4- Restaurar archivo Tipo de Servicios" << endl;
        cout << "5- Restaurar archivo Ventas de Servicio" << endl;
        cout << "6- Restaurar archivo Stock" << endl;
        cout << "7- Restaurar archivo Venta de Kiosco" << endl;
        cout << "8- Restaurar archivo Clientes" << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            restaurarEmpleados();
            break;
        case 2:
            restaurarCombustibles();
            break;
        case 3:
            restaurarCargaCombustibles();
            break;
        case 4:
            restaurarTipoServicio();
            break;
        case 5:
            restaurarVentaServicio();
            break;
        case 6:
            restaurarStock();
            break;
        case 7:
            restaurarVentaKiosco();
            break;
        case 8:
            restaurarCliente();
            break;
        case 0:
            return;
            break;
        default:
            cout << "Opcion incorrecta, vuelva a intentar" << endl;
            system("pause");
            break;
        }
        system("pause>nul");
    }
}

void backupEmpleados()
{
    ConfiguracionEmpleados archi("backupEmpleados.bkp");
    archi.backupEmpleados();
}
void restaurarEmpleados()
{
    ConfiguracionEmpleados archi("backupEmpleados.bkp");
    archi.restaurarEmpleados();
}

/// Separador----------------------------

void backupCombustibles()
{
    ConfiguracionCombustible archi("backupCombustibles.bkp");
    archi.backupCombustible();
}
void restaurarCombustibles()
{
    ConfiguracionCombustible archi("backupCombustibles.bkp");
    archi.restaurarCombustibles();
}

/// Separador----------------------------

void backupCargaCombustibles()
{
    ConfiguracionCargaCombustible archi("backupCargaCombustibles.bkp");
    archi.backupCargaCombustible();
}
void restaurarCargaCombustibles()
{
    ConfiguracionCargaCombustible archi("backupCargaCombustibles.bkp");
    archi.restaurarCargaCombustibles();
}

/// Separador----------------------------

void backupTipoServicio()
{
    ConfiguracionTipoServicio archi("backupTipoServicio.bkp");
    archi.backupTipoServicio();
}
void restaurarTipoServicio()
{
    ConfiguracionTipoServicio archi("backupTipoServicio.bkp");
    archi.restaurarTipoServicio();
}

/// Separador----------------------------

void backupVentaServicio()
{
    ConfiguracionVentaServicio archi("backupVentaServicio.bkp");
    archi.backupVentaDeServicio();
}
void restaurarVentaServicio()
{
    ConfiguracionVentaServicio archi("backupVentaServicio.bkp");
    archi.restaurarVentaDeServicio();
}

/// Separador----------------------------

void backupStock()
{
    ConfiguracionStock archi("backupStockList.bkp");
    archi.backupStock();
}
void restaurarStock()
{
    ConfiguracionStock archi("backupStockList.bkp");
    archi.restaurarStock();
}

/// Separador----------------------------

void backupVentaKiosco()
{
    ConfiguracionVentaKiosco archi("backupVentaKiosco.bkp");
    archi.backupVentaKiosco();
}
void restaurarVentaKiosco()
{
    ConfiguracionVentaKiosco archi("backupVentaKiosco.bkp");
    archi.restaurarVentaKiosco();
}

/// Separador----------------------------

void backupCliente()
{
    ConfiguracionClientes archi("backupClietes.bkp");
    archi.backupClientes();
}
void restaurarCliente()
{
    ConfiguracionClientes archi("backupClietes.bkp");
    archi.restaurarClientes();
}

#endif // MENUCONFIGURACION_H_INCLUDED
