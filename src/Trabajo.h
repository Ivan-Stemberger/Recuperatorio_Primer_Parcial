#ifndef trabajo_H_INCLUDED
#define trabajo_H_INCLUDED
#include "Servicio.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}EFecha;


typedef struct
{
    int id;
    char marcaBicicleta[128];
    char rodadoBicicleta[128];
    EServicio idServicio;
    EFecha fecha;
    int isEmpty;
}ETrabajo;

/** \brief Inicializa el array, colocando todos los valores en 0 o vacío.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 *
 */
void initialize_list(ETrabajo* trabajo,int len);

/** \brief Busca un elemento de la lista vacío y devuelve su puntero.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 * \return puntero al elemento vacío.
 *
 */
ETrabajo* find_empty(ETrabajo* trabajo,int len);

/** \brief Busca un ID en el array..
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 * \param id int id a buscar
 * \return el id si lo encuentra, 0 si no.
 *
 */
int find_byId(ETrabajo* trabajo,int len, int id);

/** \brief Crea un nuevo trabajo.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 * \return 1 si la creación fue exitosa, 0 si no.
 *
 */
int new_trabajo(ETrabajo* trabajo, int len);

/** \brief Asigna lo ingresado por el usuario al elemento.
 *
 * \param trabajo ETrabajo* El puntero al elemento a crear.
 * \param marcha char* marca de la bicicleta.
 * \param rodado char* rodado de la bicicleta.
 * \param idServicio char* id del servicio que se solicita.
 * \param dia char* dia en que se crea el trabajo.
 * \param mes char* mes en que se crea el trabajo.
 * \param anio char* año en que se crea el trabajo.
 * \return 1 si fue exitoso, 0 si no.
 *
 */
int new_trabajoParametros(ETrabajo* trabajo, char* marca, char* rodado, char* idServicio, char* dia, char* mes, char* anio);

/** \brief Modifica un trabajo.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 * \return 1 si la modificación fue exitosa, 0 si no.
 *
 */
int modify_trabajo(ETrabajo* trabajo,int len);

/** \brief Elimina un trabajo.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 * \return 1 si la eliminación fue exitosa, 0 si no.
 *
 */
int remove_trabajo(ETrabajo* trabajo, int len);

/** \brief Se le pide al usuario el orden en que quiere ordenar el listado (Ascendiente o descendiente).
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 * \return 1 si el ordenamiento fue exitoso, 0 si no.
 *
 */
int selectOrder(ETrabajo* trabajo, int len);

/** \brief Ordena el array en función del orden solicitado.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 * \param order int el orden en que se deberá ordenar (1 - Asc, 2 - Desc).
 * \return 1 si el ordenamiento fue exitoso, 0 si no.
 *
 */
int sort_trabajos(ETrabajo* trabajo, int len, int order);

/** \brief Ordena el array por año de manera ascendente.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 *
 */
void sort_byAnioAscend(ETrabajo* trabajo, int len);

/** \brief Ordena el array por marca de manera ascendente cuando el año es igual entre dos elementos.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 *
 */
void sort_byMarcaAscend(ETrabajo* trabajo, int len);

/** \brief Ordena el array por año de manera descendente.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 *
 */
void sort_byAnioDescend(ETrabajo* trabajo, int len);

/** \brief Ordena el array por marca de manera descendente cuando el año es igual entre dos elementos.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 *
 */
void sort_byMarcaDescend(ETrabajo* trabajo, int len);

/** \brief Muestra por pantalla el array de Trabajo.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 *
 */
void listar_trabajos(ETrabajo* trabajo, int len);

/** \brief Calcula el total en pesos de los trabajos realizados.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 *
 * return sumatoria total de los trabajos realizados
 */
int calcularTotal(ETrabajo* trabajo, int len, EServicio* servicio, int lenServicio);

int set_marca(ETrabajo* trabajo, char* marca);
int set_rodado(ETrabajo* trabajo, char* rodado);
int set_idServicio(ETrabajo* trabajo, char* idServicio);
int set_dia(ETrabajo* trabajo, char* dia);
int set_mes(ETrabajo* trabajo, char* mes);
int set_anio(ETrabajo* trabajo, char* anio);

/** \brief busca un trabajo por ID y devuelve su puntero.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 * \param id int id a buscar.
 *
 * return puntero al trabajo encontrado.
 */
ETrabajo* getTrabajo_byID(ETrabajo* trabajo, int len, int id);


#endif // trabajo_H_INCLUDED
