#ifndef VENTASERVICIOCLASE_H_INCLUDED
#define VENTASERVICIOCLASE_H_INCLUDED

#include <cstring>

class VentaServicio;

class VentaServicio
{
private:
    int _codVenta;
    int _servicioVendido; // 1:cambio de rueda, 2:cambio de aceite, 3:inflado de ruedas
    int _medioDePago;     // 1:efectivo, 2:debito, 3:credito ?
    int _hora;
    int _empleado;
    int _cliente;
    bool _estado;

public:
    /// sets
    void setEstado(bool e) { _estado = e; }
    void setCodigoVenta(int cod) { _codVenta = cod; }
    /// gets
    int getCodigoVenta() { return _codVenta; }
    int getTipoServicio(){return _servicioVendido;}
    bool getEstado() { return _estado; }
    int getEmpleado(){return _empleado;}
    int getServicioVendido() { return _servicioVendido; }
    /// metodos
    bool cargar()
    {
        cout << "INGRESE SERVICIO (1:Cambio de rueda, 2:Cambio de aceite, 3:Inflado de ruedas):" << endl;
        cin >> _servicioVendido;
        if (_servicioVendido < 1 || _servicioVendido > 3)
        {
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "ERROR: VUELVA A INTENTAR E INGRESE UN SERVICIO VALIDO" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE MEDIO DE PAGO: (1:efectivo, 2:debito, 3:credito)" << endl;
        cin >> _medioDePago;
        if (_medioDePago < 1 || _medioDePago > 3)
        {
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "ERROR: VUELVA A INTENTAR E INGRESE UN MEDIO DE PAGO VALIDO" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            return false;
        }
        cout << "INGRESE HORA: " << endl;
        cin >> _hora;
        cout << "INGRESE CODIGO DE EMPLEADO QUE REALIZO EL SERVICIO: " << endl;
        cin >> _empleado;
        ArchivoEmpleado archivoEmpleados;
        if (!archivoEmpleados.existeEmpleado(_empleado))
        {
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "ERROR: VUELVA A INTENTAR E INGRESE UN CODIGO DE EMPLEADO QUE EXISTA" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            return false;
        } // tiene que existir el empleado para poder cargar la venta de servicio

         ArchivoCliente archivoCliente;
        Cliente clienteX;
        int validacion;
        cout << "INGRESE EL NUMERO DE CLIENTE: " << endl;
        cin >> _cliente;
        if (archivoCliente.existeCliente(_cliente) == false){
            system("cls");
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "EL CLIENTE NO EXISTE, VUELVA A INTENTAR." << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            cout << "DESEA CARGAR EL NUEVO CLIENTE(1:SI ; 2:NO) " << endl;
            cin >> validacion;
            if(validacion==1){
                clienteX.cargar();
                archivoCliente.agregarRegistro(clienteX);
            } else {return false;}
        }

        /* _estado = true; */ // el setEstado(true) se hace en agregarRegistro() de la clase archivo
        return true;
    }
    void mostrar()
    {
        if (_estado == false)
        {
            return;
        }
        cout << endl;
        cout << "SERVICIO: " << _servicioVendido << endl;
        cout << "MEDIO DE PAGO: " << _medioDePago << endl;
        cout << "HORA: " << _hora << endl;
        cout << "CODIGO DE EMPLEADO: " << _empleado << endl;
        cout << "CODIGO CLIENTE: " << _cliente << endl;
        cout << "CODIGO DE VENTA: " << _codVenta << endl;
        cout << endl;
        divisorSimple();
    }
};

class ArchivoVentaServicio
{
private:
    char nombre[50] = "ventasDeServicio.dat";

public:
    void setArchivoCombustible(const char *e)
    {
        strcpy(nombre, e);
    }

    int buscarPosicion(int codigoVenta)
    {
        FILE *p;
        VentaServicio VentaX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return -1;
        }
        while (fread(&VentaX, sizeof(VentaServicio), 1, p) == 1)
        {
            if (VentaX.getCodigoVenta() == codigoVenta)
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
        VentaServicio VentaX;
        int codigo = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        while (fread(&VentaX, sizeof(VentaServicio), 1, p) == 1)
        {
            codigo = VentaX.getCodigoVenta();
        }
        fclose(p);
        return codigo;
    }

    bool existeVentaServicio(int codigoDeVenta)
    {
        FILE *p;
        VentaServicio VentaX;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return false;
        }
        while (fread(&VentaX, sizeof(VentaServicio), 1, p) == 1)
        {
            if (VentaX.getCodigoVenta() == codigoDeVenta)
            {
                fclose(p);
                return true;
            }
        }
        fclose(p);
        return false;
    }

    int agregarRegistro(VentaServicio ventaX)
    {
        FILE *p;
        p = fopen(nombre, "ab");
        if (p == NULL)
        {
            return -1;
        }
        ventaX.setEstado(true);
        ventaX.setCodigoVenta(buscarUltimoCodigo() + 1); // codigo de venta autoincremental
        ///sumarle al empleado lo que gano por la venta de combustible
        ArchivoEmpleado archivoEmpleado;
        ArchivoTipoServicio archivoTipoServicio;
        float precioXServicio = archivoTipoServicio.devolverPrecio(ventaX.getTipoServicio());
        archivoEmpleado.incrementarTotalRecaudado(ventaX.getEmpleado(), precioXServicio);
        int escribio = fwrite(&ventaX, sizeof(VentaServicio), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE AGREGO LA VENTA EXITOSAMENTE. :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;
    }

    int leerRegistro(int codigoVenta)
    {
        FILE *p;
        int pos = buscarPosicion(codigoVenta);
        VentaServicio ventaX;
        if (pos == -1)
        {
            textColor(12, 0);
            divisorSimple();
            cout << "NO SE ENCONTRO VENTA CON ESE CODIGO." << endl;
            divisorSimple();
            textColor(15, 0);
            return -1;
        }
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(VentaServicio) * pos, SEEK_SET);
        fread(&ventaX, sizeof(VentaServicio), 1, p);
        ventaX.mostrar();
        fclose(p);
        return 1;
    }

