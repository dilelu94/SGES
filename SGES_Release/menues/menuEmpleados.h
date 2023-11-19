#ifndef MENUEMPLEADOS_H_INCLUDED
#define MENUEMPLEADOS_H_INCLUDED

#include "../clases/EmpleadoClase.h"
void cargarEmpleado();
void BuscarYMostrarEmpleado();
void menuEmpleados();
void mostrarEmpleados();
void modificarEmpleado();
void ordenarEmpleados();
void borrarEmpleado();
void filtrarEmpleadosSueldos();

void menuEmpleados()
{
    int opc;
    while (true)
    {
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "\t    MENU EMPLEADOS" << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;

        cout << "1- Cargar" << endl;
        cout << "2- Buscar Empleado" << endl;
        cout << "3- Mostrar Todos los Empleados" << endl;
        cout << "4- Modificar Empleado" << endl;
        cout << "5- Borrar Empleado" << endl;
        cout << "6- Ordenar Empleados" << endl;
        cout << endl;
        divisorSimple();
        cout << "0- Volver al menu principal" << endl;
        divisorSimple();
        cout << "SELECCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cargarEmpleado();
            break;
        case 2:
            BuscarYMostrarEmpleado();
            break;
        case 3:
            system("cls");
            textColor(14, 0);
            divisorDoble();
            cout << "\t LISTADO DE EMPLEADOS: " << endl;
            divisorDoble();
            textColor(15, 0);

            mostrarEmpleados();
            break;
        case 4:
            modificarEmpleado();
            break;
        case 5:
            borrarEmpleado();
            break;
        case 6:
            ordenarEmpleados();
            break;
        case 0:
            return;
            break;
        }
        system("pause>nul");
    }
}

void cargarEmpleado()
{
    system("cls");
    Empleado empleadoNuevo;
    ArchivoEmpleado archivo;

    if (empleadoNuevo.cargar())
    {
        archivo.agregarRegistro(empleadoNuevo);
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

void BuscarYMostrarEmpleado()
{
    system("cls");
    ArchivoEmpleado archivo;
    int codEmp;

    cout << "Ingrese el codigo de empleado que desea buscar" << endl;
    cin >> codEmp;
    system("cls");
    textColor(14, 0);
    divisorDoble();
    cout << "\t EMPLEADO ENCONTRADO:" << endl;
    divisorDoble();
    textColor(15, 0);

    archivo.leerRegistro(codEmp);
}

void mostrarEmpleados()
{
    ArchivoEmpleado archivo;

    archivo.leerRegistros();
    archivo.estadisticaEmpleados();
}

void modificarEmpleado()
{
    system("cls");
    ArchivoEmpleado archivo;
    int codEmp;

    cout << "Ingrese el codigo de empleado que desea modificar" << endl;
    cin >> codEmp;
    archivo.modificarRegistro(codEmp);
}

void ordenarEmpleados()
{
    system("cls");
    ArchivoEmpleado archivo;
    int opc;
    textColor(14, 0);
    divisorDoble();
    cout << "\t    ORDENAR POR: " << endl;
    divisorDoble();
    textColor(15, 0);
    cout << endl;

    cout << "1- Cargo" << endl;
    cout << "2- Apellido" << endl;
    cout << "3- Filtrar Empleados por Sueldo Maximo" << endl;

    cout << endl;
    divisorSimple();
    cout << "0- Volver al menu empleados" << endl;
    divisorSimple();
    cout << "SELECCION: ";
    cin >> opc;
    switch (opc)
    {
    case 1:
        archivo.ordenarPorCargoYMostrarlos();
        break;
    case 2:
        archivo.ordenarPorApellidoYMostrarlos();
        break;
    case 3:
        filtrarEmpleadosSueldos();
        break;
    case 0:
        menuEmpleados();
        break;
    }
}

void borrarEmpleado()
{
    system("cls");
    ArchivoEmpleado archivo;
    int codEmp;

    cout << "Ingrese el codigo de empleado que desea borrar" << endl;
    cin >> codEmp;
    archivo.borrarEmpleado(codEmp);
}

void cargarVector(Empleado *v, int tam){
    ArchivoEmpleado archi;
    Empleado reg;

    for(int i=0;i<tam;i++){
        reg=archi.leerRegistroEmpleado(i);
        v[i]=reg;
    }
}

void mostrarVector(Empleado *v, int tam, float sueldo){
    for(int i=0;i<tam;i++){
        if(v[i].getSueldo()<=sueldo){
            v[i].mostrar();
        }
    }
}

void filtrarEmpleadosSueldos(){
    system("cls");
    ArchivoEmpleado archi;
    int tam=archi.contarRegistros();
    int sueldo;

    Empleado *vec;
    vec = new Empleado[tam];
    if(vec==NULL){exit(1);}

    cargarVector(vec, tam);

    cout<<"INGRESE EL LIMITE DE SUELDO POR LA QUE SE ORDENARAN LOS EMPLEADOS: ";
    cin>>sueldo;

    mostrarVector(vec, tam, sueldo);


    delete vec;
}

#endif // MENUEMPLEADOS_H_INCLUDED
