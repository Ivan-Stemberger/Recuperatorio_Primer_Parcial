#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabajo.h"
#include "Validaciones.h"

/** \brief Inicializa el array, colocando todos los valores en 0 o vacío.
 *
 * \param trabajo ETrabajo* El puntero al primer elemento del array
 * \param len int tamaño del array.
 * \return void
 *
 */
void initialize_list(ETrabajo* trabajo,int len)
{
    int i;
    int id = 20000;


    for(i=0;i<len;i++)
    {

        (*trabajo).id = id;
        strcpy((*trabajo).marcaBicicleta,"");
        strcpy((*trabajo).rodadoBicicleta,"");
        (*trabajo).idServicio.id = 0;
        (*trabajo).fecha.dia = 0;
        (*trabajo).fecha.mes = 0;
        (*trabajo).fecha.anio = 0;
        (*trabajo).isEmpty = 1;
        id++;
        trabajo++;
    }
}


ETrabajo* find_empty(ETrabajo* trabajo,int len)
{
    int i;
    ETrabajo* trabajoAux = NULL;

    for(i=0;i<len;i++)
    {
        if((*trabajo).isEmpty)
        {
            trabajoAux = trabajo;
            break;
        }

        trabajo++;
    }

    return trabajoAux;
}

int find_byId(ETrabajo* trabajo,int len, int id)
{
    int i;
    int found = 0;

    for(i=0;i<len;i++)
    {
        if((*trabajo).id == id)
        {
            found = id;
            break;
        }
        trabajo++;
    }

    return found;
}

int new_trabajo(ETrabajo* trabajo, int len)
{
    int created = 0;
    ETrabajo* trabajoAux;
    char marca[60];
    char rodado[60];
    char idServicio[10];
    char dia[4];
    char mes[4];
    char anio[4];

    trabajoAux = find_empty(trabajo,len);

   if(trabajoAux != NULL)
   {

       do
       {
    	   printf("Por favor ingrese la marca de la bicicleta.\n");
    	   fflush(stdout);
    	   scanf("%s",marca);
       }while(!soloLetras(marca));


       do
       {
    	   printf("Por favor ingrese el rodado de la bicicleta.\n");
    	   fflush(stdout);
    	   scanf("%s",rodado);
       }while(!soloLetras(rodado));



       do
       {
    	   printf("Por favor ingrese el ID del servicio.\n");
    	   fflush(stdout);
    	   scanf("%s",idServicio);
       }while(!esNumerico(idServicio));



       do
       {
           printf("Por favor ingrese el dia.\n");
           fflush(stdout);
           scanf("%s",dia);
       }while(!validacionDia(dia));


       do
       {
           printf("Por favor ingrese el mes.\n");
           fflush(stdout);
           scanf("%s",mes);
       }while(!validacionMes(mes));

       do
       {
           printf("Por favor ingrese el anio.\n");
           fflush(stdout);
           scanf("%s",anio);
       }while(!validacionYear(anio));

       new_trabajoParametros(trabajoAux, marca, rodado, idServicio, dia, mes, anio);
       created = 1;


   }


    return created;
}

int new_trabajoParametros(ETrabajo* trabajo, char* marca, char* rodado, char* idServicio, char* dia, char* mes, char* anio)
{
    int set = 0;

    if(trabajo != NULL)
    {
        set_marca(trabajo,marca);
        set_rodado(trabajo,rodado);
        set_idServicio(trabajo,idServicio);
        set_dia(trabajo,dia);
        set_mes(trabajo,mes);
        set_anio(trabajo,anio);
        (*trabajo).isEmpty = 0;
        set = 1;
    }

    return set;
}

int modify_trabajo(ETrabajo* trabajo,int len)
{
    int id;
    char idAux[6];
    int opcion;
    int modified = 0;
    char toModify[128];
    ETrabajo* trabajoAux;

    do
    {
		printf("Por favor introduzca el id del trabajo a modificar.\n");
		fflush(stdout);
		scanf("%s",idAux);
    }while(!esNumerico(idAux));

    id = atoi(idAux);
    if(find_byId(trabajo,len,id))
    {
        trabajoAux = getTrabajo_byID(trabajo,len,id);

        printf("Por favor elija una opcion.\n"
               "1) Marca.\n"
               "2) ID del Servicio.\n");
        fflush(stdout);

         scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            {
            	do
            	{
					printf("Por favor ingrese la marca de la bicicleta.\n");
					fflush(stdout);
					scanf("%s",toModify);
            	}while(!soloLetras(toModify));
                set_marca(trabajoAux,toModify);
                break;
            }


            case 2:
            {
                do
                {
             	   printf("Por favor ingrese el ID del servicio.\n");
             	   fflush(stdout);
             	   scanf("%s",toModify);
                }while(!esNumerico(toModify));
            }

        }

        modified = 1;

    }
    else
    {
        printf("El ID no existe.\n");
        fflush(stdout);
    }
    return modified;
}



