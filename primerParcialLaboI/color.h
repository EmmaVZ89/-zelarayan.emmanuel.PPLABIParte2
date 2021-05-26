#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[21];
} eColor;

#endif // COLOR_H_INCLUDED

/** \brief muestra los campos de la estructura eColor
 *
 * \param colores[] eColor array de colores
 * \param tam int dimension del array de colores
 * \return int retorna 1 si se pudo mostrar, retorna 0 si no se pudo mostrar nada (tambien en caso de error)
 *
 */
int mostrarColores(eColor colores[], int tam);

/** \brief muestra los campos de una estructura eColor
 *
 * \param color eColor estructura color
 * \return void
 *
 */
void mostrarColor(eColor color);

/** \brief intercambia en el listado que se muestra al usuario el numero de id y el nombre del color.
 *
 * \param idColor int id de un color
 * \param colores[] eColor array de colores
 * \param tam int dimension del array de colores
 * \param nombreColor[] char cadena donde se guarda el nombre del color
 * \return int retorna 1 si se pudo cargar el color, retorna 0 si no se pudo o en caso de error.
 *
 */
int cargarNombreColor(int idColor, eColor colores[], int tam, char nombreColor[]);

/** \brief busca a un color por el numero de id
 *
 * \param colores[] eColor array de colores
 * \param tam int dimension del array de colores
 * \param idColor int numero de id del color a buscar
 * \return int retorna el indice del color encontrado, si no se encontro retorna -1 (tambien en caso de error.
 *
 */
int buscarColor(eColor colores[], int tam, int idColor);
