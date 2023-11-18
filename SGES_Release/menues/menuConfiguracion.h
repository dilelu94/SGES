#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

#include "../clases/configuracion.h"
void backupEmpleados();
void restaurarEmpleados();
///seprador----------
void backupCombustibles();
void restaurarCombustibles();
///seprador----------
void backupCargaCombustibles();
void restaurarCargaCombustibles();
///seprador----------
void backupTipoServicio();
void restaurarTipoServicio();
///seprador----------
void backupVentaServicio();
void restaurarVentaServicio();
///seprador----------
void backupStock();
void restaurarStock();
///seprador----------
void backupVentaKiosco();
void restaurarVentaKiosco();
///seprador----------
void backupCliente();
void restaurarCliente();
///seprador----------





void menuConfiguracion()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t MENU TIPOS DE CONFIGURACION" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;

        cout << "1- Copia de seguridad Empleados" << endl;
        cout << "2- Restaurar archivo Empleados" << endl;
        cout << "3- Copia de seguridad Combustible" << endl;
        cout << "4- Restaurar archivo Combustible" << endl;
        cout << "5- Copia de seguridad Cargas de Combustible" << endl;
        cout << "6- Restaurar archivo Cargas de Combustible" << endl;
        cout << "7- Copia de seguridad Tipo de Servicios" << endl;
        cout << "8- Restaurar archivo Tipo de Servicios" << endl;
        cout << "9- Copia de seguridad Ventas de Servicio" << endl;
        cout << "10- Restaurar archivo Ventas de Servicio" << endl;
        cout << "11- Copia de seguridad Stock" << endl;
        cout << "12- Restaurar archivo Stock" << endl;
        cout << "13- Copia de seguridad Venta de Kiosco" << endl;
        cout << "14- Restaurar archivo Venta de Kiosco" << endl;
        cout << "15- Copia de seguridad Clientes" << endl;
        cout << "16- Restaurar archivo Clientes" << endl;
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
                restaurarEmpleados();
            break;
        case 3:
                backupCombustibles();
            break;
        case 4:
                restaurarCombustibles();
            break;
        case 5:
                backupCargaCombustibles();
            break;
        case 6:
                restaurarCargaCombustibles();
            break;
        case 7:
                backupTipoServicio();
            break;
        case 8:
                restaurarTipoServicio();
            break;
        case 9:
                backupVentaServicio();
            break;
        case 10:
                restaurarVentaServicio();
            break;
        case 11:
                backupStock();
            break;
        case 12:
                restaurarStock();
            break;
        case 13:
                backupVentaKiosco();
            break;
        case 14:
                restaurarVentaKiosco();
            break;
        case 15:
                backupCliente();
            break;
        case 16:
                restaurarCliente();
            break;
        case 0:
            return;
            break;
        }
        system("pause>nul");
    }
}

void backupEmpleados(){
    ConfiguracionEmpleados archi("backupEmpleados.bkp");
    archi.backupEmpleados();
}
void restaurarEmpleados(){
    ConfiguracionEmpleados archi("backupEmpleados.bkp");
    archi.restaurarEmpleados();
}

///Separador----------------------------

void backupCombustibles(){
    ConfiguracionCombustible archi("backupCombustibles.bkp");
    archi.backupCombustible();
}
void restaurarCombustibles(){
    ConfiguracionCombustible archi("backupCombustibles.bkp");
    archi.restaurarCombustibles();
}

///Separador----------------------------

void backupCargaCombustibles(){
    ConfiguracionCargaCombustible archi("backupCargaCombustibles.bkp");
    archi.backupCargaCombustible();
}
void restaurarCargaCombustibles(){
    ConfiguracionCargaCombustible archi("backupCargaCombustibles.bkp");
    archi.restaurarCargaCombustibles();
}

///Separador----------------------------

void backupTipoServicio(){
    ConfiguracionTipoServicio archi("backupTipoServicio.bkp");
    archi.backupTipoServicio();
}
void restaurarTipoServicio(){
    ConfiguracionTipoServicio archi("backupTipoServicio.bkp");
    archi.restaurarTipoServicio();
}

///Separador----------------------------

void backupVentaServicio(){
    ConfiguracionVentaServicio archi("backupVentaServicio.bkp");
    archi.backupVentaDeServicio();
}
void restaurarVentaServicio(){
    ConfiguracionVentaServicio archi("backupVentaServicio.bkp");
    archi.restaurarVentaDeServicio();
}

///Separador----------------------------

void backupStock(){
    ConfiguracionStock  archi("backupStockList.bkp");
    archi.backupStock();
}
void restaurarStock(){
    ConfiguracionStock archi("backupStockList.bkp");
    archi.restaurarStock();
}

///Separador----------------------------

void backupVentaKiosco(){
    ConfiguracionVentaKiosco  archi("backupVentaKiosco.bkp");
    archi.backupVentaKiosco();
}
void restaurarVentaKiosco(){
    ConfiguracionVentaKiosco archi("backupVentaKiosco.bkp");
    archi.restaurarVentaKiosco();
}

///Separador----------------------------

void backupCliente(){
    ConfiguracionClientes  archi("backupClietes.bkp");
    archi.backupClientes();
}
void restaurarCliente(){
    ConfiguracionClientes archi("backupClietes.bkp");
    archi.restaurarClientes();
}


#endif // MENUCONFIGURACION_H_INCLUDED