int remove_trabajo(ETrabajo* trabajo, int len)
{
    int id;
    char idAux[6];
    ETrabajo* trabajoAux;
    int deleted = 0;

    do
    {
        printf("Por favor introduzca el id del trabajo a eliminar.\n");
        fflush(stdout);
        scanf("%s",idAux);
    }while(esNumerico(idAux));

    id = atoi(idAux);

    if(find_byId(trabajo,len,id))
    {
    	trabajoAux = getTrabajo_byID(trabajo,len,id);
    	(*trabajoAux).isEmpty = 1;
        deleted = 1;
    }
    else
    {
        printf("El ID no existe.\n");
        fflush(stdout);
    }

    return deleted;
}

int selectOrder(ETrabajo trabajo[], int len)
{
    int order;
    int selected = 0;

    printf("Por favor seleccione el orden del listado\n."
           "1) Ascendiente.\n"
           "2) Descendiente.\n");
    fflush(stdout);
    scanf("%d",&order);

    if(sort_trabajos(trabajo,len,order))
    {
        selected = 1;
    }
    return selected;
}

int selectMarcaOrder(ETrabajo trabajo[], int len)
{
	int order;
	int selected = 0;

	    printf("Por favor seleccione el orden del listado.\n"
	           "1) Ascendiente.\n"
	           "2) Descendiente.\n");
	    fflush(stdout);
	    scanf("%d",&order);

	    if(sort_byMarca(trabajo,len,order))
	    {
	        selected = 1;
	    }
	    return selected;
}

int sort_trabajos(ETrabajo trabajo[], int len, int order)
{
    int sorted = 0;

    if(trabajo !=NULL)
    {
        switch(order)
        {
            case 1:
            {
                sort_byAnioAscend(trabajo,len);
                sort_byMarcaAscend(trabajo,len);
                sorted = 1;
                break;
            }
            case 2:
            {
                sort_byAnioDescend(trabajo,len);
                sort_byMarcaDescend(trabajo,len);
                sorted = 1;
                break;
            }
        }
    }

    return sorted;

}

int sort_byMarca(ETrabajo trabajo[], int len, int order)
{
	int sorted = 0;

	    if(trabajo !=NULL)
	    {
	        switch(order)
	        {
	            case 1:
	            {
	                sort_byMarcaAscend(trabajo,len);
	                sorted = 1;
	                break;
	            }
	            case 2:
	            {
	                sort_byMarcaDescend(trabajo,len);
	                sorted = 1;
	                break;
	            }
	        }
	    }

	    return sorted;
}

void sort_byAnioAscend(ETrabajo trabajo[], int len)
{

    int i;
    int j;
    ETrabajo aux;


    for(i=1;i<len;i++)
    {

        aux = trabajo[i];

        j= i - 1;

        while(j>=0 && aux.fecha.anio<trabajo[j].fecha.anio)
        {
            trabajo[j+1] = trabajo[j];
            j--;

        }
        trabajo[j+1] = aux;
    }


}

void sort_byAnioYMarcaAscend(ETrabajo* trabajo, int len)
{

	int i;
	int j;
	ETrabajo aux;

	for(i=1;i<len;i++)
	{

		aux = trabajo[i];

	    j= i - 1;

        while(j>=0 && strcmp(aux.marcaBicicleta,trabajo[j].marcaBicicleta)<0 && aux.fecha.anio==trabajo[j].fecha.anio)
        {
            trabajo[j+1] = trabajo[j];
            j--;
        }

        trabajo[j+1] = aux;
    }

}

void sort_byMarcaAscend(ETrabajo* trabajo, int len)
{

	int i;
	int j;
	ETrabajo aux;

	for(i=1;i<len;i++)
	{

		aux = trabajo[i];

	    j= i - 1;

        while(j>=0 && strcmp(aux.marcaBicicleta,trabajo[j].marcaBicicleta)<0)
        {
            trabajo[j+1] = trabajo[j];
            j--;
        }

        trabajo[j+1] = aux;
    }

}


void sort_byAnioDescend(ETrabajo* trabajo, int len)
{

	int i;
	int j;
	ETrabajo aux;


	for(i=1;i<len;i++)
	{

		aux = trabajo[i];

		j= i - 1;

		while(j>=0 && aux.fecha.anio>trabajo[j].fecha.anio)
		{
			trabajo[j+1] = trabajo[j];
			j--;
		}
		trabajo[j+1] = aux;
	}

}

