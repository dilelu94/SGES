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
            system("pause");
            return;
        }

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE BACKUP";
            textColor(15, 0);
            fclose(pAux);
            system("pause");
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
            system("pause");
            return;
        }

        p = fopen("empleados.dat", "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE DATOS";
            textColor(15, 0);
            fclose(pAux);
            system("pause");
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

    void backupCombustible()
    {
        Combustible reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("combustibles.dat", "rb");
        if (pAux == NULL)
        {
            textColor(12, 0);
            cout << "NO EXISTE EL ARCHIVO DE DATOS";
            textColor(15, 0);
            system("pause");
            return;
        }

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE BACKUP";
            textColor(15, 0);
            fclose(pAux);
            system("pause");
            return;
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
        system("cls");
        textColor(10, 0);
        divisorSimple();
        cout << "COPIA DE SEGURIDAD CREADA" << endl;
        divisorSimple();
        textColor(15, 0);
        system("pause");
        return;
    }

    void restaurarCombustibles()
    {
        Combustible reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
        {
            textColor(12, 0);
            cout << "NO EXISTE UN BACKUP";
            textColor(15, 0);
            system("pause");
            return;
        }

        p = fopen("combustibles.dat", "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE DATOS";
            textColor(15, 0);
            fclose(pAux);
            system("pause");
            return;
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

class ConfiguracionCargaCombustible
{
private:
    char nombre[30];

public:
    ConfiguracionCargaCombustible(const char *n) { strcpy(nombre, n); }

    void backupCargaCombustible()
    {
        CargaCombustible reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("cargasCombustible.dat", "rb");
        if (pAux == NULL)
        {
            textColor(12, 0);
            cout << "NO EXISTE EL ARCHIVO DE DATOS";
            textColor(15, 0);
            system("pause");
            return;
        }

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE BACKUP";
            textColor(15, 0);
            fclose(pAux);
            system("pause");
            return;
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
        system("cls");
        textColor(10, 0);
        divisorSimple();
        cout << "COPIA DE SEGURIDAD CREADA" << endl;
        divisorSimple();
        textColor(15, 0);
        system("pause");
        return;
    }

    void restaurarCargaCombustibles()
    {
        CargaCombustible reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
        {
            textColor(12, 0);
            cout << "NO EXISTE UN BACKUP";
            textColor(15, 0);
            system("pause");
            return;
        }

        p = fopen("cargasCombustible.dat", "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE DATOS";
            textColor(15, 0);
            fclose(pAux);
            system("pause");
            return;
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

/// Separados-----------------------

class ConfiguracionTipoServicio
{
private:
    char nombre[30];

public:
    ConfiguracionTipoServicio(const char *n) { strcpy(nombre, n); }

    void backupTipoServicio()
    {
        TipoDeServicio reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("tipoDeServicios.dat", "rb");
        if (pAux == NULL)
        {
            textColor(12, 0);
            cout << "NO EXISTE EL ARCHIVO DE DATOS";
            textColor(15, 0);
            system("pause");
            return;
        }

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE BACKUP";
            textColor(15, 0);
            fclose(pAux);
            system("pause");
            return;
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
        system("cls");
        textColor(10, 0);
        divisorSimple();
        cout << "COPIA DE SEGURIDAD CREADA" << endl;
        divisorSimple();
        textColor(15, 0);
        system("pause");
        return;
    }

    void restaurarTipoServicio()
    {
        TipoDeServicio reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
        {
            textColor(12, 0);
            cout << "NO EXISTE UN BACKUP";
            textColor(15, 0);
            system("pause");
            return;
        }

        p = fopen("tipoDeServicios.dat", "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE DATOS";
            textColor(15, 0);
            fclose(pAux);
            system("pause");
            return;
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

/// Separados-----------------------

class ConfiguracionVentaServicio
{
private:
    char nombre[30];

public:
    ConfiguracionVentaServicio(const char *n) { strcpy(nombre, n); }

    void backupVentaDeServicio()
    {
        VentaServicio reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("ventasDeServicio.dat", "rb");
        if (pAux == NULL)
        {
            textColor(12, 0);
            cout << "NO EXISTE EL ARCHIVO DE DATOS";
            textColor(15, 0);
            system("pause");
            return;
        }

        p = fopen(nombre, "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE BACKUP";
            textColor(15, 0);
            fclose(pAux);
            system("pause");
            return;
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
        system("cls");
        textColor(10, 0);
        divisorSimple();
        cout << "COPIA DE SEGURIDAD CREADA" << endl;
        divisorSimple();
        textColor(15, 0);
        system("pause");
        return;
    }

    void restaurarVentaDeServicio()
    {
        VentaServicio reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen(nombre, "rb");
        if (pAux == NULL)
        {
            textColor(12, 0);
            cout << "NO EXISTE UN BACKUP";
            textColor(15, 0);
            system("pause");
            return;
        }

        p = fopen("ventasDeServicio.dat", "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE DATOS";
            textColor(15, 0);
            fclose(pAux);
            system("pause");
            return;
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

/// Separados-----------------------

class ConfiguracionStock
{
private:
    char nombre[30];

public:
    ConfiguracionStock(const char *n) { strcpy(nombre, n); }

    void backupStock()
    {
        Stock reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("stockList.dat", "rb");
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
        system("cls");
        textColor(10, 0);
        divisorSimple();
        cout << "COPIA DE SEGURIDAD CREADA" << endl;
        divisorSimple();
        textColor(15, 0);
        system("pause");
        return;
    }

    void restaurarStock()
    {
        Stock reg;
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

        p = fopen("stockList.dat", "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE DATOS";
            textColor(15, 0);
            fclose(pAux);
            return;
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

/// Separados-----------------------

class ConfiguracionVentaKiosco
{
private:
    char nombre[30];

public:
    ConfiguracionVentaKiosco(const char *n) { strcpy(nombre, n); }

    void backupVentaKiosco()
    {
        Kiosco reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("ventasKiosco.dat", "rb");
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
        system("cls");
        textColor(10, 0);
        divisorSimple();
        cout << "COPIA DE SEGURIDAD CREADA" << endl;
        divisorSimple();
        textColor(15, 0);
        system("pause");
        return;
    }

    void restaurarVentaKiosco()
    {
        Kiosco reg;
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

        p = fopen("ventasKiosco.dat", "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE DATOS";
            textColor(15, 0);
            fclose(pAux);
            return;
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

/// Separados-----------------------

class ConfiguracionClientes
{
private:
    char nombre[30];

public:
    ConfiguracionClientes(const char *n) { strcpy(nombre, n); }

    void backupClientes()
    {
        Cliente reg;
        FILE *p;
        FILE *pAux;
        int cont = 0;

        pAux = fopen("clientes.dat", "rb");
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
        system("cls");
        textColor(10, 0);
        divisorSimple();
        cout << "COPIA DE SEGURIDAD CREADA" << endl;
        divisorSimple();
        textColor(15, 0);
        system("pause");
        return;
    }

    void restaurarClientes()
    {
        Cliente reg;
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

        p = fopen("clientes.dat", "wb");
        if (p == NULL)
        {
            textColor(12, 0);
            cout << "NO SE PUDO CREAR EL ARCHIVO DE DATOS";
            textColor(15, 0);
            fclose(pAux);
            return;
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

#endif // CONFIGURACION_H_INCLUDED
