#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "utn.h"
#include "bicicleta.h"
#include "trabajo.h"


int menuInformes()
{
    int opcion;
    system("cls");
    printf("***  Informes  ***\n\n");
    printf("Menu de opciones:\n\n");
    printf(" 1. Listar por color\n");
    printf(" 2. Listar por tipo\n");
    printf(" 3. Cantidad menor rodado\n");
    printf(" 4. Listar por tipos\n");
    printf(" 5. Cantidad por color y tipo\n");
    printf(" 6. Color mas elegido\n");
    printf(" 7. Trabajos por bicicleta\n");
    printf(" 8. Importe por bicicleta\n");
    printf(" 9. Bicicletas por servicio\n");
    printf("10. Servicios por fecha\n");
    printf("11. Salir\n");
    utn_getNumero(&opcion,"Ingrese su opcion: ","Opcion invalida!!\n\n",1,11,2);
    return opcion;
}

int informes(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC,
             eTrabajo trabajos[],int tamTR, eServicio servicios[], int tamS)
{
    int todoOk = 0;
    char salirInformes = 'n';
    if(bicicletas!=NULL && tamB>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0 && trabajos!=NULL &&
            tamTR>0 && servicios!=NULL && tamS>0)
    {
        do
        {
            switch(menuInformes())
            {
            case 1:
                bicicletaPorColor(bicicletas,tamB,tipos,tamT,colores,tamC);
                todoOk = 1;
                system("pause");
                break;
            case 2:
                bicicletaPorTipo(bicicletas,tamB,tipos,tamT,colores,tamC);
                todoOk = 1;
                system("pause");
                break;
            case 3:
                menorRodado(bicicletas,tamB,tipos,tamT,colores,tamC);
                todoOk = 1;
                system("pause");
                break;
            case 4:
                mostrarPorTipos(bicicletas,tamB,tipos,tamT,colores,tamC);
                todoOk = 1;
                system("pause");
                break;
            case 5:
                cantidadColorYtipo(bicicletas,tamB,tipos,tamT,colores,tamC);
                todoOk = 1;
                system("pause");
                break;
            case 6:
                colorMasElegido(bicicletas,tamB,colores,tamC);
                todoOk = 1;
                system("pause");
                break;
            case 7:
                trabajosPorBicicleta(bicicletas,tamB,trabajos,tamTR,tipos,tamT,colores,tamC,servicios,tamS);
                todoOk = 1;
                system("pause");
                break;
            case 8:
                importePorBicicleta(bicicletas,tamB,trabajos,tamTR,tipos,tamT,colores,tamC,servicios,tamS);
                todoOk = 1;
                system("pause");
                break;
            case 9:
                mostrarBicicletasPorServicio(bicicletas,tamB,trabajos,tamTR,tipos,tamT,colores,tamC,servicios,tamS);
                todoOk = 1;
                system("pause");
                break;
            case 10:
                mostrarServiciosPorFecha(bicicletas,tamB,trabajos,tamTR,tipos,tamT,colores,tamC,servicios,tamS);
                todoOk = 1;
                system("pause");
                break;
            case 11:
                getChar(&salirInformes,"Desea Salir? \ns: Si\nn: No\nRespuesta: ","Opcion invalida!!\n",2);
                break;
            }
        }
        while(salirInformes!='s');
    }
    return todoOk;
}

