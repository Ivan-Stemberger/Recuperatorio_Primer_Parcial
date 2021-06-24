#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int esNumerico(char auxiliar[])
{
    int i = 0;
    int esNumerico = 1;


    while(auxiliar[i] != '\0')
    {

        if(auxiliar[i] < '0' || auxiliar[i] > '9')
        {

            esNumerico = 0;

        }
        i++;

    }
    return esNumerico;
}


int soloLetras(char auxiliar[])
{
    int i = 0;
    int error = 1;

    while(auxiliar[i]!= '\0')
    {
        if((auxiliar[i] != ' ') &&(auxiliar[i] < 'a' || auxiliar[i] > 'z') && (auxiliar[i]<'A' || auxiliar[i]>'Z'))
        {
            error = 0;

        }
        i++;
    }

    return error;
}

int esAlfaNumerico(char auxiliar[])
{
    int i = 0;
    int arroba = 0;
    int guionBajo = 0;

    while(i != '\0')
    {
        if(auxiliar[i] == '@')
        {
            arroba++;
        }
        if(auxiliar[i] == '_')
        {
            guionBajo++;
        }

        if(auxiliar[i] == ' ' || auxiliar[i] == ',' || auxiliar[i] == ';' || auxiliar[i] == ':' || arroba > 1 || guionBajo > 2)
        {
            return 0;
        }

    }
    return 1;
}

int validacionTelefono(char auxiliar[])
{

    int i = 0;
    int contador = 0;

    while(auxiliar[i] != '\0')
    {
        if(auxiliar[i] == '-')
        {
            contador++;
        }

        if(((auxiliar[i] < '0' || auxiliar[i] > '9') && auxiliar[i] != '-') || contador > 2)
        {
            return 0;
        }


    }
    return 1;

}

int validacionSocio(char auxiliar[])
{
    if(soloLetras(auxiliar))
    {
        return 1;
    }
return 0;
}

int validacionLargo(char auxiliar[])
{
    if(strlen(auxiliar) > 31 || strlen(auxiliar) < 1)
    {
        return 0;
    }

    return 1;
}

int validacionSexo(char auxiliar)
{
    if(auxiliar != 'm' || auxiliar != 'f' || auxiliar != 'M' || auxiliar != 'F')
    {
        return 0;
    }

    return 1;
}

int validacionDia(char dia[])
{
    int auxDia;
    int esDia = 0;

    if(esNumerico(dia))
    {
        auxDia = atoi(dia);


        if(auxDia <= 31 && auxDia >= 1)
        {
            esDia = 1;
        }
    }

    return esDia;

}

int validacionMes(char mes[])
{
    int auxMes;
    int esMes = 0;

    if(esNumerico(mes))
    {
        auxMes = atoi(mes);

        if(auxMes <= 12 && auxMes >= 1)
        {
            esMes = 1;
        }
    }
   return esMes;
}

int validacionYear(char year[])
{
    int auxYear;
    int esAnio = 1;

    if(esNumerico(year))
    {
        auxYear = atoi(year);

        if(auxYear >= 1900 && auxYear <= 2021)
        {
            esAnio = 1;
        }
    }

    return esAnio;

}

