#include "bicicleta.h"
#include "trabajo.h"


#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief muestra el menu de opciones de informes y espera que el usuario ingrese un numero entero
 *
 * \return int retorna el numero ingresado por el usuario, 1 a 11 inclusives.
 *
 */
int menuInformes();

/** \brief recibe la opcion elegida por el usuario y llama a la funcion correspondiente
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamTR int dimension del array de trabajos
 * \param servicios[] eServicio array de servicios
 * \param tamS int dimension del array de servicios
 * \return int retorna 1 si se realizo al menos un informe, sino retorna 0 (tambien en caso de error)
 *
 */
int informes(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC,
             eTrabajo trabajos[],int tamTR, eServicio servicios[], int tamS);

/** \brief pide al usuario un numero de id de un color y muestra las bicicletas de ese color
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \return int retorna 1 si se encontro al menos un color, sino retorna 0 (tambien en caso de error)
 *
 */
int bicicletaPorColor(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC);

/** \brief  pide al usuario un numero de id de un tipo y muestra las bicicletas de ese tipo
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \return int retorna 1 si se encontro al menos un tipo, sino retorna 0 (tambien en caso de error)
 *
 */
int bicicletaPorTipo(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC);

/** \brief cuenta y muestra las bicicletas de menor rodado
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \return int retorna 1 si al menos hay una bicicleta, sino retorna 0 (tambien en caso de error)
 *
 */
int menorRodado(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC);

/** \brief muestra el listado de bicicletas separadas por tipo
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \return int retorna 1 si al menos hay una bicicleta para mostrar, sino retorna 0 (tambien en caso de error)
 *
 */
int mostrarPorTipos(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC);

/** \brief pide al usuario un numero de id de un color y un id de un tipo, cuentas las bicicletas que tengan ambos numeros
 * de id simultaneamente y muestra el numero.
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \return int retorna 1 si al menos hay una coincidencia, sino retorna 0 (tambien en caso de error)
 *
 */
int cantidadColorYtipo(eBicicleta bicicletas[], int tamB,eTipo tipos[],int tamT, eColor colores[],int tamC);

/** \brief cuenta el o los colores mas elegidos y muestra su nombre.
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \return int retorna 1 si al menos se cuenta un color, sino retorna 0 (tambien en caso de error)
 *
 */
int colorMasElegido(eBicicleta bicicletas[], int tamB, eColor colores[],int tamC);

/** \brief pide al usuario un numero de id de una bicicleta y muestra los trabajos realizados a la misma
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamTR int dimension del array de trabajos
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \param servicios[] eServicio array de servicios
 * \param tamS int dimension del array de servicios
 * \return int retorna 1 si la bicicleta tiene al menos un trabajo asociado, sino retorna 0 (tambien en caso de error)
 *
 */
int trabajosPorBicicleta(eBicicleta bicicletas[], int tamB,eTrabajo trabajos[], int tamTR,eTipo tipos[],
                         int tamT, eColor colores[],int tamC, eServicio servicios[],int tamS);

/** \brief pide al usuario una bicicleta y acumula el costo de los servicios realizados en la misma.
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamTR int dimension del array de trabajos
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \param servicios[] eServicio array de servicios
 * \param tamS int dimension del array de servicios
 * \return int retorna 1 si la bicicleta tiene al menos un trabajo asociado, sino retorna 0 (tambien en caso de error)
 *
 */
int importePorBicicleta(eBicicleta bicicletas[], int tamB,eTrabajo trabajos[], int tamTR,eTipo tipos[],
                        int tamT, eColor colores[],int tamC, eServicio servicios[],int tamS);

/** \brief pide al usuario un servicio y muestra las bicicletas a las cuales se le realizo el servicio junto con la fecha
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamTR int dimension del array de trabajos
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \param servicios[] eServicio array de servicios
 * \param tamS int dimension del array de servicios
 * \return int retorna 1 si hay al menos una bicicleta que mostrar, sino retorna 0 (tambien en caso de error)
 *
 */
int mostrarBicicletasPorServicio(eBicicleta bicicletas[], int tamB,eTrabajo trabajos[], int tamTR,eTipo tipos[],
                                 int tamT, eColor colores[],int tamC, eServicio servicios[],int tamS);

/** \brief pide al usuario una fecha valida y muestra los trabajos realizados en esa fecha.
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamB int dimension del array de bicicletas
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamTR int dimension del array de trabajos
 * \param tipos[] eTipo array de tipos
 * \param tamT int dimension del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int dimension del array de colores
 * \param servicios[] eServicio array de servicios
 * \param tamS int dimension del array de servicios
 * \return int retorna 1 si en la fecha hay al menos un trabajo realizado, sino retorna 0 (tambien en caso de error)
 *
 */
int mostrarServiciosPorFecha(eBicicleta bicicletas[], int tamB,eTrabajo trabajos[], int tamTR,eTipo tipos[],
                             int tamT, eColor colores[],int tamC, eServicio servicios[],int tamS);

