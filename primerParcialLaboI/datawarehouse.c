#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "fecha.h"



char marcasBicicleta[20][21] =
{
    "Olmo",
    "Vairo",
    "Venzo",
    "Top mega",
    "Raleigh",
    "Trinx",
    "Giant",
    "Canyon",
    "Trek",
    "Specialized",
    "Cannondale",
    "TrinxinK",
    "BMC",
    "Scott",
    "Philco",
    "Le Grand",
    "Zenith",
    "Orbea",
    "Dahon",
    "Vairo",
};

char descripcionTipos[4][21] =
{
    "Rutera",
    "Carrera",
    "Mountain",
    "BMX"
};

char nombreColores[5][21] =
{
    "Gris",
    "Negro",
    "Blanco",
    "Azul",
    "Rojo"
};

char descripcionServicios[4][26] =
{
    "Limpieza",
    "Parche",
    "Centrado",
    "Cadena"
};

float preciosServicios[4] =
{
    250,300,400,350
};



int idTipos[20] =
{
    1000,1001,1002,1003,1002,1002,1001,1003,1000,1002,
    1000,1001,1002,1003,1002,1002,1001,1003,1000,1002
};

int idColores[20] =
{
    5000,5001,5002,5003,5004,5002,5001,5001,5004,5000,
    5000,5001,5002,5003,5004,5002,5001,5001,5004,5000
};

float rodados[20] =
{
    20,26,27.5,29,26,26,20,29,27.5,27.5,
    20,26,27.5,29,26,26,20,29,27.5,27.5
};

int idServicios[20] =
{
    20000,20001,20002,20003,20000,20001,20001,20003,20002,20000,
    20000,20001,20002,20003,20000,20001,20001,20003,20002,20000
};

eFecha fechas[20] =
{
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021}
};


int hardcodearBicicletas(eBicicleta bicicletas[], int tam, int cant, int* id)
{
    int cantidad = 0;

    if(bicicletas != NULL && tam > 0 && cant >= 0 && cant <= tam && id != NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            bicicletas[i].id = *id;
            *id = *id + 1;
            strcpy(bicicletas[i].marca, marcasBicicleta[i]);
            bicicletas[i].idTipo = idTipos[i];
            bicicletas[i].idColor = idColores[i];
            bicicletas[i].rodado = rodados[i];
            bicicletas[i].isEmpty = 0;
            cantidad++;
        }
    }
    return cantidad;
}

int hardcodearTrabajos(eTrabajo trabajos[], int tamT, eBicicleta bicicletas[], int tamB, int cant, int* id)
{
    int cantidad = 0;

    if(trabajos!=NULL && tamT>0 && bicicletas!=NULL && tamB>0 && cant>0 && cant <= tamT && id!=NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            trabajos[i].id = *id;
            *id = *id + 1;
            trabajos[i].idBicicleta = bicicletas[i].id;
            trabajos[i].idServicio = idServicios[i];
            trabajos[i].fecha = fechas[i];
            trabajos[i].isEmpty = 0;
            cantidad++;
        }
    }
    return cantidad;
}

int hardcodearTipos(eTipo tipos[], int tam,int cant, int* id)
{
    int cantidad = 0;

    if(tipos!=NULL && tam>0 && cant >= 0 && cant <= tam && id!=NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            tipos[i].id = *id;
            *id = *id + 1;
            strcpy(tipos[i].descripcion,descripcionTipos[i]);
            cantidad++;
        }
    }
    return cantidad;
}

int hardcodearColores(eColor colores[], int tam,int cant, int* id)
{
    int cantidad = 0;

    if(colores!=NULL && tam>0 && cant >= 0 && cant <= tam && id!=NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            colores[i].id = *id;
            *id = *id + 1;
            strcpy(colores[i].nombreColor,nombreColores[i]);
            cantidad++;
        }
    }
    return cantidad;
}

int hardcodearServicios(eServicio servicios[], int tam,int cant, int* id)
{
    int cantidad = 0;

    if(servicios!=NULL && tam>0 && cant >= 0 && cant <= tam && id!=NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            servicios[i].id = *id;
            *id = *id + 1;
            strcpy(servicios[i].descripcion,descripcionServicios[i]);
            servicios[i].precio = preciosServicios[i];
            cantidad++;
        }
    }
    return cantidad;
}
