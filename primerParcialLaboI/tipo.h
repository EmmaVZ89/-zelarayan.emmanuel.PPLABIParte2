#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];
} eTipo;

#endif // TIPO_H_INCLUDED

/** \brief muestra el listado de tipos de bicicletas
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int dimension del array de tipos
 * \return int retorna 1 si se pudo mostrar, sino retorna 0 (tambien en caso de error)
 *
 */
int mostrarTipos(eTipo tipos[], int tam);

/** \brief muestra los campos de una estructura tipo
 *
 * \param tipo eTipo estructura tipo
 * \return void
 *
 */
void mostrarTipo(eTipo tipo);

/** \brief intercambia en el listado que se muestra el usuario el id del tipo y la descripcion, para que se vea unicamente la descripcion.
 *
 * \param idTipo int id de un tipo
 * \param tipos[] eTipo array de tipos
 * \param tam int dimension del array de tipos
 * \param desc[] char cadena donde se guarda la descripcion del tipo
 * \return int retorna 1 si se pudo cargar la descripcion del tipo, sino retorna 0 (tambien en caso de error)
 *
 */
int cargarDescripcionTipo(int idTipo, eTipo tipos[], int tam, char desc[]);

/** \brief busca por su numero de id a un tipo
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int dimension del array de tipos
 * \param idTipo int id de un tipo
 * \return int si se encuentra el tipo retorna el numero de indice, sino retorna -1 ( tambien en caso de error)
 *
 */
int buscarTipo(eTipo tipos[], int tam, int idTipo);
