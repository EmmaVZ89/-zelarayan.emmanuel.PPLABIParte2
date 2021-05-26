#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"

int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("***  Bicicleteria  ***\n\n");
    printf("Menu de opciones:\n\n");
    printf("1. ALTA BICICLETA\n");
    printf("2. MODIFICAR BICICLETA\n");
    printf("3. BAJA BICICLETA\n");
    printf("4. LISTAR BICICLETAS\n");
    printf("5. LISTAR TIPOS\n");
    printf("6. LISTAR COLORES\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO\n");
    printf("9. LISTAR TRABAJOS\n");
    printf("10. Salir\n");
    utn_getNumero(&opcion,"Ingrese su opcion: ","Opcion invalida!!\n\n",1,10,2);
    return opcion;
}



int altaBicicleta(eBicicleta bicicletas[], int tam, int* idBicicleta, eTipo tipos[],
                  int tamT,eColor colores[],int tamC)
{
    int todoOk = 0;
    int indice;

    if(bicicletas!=NULL && tam > 0 && idBicicleta!=NULL && tipos!=NULL && tamT>0
            && colores!=NULL && tamC>0)
    {
        system("cls");
        printf("***  Alta Juegos  ***\n\n");
        indice = buscarLibreBicicleta(bicicletas,tam);
        if(indice != -1)
        {
            utn_getNombre(&bicicletas[indice].marca,22,"Ingrese marca: ","Ingreso invalido, ingrese solo letras!!\n\n",2);

            mostrarTipos(tipos,tamT);
            utn_getNumero(&bicicletas[indice].idTipo,"Ingrese id del tipo: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
            while(buscarTipo(tipos,tamT,bicicletas[indice].idTipo) == -1)
            {
                utn_getNumero(&bicicletas[indice].idTipo,"Error. Reingrese id del tipo: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
            }

            mostrarColores(colores,tamC);
            utn_getNumero(&bicicletas[indice].idColor,"Ingrese id del Color: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
            while(buscarColor(colores,tamC,bicicletas[indice].idColor) == -1)
            {
                utn_getNumero(&bicicletas[indice].idColor,"Error. Reingrese id del Color: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
            }

            utn_getNumeroFlotante(&bicicletas[indice].rodado,"Ingrese rodado(20, 26, 27.5 y 29): ","Ingreso invalido!!\n\n",20,29,2);
            while(bicicletas[indice].rodado!=20&&bicicletas[indice].rodado!=26
                    &&bicicletas[indice].rodado!=27.5&&bicicletas[indice].rodado!=29)
            {
                utn_getNumeroFlotante(&bicicletas[indice].rodado,"Error. Reingrese rodado(20, 26, 27.5 y 29): ","Ingreso invalido!!\n\n",20,29,2);
            }

            bicicletas[indice].id = *idBicicleta;
            *idBicicleta = *idBicicleta+1;
            bicicletas[indice].isEmpty = 0;
            todoOk = 1;
        }
        else
        {
            printf("\n   No hay lugar en el sistema!!\n\n");
        }
    }
    return todoOk;
}

int inicializarBicicletas(eBicicleta bicicletas[], int tam)
{
    int todoOk = 0;
    if(bicicletas!=NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            bicicletas[i].isEmpty = 1;
            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarLibreBicicleta(eBicicleta bicicletas[], int tam)
{
    int indice = -1;
    if(bicicletas!=NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(bicicletas[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int bajaBicicleta(eBicicleta bicicletas[], int tam,eTipo tipos[],int tamT,eColor colores[],int tamC)
{
    int todoOk = 0;
    char confirmarBaja = 'n';
    int indice;
    int idBicicleta;
    if(bicicletas!=NULL && tam > 0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        system("cls");
        printf("***  Baja Bicicletas  ***\n\n");
        mostrarBicicletas(bicicletas,tam,tipos,tamT,colores,tamC);
        utn_getNumero(&idBicicleta,"Ingrese Id: ","Ingreso invalido!\n\n",-1000000,1000000,2);
        indice = buscarBicicleta(bicicletas,tam,idBicicleta);
        if(indice != -1)
        {
            printf("\n------------- Bicicleta a eliminar -----------------\n");
            mostrarBicicleta(bicicletas[indice],tipos,tamT,colores,tamC);
            printf("----------------------------------------------------\n\n");
            printf("Desea eliminar bicicleta con el numero de Id %d ? \n", idBicicleta);
            getChar(&confirmarBaja,"s: Si\nn: No\nRespuesta: ","Opcion invalida!!\n",2);
            if(confirmarBaja == 's')
            {
                bicicletas[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("\n   El usuario cancelo la baja!\n\n");
            }
        }
        else
        {
            printf("\n   No se encontro la bicicleta con el numero de Id %d\n\n",idBicicleta);
        }

    }
    return todoOk;
}

int buscarBicicleta(eBicicleta bicicletas[], int tam, int idBicicleta)
{
    int indice = -1;
    if(bicicletas!=NULL && tam>0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(bicicletas[i].id == idBicicleta && bicicletas[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int mostrarBicicletas(eBicicleta bicicletas[], int tam, eTipo tipos[],int tamT, eColor colores[],int tamC)
{
    int todoOk = 0;
    int flag = 1;
    if(bicicletas!=NULL && tam>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        ordenarBicicletas(bicicletas,tam);
        printf("\n************  Listado de Bicicletas  ***************\n\n");
        printf("----------------------------------------------------\n");
        printf(" Id       Marca         Tipo        Color      Rodado\n");
        printf("----------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(bicicletas[i].isEmpty == 0)
            {
                mostrarBicicleta(bicicletas[i],tipos,tamT,colores,tamC);
                flag = 0;
                todoOk = 1;
            }
        }
        if(flag)
        {
            printf("   No hay bicicletas que mostrar\n");
        }
        printf("----------------------------------------------------\n\n");
    }
    return todoOk;
}

int mostrarBicicleta(eBicicleta bicicleta,eTipo tipos[],int tamT,eColor colores[],int tamC)
{
    int todoOk = 0;
    char tipo[21];
    char color[21];
    if(tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        if(cargarDescripcionTipo(bicicleta.idTipo,tipos,tamT,tipo)&&
                cargarNombreColor(bicicleta.idColor,colores,tamC,color))
        {
            printf(" %5d    %-12s  %-10s  %-10s %.2f\n",
                   bicicleta.id,
                   bicicleta.marca,
                   tipo,
                   color,
                   bicicleta.rodado);
            todoOk = 1;
        }
    }
    return todoOk;
}


int subMenuModificarBicicleta()
{
    int opcion;
    printf("***  Modificar Bicicletas  ***\n\n");
    printf("Que desea modificar?\n\n");
    printf("1. Tipo\n");
    printf("2. Rodado\n");
    printf("3. Salir\n");
    utn_getNumero(&opcion,"Ingrese su opcion: ","Opcion invalida!!\n\n",1,3,2);
    return opcion;
}

int modificarBicicletas(eBicicleta bicicletas[], int tam,eTipo tipos[],int tamT,eColor colores[],int tamC)
{
    int todoOk = 0;
    char salirModificarBicicleta = 'n';
    char confirmarCambios;
    char confirmarBicicleta;
    int flag;
    int indice;
    int idBicicleta;
    eBicicleta auxBicicleta;

    if(bicicletas!=NULL && tam>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        system("cls");
        printf("***  Modificar Bicicletas  ***\n\n");
        mostrarBicicletas(bicicletas,tam,tipos,tamT,colores,tamC);
        utn_getNumero(&idBicicleta,"Ingrese Id: ","Ingreso invalido!\n\n",-1000000,1000000,2);
        indice = buscarBicicleta(bicicletas,tam,idBicicleta);
        if(indice != -1)
        {
            printf("------------- Bicicleta a Modificar ----------------\n");
            mostrarBicicleta(bicicletas[indice],tipos,tamT,colores,tamC);
            printf("----------------------------------------------------\n\n");
            printf("Desea modificar la bicicleta con el numero de Id %d ?\n", idBicicleta);
            getChar(&confirmarBicicleta,"s: Si\nn: No\nRespuesta: ","Opcion invalida!!\n",2);
            if(confirmarBicicleta=='s')
            {
                do
                {
                    system("cls");
                    flag = 0;
                    auxBicicleta = bicicletas[indice];
                    printf("------------- Bicicleta a Modificar ----------------\n");
                    mostrarBicicleta(bicicletas[indice],tipos,tamT,colores,tamC);
                    printf("----------------------------------------------------\n\n");
                    switch(subMenuModificarBicicleta())
                    {
                    case 1:
                        mostrarTipos(tipos,tamT);
                        utn_getNumero(&auxBicicleta.idTipo,"Ingrese id del tipo: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
                        while(buscarTipo(tipos,tamT,auxBicicleta.idTipo) == -1)
                        {
                            utn_getNumero(&auxBicicleta.idTipo,"Error. Reingrese id del tipo: ","Ingreso invalido!!\n\n",-1000000,1000000,2);
                        }
                        flag = 1;
                        break;
                    case 2:
                        utn_getNumeroFlotante(&auxBicicleta.rodado,"Ingrese rodado(20, 26, 27.5 y 29): ","Ingreso invalido!!\n\n",20,29,2);
                        while(auxBicicleta.rodado!=20&&auxBicicleta.rodado!=26
                                &&auxBicicleta.rodado!=27.5&&auxBicicleta.rodado!=29)
                        {
                            utn_getNumeroFlotante(&auxBicicleta.rodado,"Error. Reingrese rodado(20, 26, 27.5 y 29): ","Ingreso invalido!!\n\n",20,29,2);
                        }
                        flag = 1;
                        break;
                    case 3:
                        getChar(&salirModificarBicicleta,"Desea Salir? \ns: Si\nn: No\nRespuesta: ","Opcion invalida!!\n",2);
                        break;
                    }
                    if(flag)
                    {
                        getChar(&confirmarCambios,"Desea confirmar los cambios? \ns: Si\nn: No\nRespuesta: ","Opcion invalida!!\n",2);
                        if(confirmarCambios=='s')
                        {
                            bicicletas[indice] = auxBicicleta;
                            printf("\n-------------- Bicicleta Modificada ----------------\n");
                            mostrarBicicleta(bicicletas[indice],tipos,tamT,colores,tamC);
                            printf("----------------------------------------------------\n\n");
                            todoOk = 1;
                        }
                        else
                        {
                            printf("\n   El usuario cancelo las modificaciones\n\n");
                        }
                        system("pause");
                    }
                }
                while(salirModificarBicicleta!='s');
            }
            else
            {
                printf("\n   El usuario cancelo la modificacion\n\n");
            }
        }
        else
        {
            printf("\n   No se encontro la bicicleta con el numero de Id %d\n\n",idBicicleta);
        }
    }
    return todoOk;
}

int cargarMarcaBicicleta(int idBicicleta, eBicicleta bicicletas[], int tam, char marca[])
{
    int todoOk = 0;
    int indice;
    if(bicicletas != NULL && tam > 0 && marca != NULL)
    {
        indice = buscarBicicleta(bicicletas,tam,idBicicleta);
        if(indice!=-1)
        {
            strcpy(marca, bicicletas[indice].marca);
            todoOk = 1;
        }
    }
    return todoOk;
}

int ordenarBicicletas(eBicicleta bicicletas[], int tam)
{
    int todoOk = 0;
    eBicicleta auxBicicleta;

    if(bicicletas != NULL && tam > 0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(bicicletas[i].rodado > bicicletas[j].rodado ||
                        (bicicletas[i].rodado == bicicletas[j].rodado &&
                         bicicletas[i].idTipo > bicicletas[j].idTipo))
                {
                    auxBicicleta = bicicletas[i];
                    bicicletas[i] = bicicletas[j];
                    bicicletas[j] = auxBicicleta;
                    todoOk = 0;
                }
            }
        }
    }
    return todoOk;
}

int todoVacioBicicletas(eBicicleta bicicletas[], int tam)
{
    int vacio = 1;
    if(bicicletas != NULL && tam > 0) // validacion
    {
        for(int i = 0; i < tam; i++)
        {
            if(bicicletas[i].isEmpty == 0) // se verifica si la ubicacion esta ocupada
            {
                vacio = 0; // al encontrarse una ubicacion ocupada se cambia el valor de la variable empty por 0, lo cual indica que el array no esta vacio
                break;
            }
        }
    }
    return vacio; // devuelve 1 si el array esta vacio. Devuelve 0 si el array no esta vacio.
}
