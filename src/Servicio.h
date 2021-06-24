#ifndef servicio_H_INCLUDED
#define servicio_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[128];
    int precio;
}EServicio;


/** \brief Muestra por pantalla los servicios.
 *
 * \param servicio EServicio* El puntero al primer elemento del array
 * \param len int tamaño del array.
 *
 * \return
 */
void listar_Servicios(EServicio* servicio, int len);

/** \brief Busca un servicio por ID y devuelve su precio.
 *
 * \param servicio EServicio* El puntero al primer elemento del array
 * \param len int tamaño del array.
 * \param id int id del servicio a buscar.
 *
 * \return el precio del servicio, si no lo encuentra 0.
 */
int findPrecio_byId(EServicio* servicio, int len, int id);

void listar_ServiciosById(EServicio* servicio, int len, int id);

#endif // servicio_H_INCLUDED
