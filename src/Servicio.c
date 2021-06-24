#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"



int findPrecio_byId(EServicio* servicio, int len, int id)
{
    int i;
    int precio = 0;

    for(i=0;i<len;i++)
    {

        if((*servicio).id == id)
        {
            precio = (*servicio).precio;
            break;
        }
        servicio++;
    }

    return precio;
}

void listar_Servicios(EServicio* servicio, int len)
{
    int i;

    printf("ID || Descripcion || Precio\n");
    fflush(stdout);

    for(i=0;i<len;i++)
    {
        printf("%d,%s,%d\n",(*servicio).id,(*servicio).descripcion,(*servicio).precio);
        fflush(stdout);
        servicio++;
    }
}
