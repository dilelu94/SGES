#ifndef CLIENTECLASE_H_INCLUDED
#define CLIENTECLASE_H_INCLUDED

#include <cstring>

class Cliente;

class Cliente
{
private:
    int _numeroCliente;
    char _nombre[30];
    char _apellido[30];
    int _DNI;
    int _telefono;
    bool _estado;

public:
    // sets
    void setNumeroCliente(int c) { _numeroCliente = c; }
    void setNombre(const char *n) { strcpy(_nombre, n); }
    void setApellido(const char *a) { strcpy(_apellido, a); }
    void setDNI(int d) { _DNI = d; }
    void setTelefono(int t) { _telefono = t; }
    void setEstado(bool e) { _estado = e; }
    // gets
    int getNumeroCliente() { return _numeroCliente; }
    bool getEstado() { return _estado; }
    // Metodos
    void cargar()
    {
        // nCliente es autoincremental
        cout << "INGRESE NOMBRE: " << endl;
        cin >> _nombre;
        cout << "INGRESE APELLIDO: " << endl;
        cin >> _apellido;
        cout << "INGRESE DNI: " << endl;
        cin >> _DNI;
        if (_DNI <= 0)
        {
            textColor(12, 0);
            divisorSimpleLargo();
            cout << "ERROR: VUELVA A INTENTAR E INGRESE UN DNI VALIDO" << endl;
            divisorSimpleLargo();
            textColor(15, 0);
            return;
        }
        cout << "INGRESE N. TELEFONO: " << endl;
        cin >> _telefono;
    }

    void mostrar()
    {
        if (_estado == false)
        {
            return;
        }
        cout << endl;
        cout << "NUMERO DE CLIENTE: " << _numeroCliente << endl;
        cout << "NOMBRE: " << _nombre << endl;
        cout << "APELLIDO: " << _apellido << endl;
        cout << "DNI: " << _DNI << endl;
        cout << "TELEFONO: " << _telefono << endl;
        cout << endl;
        divisorSimple();
    }
};

class ArchivoCliente
{
private:
    char nombre[30] = "clientes.dat";

public:
    void setArchivoClientes(const char *c)
    {
        strcpy(nombre, c);
    }

    int buscarNumCliente(int numCliente)
    {
        FILE *p;
        Cliente x;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        while (fread(&x, sizeof(Cliente), 1, p) == 1)
        {
            if (x.getNumeroCliente() == numCliente)
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
        Cliente clienteX;
        int codigo = 0;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        while (fread(&clienteX, sizeof(Cliente), 1, p) == 1)
        {
            codigo = clienteX.getNumeroCliente();
        }
        fclose(p);
        return codigo;
    }

    bool existeCliente(int codCliente)
    {
        FILE *p;
        Cliente clienteX;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return false;
        }
        while (fread(&clienteX, sizeof(Cliente), 1, p) == 1)
        {
            if (clienteX.getNumeroCliente() == codCliente && clienteX.getEstado() == true)
            {
                fclose(p);
                return true;
            }
        }
        fclose(p);
        return false;
    }

    int agregarRegistro(Cliente clienteX)
    {
        FILE *p;
        p = fopen(nombre, "ab");
        if (p == NULL)
        {
            return -1;
        }
        clienteX.setEstado(true);
        clienteX.setNumeroCliente(buscarUltimoCodigo() + 1); // codigo de cliente autoincremental
        int escribio = fwrite(&clienteX, sizeof(Cliente), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE AGREGO EL CLIENTE EXITOSAMENTE :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;
    }

    int leerRegistro(int numCliente)
    {
        FILE *p;
        Cliente x;
        p = fopen(nombre, "rb");
        if (p == NULL)
            exit(1);
        int contNumCliente = 0;
        while (fread(&x, sizeof(Cliente), 1, p) == 1)
        {
            if (x.getNumeroCliente() == numCliente)
            {
                fseek(p, sizeof x * contNumCliente, 0);
                fread(&x, sizeof x, 1, p);
                x.mostrar();
                fclose(p);
                return 1;
            }
            contNumCliente++;
        }
        fclose(p);
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE NUMERO DE CLIENTE";
        return -1;
    }

    Cliente leerRegistros()
    {
        FILE *p;
        Cliente x;
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

    int modificarRegistro(int numCliente)
    {
        FILE *p;
        int pos = buscarNumCliente(numCliente);
        Cliente clienteX;
        if (pos == -1)
        {
            return -1;
        }
        p = fopen(nombre, "rb+");
        if (p == NULL)
        {
            return -1;
        }
        // usar clienteX para cargar los datos nuevos
        fseek(p, sizeof(Cliente) * pos, SEEK_SET);
        fread(&clienteX, sizeof(Cliente), 1, p);
        clienteX.cargar();
        fseek(p, sizeof(Cliente) * pos, SEEK_SET);
        int escribio = fwrite(&clienteX, sizeof(Cliente), 1, p);
        fclose(p);
        if (escribio == 1)
        {
            textColor(10, 0);
            divisorSimple();
            cout << "SE MODIFICO EL CLIENTE EXITOSAMENTE :)" << endl;
            divisorSimple();
            textColor(15, 0);
        }
        return escribio;
    }

    // baja logica estado = false
    int borrarCliente(int numCliente)
    {
        FILE *p;
        Cliente x;
        p = fopen(nombre, "rb+");
        if (p == NULL)
            exit(1);
        int contNumCliente = 0;
        while (fread(&x, sizeof(Cliente), 1, p) == 1)
        {
            if (x.getNumeroCliente() == numCliente)
            {
                x.setEstado(false);
                fseek(p, sizeof x * contNumCliente, 0);
                int escribio = fwrite(&x, sizeof x, 1, p);
                fclose(p);
                return escribio;
            }
            contNumCliente++;
        }
        fclose(p);
        cout << "NO SE ENCONTRO UN REGISTRO CON ESE NUMERO DE CLIENTE";
        return -1;
    };
};

#endif // CLIENTECLASE_H_INCLUDED
