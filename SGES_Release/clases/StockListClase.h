#ifndef STOCKLISTCLASE_H_INCLUDED
#define STOCKLISTCLASE_H_INCLUDED

class Stock;

class Stock
{
private:
    int _codigoArt, _cantidad;
    char _nombreArticulo[30];
    float _precio;
    bool _estado;

public:
    // sets
    void setCodigoArt(int c)
    {
        _codigoArt = c;
    }
    void setArticulo(const char *a)
    {
        strcpy(_nombreArticulo, a);
    }
    void setCodigoArt(float p)
    {
        _precio = p;
    }
    void setCantidad(int c)
    {
        _cantidad = c;
    }
    void setEstado(bool e)
    {
        _estado = e;
    }
    // gets
    int getCodigoStock()
    {
        return _codigoArt;
    }
    bool getEstado()
    {
        return _estado;
    }
    float getPrecio()
    {
        return _precio;
    }
    int getCantidad()
    {
        return _cantidad;
    }
    // Metodos
    bool cargar()
    {
        cout << "INGRESE CODIGO DE ARTICULO: " << endl;
        cin >> _codigoArt;
        if (_codigoArt < 0)
        {
            textColor(12, 0);
            divisorSimple();
            cout << "EL CODIGO DE ARTICULO NO PUEDE SER NEGATIVO" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE NOMBRE: " << endl;
        cargarCadena(_nombreArticulo, 29);
        cout << "INGRESE PRECIO: " << endl;
        cin >> _precio;
        if (_precio < 0)
        {
            textColor(12, 0);
            divisorSimple();
            cout << "EL PRECIO NO PUEDE SER NEGATIVO" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE LA CANTIDAD: " << endl;
        cin >> _cantidad;
        if (_cantidad <= 0)
        {
            textColor(12, 0);
            divisorSimple();
            cout << "LA CANTIDAD NO PUEDE SER NEGATIVO NI CERO" << endl;
            divisorSimple();
            textColor(15, 0);
            return false;
        }
        /* _estado = true; */ // ya se hace mas abajo esto con el setEstado
        return true;
    }
    void mostrar()
    {
        if (_estado == false)
        {
            return;
        }
        cout << endl;
        cout << "CODIGO DE ARTICULO: " << _codigoArt << endl;
        cout << "NOMBRE: " << _nombreArticulo << endl;
        cout << "PRECIO: " << _precio << endl;
        cout << "CANTIDAD: " << _cantidad << endl;
        cout << endl;
        divisorSimple();
    }
};

class ArchivoStock
{
private:
    char nombre[30] = "stockList.dat";

public:
    void setArchivoStock(const char *s)
    {
        strcpy(nombre, s);
    }

    int buscarPosicion(int numeroItem)
    {
        FILE *p;
        Stock stockX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return -1;
        }
        while (fread(&stockX, sizeof(Stock), 1, p) == 1)
        {
            if (stockX.getCodigoStock() == numeroItem && stockX.getEstado() == true)
            {
                fclose(p);
                return pos;
            }
            pos++;
        }
        fclose(p);
        textColor(12, 0);
        divisorSimple();
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE CODIGO" << endl;
        divisorSimple();
        textColor(15, 0);

        return -1;
    }

    bool buscarCodStockExistente(int codStock)
    {
        FILE *p;
        Stock x;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&x, sizeof(Stock), 1, p) == 1)
        {
            if (x.getCodigoStock() == codStock && x.getEstado() == true)
            {
                return true;
                fclose(p);
            }
        }
        fclose(p);
        return false;
    }

    int agregarRegistro(Stock stockX)
    {
        FILE *p;
        p = fopen(nombre, "ab");
        if (p == NULL)
        {
            return -1;
        }
        stockX.setEstado(true);
        // verificar si ya existe ese codigo de combustible
        if (buscarCodStockExistente(stockX.getCodigoStock()))
        {
            textColor(12, 0);
            divisorSimple();
            cout << "YA EXISTE UN REGISTRO CON ESE CODIGO" << endl;
            divisorSimple();
            textColor(15, 0);
            return -1;
        }
        int escribio = fwrite(&stockX, sizeof(Stock), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE AGREGO EL REGISTRO EXITOSAMENTE :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;
    }

    int leerRegistro(int codItem)
    {
        FILE *p;
        int pos = buscarPosicion(codItem);
        Stock stockX;
        if (pos == -1)
        {
            return -1;
        }
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(Stock) * pos, SEEK_SET);
        fread(&stockX, sizeof(Stock), 1, p);
        stockX.mostrar();
        fclose(p);
        return 1;
    }

    Stock leerRegistros()
    {
        FILE *p;
        Stock x;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&x, sizeof x, 1, p) == 1)
        {
            fseek(p, sizeof x * pos, 0);
            fread(&x, sizeof x, 1, p);
            x.mostrar();
            pos++;
        }
        fclose(p);
        return x;
    }

    float devolverPrecio(int codStock)
    {
        FILE *p;
        Stock x;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&x, sizeof(Stock), 1, p) == 1)
        {
            if (x.getCodigoStock() == codStock && x.getEstado() == true)
            {
                return x.getPrecio();
                fclose(p);
            }
        }
        fclose(p);
        return -1;
    }

    int devolverCantidad(int codStock)
    {
        FILE *p;
        Stock x;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&x, sizeof(Stock), 1, p) == 1)
        {
            if (x.getCodigoStock() == codStock && x.getEstado() == true)
            {
                return x.getCantidad();
                fclose(p);
            }
        }
        fclose(p);
        return -1;
    }


    int modificarRegistro(int numeroItem)
    {
        FILE *p;
        int pos = buscarPosicion(numeroItem);
        Stock stockX;
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
        fseek(p, sizeof(Stock) * pos, SEEK_SET);
        fread(&stockX, sizeof(Stock), 1, p);
        stockX.cargar();
        fseek(p, sizeof(Stock) * pos, SEEK_SET);
        if (buscarCodStockExistente(stockX.getCodigoStock()))
        {
            textColor(12, 0);
            divisorSimple();
            cout << "YA EXISTE UNA VENTA CON ESE NUMERO DE VENTA" << endl;
            divisorSimple();
            textColor(15, 0);
            return -1;
        }
        int escribio = fwrite(&stockX, sizeof(Stock), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE MODIFICO EL REGISTRO EXITOSAMENTE :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;
    }

    int borrarItemDelStock(int numeroItem)
    {
        FILE *p;
        int pos = buscarPosicion(numeroItem);
        Stock stockX;
        if (pos == -1)
        {
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(Stock) * pos, SEEK_SET);
        fread(&stockX, sizeof(Stock), 1, p);
        stockX.setEstado(false);
        fseek(p, sizeof(Stock) * pos, SEEK_SET);
        int escribio = fwrite(&stockX, sizeof(Stock), 1, p);
        fclose(p);
        return escribio;
    }

    int actualizarCantidad(int cod, int cant)
    {
        FILE *p;
        int pos = buscarPosicion(cod);
        Stock stockX;
        if (pos == -1)
        {
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }

        fseek(p, sizeof(Stock) * pos, SEEK_SET);
        fread(&stockX, sizeof(Stock), 1, p);


        ///cambiamos el valor del registro
        stockX.setCantidad(stockX.getCantidad()-cant);

        fseek(p, sizeof(Stock) * pos, SEEK_SET);
        int escribio = fwrite(&stockX, sizeof(Stock), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE MODIFICO EL REGISTRO EXITOSAMENTE :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;




    }
};

#endif // STOCKLISTCLASE_H_INCLUDED
