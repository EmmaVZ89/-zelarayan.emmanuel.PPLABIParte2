#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "bicicleta.h"
#include "servicio.h"
#include "trabajo.h"
#include "datawarehouse.h"
#include "informes.h"

#define CANT_TIPOS 4
#define CANT_COLORES 5
#define CANT_BICICLETAS 20
#define CANT_SERVICIOS 4
#define CANT_TRABAJOS 20


int main()
{
    char salir = 'n';
    int nextIdTipos = 1000;
    int nextIdColores = 5000;
    int nextIdServicios = 20000;
    int nextIdBicicleta = 50000;
    int nextIdTrabajo = 60000;
    eTipo tipos[CANT_TIPOS];
    eColor colores[CANT_COLORES];
    eServicio servicios[CANT_SERVICIOS];
    eTrabajo trabajos[CANT_TRABAJOS];
    eBicicleta bicicletas[CANT_BICICLETAS];

    inicializarBicicletas(bicicletas,CANT_BICICLETAS);
    inicializarTrabajos(trabajos,CANT_TRABAJOS);

//***********************************    HARDCODEO    **************************************
    hardcodearTipos(tipos,CANT_TIPOS,4,&nextIdTipos);
    hardcodearColores(colores,CANT_COLORES,5,&nextIdColores);
    hardcodearServicios(servicios,CANT_SERVICIOS,4,&nextIdServicios);
    hardcodearBicicletas(bicicletas,CANT_BICICLETAS,15,&nextIdBicicleta);
    hardcodearTrabajos(trabajos,CANT_TRABAJOS,bicicletas,CANT_BICICLETAS,15,&nextIdTrabajo);
//******************************************************************************************

    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(altaBicicleta(bicicletas,CANT_BICICLETAS,&nextIdBicicleta,tipos,CANT_TIPOS,
                             colores,CANT_COLORES))
            {
                printf("\n   Alta exitosa!!\n\n");
            }
            else
            {
                printf("\n   Hubo un problema y no se realizo el alta!\n\n");
            }
            system("pause");
            break;
        case 2:
            if(todoVacioBicicletas(bicicletas,CANT_BICICLETAS) == 0)
            {
                modificarBicicletas(bicicletas,CANT_BICICLETAS,tipos,CANT_TIPOS,colores,CANT_COLORES);
            }
            else
            {
                printf("\n   No hay bicicletas registradas\n\n");
            }
            system("pause");
            break;
        case 3:
            if(todoVacioBicicletas(bicicletas,CANT_BICICLETAS) == 0)
            {
                if(bajaBicicleta(bicicletas,CANT_BICICLETAS,tipos,CANT_TIPOS,colores,CANT_COLORES))
                {
                    printf("\n   Baja Exitosa!!\n\n");
                }
                else
                {
                    printf("   No se pudo realizar la baja!\n\n");
                }
            }
            else
            {
                printf("\n   No hay bicicletas registradas\n\n");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            mostrarBicicletas(bicicletas,CANT_BICICLETAS,tipos,CANT_TIPOS,colores,CANT_COLORES);
            system("pause");
            break;
        case 5:
            mostrarTipos(tipos,CANT_TIPOS);
            system("pause");
            break;
        case 6:
            mostrarColores(colores,CANT_COLORES);
            system("pause");
            break;
        case 7:
            mostrarServicios(servicios,CANT_SERVICIOS);
            system("pause");
            break;
        case 8:
            if(todoVacioBicicletas(bicicletas,CANT_BICICLETAS) == 0)
            {
                if(altaTrabajo(trabajos,CANT_TRABAJOS,&nextIdTrabajo,bicicletas,
                               CANT_BICICLETAS,tipos,CANT_TIPOS,colores,CANT_COLORES,servicios,CANT_SERVICIOS))
                {
                    printf("\n   Alta exitosa!!\n\n");
                }
                else
                {
                    printf("\n   Hubo un problema y no se pudo realizar el alta\n\n");
                }
            }
            else
            {
                printf("\n   Primero debe dar de alta una bicicleta\n\n");
                system("pause");
            }
            break;
        case 9:
            mostrarTrabajos(trabajos,CANT_TRABAJOS,tipos,CANT_TIPOS,servicios,CANT_SERVICIOS,
                            bicicletas,CANT_BICICLETAS);
            system("pause");
            break;
        case 10:
            if(todoVacioBicicletas(bicicletas,CANT_BICICLETAS) == 0)
            {
                informes(bicicletas,CANT_BICICLETAS,tipos,CANT_TIPOS,colores,CANT_COLORES,trabajos,
                         CANT_TRABAJOS,servicios,CANT_SERVICIOS);
            }
            else
            {
                printf("\n   Primero debe dar de alta una bicicleta\n\n");
                system("pause");
            }
            break;
        case 11:
            getChar(&salir,"Desea Salir? \ns: Si\nn: No\nRespuesta: ","Opcion invalida!!\n",2);
            break;
        }
    }
    while(salir!='s');
    return 0;
}

