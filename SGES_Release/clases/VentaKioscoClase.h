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
    void setNumeroVenta(int n) { _nVenta = n; }
    void setCodigoArt(int c) { _codigoArt = c; }
    void setCant(int ca) { _codigoArt = ca; }
    void setMedioPago(float mp) { _medioPago = mp; }
    /* void setHora(float h){_hora=h;} */
    void setCodigoEmpleado(float ce) { _codigoEmpleado = ce; }
    void setTotal(float t) { _total = t; }
    void setEstado(bool e) { _estado = e; }
    // gets
    int getNumeroVenta() { return _nVenta; }
    int getCodigoArt() { return _codigoArt; }
    int getCantidad() { return _cant; }
    int getEmpleado() { return _codigoEmpleado; }
    bool getEstado() { return _estado; }
    float getTotal() { return _total; }
    // Metodos
    int cargar()
    {
        int cantidadStock;
        // nVenta es autoincremental
        cout << "INGRESE CODIGO DE ARTICULO VENDIDO: " << endl;
        cin >> _codigoArt;

        ArchivoStock archivoStock;
        ArchivoEmpleado ArchivoEmpleado;
        float precio;
        precio = archivoStock.devolverPrecio(_codigoArt);
        if (precio == -1)
        {
            textColor(12, 0);
            divisorSimple();
            cout << "CODIGO DE ARTICULO INEXISTENTE" << endl;
            divisorSimple();
            textColor(15, 0);
            system("pause");
            return -1;
        }
        cantidadStock=archivoStock.devolverCantidad(_codigoArt);
        cout << "INGRESE CANTIDAD: " << endl;
        cin >> _cant;
        if (_cant <= 0)
        {
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "ERROR: VUELVA A INTENTAR E INGRESE UNA CANTIDAD VALIDA" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            return -1;
        }
        if(_cant>cantidadStock){
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "ERROR: VUELVA A INTENTAR E INGRESE UNA CANTIDAD MENOR AL TOTAL PARA EL ARTICULO SELECCIONADO" << endl;
            cout << "LIMITE :" << cantidadStock << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            return -1;
        }
        cout << "INGRESE MEDIO DE PAGO: (1-Tarjeta 2-Efectivo)" << endl;
        cin >> _medioPago;
        if (_medioPago < 1 || _medioPago > 2)
        {
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "ERROR: VUELVA A INTENTAR E INGRESE UN MEDIO DE PAGO VALIDO" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            return -1;
        }
        cout << "INGRESE HORA: " << endl;
        cin >> _hora;
        if (_hora < 0 || _hora > 23)
        {
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "ERROR: VUELVA A INTENTAR E INGRESE UNA HORA VALIDA" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            return -1;
        }
        cout << "INGRESE CODIGO DE EMPLEADO ATENDIENDO: " << endl;
        cin >> _codigoEmpleado;
        if (!ArchivoEmpleado.existeEmpleado(_codigoEmpleado))
        {
            textColor(12, 0);
            divisorSimple();
            cout << "CODIGO DE EMPLEADO INEXISTENTE" << endl;
            divisorSimple();
            textColor(15, 0);
            system("pause");
            return -1;
        }
        _total = _cant * precio;
        return 1;
    }
    void mostrar()
    {
        if (_estado == false)
        {
            return;
        }
        cout << endl;
        cout << "NUMERO DE VENTA: " << _nVenta << endl;
        cout << "CODIGO DE ARTICULO VENDIDO: " << _codigoArt << endl;
        cout << "CANTIDAD: " << _cant << endl;
        cout << "MEDIO DE PAGO: " << _medioPago << endl;
        cout << "HORA: " << _hora << endl;
        cout << "CODIGO DE EMPLEADO ATENDIENDO: " << _codigoEmpleado << endl;
        cout << "TOTAL: " << _total << endl;
        cout << endl;
        divisorSimple();
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

    int buscarUltimoCodigo()
    {
        FILE *p;
        Kiosco kioscoX;
        int codigo = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        while (fread(&kioscoX, sizeof(Kiosco), 1, p) == 1)
        {
            codigo = kioscoX.getNumeroVenta();
        }
        fclose(p);
        return codigo;
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
        kioscoX.setNumeroVenta(buscarUltimoCodigo() + 1); // n de venta autoincremental
        /// sumarle al empleado lo que gano por la venta del kiosco

        ArchivoEmpleado archivoEmpleado;
        ArchivoStock ArchivoStock;
        float precioXArticulo = ArchivoStock.devolverPrecio(kioscoX.getCodigoArt());
        float recaudacion = precioXArticulo * kioscoX.getCantidad();
        archivoEmpleado.incrementarTotalRecaudado(kioscoX.getEmpleado(), recaudacion);

        // Restar item vendido del stock

        ArchivoStock.actualizarCantidad(kioscoX.getCodigoArt(), kioscoX.getCantidad());

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
        /// borrar recaudacion de Empleado
        ArchivoEmpleado archivoEmpleado;
        ArchivoStock ArchivoStock;
        float precioXArticulo = ArchivoStock.devolverPrecio(kioscoX.getCodigoArt());
        float recaudacion = precioXArticulo * kioscoX.getCantidad();
        archivoEmpleado.decrementarTotalRecaudado(kioscoX.getEmpleado(), recaudacion);

        ///borrar stock
        ArchivoStock.restablecerCantidad(kioscoX.getCodigoArt(), kioscoX.getCantidad());

        kioscoX.cargar();

        /// agregar la nueva recaudacion de empleado
        precioXArticulo = ArchivoStock.devolverPrecio(kioscoX.getCodigoArt());
        recaudacion = precioXArticulo * kioscoX.getCantidad();
        archivoEmpleado.incrementarTotalRecaudado(kioscoX.getEmpleado(), recaudacion);


        ///agregar nuevo stock
        ArchivoStock.actualizarCantidad(kioscoX.getCodigoArt(), kioscoX.getCantidad());

        fseek(p, sizeof(Kiosco) * pos, SEEK_SET);
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
        int escribio = fwrite(&kioscoX, sizeof(Kiosco), 1, p);
        fclose(p);
        return escribio;
    }

    bool stadistiaVentasDeKiosco()
    {
        FILE *p;
        Kiosco kioscoX;
        int cantVentas = 0;
        float totalRecaudado = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return false;
        }
        while (fread(&kioscoX, sizeof(Kiosco), 1, p) == 1)
        {
            if (kioscoX.getEstado() == true)
            {
                cantVentas++;
                totalRecaudado += kioscoX.getTotal();
            }
        }
        fclose(p);
        // mostrar estadisticas con Recuadro
        int x = 50, y = 1;
        if (cantVentas == 0)
        {
            return false;
        }
        int base = 39, altura = 7;
        textColor(1, 0);
        dibujarRecuadro(base, altura, x - 2, 0);
        textColor(15, 0);
        gotoxy(x, y);
        cout << "ESTADISTICAS DE VENTAS DE KIOSCO" << endl;
        y += 1;
        gotoxy(x, y + 1);
        cout << "CANTIDAD DE VENTAS: " << cantVentas << endl;
        gotoxy(x, y + 2);
        cout << "TOTAL RECAUDADO: " << totalRecaudado << endl;
        gotoxy(x, y + 3);
        cout << "RECAUDACION PROMEDIO x VENTA: " << totalRecaudado / cantVentas << endl;
        cout << endl;
        return true;
    }
};

#endif // VENTAKIOSCOCLASE_H_INCLUDED
