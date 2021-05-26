#include "fecha.h"
#include "bicicleta.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;


#endif // TRABAJO_H_INCLUDED

/** \brief espera que el usuario ingrese los campos idBicicleta, idServicio y fecha de una estructura eTrabajo.
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int dimension del array de trabajos
 * \param idTrabajo int* puntero del numero de id de un trabajo para autoincrementarlo en caso que se haga el alta
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \param servicios[] eServicio array de servicios
 * \param tamS int dimension del array de servicios
 * \return int retorna 1 si se realizo el alta con exito, sino retorna 0 ( tambien en caso de error)
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tam, int* idTrabajo,eBicicleta bicicletas[], int tamB,eTipo tipos[],
                int tamT, eColor colores[], int tamC,eServicio servicios[], int tamS);

/** \brief ambia todos los campos isEmpty del array de trabajos a 1.
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int dimension del array de trabajos
 * \return int retorna 1 si se realizo la tarea, retorna 0 en caso de error.
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tam);

/** \brief busca el primer lugar libre en el array de trabajos
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int dimension del array de trabajos
 * \return int si hay lugar libre retorna el numero de indice, sino retorna -1 (tambien en caso de error)
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tam);

/** \brief muestra el listado de trabajos activos
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int dimension del array de trabajos
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param servicios[] eServicio array de servicios
 * \param tamS int dimension del array de servicios
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \return int retorna 1 si se mostro algun trabajo, sino retorna 0 (tambien en caso de error)
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tam, eTipo tipos[],int tamT,eServicio servicios[],int tamS,
                    eBicicleta bicicletas[], int tamB);

/** \brief muestra el campo de una estructura eTrabajo
 *
 * \param trabajo eTrabajo una estructura eTrabajo
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param servicios[] eServicio array de servicios
 * \param tamS int dimension del array de servicios
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \return int retorna 1 si se mostro los campos de la estructura, sino retorna 0 (tambien en caso de error)
 *
 */
int mostrarTrabajo(eTrabajo trabajo, eTipo tipos[],int tamT,eServicio servicios[],int tamS,
                   eBicicleta bicicletas[], int tamB);
