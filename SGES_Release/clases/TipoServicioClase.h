#ifndef TIPOSERVICIOCLASE_H_INCLUDED
#define TIPOSERVICIOCLASE_H_INCLUDED

class TipoDeServicio;

class TipoDeServicio
{
private:
    int _servicio; // 1:Cambio de rueda, 2:Cambio de aceite, 3:Inflado de ruedas
    char _descripcion[100]; // ya acepta espacio, cambiar por memoria dinamica quizas?
    float _precio;
    bool _estado;
    int _codigoServicio; // codigo de servicio autoincremental

public:
    // sets
    void setEstado(bool e) { _estado = e; }
    void setCodigoServicio(int cod) { _codigoServicio = cod; }
    // gets
    int getServicio() { return _servicio; }
    int getCodigoServicio() { return _codigoServicio; }
    bool getEstado() { return _estado; }
    // metodos
    bool cargar()
    {
        cout << "INGRESE SERVICIO (1:Cambio de rueda, 2:Cambio de aceite, 3:Inflado de ruedas): " << endl;
        cin >> _servicio;
        if (_servicio < 1 || _servicio > 3)
        {
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "ERROR: VUELVA A INTENTAR E INGRESE UN SERVICIO VALIDO" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE DESCRIPCION (Maximo 99 caracteres): " << endl;
        cargarCadena(_descripcion, 100);
        cout << "INGRESE PRECIO: " << endl;
        cin >> _precio;
        if (_precio <= 0)
        {
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "ERROR: VUELVA A INTENTAR E INGRESE UN PRECIO VALIDO" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            return false;
        }
        /* _estado = true; */ // el setEstado(true) se hace en agregarRegistro() de la clase archivo
        return true; // si llega hasta aca es porque se cargo correctamente y luego se llama a agregarRegistro() en el menuTipoServicios si es true
    }
    void mostrar()
    {
        if (_estado == false)
        {
            return;
        }
        cout << endl;
        cout << "SERVICIO: ";
        if (_servicio == 1)
        {
            cout << "Cambio de rueda" << endl;
        }
        else if (_servicio == 2)
        {
            cout << "Cambio de aceite" << endl;
        }
        else
        {
            cout << "Inflado de ruedas" << endl;
        }

        cout << "DESCRIPCION: " << _descripcion << endl;
        cout << "PRECIO: " << _precio << endl;
        cout << "CODIGO DE SERVICIO: " << _codigoServicio << endl;
        cout << endl;
        divisorSimple();
    }
};

class ArchivoTipoServicio
{
private:
    char nombre[30] = "tipoDeServicios.dat";

public:
    void setArchivoTipoServicio(const char *s)
    {
        strcpy(nombre, s);
    }

    int buscarPosicion(int codServ)
    {
        FILE *p;
        TipoDeServicio servicioX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return -1;
        }
        while (fread(&servicioX, sizeof(servicioX), 1, p) == 1)
        {
            if (servicioX.getCodigoServicio() == codServ && servicioX.getEstado() == true)
            {
                fclose(p);
                return pos;
            }
            pos++;
        }
        fclose(p);
        return -1;
    }

    int buscarUltimoCodigo()
    {
        FILE *p;
        TipoDeServicio servicioX;
        int codigo = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        while (fread(&servicioX, sizeof(servicioX), 1, p) == 1)
        {
            codigo = servicioX.getCodigoServicio();
        }
        fclose(p);
        return codigo;
    }

    int agregarRegistro(TipoDeServicio servicioX)
    {
        FILE *p;
        p = fopen(nombre, "ab");
        if (p == NULL)
        {
            return -1;
        }
        servicioX.setEstado(true);
        servicioX.setCodigoServicio(buscarUltimoCodigo() + 1); // codigo de servicio autoincremental
        int escribio = fwrite(&servicioX, sizeof(TipoDeServicio), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimpleLargo();
            cout << "  SE AGREGO EL TIPO DE SERVICIO EXITOSAMENTE. :)" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
        }
        return escribio;
    }

    int leerRegistro(int codServ)
    {
        FILE *p;
        int pos = buscarPosicion(codServ);
        TipoDeServicio servicioX;
        if (pos == -1)
        {
            textColor(12, 0);
            divisorSimple();
            cout << "NO SE ENCONTRO EL TIPO DE SERVICIO :(" << endl;
            divisorSimple();
            textColor(15, 0);
            return -1;
        }
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(TipoDeServicio) * pos, SEEK_SET);
        fread(&servicioX, sizeof(TipoDeServicio), 1, p);
        servicioX.mostrar();
        fclose(p);
        return 1;
    }

    TipoDeServicio leerRegistros()
    {
        FILE *p;
        TipoDeServicio servicioX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            exit(-1);
        }
        while (fread(&servicioX, sizeof(TipoDeServicio), 1, p) == 1)
        {
            fseek(p, sizeof(TipoDeServicio) * pos, SEEK_SET);
            fread(&servicioX, sizeof(TipoDeServicio), 1, p);
            servicioX.mostrar();
            pos++;
        }
        fclose(p);
        return servicioX;
    }

    int modificarRegistro(int codServ)
    {
        FILE *p;
        int pos = buscarPosicion(codServ);
        TipoDeServicio servicioX;
        if (pos == -1)
        {
            textColor(12, 0);
            divisorSimple();
            cout << "NO SE ENCONTRO EL TIPO DE SERVICIO :(" << endl;
            divisorSimple();
            textColor(15, 0);
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(TipoDeServicio) * pos, SEEK_SET);
        fread(&servicioX, sizeof(TipoDeServicio), 1, p);
        servicioX.cargar();
        fseek(p, sizeof(TipoDeServicio) * pos, SEEK_SET);
        int escribio = fwrite(&servicioX, sizeof(TipoDeServicio), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimpleLargo();
            cout << "SE MODIFICO EL TIPO DE SERVICIO EXITOSAMENTE :)" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
        }
        return escribio;
    }

    int borrarTipoDeServicio(int codServ)
    {
        FILE *p;
        int pos = buscarPosicion(codServ);
        TipoDeServicio servicioX;
        if (pos == -1)
        {
            textColor(12, 0);
            divisorSimple();
            cout << "NO SE ENCONTRO EL TIPO DE SERVICIO :(" << endl;
            divisorSimple();
            textColor(15, 0);
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(TipoDeServicio) * pos, SEEK_SET);
        fread(&servicioX, sizeof(TipoDeServicio), 1, p);
        servicioX.setEstado(false);
        fseek(p, sizeof(TipoDeServicio) * pos, SEEK_SET);
        int escribio = fwrite(&servicioX, sizeof(TipoDeServicio), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimpleLargo();
            cout << "SE DIO DE BAJA EL TIPO DE SERVICIO EXITOSAMENTE. :)" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
        }
        return escribio;
    }
};
#endif // TIPOSERVICIOCLASE_H_INCLUDED
