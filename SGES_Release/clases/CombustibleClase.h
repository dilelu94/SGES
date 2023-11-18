#ifndef COMBUSTIBLECLASE_H_INCLUDED
#define COMBUSTIBLECLASE_H_INCLUDED

class Combustible;

class Combustible
{
private:
    int _codigoCombustible; // para que la vida sea mas facil
    int _tipoCombustible;
    float _precio;
    int _calidad;
    bool _estado; // el estado se tiene que actualizar en el guardado del archivo o pasan cosas feas

public:
    // sets
    void setCodigoCombustible(int e) { _codigoCombustible = e; }
    void setTipoCombustible(int t) { _tipoCombustible = t; }
    void setPrecio(float p) { _precio = p; }
    void setCalidad(int c) { _calidad = c; }
    void setEstado(bool e) { _estado = e; }
    // gets
    int getCodigoCombustible() { return _codigoCombustible; }
    int getTipoCombustible() { return _tipoCombustible; }
    float getPrecio() { return _precio; }
    int getCalidad() { return _calidad; }
    bool getEstado() { return _estado; }
    // Metodos
    bool cargar()
    {
        // codCombustible es autoincremental
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
            system("pause");
            return 0;
            break;
        }
        cout << "INGRESE PRECIO x LITRO: " << endl;
        cin >> _precio;
        cout << "INGRESE CALIDAD(1:Buena, 2:Muy Buena, 3:Normal): " << endl;
        cin >> _calidad;
        switch (_calidad)
        {
        case 1:
            _calidad = 1;
            break;
        case 2:
            _calidad = 2;
            break;
        case 3:
            _calidad = 3;
            break;
        default:
            system("cls");
            textColor(12, 0);
            divisorSimple();
            cout << "CALIDAD INCORRECTA" << endl;
            divisorSimple();
            textColor(15, 0);
            system("pause");
            return 0;
            break;
        }
        return 1;
    }
    void mostrar()
    {
        if (_estado == false)
        {
            return;
        } // si el estado es falso no muestra nada
        cout << endl;
        cout << "ID DE COMBUSTIBLE: " << _codigoCombustible << endl;
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

        cout << "PRECIO x LITRO: " << _precio << endl;
        cout << "CALIDAD: ";
        if (_calidad == 1)
        {
            cout << "Buena" << endl;
        }
        else if (_calidad == 2)
        {
            cout << "Muy Buena" << endl;
        }
        else
        {
            cout << "Normal" << endl;
        }

        cout << endl;
        divisorSimple();
    }
};

class ArchivoCombustible
{
private:
    char nombre[30] = "combustibles.dat";

public:
    void setArchivoCombustible(const char *e)
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
        cantRegistros = ftell(p) / sizeof(Combustible);
        fclose(p);
        return cantRegistros;
    }

    int buscarPosicion(int codigoCombustible)
    {
        FILE *p;
        Combustible combustibleX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return -1;
        }
        while (fread(&combustibleX, sizeof(Combustible), 1, p) == 1)
        {
            if (combustibleX.getCodigoCombustible() == codigoCombustible)
            {
                fclose(p);
                return pos;
            }
            pos++;
        }
        fclose(p);
        textColor(12, 0);
        divisorSimple();
        cout << "NO SE ENCONTRO COMBUSTIBLE CON ESE CODIGO" << endl;
        divisorSimple();
        textColor(15, 0);

        return -1;
    }

    int buscarUltimoCodigo()
    {
        FILE *p;
        Combustible combustibleX;
        int codigo = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        while (fread(&combustibleX, sizeof(Combustible), 1, p) == 1)
        {
            codigo = combustibleX.getCodigoCombustible();
        }
        fclose(p);
        return codigo;
    }

    bool existeCombustible(int codigoCombustible)
    {
        FILE *p;
        Combustible combustibleX;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return false;
        }
        while (fread(&combustibleX, sizeof(Combustible), 1, p) == 1)
        {
            if (combustibleX.getCodigoCombustible() == codigoCombustible && combustibleX.getEstado() == true)
            {
                fclose(p);
                return true;
            }
        }
        fclose(p);
        return false;
    }

    int agregarRegistro(Combustible combustibleX)
    {
        FILE *p;
        p = fopen(nombre, "ab");
        if (p == NULL)
        {
            return -1;
        }
        combustibleX.setEstado(true);
        combustibleX.setCodigoCombustible(buscarUltimoCodigo() + 1); // codigo de combustible autoincremental
        int escribio = fwrite(&combustibleX, sizeof(Combustible), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE AGREGO EL COMBUSTIBLE EXITOSAMENTE :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;
    }

    int leerRegistro(int codigoCombustible)
    {
        FILE *p;
        int pos = buscarPosicion(codigoCombustible);
        Combustible combustibleX;
        if (pos == -1)
        {
            return -1;
        }
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(Combustible) * pos, SEEK_SET);
        fread(&combustibleX, sizeof(Combustible), 1, p);
        combustibleX.mostrar();
        fclose(p);
        return 1;
    }

    Combustible leerRegistroObj(int pos)
    {
        Combustible reg;
        FILE *p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return reg;
        }
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }

    Combustible leerRegistros()
    {
        FILE *p;
        Combustible combustibleX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            exit(-1);
        }
        while (fread(&combustibleX, sizeof(Combustible), 1, p) == 1)
        {
            fseek(p, sizeof(Combustible) * pos, SEEK_SET);
            fread(&combustibleX, sizeof(Combustible), 1, p);
            combustibleX.mostrar();
            pos++;
        }
        fclose(p);
        return combustibleX;
    }

    int modificarRegistro(int codigoCombustible)
    {
        FILE *p;
        int pos = buscarPosicion(codigoCombustible);
        Combustible combustibleX;
        if (pos == -1)
        {
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }
        // usar combustibleX.cargar() para modificar los datos
        fseek(p, sizeof(Combustible) * pos, SEEK_SET);
        fread(&combustibleX, sizeof(Combustible), 1, p);
        combustibleX.cargar();
        fseek(p, sizeof(Combustible) * pos, SEEK_SET);
        int escribio = fwrite(&combustibleX, sizeof(Combustible), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE MODIFICO EL COMBUSTIBLE EXITOSAMENTE :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;
    }

    int borrarCombustible(int codigoCombustible)
    {
        FILE *p;
        int pos = buscarPosicion(codigoCombustible);
        Combustible combustibleX;
        if (pos == -1)
        {
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(Combustible) * pos, SEEK_SET);
        fread(&combustibleX, sizeof(Combustible), 1, p);
        combustibleX.setEstado(false);
        fseek(p, sizeof(Combustible) * pos, SEEK_SET);
        fwrite(&combustibleX, sizeof(Combustible), 1, p);
        fclose(p);
        return 1;
    }

    float devolverPrecio(int codCombustible)
    {
        FILE *p;
        Combustible combustibleX;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        while (fread(&combustibleX, sizeof(Combustible), 1, p) == 1)
        {
            if (combustibleX.getCodigoCombustible() == codCombustible)
            {
                fclose(p);
                return combustibleX.getPrecio();
            }
        }
        fclose(p);
        return -1;
    }
};

#endif // COMBUSTIBLECLASE_H_INCLUDED
