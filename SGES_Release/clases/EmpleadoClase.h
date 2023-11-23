#ifndef EMPLEADOCLASE_H_INCLUDED
#define EMPLEADOCLASE_H_INCLUDED

#include <cstring>

class Empleado;

class Empleado
{
private:
    int _codigoEmpleado;
    char _nombre[30];
    char _apellido[30];
    int _edad;
    char _telefono[40];
    int _DNI;
    float _sueldo;
    char _cargo[30];
    float _totalRec = 0;
    bool _estado;

public:
    // sets
    void setCodigoEmpleado(int e) { _codigoEmpleado = e; }
    void setNombre(const char *n) { strcpy(_nombre, n); }
    void setApellido(const char *a) { strcpy(_apellido, a); }
    void setEdad(int ed) { _edad = ed; }
    void setDNI(int d) { _DNI = d; }
    void setSueldo(float s) { _sueldo = s; }
    void setCargo(const char *c) { strcpy(_cargo, c); }
    void setEstado(bool e) { _estado = e; }
    void setTotalRecaudado(float r) { _totalRec = r; }
    // gets
    int getCodigoEmp() { return _codigoEmpleado; }
    bool getEstado() { return _estado; }
    const char *getCargo() { return _cargo; }
    const char *getApellido() { return _apellido; }
    float getSueldo() { return _sueldo; }
    float getTotalRecaudado() { return _totalRec; }
    int getEdad() { return _edad; }
    // Metodos
    bool cargar()
    {
        // cEmpleado es autoincremental
        cout << "INGRESE NOMBRE: " << endl;
        cin >> _nombre;
        cout << "INGRESE APELLIDO: " << endl;
        cin >> _apellido;
        cout << "INGRESE EDAD: " << endl;
        cin >> _edad;
        if (_edad < 0)
        {
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "LA EDAD NO PUEDE SER NEGATIVA" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE N. TELEFONO: " << endl;
        cargarCadena(_telefono, 39);
        if (_telefono[0] < 0)
        {
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "EL TELEFONO NO PUEDE SER NEGATIVO" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE DNI: " << endl;
        cin >> _DNI;
        if (_DNI < 0)
        {
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "EL DNI NO PUEDE SER NEGATIVO" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE SUELDO: " << endl;
        cin >> _sueldo;
        if (_sueldo < 0)
        {
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "EL SUELDO NO PUEDE SER NEGATIVO" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE NOMBRE DEL CARGO" << endl;
        cargarCadena(_cargo, 30);
        /* _estado = true; */ // el setEstado(true) ya se hace en el agregarRegistro() de ArchivoEmpleado
        /* _totalRec = 0; */
        return true;
    }
    void mostrar()
    {
        if (_estado == false)
        {
            return;
        } // si el estado es falso no muestra nada
        cout << endl;
        cout << "CODIGO EMPLEADO: " << _codigoEmpleado << endl;
        cout << "NOMBRE: " << _nombre << endl;
        cout << "APELLIDO: " << _apellido << endl;
        cout << "EDAD: " << _edad << endl;
        cout << "TELEFONO: " << _telefono << endl;
        cout << "DNI: " << _DNI << endl;
        cout << "SUELDO: " << _sueldo << endl;
        cout << "TOTAL RECAUDADO: " << _totalRec << endl;
        cout << "CARGO: " << _cargo << endl;
        cout << endl;
        divisorSimple();
    }
};

class ArchivoEmpleado
{
private:
    char nombre[30] = "empleados.dat";

public:
    void setArchivoEmpleados(const char *e)
    {
        strcpy(nombre, e);
    }

    int contarRegistros()
    {
        FILE *p;
        int cantRegistros;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return 0;
        }
        fseek(p, 0, SEEK_END);
        cantRegistros = ftell(p) / sizeof(Empleado);
        fclose(p);
        return cantRegistros;
    }

    int buscarCodEmp(int codEmp)
    {
        FILE *p;
        Empleado empleadoX;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&empleadoX, sizeof(Empleado), 1, p) == 1)
        {
            if (empleadoX.getCodigoEmp() == codEmp)
            {
                return 1;
                fclose(p);
            }
        }
        fclose(p);
        return -1;
    }

    int buscarUltimoCodigo()
    {
        FILE *p;
        Empleado empleadoX;
        int codigo = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        while (fread(&empleadoX, sizeof(Empleado), 1, p) == 1)
        {
            codigo = empleadoX.getCodigoEmp();
        }
        fclose(p);
        return codigo;
    }

    bool existeEmpleado(int codEmp)
    {
        FILE *p;
        Empleado empleadoX;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&empleadoX, sizeof(Empleado), 1, p) == 1)
        {
            if (empleadoX.getCodigoEmp() == codEmp && empleadoX.getEstado() == true)
            {
                fclose(p);
                return true;
            }
        }
        fclose(p);
        return false;
    }

    bool esPlayero(int codEmp)
    {
        FILE *p;
        Empleado empleadoX;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&empleadoX, sizeof(Empleado), 1, p) == 1)
        {
            if (empleadoX.getCodigoEmp() == codEmp && empleadoX.getEstado() == true)
            {
                if (strcmp(empleadoX.getCargo(), "Playero") == 0)
                {
                    fclose(p);
                    return true;
                }
            }
        }
        fclose(p);
        return false;
    }

    int agregarRegistro(Empleado empleadoX)
    {
        FILE *p;
        p = fopen(nombre, "ab");
        if (p == NULL)
        {
            return -1;
        }
        empleadoX.setEstado(true);
        empleadoX.setCodigoEmpleado(buscarUltimoCodigo() + 1); // codigo de empleado autoincremental
        if (existeEmpleado(empleadoX.getCodigoEmp()))
        {
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "YA EXISTE UN EMPLEADO CON ESE CODIGO" << endl;
            divisorSimple();
            textColor(15, 0);
            fclose(p);
            return -1;
        }

        int escribio = fwrite(&empleadoX, sizeof empleadoX, 1, p);
        fclose(p);
        return escribio;
    }

    int leerRegistro(int codEmp)
    {
        FILE *p;
        Empleado empleadoX;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        int contCodEmp = 0;
        while (fread(&empleadoX, sizeof(Empleado), 1, p) == 1)
        {
            if (empleadoX.getCodigoEmp() == codEmp)
            {
                fseek(p, sizeof empleadoX * contCodEmp, 0);
                fread(&empleadoX, sizeof empleadoX, 1, p);
                empleadoX.mostrar();
                fclose(p);
                return 1;
            }
            contCodEmp++;
        }
        system("cls");
        fclose(p);
        textColor(12, 0);
        divisorSimpleLargo();
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE CODIGO DE EMPLEADO" << endl;
        divisorSimpleLargo();
        textColor(15, 0);
        return -1;
    }

    Empleado leerRegistroEmpleado(int pos)
    {
        Empleado reg;
        reg.setEstado(0);
        FILE *p;
        p = fopen(nombre, "rb");
        if (p == NULL)
            return reg;
        fseek(p, sizeof reg * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    Empleado leerRegistros()
    {
        FILE *p;
        Empleado empleadoX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&empleadoX, sizeof empleadoX, 1, p) == 1)
        {
            fseek(p, sizeof empleadoX * pos, 0);
            fread(&empleadoX, sizeof empleadoX, 1, p);
            empleadoX.mostrar();
            pos++;
        }
        fclose(p);
        return empleadoX;
    }

    int modificarRegistro(int codEmp)
    {
        FILE *p;
        Empleado empleadoX;
        p = fopen(nombre, "rb+");
        if (p == NULL)
            exit(1);
        int contCodEmp = 0;
        while (fread(&empleadoX, sizeof(Empleado), 1, p) == 1)
        {
            if (empleadoX.getCodigoEmp() == codEmp)
            {
                fseek(p, sizeof empleadoX * contCodEmp, 0);
                fread(&empleadoX, sizeof(Empleado), 1, p);
                empleadoX.cargar();
                cout << "INGRESE RECAUDACION TOTAL DEL EMPLEADO: " << endl;
                float nuevaRecaudacion;
                cin >> nuevaRecaudacion;
                empleadoX.setTotalRecaudado(nuevaRecaudacion);
                fseek(p, sizeof empleadoX * contCodEmp, 0);
                int escribio = fwrite(&empleadoX, sizeof empleadoX, 1, p);
                fclose(p);
                if (escribio)
                {
                    system("cls");
                    textColor(10, 0);
                    divisorSimple();
                    cout << "SE MODIFICO EL EMPLEADO EXITOSAMENTE :)" << endl;
                    divisorSimple();
                    textColor(15, 0);
                    return escribio;
                }
                else
                {
                    system("cls");
                    textColor(12, 0);
                    divisorSimple();
                    cout << "NO SE PUDO MODIFICAR EL EMPLEADO :(" << endl;
                    divisorSimple();
                    textColor(15, 0);
                    return escribio;
                }
            }
            contCodEmp++;
        }
        system("cls");
        fclose(p);
        textColor(12, 0);
        divisorSimpleLargo();
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE CODIGO DE EMPLEADO" << endl;
        divisorSimpleLargo();
        textColor(15, 0);
        return -1;
    }

    // baja logica estado = false
    int borrarEmpleado(int codEmp)
    {
        FILE *p;
        Empleado empleadoX;
        p = fopen(nombre, "rb+");
        if (p == NULL)
            exit(1);
        int contCodEmp = 0;
        while (fread(&empleadoX, sizeof(Empleado), 1, p) == 1)
        {
            if (empleadoX.getCodigoEmp() == codEmp)
            {
                empleadoX.setEstado(false);
                fseek(p, sizeof empleadoX * contCodEmp, 0);
                int escribio = fwrite(&empleadoX, sizeof empleadoX, 1, p);
                fclose(p);
                if (escribio == 1)
                {
                    system("cls");
                    textColor(10, 0);
                    divisorSimple();
                    cout << "SE DIO DE BAJA EL EMPLEADO EXITOSAMENTE :)" << endl;
                    divisorSimple();
                    textColor(15, 0);
                    return escribio;
                }
                else
                {
                    system("cls");
                    textColor(12, 0);
                    divisorSimple();
                    cout << "NO SE PUDO ELIMINAR EL EMPLEADO :(" << endl;
                    divisorSimple();
                    textColor(15, 0);
                    return escribio;
                }
            }
            contCodEmp++;
        }
        system("cls");
        fclose(p);
        textColor(12, 0);
        divisorSimpleLargo();
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE CODIGO DE EMPLEADO" << endl;
        divisorSimpleLargo();
        textColor(15, 0);
        return -1;
    };

    bool estadisticaEmpleados()
    {
        FILE *p;
        Empleado empleadoX;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            exit(1);
        }
        int cantidadDeEmpleados = 0;
        float promedioEdades = 0;
        float promedioSueldos = 0;
        int codigoEmpleadoConMayorRecaudacion = 0;
        float mayorRecaudacion = 0;
        int codigoEmpleadoConMenorRecaudacion = 0;
        float menorRecaudacion = 0;
        float totalRecaudado = 0;
        bool primerEmpleadoLeido = false;
        while (fread(&empleadoX, sizeof(Empleado), 1, p) == 1)
        {
            if (empleadoX.getEstado() == true)
            {
                if (primerEmpleadoLeido == false)
                {
                    menorRecaudacion = empleadoX.getTotalRecaudado();
                    codigoEmpleadoConMenorRecaudacion = empleadoX.getCodigoEmp();
                    primerEmpleadoLeido = true;
                }
                cantidadDeEmpleados++;
                promedioEdades += empleadoX.getEdad();
                promedioSueldos += empleadoX.getSueldo();
                totalRecaudado += empleadoX.getTotalRecaudado();
                if (empleadoX.getTotalRecaudado() > mayorRecaudacion)
                {
                    mayorRecaudacion = empleadoX.getTotalRecaudado();
                    codigoEmpleadoConMayorRecaudacion = empleadoX.getCodigoEmp();
                }
                if (empleadoX.getTotalRecaudado() < menorRecaudacion)
                {
                    menorRecaudacion = empleadoX.getTotalRecaudado();
                    codigoEmpleadoConMenorRecaudacion = empleadoX.getCodigoEmp();
                }

            }
        }
        fclose(p);
        promedioEdades = promedioEdades / cantidadDeEmpleados;
        promedioSueldos = promedioSueldos / cantidadDeEmpleados;
        // mostrar estadisticas y dibujar recuadro
        int x = 50, y = 1;
        int base = 48, altura = 10;
        if (cantidadDeEmpleados == 0)
        {
            return false;
        }
        if (totalRecaudado > 999)
        {
            base = 49;
        }
        if (totalRecaudado > 9999)
        {
            base = 52;
        }
        textColor(1, 0);
        dibujarRecuadro(base, altura, x - 2, 0); // x-2 para que halla un espacio entre pared y texto
        textColor(15, 0);
        gotoxy(x, y);
        cout << "ESTADISTICAS DE EMPLEADOS" << endl;
        y += 1;
        gotoxy(x, y + 1);
        cout << "CANTIDAD DE EMPLEADOS: " << cantidadDeEmpleados << endl;
        gotoxy(x, y + 2);
        cout << "PROMEDIO DE EDADES: " << promedioEdades << endl;
        gotoxy(x, y + 3);
        cout << "PROMEDIO DE SUELDOS: " << promedioSueldos << endl;
        gotoxy(x, y + 4);
        cout << "CODIGO EMPLEADO CON MAYOR RECAUDACION: " << codigoEmpleadoConMayorRecaudacion << endl;
        gotoxy(x, y + 5);
        cout << "CODIGO EMPLEADO CON MENOR RECAUDACION: " << codigoEmpleadoConMenorRecaudacion << endl;
        gotoxy(x, y + 6);
        textColor(10, 0);
        cout << "TOTAL RECAUDADO POR TODOS LOS EMPLEADOS: " << totalRecaudado << endl;
        textColor(15, 0);
        cout << endl;
        return true;
    }

    void ordenarPorCargoYMostrarlos()
    {
        int cantRegistros = contarRegistros();
        Empleado *vEmpleados = new Empleado[cantRegistros];
        FILE *p;
        p = fopen("empleados.dat", "rb");
        if (p == NULL)
        {
            return;
        }
        fread(vEmpleados, sizeof(Empleado), cantRegistros, p);
        fclose(p);
        Empleado aux;
        for (int i = 0; i < cantRegistros - 1; i++)
        {
            for (int j = 0; j < cantRegistros - i - 1; j++)
            {
                if (strcmp(vEmpleados[j].getCargo(), vEmpleados[j + 1].getCargo()) > 0)
                {
                    aux = vEmpleados[j];
                    vEmpleados[j] = vEmpleados[j + 1];
                    vEmpleados[j + 1] = aux;
                }
            }
        }
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "   EMPLEADOS ORDENADOS POR CARGO: " << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;
        for (int i = 0; i < cantRegistros; i++)
        {
            vEmpleados[i].mostrar();
        }
        delete[] vEmpleados;
        system("pause");
        return;
    };

    void ordenarPorApellidoYMostrarlos()
    {
        int cantRegistros = contarRegistros();
        Empleado *vEmpleados = new Empleado[cantRegistros];
        FILE *p;
        p = fopen("empleados.dat", "rb");
        if (p == NULL)
        {
            return;
        }
        fread(vEmpleados, sizeof(Empleado), cantRegistros, p);
        fclose(p);
        Empleado aux;
        for (int i = 0; i < cantRegistros - 1; i++)
        {
            for (int j = 0; j < cantRegistros - i - 1; j++)
            {
                if (strcmp(vEmpleados[j].getApellido(), vEmpleados[j + 1].getApellido()) > 0)
                {
                    aux = vEmpleados[j];
                    vEmpleados[j] = vEmpleados[j + 1];
                    vEmpleados[j + 1] = aux;
                }
            }
        }
        system("cls");
        textColor(14, 0);
        divisorDoble();
        cout << "   EMPLEADOS ORDENADOS POR APELLIDO: " << endl;
        divisorDoble();
        textColor(15, 0);
        cout << endl;
        for (int i = 0; i < cantRegistros; i++)
        {
            vEmpleados[i].mostrar();
        }
        delete[] vEmpleados;
        system("pause");
        return;
    };

    void incrementarTotalRecaudado(int codEmpleado, float recaudacion)
    {
        FILE *p;
        Empleado empleadoX;
        p = fopen(nombre, "rb+");
        if (p == NULL)
            exit(1);
        int contCodEmp = 0;
        while (fread(&empleadoX, sizeof(Empleado), 1, p) == 1)
        {
            if (empleadoX.getCodigoEmp() == codEmpleado)
            {
                fseek(p, sizeof empleadoX * contCodEmp, 0);
                fread(&empleadoX, sizeof(Empleado), 1, p);
                empleadoX.setTotalRecaudado(empleadoX.getTotalRecaudado() + recaudacion);
                fseek(p, sizeof empleadoX * contCodEmp, 0);
                int escribio = fwrite(&empleadoX, sizeof empleadoX, 1, p);
                fclose(p);
                if (escribio == 1)
                {
                    system("cls");
                    textColor(10, 0);
                    divisorSimpleLargo();
                    cout << "SE INCREMENTO EL TOTAL RECAUDADO DEL EMPLEADO EXITOSAMENTE :)" << endl;
                    divisorSimpleLargo();
                    textColor(15, 0);
                    return;
                }
                else
                {
                    system("cls");
                    textColor(12, 0);
                    divisorSimpleLargo();
                    cout << "NO SE PUDO INCREMENTAR EL TOTAL RECAUDADO DEL EMPLEADO :(" << endl;
                    divisorSimpleLargo();
                    textColor(15, 0);
                    return;
                }
            }
            contCodEmp++;
        }
        system("cls");
        fclose(p);
        textColor(12, 0);
        divisorSimpleLargo();
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE CODIGO DE EMPLEADO" << endl;
        divisorSimpleLargo();
        textColor(15, 0);
        return;
    }

    void decrementarTotalRecaudado(int codEmpleado, float recaudacion)
    {
        FILE *p;
        Empleado empleadoX;
        p = fopen(nombre, "rb+");
        if (p == NULL)
            exit(1);
        int contCodEmp = 0;
        while (fread(&empleadoX, sizeof(Empleado), 1, p) == 1)
        {
            if (empleadoX.getCodigoEmp() == codEmpleado)
            {
                fseek(p, sizeof empleadoX * contCodEmp, 0);
                fread(&empleadoX, sizeof(Empleado), 1, p);
                empleadoX.setTotalRecaudado(empleadoX.getTotalRecaudado() - recaudacion);
                fseek(p, sizeof empleadoX * contCodEmp, 0);
                int escribio = fwrite(&empleadoX, sizeof empleadoX, 1, p);
                fclose(p);
                if (escribio == 1)
                {
                    system("cls");
                    textColor(10, 0);
                    divisorSimpleLargo();
                    cout << "SE DECREMENTO EL TOTAL RECAUDADO DEL EMPLEADO EXITOSAMENTE :)" << endl;
                    divisorSimpleLargo();
                    textColor(15, 0);
                    return;
                }
                else
                {
                    system("cls");
                    textColor(12, 0);
                    divisorSimpleLargo();
                    cout << "NO SE PUDO DECREMENTAR EL TOTAL RECAUDADO DEL EMPLEADO :(" << endl;
                    divisorSimpleLargo();
                    textColor(15, 0);
                    return;
                }
            }
            contCodEmp++;
        }
        system("cls");
        fclose(p);
        textColor(12, 0);
        divisorSimpleLargo();
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE CODIGO DE EMPLEADO" << endl;
        divisorSimpleLargo();
        textColor(15, 0);
        return;
    }
};

#endif // EMPLEADOCLASE_H_INCLUDED