void sort_byMarcaYAnioDescend(ETrabajo* trabajo, int len)
{

	int i;
	int j;
	ETrabajo aux;

	for(i=1;i<len;i++)
	{

		aux = trabajo[i];

		j= i - 1;

	    while(j>=0 && strcmp(aux.marcaBicicleta,trabajo[j].marcaBicicleta)>0 && aux.fecha.anio==trabajo[j].fecha.anio)
	    {
			trabajo[j+1] = trabajo[j];
			j--;
	    }

	    trabajo[j+1] = aux;
	}

}

void sort_byMarcaDescend(ETrabajo* trabajo, int len)
{

	int i;
	int j;
	ETrabajo aux;

	for(i=1;i<len;i++)
	{

		aux = trabajo[i];

		j= i - 1;

	    while(j>=0 && strcmp(aux.marcaBicicleta,trabajo[j].marcaBicicleta)>0)
	    {
			trabajo[j+1] = trabajo[j];
			j--;
	    }

	    trabajo[j+1] = aux;
	}

}

int moreServicesDone(ETrabajo* trabajo, int len, EServicio* servicio, int lenServicio)
{
	int i;
	int j;
	int id;
	int id2 = 0;
	int id3 = 0;
	int id4 = 0;
	int cantidad = 0;
	int mayor = 0;
	int listed = 0;
	for(i=0;i<lenServicio;i++)
	{
		for(j=0;j<len;j++)
		{
			if((*servicio).id == (*trabajo).idServicio.id)
			{
				cantidad++;
				trabajo++;
				listed = 1;
			}

			if(cantidad>mayor)
			{
				mayor = cantidad;
				id = i+1;
			}
			if(cantidad == mayor)
			{
				id2 = i+1;
			}
			if(cantidad == mayor && id2 != i+1)
			{
				id3 = i+1;
			}
			if(cantidad == mayor && id3 != i+1)
			{
				id4 = i+1;
			}
		}
	}

	listar_ServiciosById(servicio,lenServicio,id);
	if(id2 != 0)
	{
		listar_ServiciosById(servicio,lenServicio,id2);
	}
	if(id3 != 0)
	{
		listar_ServiciosById(servicio,lenServicio,id3);
	}
	if(id4 != 0)
	{
		listar_ServiciosById(servicio,lenServicio,id4);
	}

	return listed;


}


void listar_trabajos(ETrabajo* trabajo, int len)
{
    int i;

    printf("ID || Marca || Rodado || Servicio || Fecha(DD/MM/AAAA)\n");
    fflush(stdout);

    for(i=0;i<len;i++)
    {
        if(!(*trabajo).isEmpty)
        {
            printf("%d || %s || %s || %d || %d/%d/%d\n",(*trabajo).id,(*trabajo).marcaBicicleta,(*trabajo).rodadoBicicleta, (*trabajo).idServicio.id,(*trabajo).fecha.dia,(*trabajo).fecha.mes,(*trabajo).fecha.anio);
            fflush(stdout);
        }
        trabajo++;

    }
}

int calcularTotal(ETrabajo* trabajo, int len, EServicio* servicio, int lenServicio)
{
    int i;
    int parcial;
    int total= 0;

    for(i=0;i<len;i++)
    {
        parcial = findPrecio_byId(servicio,lenServicio,(*trabajo).idServicio.id);
        total = parcial + total;
        trabajo++;
    }

    return total;

}

int set_marca(ETrabajo* trabajo, char* marca)
{
    strcpy((*trabajo).marcaBicicleta,marca);

    return 1;
}

int set_rodado(ETrabajo* trabajo, char* rodado)
{
    strcpy((*trabajo).rodadoBicicleta,rodado);
    return 1;
}

int set_idServicio(ETrabajo* trabajo, char* idServicio)
{
    (*trabajo).idServicio.id = atoi(idServicio);
    return 1;
}

int set_dia(ETrabajo* trabajo, char* dia)
{
    (*trabajo).fecha.dia = atoi(dia);
    return 1;
}

int set_mes(ETrabajo* trabajo, char* mes)
{
    (*trabajo).fecha.mes = atoi(mes);
    return 1;
}

int set_anio(ETrabajo* trabajo, char* anio)
{
    (*trabajo).fecha.anio = atoi(anio);
    return 1;
}

ETrabajo* getTrabajo_byID(ETrabajo* trabajo, int len, int id)
{
    int i;
    ETrabajo* trabajoAux;

    for(i=0;i<len;i++)
    {
        if((*trabajo).id == id && (*trabajo).isEmpty == 0)
        {
            trabajoAux = trabajo;
        }
        trabajo++;
    }

    return trabajoAux;
}
