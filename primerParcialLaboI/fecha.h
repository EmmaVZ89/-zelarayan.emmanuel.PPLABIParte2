#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;


#endif // FECHA_H_INCLUDED

/** \brief compara dos estructura eFecha
 *
 * \param f1 eFecha primer estructura eFecha
 * \param f2 eFecha segunda estructura eFecha
 * \return int si las fechas son iguales retorna 1, sino retorna 0(tambien en caso de error)
 *
 */
int comparaFechas(eFecha f1, eFecha f2);

/** \brief valida que el ingreso de una fecha sea el correcto, teniendo en cuenta los dias, meses y anio biciestos
 *
 * \param dia int un dia
 * \param mes int un mes
 * \param anio int un anio
 * \return int si la fecha es valida retorna 1, sino retorna 0.
 *
 */
int validarFecha(int dia,int mes,int anio);
