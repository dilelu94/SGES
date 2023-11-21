#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

class ConfiguracionEmpleados
{
private:
    char nombre[30];

public:
    ConfiguracionEmpleados(const char *n) { strcpy(nombre, n); }

    void backupEmpleados()
    {
        Empleado reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("empleados.dat", "rb");
        if (pAux == NULL)
        {
            textColor(12, 0);
            cout << "NO EXISTE EL ARCHIVO DE DATOS";
            textColor(15, 0);
            return;
        }

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE BACKUP";
            textColor(15, 0);
            fclose(pAux);
            return;
        }
        while (fread(&reg, sizeof(Empleado), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(Empleado), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        system("cls");
        textColor(10, 0);
        divisorSimple();
        cout << "COPIA DE SEGURIDAD CREADA" << endl;
        divisorSimple();
        textColor(15, 0);
        system("pause");
        return;
    }

    void restaurarEmpleados()
    {
        Empleado reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
        {
            textColor(12, 0);
            cout << "NO EXISTE UN BACKUP";
            textColor(15, 0);
            return;
        }

        p = fopen("empleados.dat", "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE DATOS";
            textColor(15, 0);
            fclose(pAux);
            return;
        }
        while (fread(&reg, sizeof(Empleado), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(Empleado), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        system("cls");
        textColor(10, 0);
        divisorSimple();
        cout << "RESTAURACION DE ARCHIVO COMPLETA" << endl;
        divisorSimple();
        textColor(15, 0);
        system("pause");
        return;
    }
};
/// Separador-------------------
class ConfiguracionCombustible
{
private:
    char nombre[30];

public:
    ConfiguracionCombustible(const char *n) { strcpy(nombre, n); }

    int backupCombustible()
    {
        Combustible reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("combustibles.dat", "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE EL ARCHIVO DE DATOS";
        textColor(15, 0);
        return 1;
        ;

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(Combustible), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(Combustible), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "COPIA DE SEGURIDAD CREADA";
        return 1;
    }

    int restaurarCombustibles()
    {
        Combustible reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE UN BACKUP";
        textColor(15, 0);
        return 1;
        ;

        p = fopen("combustibles.dat", "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(Combustible), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(Combustible), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "RESTAURACION DE ARCHIVO COMPLETA";
        return 1;
    }
};

/// Separador-------------------

class ConfiguracionCargaCombustible
{
private:
    char nombre[30];

public:
    ConfiguracionCargaCombustible(const char *n) { strcpy(nombre, n); }

    int backupCargaCombustible()
    {
        CargaCombustible reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("cargasCombustible.dat", "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE EL ARCHIVO DE DATOS";
        textColor(15, 0);
        return 1;
        ;

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(CargaCombustible), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(CargaCombustible), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "COPIA DE SEGURIDAD CREADA";
        return 1;
    }

    int restaurarCargaCombustibles()
    {
        CargaCombustible reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE UN BACKUP";
        textColor(15, 0);
        return 1;
        ;

        p = fopen("cargasCombustible.dat", "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(CargaCombustible), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(CargaCombustible), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "RESTAURACION DE ARCHIVO COMPLETA";
        return 1;
    }
};

/// Separados-----------------------

class ConfiguracionTipoServicio
{
private:
    char nombre[30];

public:
    ConfiguracionTipoServicio(const char *n) { strcpy(nombre, n); }

    int backupTipoServicio()
    {
        TipoDeServicio reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("tipoDeServicios.dat", "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE EL ARCHIVO DE DATOS";
        textColor(15, 0);
        return 1;
        ;

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(TipoDeServicio), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(TipoDeServicio), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "COPIA DE SEGURIDAD CREADA";
        return 1;
    }

    int restaurarTipoServicio()
    {
        TipoDeServicio reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE UN BACKUP";
        textColor(15, 0);
        return 1;
        ;

        p = fopen("tipoDeServicios.dat", "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(TipoDeServicio), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(TipoDeServicio), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "RESTAURACION DE ARCHIVO COMPLETA";
        return 1;
    }
};

/// Separados-----------------------

class ConfiguracionVentaServicio
{
private:
    char nombre[30];

public:
    ConfiguracionVentaServicio(const char *n) { strcpy(nombre, n); }

    int backupVentaDeServicio()
    {
        VentaServicio reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("ventaDeServicio.dat", "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE EL ARCHIVO DE DATOS";
        textColor(15, 0);
        return 1;
        ;

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(VentaServicio), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(VentaServicio), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "COPIA DE SEGURIDAD CREADA";
        return 1;
    }

    int restaurarVentaDeServicio()
    {
        VentaServicio reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE UN BACKUP";
        textColor(15, 0);
        return 1;
        ;

        p = fopen("ventaDeServicio.dat", "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(VentaServicio), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(VentaServicio), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "RESTAURACION DE ARCHIVO COMPLETA";
        return 1;
    }
};

/// Separados-----------------------

class ConfiguracionStock
{
private:
    char nombre[30];

public:
    ConfiguracionStock(const char *n) { strcpy(nombre, n); }

    int backupStock()
    {
        Stock reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("stockList.dat", "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE EL ARCHIVO DE DATOS";
        textColor(15, 0);
        return 1;
        ;

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(Stock), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(Stock), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "COPIA DE SEGURIDAD CREADA";
        return 1;
    }

    int restaurarStock()
    {
        Stock reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE UN BACKUP";
        textColor(15, 0);
        return 1;
        ;

        p = fopen("stockList.dat", "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(Stock), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(Stock), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "RESTAURACION DE ARCHIVO COMPLETA";
        return 1;
    }
};

/// Separados-----------------------

class ConfiguracionVentaKiosco
{
private:
    char nombre[30];

public:
    ConfiguracionVentaKiosco(const char *n) { strcpy(nombre, n); }

    int backupVentaKiosco()
    {
        Kiosco reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("ventasKiosco.dat", "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE EL ARCHIVO DE DATOS";
        textColor(15, 0);
        return 1;
        ;

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(Kiosco), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(Kiosco), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "COPIA DE SEGURIDAD CREADA";
        return 1;
    }

    int restaurarVentaKiosco()
    {
        Kiosco reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE UN BACKUP";
        textColor(15, 0);
        return 1;

        p = fopen("ventasKiosco.dat", "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(Kiosco), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(Kiosco), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "RESTAURACION DE ARCHIVO COMPLETA";
        return 1;
    }
};

/// Separados-----------------------

class ConfiguracionClientes
{
private:
    char nombre[30];

public:
    ConfiguracionClientes(const char *n) { strcpy(nombre, n); }

    int backupClientes()
    {
        Cliente reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("clientes.dat", "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE EL ARCHIVO DE DATOS";
        textColor(15, 0);
        return 1;
        ;

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(Cliente), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(Cliente), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "COPIA DE SEGURIDAD CREADA";
        return 1;
    }

    int restaurarClientes()
    {
        Cliente reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
            textColor(12, 0);
        cout << "NO EXISTE UN BACKUP";
        textColor(15, 0);
        return 1;
        ;

        p = fopen("clientes.dat", "wb");
        if (p == NULL)
        {
            fclose(pAux);
            exit(1);
        }
        while (fread(&reg, sizeof(Cliente), 1, pAux) == 1)
        {
            fseek(pAux, sizeof reg * cont, 0);
            fread(&reg, sizeof(Cliente), 1, pAux);
            fseek(p, sizeof reg * cont, 0);
            fwrite(&reg, sizeof reg, 1, p);
            cont++;
        }
        fclose(p);
        fclose(pAux);
        cout << "RESTAURACION DE ARCHIVO COMPLETA";
        return 1;
    }
};

#endif // CONFIGURACION_H_INCLUDED
