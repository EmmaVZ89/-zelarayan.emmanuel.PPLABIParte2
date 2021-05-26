#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "trabajo.h"
#include "bicicleta.h"
#include "servicio.h"

int altaTrabajo(eTrabajo trabajos[], int tam, int* idTrabajo,eBicicleta bicicletas[], int tamB,
                eTipo tipos[], int tamT, eColor colores[], int tamC,eServicio servicios[], int tamS)
{
    int todoOk = 0;
    int indice;

    if(trabajos!=NULL && tam > 0 && idTrabajo!=NULL && bicicletas!=NULL && tamB>0 && tipos!=NULL && tamT>0 &&
            colores!=NULL && tamC>0 && servicios!= NULL && tamS>0)
    {
        system("cls");
        printf("***  Alta Trabajos  ***\n\n");
        indice = buscarLibreTrabajo(trabajos,tam);
        if(indice != -1)
        {
            mostrarBicicletas(bicicletas,tamB,tipos,tamT,colores,tamC);
            utn_getNumero(&trabajos[indice].idBicicleta,"Ingrese Id bicicleta: ","Ingreso Invalido!\n\n",-1000000,1000000,2);
            while(buscarBicicleta(bicicletas,tamB,trabajos[indice].idBicicleta) == -1)
            {
                utn_getNumero(&trabajos[indice].idBicicleta,"Error. Reingrese Id bicicleta: ","Ingreso Invalido!\n\n",-1000000,1000000,2);
            }

            mostrarServicios(servicios,tamS);
            utn_getNumero(&trabajos[indice].idServicio,"Ingrese Id Servicio: ","Ingreso Invalido!\n\n",-1000000,1000000,2);
            while(buscarServicio(servicios,tamS,trabajos[indice].idServicio) == -1)
            {
                utn_getNumero(&trabajos[indice].idServicio,"Error. Reingrese Id Servicio: ","Ingreso Invalido!\n\n",-1000000,1000000,2);
            }

            printf("Ingese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &trabajos[indice].fecha.dia,
                  &trabajos[indice].fecha.mes,
                  &trabajos[indice].fecha.anio);
            while(validarFecha(trabajos[indice].fecha.dia,trabajos[indice].fecha.mes,trabajos[indice].fecha.anio) == 0)
            {
                printf("\n   Fecha no valida!\n\n");
                printf("Reingrese fecha dd/mm/aaaa: ");
                scanf("%d/%d/%d", &trabajos[indice].fecha.dia,
                      &trabajos[indice].fecha.mes,
                      &trabajos[indice].fecha.anio);
            }

            trabajos[indice].id = *idTrabajo;
            *idTrabajo = *idTrabajo+1;
            trabajos[indice].isEmpty = 0;
            todoOk = 1;
        }
        else
        {
            printf("\n   No hay lugar en el sistema!!\n\n");
        }
    }
    return todoOk;
}

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;
    if(trabajos!=NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
    int indice = -1;
    if(trabajos!=NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(trabajos[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int mostrarTrabajos(eTrabajo trabajos[], int tam, eTipo tipos[],int tamT,eServicio servicios[],int tamS,
                    eBicicleta bicicletas[], int tamB)
{
    int todoOk = 0;
    int flag = 1;
    if(trabajos!=NULL && tam>0 && tipos!=NULL && tamT>0 && servicios!=NULL && tamS>0 && bicicletas!=NULL && tamB>0)
    {
        system("cls");
        printf("\n    ******* Listado de Trabajos ********\n\n");
        printf("-----------------------------------------------\n");
        printf("Id       Bicicleta       Servicio     Fecha\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],tipos,tamT,servicios,tamS,bicicletas,tamB);
                flag = 0;
                todoOk = 1;
            }
        }
        if(flag)
        {
            printf("   No hay trabajos que mostrar\n");
        }
        printf("-----------------------------------------------\n\n");
    }
    return todoOk;
}

int mostrarTrabajo(eTrabajo trabajo, eTipo tipos[],int tamT,eServicio servicios[],int tamS,
                   eBicicleta bicicletas[], int tamB)
{
    int todoOk = 0;
    char marca[22];
    char servicio[26];
    if(tipos!=NULL && tamT>0 && servicios!=NULL && tamS>0 && bicicletas!=NULL && tamB>0)
    {
        if(cargarNombreServicio(trabajo.idServicio,servicios,tamS,servicio)&&
                cargarMarcaBicicleta(trabajo.idBicicleta,bicicletas,tamB,marca))
        {
            printf("%5d    %-12s    %-10s  %2d/%2d/%4d\n",
                   trabajo.id,
                   marca,
                   servicio,
                   trabajo.fecha.dia,
                   trabajo.fecha.mes,
                   trabajo.fecha.anio);
            todoOk = 1;
        }
    }
    return todoOk;
}


