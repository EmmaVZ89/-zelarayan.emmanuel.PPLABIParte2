#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"


int comparaFechas(eFecha f1, eFecha f2)
{
    int esIgual = 0;
    if(f1.dia == f2.dia && f1.mes == f2.mes && f1.anio == f2.anio)
    {
        esIgual = 1;
    }
    return esIgual;
}

int validarFecha(int dia,int mes,int anio)
{
    int valida = 0;
    int diaMaximo;
    switch(mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        diaMaximo = 31;
        break;
    case  4:
    case  6:
    case  9:
    case 11:
        diaMaximo = 30;
        break;

    case 2:
        if (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0))
        {
            diaMaximo = 29;
        }
        else
        {
            diaMaximo = 28;
        }
    }

    if(dia >= 1 && dia <= diaMaximo)
    {
        valida = 1;
    }

    return valida;
}
