#ifndef VENTAKIOSCOCLASE_H_INCLUDED
#define VENTAKIOSCOCLASE_H_INCLUDED

class Kiosco;

class Kiosco
{
private:
    int _nVenta;
    int _codigoArt;
    int _cant;
    int _medioPago;
    int _hora;
    int _codigoEmpleado;
    float _total;
    bool _estado;

public:
    // sets
    void setNumeroVenta(int n){_nVenta=n;}
    void setCodigoArt(int c) { _codigoArt = c; }
    void setCant(int ca) { _codigoArt = ca; }
    void setMedioPago(float mp) { _medioPago = mp; }
    /* void setHora(float h){_hora=h;} */
    void setCodigoEmpleado(float ce) { _codigoEmpleado = ce; }
    void setTotal(float t) { _total = t; }
    void setEstado(bool e){_estado=e;}
    //gets
    int getNumeroVenta(){return _nVenta;}
    bool getEstado(){return _estado;}
    // Metodos
    int cargar()
    {
        cout << "INGRESE NUMERO DE LA VENTA: " << endl;
        cin >> _nVenta;
        cout << "INGRESE CODIGO DE ARTICULO VENDIDO: " << endl;
        cin >> _codigoArt;

        ArchivoStock archivo;
        int precio;
        precio = archivo.devolverPrecio(_codigoArt);
        if (precio == -1)
        {
            cout << "CODIGO DE ARTICULO INEXISTENTE" << endl;
            system("pause");
            return -1;
        }

        cout << "INGRESE CANTIDAD: " << endl;
        cin >> _cant;
        cout << "INGRESE MEDIO DE PAGO: (1-Tarjeta 2-Efectivo)" << endl;
        cin >> _medioPago;
        cout << "INGRESE HORA: " << endl;
        cin >> _hora;
        cout << "INGRESE CODIGO DE EMPLEADO ATENDIENDO: " << endl;
        cin >> _codigoEmpleado;
        _total = _cant * precio;
        return 1;
    }
    void mostrar()
    {
        cout << "NUMERO DE VENTA: " << _nVenta << endl;
        cout << "CODIGO DE ARTICULO VENDIDO: " << _codigoArt << endl;
        cout << "CANTIDAD: " << _cant << endl;
        cout << "MEDIO DE PAGO: " << _medioPago << endl;
        cout << "HORA: " << _hora << endl;
        cout << "CODIGO DE EMPLEADO ATENDIENDO: " << _codigoEmpleado << endl;
        cout << "TOTAL: " << _total << endl;
    }
};

class ArchivoKiosco
{
private:
    char nombre[30] = "ventasKiosco.dat";

public:
    void setArchivoKiosco(const char *k)
    {
        strcpy(nombre, k);
    }

    int buscarPosicion(int numeroVenta)
    {
        FILE *p;
        Kiosco kioscoX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return -1;
        }
        while (fread(&kioscoX, sizeof(Kiosco), 1, p) == 1)
        {
            if (kioscoX.getNumeroVenta() == numeroVenta)
            {
                fclose(p);
                return pos;
            }
            pos++;
        }
        fclose(p);
        textColor(12, 0);
        divisorSimple();
        cout << "NO SE ENCONTRO UNA VENTA CON ESE NUMERO DE VENTA" << endl;
        divisorSimple();
        textColor(15, 0);

        return -1;
    }

    bool existeVentaServicio(int numeroDeVenta)
    {
        FILE *p;
        Kiosco kioscoX;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return false;
        }
        while (fread(&kioscoX, sizeof(Kiosco), 1, p) == 1)
        {
            if (kioscoX.getNumeroVenta() == numeroDeVenta && kioscoX.getEstado() == true)
            {
                fclose(p);
                return true;
            }
        }
        fclose(p);
        return false;
    }

    int agregarRegistro(Kiosco kioscoX)
    {
        FILE *p;
        p = fopen(nombre, "ab");
        if (p == NULL)
        {
            return -1;
        }
        kioscoX.setEstado(true);
        // verificar si ya existe ese codigo de combustible
        if (existeVentaServicio(kioscoX.getNumeroVenta()))
        {
            textColor(12, 0);
            divisorSimple();
            cout << "YA EXISTE UNA VENTA CON ESE NUMERO DE VENTA" << endl;
            divisorSimple();
            textColor(15, 0);
            return -1;
        }
        int escribio = fwrite(&kioscoX, sizeof(Kiosco), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE AGREGO LA VENTA EXITOSAMENTE :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;
    }

    int leerRegistro(int numeroVenta)
    {
        FILE *p;
        int pos = buscarPosicion(numeroVenta);
        Kiosco kioscoX;
        if (pos == -1)
        {
            return -1;
        }
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(Kiosco) * pos, SEEK_SET);
        fread(&kioscoX, sizeof(Kiosco), 1, p);
        kioscoX.mostrar();
        fclose(p);
        return 1;
    }

    Kiosco leerRegistros()
    {
        FILE *p;
        Kiosco kioscoX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            exit(-1);
        }
        while (fread(&kioscoX, sizeof(Kiosco), 1, p) == 1)
        {
            fseek(p, sizeof(Kiosco) * pos, SEEK_SET);
            fread(&kioscoX, sizeof(Kiosco), 1, p);
            kioscoX.mostrar();
            pos++;
        }
        fclose(p);
        return kioscoX;
    }

    int modificarRegistro(int numeroVenta)
    {
        FILE *p;
        int pos = buscarPosicion(numeroVenta);
        Kiosco kioscoX;
        if (pos == -1)
        {
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }
        /// usar OBJ.cargar() para modificar los datos
        fseek(p, sizeof(Kiosco) * pos, SEEK_SET);
        fread(&kioscoX, sizeof(Kiosco), 1, p);
        kioscoX.cargar();
        fseek(p, sizeof(Kiosco) * pos, SEEK_SET);
        if (existeVentaServicio(kioscoX.getNumeroVenta()))
        {
            textColor(12, 0);
            divisorSimple();
            cout << "YA EXISTE UNA VENTA CON ESE NUMERO DE VENTA" << endl;
            divisorSimple();
            textColor(15, 0);
            return -1;
        }
        int escribio = fwrite(&kioscoX, sizeof(Kiosco), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE MODIFICO LA VENTA EXITOSAMENTE :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;
    }

    int borrarVentaKiosco(int numeroVenta)
    {
        FILE *p;
        int pos = buscarPosicion(numeroVenta);
        Kiosco kioscoX;
        if (pos == -1)
        {
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(Kiosco) * pos, SEEK_SET);
        fread(&kioscoX, sizeof(Kiosco), 1, p);
        kioscoX.setEstado(false);
        fseek(p, sizeof(Kiosco) * pos, SEEK_SET);
        fwrite(&kioscoX, sizeof(Kiosco), 1, p);
        fclose(p);
        return 1;
    }
};

#endif // VENTAKIOSCOCLASE_H_INCLUDED