    VentaServicio leerRegistroVentaServicio(int pos)
    {
        VentaServicio reg;
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

    VentaServicio leerRegistros()
    {
        FILE *p;
        VentaServicio ventaX;
        int pos = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            exit(-1);
        }
        while (fread(&ventaX, sizeof(VentaServicio), 1, p) == 1)
        {
            fseek(p, sizeof(VentaServicio) * pos, SEEK_SET);
            fread(&ventaX, sizeof(VentaServicio), 1, p);
            ventaX.mostrar();
            pos++;
        }
        fclose(p);
        return ventaX;
    }

    int modificarRegistro(int codigoVenta)
    {
        FILE *p;
        int pos = buscarPosicion(codigoVenta);
        VentaServicio ventaX;
        if (pos == -1)
        {
            textColor(12, 0);
            divisorSimple();
            cout << "NO SE ENCONTRO VENTA CON ESE CODIGO." << endl;
            divisorSimple();
            textColor(15, 0);
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }
        /// usar OBJ.cargar() para modificar los datos
        fseek(p, sizeof(VentaServicio) * pos, SEEK_SET);
        fread(&ventaX, sizeof(VentaServicio), 1, p);
        ///Borrar el ingreso viejo del empleado
        ArchivoEmpleado archivoEmpleado;
        ArchivoTipoServicio archivoTipoServicio;
        float precioXServicio = archivoTipoServicio.devolverPrecio(ventaX.getTipoServicio());
        archivoEmpleado.decrementarTotalRecaudado(ventaX.getEmpleado(), precioXServicio);

        ventaX.cargar();

         ///Cargar el ingreso nuevo del empleado
        precioXServicio = archivoTipoServicio.devolverPrecio(ventaX.getTipoServicio());
        archivoEmpleado.incrementarTotalRecaudado(ventaX.getEmpleado(), precioXServicio);


        fseek(p, sizeof(VentaServicio) * pos, SEEK_SET);
        int escribio = fwrite(&ventaX, sizeof(VentaServicio), 1, p);
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

    int borrarVentaServicio(int codigoVenta)
    {
        FILE *p;
        int pos = buscarPosicion(codigoVenta);
        VentaServicio ventaX;
        if (pos == -1)
        {
            textColor(12, 0);
            divisorSimple();
            cout << "NO SE ENCONTRO VENTA CON ESE CODIGO." << endl;
            divisorSimple();
            textColor(15, 0);
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, sizeof(VentaServicio) * pos, SEEK_SET);
        fread(&ventaX, sizeof(VentaServicio), 1, p);
        ventaX.setEstado(false);
        fseek(p, sizeof(VentaServicio) * pos, SEEK_SET);
        int escribio = fwrite(&ventaX, sizeof(VentaServicio), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE DIO DE BAJA LA VENTA EXITOSAMENTE. :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;
    }

    bool estadisticaDeVentas()
    {
        FILE *p;
        VentaServicio ventaX;
        int totalVentas = 0;
        int cantCambioDeRueda = 0;
        int cantCambioDeAceite = 0;
        int cantInfladoDeRuedas = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return false;
        }
        while (fread(&ventaX, sizeof(VentaServicio), 1, p) == 1)
        {
            if (ventaX.getEstado())
            {
                totalVentas++;
                switch (ventaX.getServicioVendido())
                {
                case 1:
                    cantCambioDeRueda++;
                    break;
                case 2:
                    cantCambioDeAceite++;
                    break;
                case 3:
                    cantInfladoDeRuedas++;
                    break;
                }
            }
        }
        fclose(p);
        // mostrar estadisticas y dibujar recuadro
        int x = 50, y = 1;
        if (totalVentas == 0)
        {
            return false;
        }
        int base = 39, altura = 8;
        if (cantCambioDeRueda > 999 || cantCambioDeAceite > 999 || cantInfladoDeRuedas > 999)
        {
            base = 42;
        }
        textColor(1, 0);
        dibujarRecuadro(base, altura, x - 2, 0);
        textColor(15, 0);
        gotoxy(x, y);
        cout << "ESTADISTICA DE VENTAS DE SERVICIOS:" << endl;
        y += 1;
        gotoxy(x, y + 1);
        cout << "CANTIDAD DE CAMBIOS DE RUEDA: " << cantCambioDeRueda << endl;
        gotoxy(x, y + 2);
        cout << "CANTIDAD DE CAMBIOS DE ACEITE: " << cantCambioDeAceite << endl;
        gotoxy(x, y + 3);
        cout << "CANTIDAD DE INFLADOS DE RUEDAS: " << cantInfladoDeRuedas << endl;
        gotoxy(x, y + 4);
        textColor(10, 0);
        cout << "TOTAL DE VENTAS: " << totalVentas << endl;
        textColor(15, 0);
        cout << endl;
        return true;
    }
};

#endif // VENTASERVICIOCLASE_H_INCLUDED
