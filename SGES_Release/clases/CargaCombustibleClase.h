#ifndef CARGACOMBUSTIBLECLASE_H_INCLUDED
#define CARGACOMBUSTIBLECLASE_H_INCLUDED

class CargaCombustible;

bool existeEmpleado(int);    // estos ya no se usan
bool existeCombustible(int); // estos ya no se usan

class CargaCombustible
{
private:
    int _numVentaCombustible; // autoincremental
    int _codigoCombustible;
    int _medioDePago;
    float _cantidadCargada;
    int _horaCarga;
    int _empleado;
    bool _estado;

public:
    // sets
    void setNumVenta(int n) { _numVentaCombustible = n; }
    void setEstado(bool e) { _estado = e; }
    // gets
    int getNumVenta() { return _numVentaCombustible; }
    bool getEstado() { return _estado; }
    int getNumVentaCombustible() { return _numVentaCombustible; }
    float getCantidadCargada() { return _cantidadCargada; }
    int getEmpleado() { return _empleado; }
    int getCodigoCombustible() { return _codigoCombustible; }
    // metodos
    bool cargar()
    {
        // nVenta es autoincremental
        cout << "INGRESE EL CODIGO DE COMBUSTIBLE: " << endl;
        cin >> _codigoCombustible;
        ArchivoCombustible archivoCombustible;
        if (!archivoCombustible.existeCombustible(_codigoCombustible))
        {
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "COMBUSTIBLE INEXISTENTE, VUELVA A INTENTAR." << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE MEDIO DE PAGO(1:Efectivo, 2:Credito, 3:Debito): " << endl;
        cin >> _medioDePago;
        switch (_medioDePago)
        {
        case 1:
            _medioDePago = 1;
            break;
        case 2:
            _medioDePago = 2;
            break;
        case 3:
            _medioDePago = 3;
            break;
        default:
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "MEDIO DE PAGO INCORRECTO" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
            break;
        }
        cout << "INGRESE CANTIDAD DE LITROS CARGADA: " << endl;
        cin >> _cantidadCargada;
        if (_cantidadCargada <= 0)
        {
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "CANTIDAD INCORRECTA" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE HORA DE CARGA: " << endl;
        cin >> _horaCarga;
        if (_horaCarga < 0 || _horaCarga > 23)
        {
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "HORA INCORRECTA" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE EMPLEADO QUE REALIZO LA CARGA: " << endl;
        cin >> _empleado;
        ArchivoEmpleado archivoEmpleado;
        if (!archivoEmpleado.existeEmpleado(_empleado))
        {
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "EMPLEADO INEXISTENTE, VUELVA A INTENTAR." << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        _estado = true;
        return true;
    }
    void mostrar()
    {
        if (_estado == false)
        {
            return;
        } // si el estado es falso no muestra nada
        cout << endl;
        cout << "NUMERO DE VENTA: " << _numVentaCombustible << endl;
        cout << "CODIGO DE COMBUSTIBLE: " << _codigoCombustible << endl;
        cout << "MEDIO DE PAGO: ";
        if (_medioDePago == 1)
        {
            cout << "Efectivo" << endl;
        }
        else if (_medioDePago == 2)
        {
            cout << "Credito" << endl;
        }
        else
        {
            cout << "Debito" << endl;
        }

        cout << "CANTIDAD CARGADA: " << _cantidadCargada << endl;
        cout << "HORA DE CARGA: " << _horaCarga << endl;
        cout << "EMPLEADO QUE REALIZO LA CARGA: " << _empleado << endl;
        cout << endl;
        divisorSimple();
    }
};

class ArchivoCargaCombustible
{
private:
    char nombre[30] = "cargasCombustible.dat";

public:
    void setArchivoCargaCombustible(const char *c)
    {
        strcpy(nombre, c);
    }

    int buscarNumVenta(int codVent)
    {
        FILE *p;
        CargaCombustible combustibleX;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&combustibleX, sizeof(CargaCombustible), 1, p) == 1)
        {
            if (combustibleX.getNumVenta() == codVent)
            {
                return 1;
                fclose(p);
            }
        }
        fclose(p);
        return -1;
    }

    buscarUltimoCodigo()
    {
        FILE *p;
        CargaCombustible combustibleX;
        int codigo = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        while (fread(&combustibleX, sizeof(CargaCombustible), 1, p) == 1)
        {
            codigo = combustibleX.getNumVenta();
        }
        fclose(p);
        return codigo;
    }

    bool existeNumeroDeVentaCombustible(int codVent)
    {
        FILE *p;
        CargaCombustible combustibleX;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&combustibleX, sizeof(CargaCombustible), 1, p) == 1)
        {
            if (combustibleX.getNumVenta() == codVent)
            {
                fclose(p);
                return true;
            }
        }
        fclose(p);
        return false;
    }

