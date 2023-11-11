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
        cout << "INGRESE N. DE CLIENTE: " << endl;
        cin >> _numeroCliente;
        cout << "INGRESE NOMBRE: " << endl;
        cin >> _nombre;
        cout << "INGRESE APELLIDO: " << endl;
        cin >> _apellido;
        cout << "INGRESE DNI: " << endl;
        cin >> _DNI;
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

    int agregarRegistro(Cliente x)
    {
        FILE *p;
        p = fopen(nombre, "ab");
        if (p == NULL)
            return -1;
        int numCliente = buscarNumCliente(x.getNumeroCliente());
        if (numCliente == -1)
        {
            x.setEstado(true);
            int escribio = fwrite(&x, sizeof x, 1, p);
            fclose(p);
            return escribio;
        }
        else if (x.getEstado() == false)
        {
            cout << "hay un registro DADO DE BAJA con ese NUMERO DE CLIENTE";
            fclose(p);
            return -1;
        }
        else
        {
            cout << "hay un registro con ese NUMERO DE CLIENTE";
            fclose(p);
            return -1;
        }
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
        Cliente x;
        p = fopen(nombre, "rb+");
        if (p == NULL)
            exit(1);
        int contNumCliente = 0;
        while (fread(&x, sizeof(Empleado), 1, p) == 1)
        {
            if (x.getNumeroCliente() == numCliente)
            {
                fseek(p, sizeof x * contNumCliente, 0);
                fread(&x, sizeof(Empleado), 1, p);
                x.cargar();
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