int bicicletaPorColor(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC)
{
    int todoOk = 0;
    int idColor;
    int indice;
    if(bicicletas!=NULL && tamB>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        mostrarColores(colores,tamC);
        utn_getNumero(&idColor,"Ingrese id del color: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
        indice =buscarColor(colores,tamC,idColor);
        while(indice == -1)
        {
            utn_getNumero(&idColor,"Error. Reingrese id del color: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
        }
        printf("\n         ***  Bicicletas Color %s  ***\n", colores[indice].nombreColor);
        printf("-----------------------------------------------------\n");
        printf(" Id       Marca         Tipo        Color      Rodado\n");
        printf("-----------------------------------------------------\n");
        for(int i = 0; i<tamB ; i++)
        {
            if(bicicletas[i].isEmpty == 0 && bicicletas[i].idColor == idColor)
            {
                mostrarBicicleta(bicicletas[i],tipos,tamT,colores,tamC);
                todoOk = 1;
            }
        }
        printf("-----------------------------------------------------\n\n");
    }
    return todoOk;
}

int bicicletaPorTipo(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC)
{
    int todoOk = 0;
    int idTipo;
    int indice;
    if(bicicletas!=NULL && tamB>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        mostrarTipos(tipos,tamT);
        utn_getNumero(&idTipo,"Ingrese id del tipo: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
        indice = buscarTipo(tipos,tamT,idTipo);
        while(indice == -1)
        {
            utn_getNumero(&idTipo,"Error. Reingrese id del tipo: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
        }
        printf("\n         ***  Bicicletas Tipo %s  ***\n", tipos[indice].descripcion);
        printf("-----------------------------------------------------\n");
        printf(" Id       Marca         Tipo        Color      Rodado\n");
        printf("-----------------------------------------------------\n");
        for(int i = 0; i<tamB ; i++)
        {
            if(bicicletas[i].isEmpty == 0 && bicicletas[i].idTipo == idTipo)
            {
                mostrarBicicleta(bicicletas[i],tipos,tamT,colores,tamC);
                todoOk = 1;
            }
        }
        printf("-----------------------------------------------------\n\n");
    }
    return todoOk;
}

int menorRodado(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC)
{
    int todoOk = 0;
    int contadorBicicletas = 0;
    float rodadoMenor;
    int flag = 1;
    if(bicicletas!=NULL && tamB>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        for(int i = 0; i<tamB ; i++)
        {
            if(bicicletas[i].isEmpty == 0 && (flag || bicicletas[i].rodado < rodadoMenor))
            {
                rodadoMenor = bicicletas[i].rodado;
                flag = 0;
                todoOk = 1;
            }
        }
        printf("\n         ***  Bicicletas rodado %.2f  ***\n",rodadoMenor);
        printf("-----------------------------------------------------\n");
        printf(" Id       Marca         Tipo        Color      Rodado\n");
        printf("-----------------------------------------------------\n");
        for(int i = 0; i<tamB ; i++)
        {
            if(bicicletas[i].isEmpty == 0 && bicicletas[i].rodado == rodadoMenor)
            {
                mostrarBicicleta(bicicletas[i],tipos,tamT,colores,tamC);
                contadorBicicletas++;
            }
        }
        printf("-----------------------------------------------------\n");
        printf("Cantidad de bicicletas de menor rodado: %d\n\n", contadorBicicletas);
    }
    return todoOk;
}

int mostrarPorTipos(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC)
{
    int todoOk = 0;
    int contadorBicicletas;
    if(bicicletas!=NULL && tamB>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        system("cls");
        for(int i = 0; i<tamT; i++)
        {
            contadorBicicletas = 0;
            printf("Tipo de bicicleta: %s",tipos[i].descripcion);
            printf("\n-----------------------------------------------------\n");
            printf(" Id       Marca         Tipo        Color      Rodado\n");
            printf("-----------------------------------------------------\n");
            for(int j = 0; j<tamB; j++)
            {
                if(bicicletas[j].isEmpty == 0 && tipos[i].id == bicicletas[j].idTipo)
                {
                    mostrarBicicleta(bicicletas[j],tipos,tamT,colores,tamC);
                    contadorBicicletas++;
                    todoOk = 1;
                }
            }
            printf("-----------------------------------------------------\n");
            printf("Cantidad: %d\n\n\n",contadorBicicletas);
        }
    }
    return todoOk;
}

int cantidadColorYtipo(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC)
{
    int todoOk = 0;
    int contadorTipoYColor = 0;
    int idTipo;
    int idColor;
    char nombreColor[21];
    char descripcionTipo[21];
    if(bicicletas!=NULL && tamB>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        mostrarTipos(tipos,tamT);
        utn_getNumero(&idTipo,"Ingrese id del tipo: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
        while(buscarTipo(tipos,tamT,idTipo) == -1)
        {
            utn_getNumero(&idTipo,"Error. Reingrese id del tipo: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
        }

        mostrarColores(colores,tamC);
        utn_getNumero(&idColor,"Ingrese id del color: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
        while(buscarColor(colores,tamC,idColor) == -1)
        {
            utn_getNumero(&idColor,"Error. Reingrese id del color: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
        }

        for(int i = 0; i<tamB ; i++)
        {
            if(bicicletas[i].isEmpty == 0 && bicicletas[i].idTipo == idTipo && bicicletas[i].idColor == idColor)
            {
                contadorTipoYColor++;
                todoOk = 1;
            }
        }
        cargarNombreColor(idColor,colores,tamC,nombreColor);
        cargarDescripcionTipo(idTipo,tipos,tamT,descripcionTipo);
        printf("\nCantidad de bicicletas de tipo %s y color %s: %d\n\n",descripcionTipo,nombreColor,contadorTipoYColor);
    }
    return todoOk;
}

int colorMasElegido(eBicicleta bicicletas[], int tamB,eColor colores[],int tamC)
{
    int todoOk = 0;
    int totalPorColor[tamC];
    int mayor;
    if(bicicletas!=NULL && tamB>0 && colores!=NULL && tamC>0)
    {
        for(int i = 0; i<tamC ; i++)
        {
            totalPorColor[i] = 0;
            for(int j = 0; j <tamB ; j++)
            {
                if(bicicletas[j].isEmpty == 0 && bicicletas[j].idColor == colores[i].id)
                {
                    totalPorColor[i]++;
                    todoOk = 1;
                }
            }
        }

        mayor = totalPorColor[0];
        for(int i = 0; i<tamC ; i++)
        {
            if(mayor < totalPorColor[i])
            {
                mayor = totalPorColor[i];
            }
        }
        printf("\n***  Color/es mas elegidos por los clientes: ");
        for(int i = 0; i<tamC ; i++)
        {
            if(mayor == totalPorColor[i])
            {
                printf("%s, ",colores[i].nombreColor);
            }
        }
        printf("  ***\n\n");
    }
    return todoOk;
}

int trabajosPorBicicleta(eBicicleta bicicletas[], int tamB,eTrabajo trabajos[], int tamTR,
                         eTipo tipos[],int tamT, eColor colores[],int tamC, eServicio servicios[],int tamS)
{
    int todoOk = 0;
    int flag = 1;
    int idBicicleta;
    int indice;
    if(bicicletas!=NULL && tamB>0 && trabajos!=NULL && tamTR>0 && tipos!=NULL && tamT>0
            && colores!=NULL && tamC>0 && servicios!=NULL && tamT>0)
    {
        system("cls");
        mostrarBicicletas(bicicletas,tamB,tipos,tamT,colores,tamC);
        utn_getNumero(&idBicicleta,"Ingrese Id: ","Ingreso invalido!\n\n",-1000000,1000000,2);
        indice = buscarBicicleta(bicicletas,tamB,idBicicleta);
        while(indice == -1)
        {
            utn_getNumero(&idBicicleta,"Error. Reingrese Id: ","Ingreso invalido!\n\n",-1000000,1000000,2);
            indice = buscarBicicleta(bicicletas,tamB,idBicicleta);
        }
        printf("\nId Bicicleta: %d",idBicicleta);
        printf("\n-----------------------------------------------\n");
        printf("Id       Bicicleta       Servicio     Fecha\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i<tamTR ; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idBicicleta == idBicicleta)
            {
                mostrarTrabajo(trabajos[i],tipos,tamT,servicios,tamS,bicicletas,tamB);
                flag = 0;
                todoOk = 1;
            }
        }
        if(flag)
        {
            printf("   La bicicleta no tiene trabajos asociados!\n");
        }
        printf("-----------------------------------------------\n\n");
    }
    return todoOk;
}

int importePorBicicleta(eBicicleta bicicletas[], int tamB,eTrabajo trabajos[], int tamTR,
                        eTipo tipos[],int tamT, eColor colores[],int tamC, eServicio servicios[],int tamS)
{
    int todoOk = 0;
    float importe = 0;
    int idBicicleta;
    int indice;
    if(bicicletas!=NULL && tamB>0 && trabajos!=NULL && tamTR>0 && tipos!=NULL && tamT>0
            && colores!=NULL && tamC>0 && servicios!=NULL && tamT>0)
    {
        system("cls");
        mostrarBicicletas(bicicletas,tamB,tipos,tamT,colores,tamC);
        utn_getNumero(&idBicicleta,"Ingrese Id: ","Ingreso invalido!\n\n",-1000000,1000000,2);
        indice = buscarBicicleta(bicicletas,tamB,idBicicleta);
        while(indice == -1)
        {
            utn_getNumero(&idBicicleta,"Error. Reingrese Id: ","Ingreso invalido!\n\n",-1000000,1000000,2);
            indice = buscarBicicleta(bicicletas,tamB,idBicicleta);
        }

        for(int i = 0; i<tamTR ; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idBicicleta == idBicicleta)
            {
                for(int j = 0; j<tamS ; j++)
                {
                    if(trabajos[i].idServicio == servicios[j].id)
                    {
                        importe+=servicios[j].precio;
                        todoOk = 1;
                    }
                }
            }
        }
        printf("\n***  Total a pagar bicicleta %s: $ %.2f  ***\n\n",bicicletas[indice].marca,importe);
    }
    return todoOk;
}

int mostrarBicicletasPorServicio(eBicicleta bicicletas[], int tamB,eTrabajo trabajos[], int tamTR,
                                 eTipo tipos[],int tamT, eColor colores[],int tamC, eServicio servicios[],int tamS)
{
    int todoOk = 0;
    int idServicio;
    int indice;
    int indiceBicicleta;
    if(bicicletas!=NULL && tamB>0 && trabajos!=NULL && tamTR>0 && tipos!=NULL && tamT>0
            && colores!=NULL && tamC>0 && servicios!=NULL && tamT>0)
    {
        system("cls");
        mostrarServicios(servicios,tamS);
        utn_getNumero(&idServicio,"Ingrese Id Servicio: ","Ingreso Invalido!\n\n",-1000000,1000000,2);
        indice = buscarServicio(servicios,tamS,idServicio);
        while(indice == -1)
        {
            utn_getNumero(&trabajos[indice].idServicio,"Error. Reingrese Id Servicio: ","Ingreso Invalido!\n\n",-1000000,1000000,2);
            indice = buscarServicio(servicios,tamS,idServicio);
        }
        printf("\nServicio: %s\n",servicios[indice].descripcion);
        printf("------------------------------------------------------------------\n");
        printf("   Fecha      Id       Marca         Tipo        Color      Rodado\n");
        printf("------------------------------------------------------------------\n");
        for(int i = 0; i<tamTR ; i++)
        {
            if(trabajos[i].isEmpty==0 && trabajos[i].idServicio == idServicio)
            {
                indiceBicicleta = buscarBicicleta(bicicletas,tamB,trabajos[i].idBicicleta);
                if(indiceBicicleta!=-1)
                {
                    printf("%2d/%2d/%4d   ",trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
                    mostrarBicicleta(bicicletas[indiceBicicleta],tipos,tamT,colores,tamC);
                    todoOk = 1;
                }
            }
        }
        printf("------------------------------------------------------------------\n\n");
    }
    return todoOk;
}

int mostrarServiciosPorFecha(eBicicleta bicicletas[], int tamB,eTrabajo trabajos[], int tamTR,
                             eTipo tipos[],int tamT, eColor colores[],int tamC, eServicio servicios[],int tamS)
{
    int todoOk = 0;
    int contadorTrabajos = 0;
    eFecha auxFecha;
    if(bicicletas!=NULL && tamB>0 && trabajos!=NULL && tamTR>0 && tipos!=NULL && tamT>0
            && colores!=NULL && tamC>0 && servicios!=NULL && tamT>0)
    {
        printf("\n");
        printf("Ingese fecha dd/mm/aaaa: ");
        scanf("%d/%d/%d", &auxFecha.dia,
              &auxFecha.mes,
              &auxFecha.anio);
        while(validarFecha(auxFecha.dia,auxFecha.mes,auxFecha.anio) == 0)
        {
            printf("\n   Fecha no valida!\n\n");
            printf("Reingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &auxFecha.dia,
                  &auxFecha.mes,
                  &auxFecha.anio);
        }

        printf("\nFecha: %2d/%2d/%4d\n", auxFecha.dia,auxFecha.mes,auxFecha.anio);
        printf("-----------------------------------------------\n");
        printf("Id       Bicicleta       Servicio     Fecha\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i<tamTR; i++)
        {
            if(comparaFechas(auxFecha,trabajos[i].fecha))
            {
                mostrarTrabajo(trabajos[i],tipos,tamT,servicios,tamS,bicicletas,tamB);
                contadorTrabajos++;
                todoOk = 1;
            }
        }
        printf("-----------------------------------------------\n");
        printf("Cantidad de trabajos: %d\n\n",contadorTrabajos);
    }
    return todoOk;
}
