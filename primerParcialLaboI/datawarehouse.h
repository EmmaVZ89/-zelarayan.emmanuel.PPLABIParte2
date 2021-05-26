#include "bicicleta.h"
#include "trabajo.h"

#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED



#endif // DATAWAREHOUSE_H_INCLUDED

/** \brief carga automaticamente los campos de una estructura eBicicleta
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension del array de bicicletas
 * \param cant int cantidad de elementos a cargar
 * \param id int* numero de id de bicicleta que debe asignarse y autoincrementarse
 * \return int si se puede cargar las estructuras retorna la cantidad cargada, sino retorna 0 (tambien en caso de error)
 *
 */
int hardcodearBicicletas(eBicicleta bicicletas[], int tam, int cant, int* id);

/** \brief carga automaticamente los campos de una estructura eTrabajo
 *
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamT int dimension del array de trabajos
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param cant int cantidad de elementos a cargar
 * \param id int* numero de id de trabajos que debe asignarse y autoincrementarse
 * \return int si se puede cargar las estructuras retorna la cantidad cargada, sino retorna 0 (tambien en caso error)
 *
 */
int hardcodearTrabajos(eTrabajo trabajos[], int tamT, eBicicleta bicicletas[], int tamB, int cant, int* id);

/** \brief carga automaticamente los campos de una estructura eTipo
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int dimension del array de tipos
 * \param cant int cantidad de elementos a cargar
 * \param id int* numero de id de tipos que debe asignarse y autoincrementarse
 * \return int si se puede cargar las estructuras retorna la cantidad cargada, sino retorna 0 (tambien en caso error)
 *
 */
int hardcodearTipos(eTipo tipos[], int tam,int cant, int* id);

/** \brief carga automaticamente los campos de una estructura eColor
 *
 * \param colores[] eColor array de colores
 * \param tam int dimension del array de colores
 * \param cant int cantidad de elementos a cargar
 * \param id int* numero de id de colores que debe asignarse y autoincrementarse
 * \return int si se puede cargar las estructuras retorna la cantidad cargada, sino retorna 0 (tambien en caso error)
 *
 */
int hardcodearColores(eColor colores[], int tam,int cant, int* id);

/** \brief carga automaticamente los campos de una estructura eServicio
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int dimension del array de servicios
 * \param cant int cantidad de elementos a cargar
 * \param id int* numero de id de servicios que debe asignarse y autoincrementarse
 * \return int si se puede cargar las estructuras retorna la cantidad cargada, sino retorna 0 (tambien en caso error)
 *
 */
int hardcodearServicios(eServicio servicios[], int tam,int cant, int* id);

