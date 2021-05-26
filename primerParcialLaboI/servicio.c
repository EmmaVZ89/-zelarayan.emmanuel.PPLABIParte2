#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "servicio.h"

int mostrarServicios(eServicio servicios[], int tam)
{
    int todoOk = 0;
    if(servicios!=NULL && tam>0)
    {
        system("cls");
        printf("\n   *** Listado de Servicios ***\n\n");
        printf("------------------------------------\n");
        printf("Id         Descripcion       Precio    \n");
        printf("------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
                mostrarServicio(servicios[i]);
                todoOk = 1;
        }
        printf("------------------------------------\n\n");
    }
    return todoOk;
}

void mostrarServicio(eServicio servicio)
{
    printf("%5d      %-10s        %.2f\n",servicio.id,servicio.descripcion,servicio.precio);
}

int cargarNombreServicio(int idServicio, eServicio servicios[], int tam, char nombreServicio[])
{
    int todoOk = 0;

    if(idServicio >= 20000 && idServicio <= 20003 && servicios != NULL && tam > 0 && nombreServicio != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(servicios[i].id == idServicio)
            {
                strcpy(nombreServicio, servicios[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int buscarServicio(eServicio servicios[], int tam, int idServicio)
{
    int indice = -1;
    if(servicios!=NULL && tam>0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(servicios[i].id == idServicio)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