    bool agregarRegistro(CargaCombustible combustibleX)
    {
        FILE *p;
        p = fopen(nombre, "ab");
        if (p == NULL)
        {
            return false;
        }
        combustibleX.setEstado(true);
        combustibleX.setNumVenta(buscarUltimoCodigo() + 1); // n de venta autoincremental
        ///sumarle al empleado lo que gano por la venta de combustible
        ArchivoEmpleado archivoEmpleado;
        ArchivoCombustible archivoCombustible;
        float precioXLitro = archivoCombustible.devolverPrecio(combustibleX.getCodigoCombustible());
        float recaudacion = precioXLitro * combustibleX.getCantidadCargada();
        archivoEmpleado.incrementarTotalRecaudado(combustibleX.getEmpleado(), recaudacion);
        int escribio = fwrite(&combustibleX, sizeof(CargaCombustible), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE CARGO LA VENTA DE COMBUSTIBLE. :)" << endl;
            divisorSimple();
            textColor(15, 0);
            return true;
        }
        else
        {
            return false;
        }
    }

    int leerRegistro(int codVent)
    {
        FILE *p;
        CargaCombustible combustibleX;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            exit(1);
        }
        int contCodComb = 0;
        while (fread(&combustibleX, sizeof(CargaCombustible), 1, p) == 1)
        {
            if (combustibleX.getNumVenta() == codVent)
            {
                fseek(p, sizeof combustibleX * contCodComb, 0);
                fread(&combustibleX, sizeof combustibleX, 1, p);
                combustibleX.mostrar();
                fclose(p);
                return 1;
            }
            contCodComb++;
        }
        fclose(p);
        textColor(12, 0);
        divisorSimpleLargo();
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE CODIGO DE COMBUSTIBLE" << endl;
        divisorSimpleLargo();
        textColor(15, 0);
        return -1;
    }

    CargaCombustible leerRegistros()
    {
        FILE *p;
        CargaCombustible combustibleX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&combustibleX, sizeof combustibleX, 1, p) == 1)
        {
            fseek(p, sizeof combustibleX * pos, 0);
            fread(&combustibleX, sizeof combustibleX, 1, p);
            combustibleX.mostrar();
            pos++;
        }
        fclose(p);
        return combustibleX;
    }

    int modificarRegistro(int codVent)
    {
        FILE *p;
        CargaCombustible combustibleX;
        p = fopen(nombre, "rb+");
        if (p == NULL)
            exit(1);
        int contCodComb = 0;
        while (fread(&combustibleX, sizeof(CargaCombustible), 1, p) == 1)
        {
            if (combustibleX.getNumVenta() == codVent)
            {
                fseek(p, sizeof combustibleX * contCodComb, 0);
                fread(&combustibleX, sizeof(CargaCombustible), 1, p);
                ///Borrar el ingreso viejo del empleado
                ArchivoEmpleado archivoEmpleado;
                ArchivoCombustible archivoCombustible;
                float precioXLitro = archivoCombustible.devolverPrecio(combustibleX.getCodigoCombustible());
                float recaudacionEliminar = precioXLitro * combustibleX.getCantidadCargada();
                archivoEmpleado.decrementarTotalRecaudado(combustibleX.getEmpleado(), recaudacionEliminar);

                combustibleX.cargar();

                ///Cargar el ingreso nuevo del empleado
                precioXLitro = archivoCombustible.devolverPrecio(combustibleX.getCodigoCombustible());
                float recaudacion = precioXLitro * combustibleX.getCantidadCargada();
                archivoEmpleado.incrementarTotalRecaudado(combustibleX.getEmpleado(), recaudacion);

                fseek(p, sizeof combustibleX * contCodComb, 0);
                int escribio = fwrite(&combustibleX, sizeof combustibleX, 1, p);
                fclose(p);
                if (escribio)
                {
                    system("cls");
                    textColor(10, 0);
                    divisorSimple();
                    cout << "SE MODIFICO LA CARGA DE COMBUSTIBLE. :)" << endl;
                    divisorSimple();
                    textColor(15, 0);
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            contCodComb++;
        }
        fclose(p);
        system("cls");
        textColor(12, 0);
        divisorSimpleLargo();
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE CODIGO DE COMBUSTIBLE" << endl;
        divisorSimpleLargo();
        textColor(15, 0);
        return -1;
    }

    // baja logica estado = false
    int borrarCargaCombustible(int codVent)
    {
        FILE *p;
        CargaCombustible combustibleX;
        p = fopen(nombre, "rb+");
        if (p == NULL)
            exit(1);
        int contCodComb = 0;
        while (fread(&combustibleX, sizeof(CargaCombustible), 1, p) == 1)
        {
            if (combustibleX.getNumVenta() == codVent)
            {
                combustibleX.setEstado(false);
                fseek(p, sizeof combustibleX * contCodComb, 0);
                if (existeNumeroDeVentaCombustible(codVent))
                {
                    system("cls");
                    textColor(12, 0);
                    divisorSimpleLargo();
                    cout << "YA EXISTE UNA VENTA DE COMBUSTIBLE CON ESE NUMERO" << endl;
                    divisorSimpleLargo();
                    textColor(15, 0);
                    fclose(p);
                    return 1;
                }
                int escribio = fwrite(&combustibleX, sizeof combustibleX, 1, p);
                fclose(p);
                if (escribio == 1)
                {
                    system("cls");
                    textColor(10, 0);
                    divisorSimple();
                    cout << "SE DIO DE BAJA LA CARGA DE COMBUSTIBLE. :)" << endl;
                    divisorSimple();
                    textColor(15, 0);
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            contCodComb++;
        }
        fclose(p);
        system("cls");
        textColor(12, 0);
        divisorSimpleLargo();
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE CODIGO DE COMBUSTIBLE" << endl;
        divisorSimpleLargo();
        textColor(15, 0);
        return -1;
    };
};

bool existeEmpleado(int empleado)
{
    ArchivoEmpleado archi;
    bool x;

    x = archi.existeEmpleado(empleado);
    if (x == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool existeCombustible(int combustible)
{
    ArchivoCombustible archi;
    bool x;

    x = archi.existeCombustible(combustible);
    if (x == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // CARGACOMBUSTIBLECLASE_H_INCLUDED
