#ifndef CARGACOMBUSTIBLECLASE_H_INCLUDED
#define CARGACOMBUSTIBLECLASE_H_INCLUDED

class CargaCombustible;

class CargaCombustible
{
private:
    int _numVentaCombustible; // para que la vida sea mas facil
    int _tipoCombustible;
    int _medioDePago;
    float _cantidadCargada;
    int _horaCarga;
    int _empleado;
    bool _estado;

public:
    // sets
    void setEstado(bool e) { _estado = e; }
    // gets
    int getNumVenta() { return _numVentaCombustible; }
    bool getEstado() { return _estado; }
    int getNumVentaCombustible() { return _numVentaCombustible; }
    // metodos
    bool cargar()
    {
        cout << "INGRESE EL NUMERO DE LA VENTA: " << endl;
        cin >> _numVentaCombustible;
        cout << "INGRESE EL TIPO DE COMBUSTIBLE(1:Super, 2:Premium, 3:Gasoil): " << endl;
        cin >> _tipoCombustible;
        switch (_tipoCombustible)
        {
        case 1:
            _tipoCombustible = 1;
            break;
        case 2:
            _tipoCombustible = 2;
            break;
        case 3:
            _tipoCombustible = 3;
            break;
        default:
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "TIPO DE COMBUSTIBLE INCORRECTO" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
            break;
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
        cout << "INGRESE HORA DE CARGA: " << endl;
        cin >> _horaCarga;
        cout << "INGRESE EMPLEADO QUE REALIZO LA CARGA: " << endl;
        cin >> _empleado;
        _estado=true;
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
        cout << "TIPO DE COMBUSTIBLE: ";
        if (_tipoCombustible == 1)
        {
            cout << "Super" << endl;
        }
        else if (_tipoCombustible == 2)
        {
            cout << "Premium" << endl;
        }
        else
        {
            cout << "Gasoil" << endl;
        }
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
            exit(1);
        if (existeNumeroDeVentaCombustible(combustibleX.getNumVentaCombustible()))
        {
            system("cls");
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "YA EXISTE UNA VENTA DE COMBUSTIBLE CON ESE NUMERO" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            fclose(p);
            return false;
        }
        bool escribio = fwrite(&combustibleX, sizeof combustibleX, 1, p);
        fclose(p);
        return escribio;
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
                combustibleX.cargar();
                fseek(p, sizeof combustibleX * contCodComb, 0);
                //si existe cod comb no lo deja modificar
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

#endif // CARGACOMBUSTIBLECLASE_H_INCLUDED
