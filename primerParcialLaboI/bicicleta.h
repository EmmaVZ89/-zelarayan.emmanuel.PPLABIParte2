#include "tipo.h"
#include "color.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
} eBicicleta;


#endif // BICICLETA_H_INCLUDED

/** \brief Muetra el menu principal y espera que el usuario ingrese un numero entero
 *
 * \return int retorna el numero que ingrese el usuario en el rango 1 a 10, inclusive.
 *
 */
int menuPrincipal();


/** \brief pide al usuario el ingreso de los campos de una estructura bicicleta y autoincrementa el numero de Id.
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension del array de bicicletas
 * \param idBicicleta int* puntero con el numero de id de una bicicleta
 * \param tipos[] eTipo array de tipos de bicicleta
 * \param tamT int dimension del array de tipos de bicicleta
 * \param colores[] eColor array de colores de bicicleta
 * \param tamC int dimension del array de colores de bicicleta
 * \return int retorna 1 si se pudo hacer la carga exitosa, retorna 0 si hubo error en realizar la carga o memoria NULL.
 *
 */
int altaBicicleta(eBicicleta bicicletas[], int tam, int* idBicicleta, eTipo tipos[], int tamT,eColor colores[],int tamC);

/** \brief cambia todos los campos isEmpty del array de bicicletas a 1.
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension de array de bicicletas
 * \return int retorna 1 si se realizo la tarea, retorna 0 en caso de error.
 *
 */
int inicializarBicicletas(eBicicleta bicicletas[], int tam);

/** \brief busca el primer indice libre en el array de bicicletas
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension de array de bicicletas
 * \return int retorna el numero de indice, en caso de no encontrarlo retorna -1 (tambien en caso de error)
 *
 */
int buscarLibreBicicleta(eBicicleta bicicletas[], int tam);

/** \brief pide al usuario un numero de id de una bicicleta y realiza una baja logica, cambiando el campo isEmpty a 1.
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension de array de bicicletas
 * \param tipos[] eTipo array de tipos de bicicletas
 * \param tamT int dimension de array de tipos de bicicletas
 * \param colores[] eColor array de colores de bicicletas
 * \param tamC int dimension del array de colores de bicicletas
 * \return int retorna 1 si se pudo realizar la baja, retorna 0 si la cancelo el usuaio o en caso de error.
 *
 */
int bajaBicicleta(eBicicleta bicicletas[], int tam,eTipo tipos[],int tamT,eColor colores[],int tamC);

/** \brief busca el indice de una bicicleta por su numero de id
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension del array de bicicletas
 * \param idBicicleta int numero de id de una bicicleta
 * \return int si se encuentra la bicicleta retorna su numero de indice, sino retorna -1 (tambien en caso de error)
 *
 */
int buscarBicicleta(eBicicleta bicicletas[], int tam, int idBicicleta);

/** \brief muestra un listado de todas las bicicletas dadas de alta, mostrando sus campos.
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension del array de bicicletas
 * \param tipos[] eTipo array de tipo de bicicletas
 * \param tamT int dimension del array de tipo de bicicletas
 * \param colores[] eColor array de colores de bicicletras
 * \param tamC int dimension del array de colores de bicicletas
 * \return int retorna 1 si se pudo mostrar alguna bicicleta, sino hay nada que mostrar retorna 0 (tambien en caso de error)
 *
 */
int mostrarBicicletas(eBicicleta bicicletas[], int tam, eTipo tipos[],int tamT, eColor colores[],int tamC);

/** \brief muestra los campos de una bicicleta
 *
 * \param bicicleta eBicicleta estructura de una bicicleta
 * \param tipos[] eTipo array de tipos de bicicletas
 * \param tamT int  dimension del array de tipos de bicicletas
 * \param colores[] eColor array de colores de bicicletas
 * \param tamC int dimension del array de colores de bicicletas
 * \return int retorna 1 si se pudo mostrar, retorna 0 sino se pudo mostrar (tambien en caso de error)
 *
 */
int mostrarBicicleta(eBicicleta bicicleta,eTipo tipos[],int tamT,eColor colores[],int tamC);

/** \brief muestra el menu de modificacion de bicicleta y espera que el usuario ingrese un numero entero
 *
 * \return int retorna el numero ingresado por el usuario, 1 al 3 inclusive.
 *
 */
int subMenuModificarBicicleta();

/** \brief espera que el usuario ingrese los campos idTipo y rodado de una bicicleta, espera confirmacion para realizar los cambios.
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension del array de bicicletas
 * \param tipos[] eTipo array de tipos de bicicletas
 * \param tamT int dimension del array de tipos de bicicletas
 * \param colores[] eColor array de colores de bicicletas
 * \param tamC int dimensio del array de colores de bicicletas
 * \return int retorna 1 si se realizan los cambios, retorna 0 si se cancelan (tambien en caso de error)
 *
 */
int modificarBicicletas(eBicicleta bicicletas[], int tam,eTipo tipos[],int tamT,eColor colores[],int tamC);

/** \brief intercambia el numero de id de una bicicleta por su marca en el listado que se muestra al usuario
 *
 * \param idBicicleta int id de una bicicleta
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension del array de bicicletas
 * \param marca[] char cadena donde se guarda la marca de la bicicleta
 * \return int retorna 1 si se pudo realizar la carga de la marca, retorna 0 si no se pudo (tambien en caso de error)
 *
 */
int cargarMarcaBicicleta(int idBicicleta, eBicicleta bicicletas[], int tam, char marca[]);

/** \brief ordena el lista de bicicletas por tipo y rodado
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension del array de bicicletas
 * \return int retorna 1 si se pudo ordenar, retorna 0 en caso de error.
 *
 */
int ordenarBicicletas(eBicicleta bicicletas[], int tam);

/** \brief verifica si todos los elementos del array de bicicletas estan vacios
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int dimension del array de bicicletas
 * \return int retorna 1 si el array esta totalmente vacio, retorna 0 si no lo esta (tambien en caso de error)
 *
 */
int todoVacioBicicletas(eBicicleta bicicletas[], int tam);
