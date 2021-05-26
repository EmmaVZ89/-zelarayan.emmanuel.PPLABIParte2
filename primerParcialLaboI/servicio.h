#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[26];
    float precio;
} eServicio;


#endif // SERVICIO_H_INCLUDED

/** \brief muestra el listado de servicios
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int dimension del array de servicios
 * \return int retorna 1 si se mostro algun servicio, sino retorna 0 (tambien en caso de error)
 *
 */
int mostrarServicios(eServicio servicios[], int tam);

/** \brief muestra los campos de una estructura eServicio
 *
 * \param servicio eServicio estructura eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief intercambia en el listado que se muestra al usuario el numero de id y el nombre del servicio, para que se vea unicamente el nombre.
 *
 * \param idServicio int id de un servicio
 * \param servicios[] eServicio array de servicios
 * \param tam int dimension del array de servicios
 * \param nombreServicio[] char cadena donde se guarda el nombre de servicio
 * \return int retorna 1 si se pudo cargar el nombre del servicio, sino retorna 0 (tambien en caso de error)
 *
 */
int cargarNombreServicio(int idServicio, eServicio servicios[], int tam, char nombreServicio[]);

/** \brief busca un servicio por su numero de id
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int dimension del array de servicios
 * \param idServicio int id del
 * \return int si se encuentra el servicio retorna el numero de indice, sino retorna -1 (tambien en caso de error)
 *
 */
int buscarServicio(eServicio servicios[], int tam, int idServicio);
