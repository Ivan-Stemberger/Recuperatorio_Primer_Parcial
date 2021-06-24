#include <stdio.h>
#include <stdlib.h>
#include "Trabajo.h"
#include "Servicio.h"
#define len 100

int main()
{
    ETrabajo trabajo[len];
    EServicio servicio[4] = {{1,"Limpieza",250},{2,"Parche",300},{3,"Centrado",400},{4,"Cadena",500}};
    int alta = 0;
    int opcion;
    int total;

    initialize_list(trabajo,len);



    do
    {

    	printf("Por favor elija una opcion para continuar.\n"
               "1) Dar de alta un Trabajo. \n"
               "2) Modificar un trabajo existente.\n"
               "3) Dar de baja un trabajo.\n"
               "4) Listar trabajos por anio y marca.\n"
               "5) Listar Servicios\n"
               "6) Total en pesos por los servicios prestados\n"
               "7) Listado de trabajos ordenados por marca de bicicleta.\n"
    		   "8) Listar servicio con más trabajos realizados\n."
    		   "9)Salir.\n");
    	fflush(stdout);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            {
                if(new_trabajo(trabajo,len))
                {
                    printf("El trabajo ha sido correctamente cargado.\n");
                    fflush(stdout);
                    alta = 1;
                }

                break;
            }
            case 2:
            {
                if(alta)
                {
                    if(modify_trabajo(trabajo,len))
                    {
                        printf("El trabajo ha sido correctamente modificado.\n");
                        fflush(stdout);
                    }
                }
                else
                {
                    printf("Primero debe cargar al menos un trabajo.\n");
                    fflush(stdout);
                }

                break;
            }
            case 3:
            {
                if(alta)
                {
                    if(remove_trabajo(trabajo,len))
                    {
                        printf("El trabajo ha sido correctamente borrado.\n");
                        fflush(stdout);
                    }
                }
                else
                {
                    printf("Primero debe cargar al menos un trabajo.");
                    fflush(stdout);
                }
                break;
            }
            case 4:
            {
                if(alta)
                {
                    if(selectOrder(trabajo, len))
                    {
                        listar_trabajos(trabajo,len);
                    }
                }
                else
                {
                    printf("Primero debe cargar al menos un trabajo\n.");
                    fflush(stdout);
                }
                break;
            }
            case 5:
            {
                if(alta)
                {
                    listar_Servicios(servicio,4);
                }
                else
                {
                    printf("Primero debe cargar al menos un trabajo\n.");
                    fflush(stdout);
                }
                break;
            }
            case 6:
            {
                if(alta)
                {
                    total = calcularTotal(trabajo, len, servicio, 4);
                    printf("El valor total por los servicios prestados es %d\n",total);
                    fflush(stdout);
                }
                else
                {
                    printf("Primero debe cargar al menos un trabajo\n.");
                    fflush(stdout);
                }
                break;
            }
            case 7:
            {
            	if(alta)
            	{
            		selectMarcaOrder(trabajo,len);
            	}
                else
                {
                    printf("Primero debe cargar al menos un trabajo\n.");
                    fflush(stdout);
                }
                break;
            }
            case 8:
            {
            	if(alta)
            	{
            		selectMarcaOrder(trabajo,len);
            	}
                else
                {
                    printf("Primero debe cargar al menos un trabajo\n.");
                    fflush(stdout);
                }
            	break;
            }
            case 9:
            {
            	if(alta)
            	{
            		moreServicesDone(trabajo,len,servicio,4);
            	}
                else
                {
                    printf("Primero debe cargar al menos un trabajo\n.");
                    fflush(stdout);
                }
            	break;
            }
        }

    }while(opcion!=9);

    return 0;
}
