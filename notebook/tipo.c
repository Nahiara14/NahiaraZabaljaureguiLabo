#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
void mostrarTipos(eTipo tipos[], int tam)
{
    printf("-------------------------------------------\n");
    printf("   <<<<<   Listado de tipos  >>>>>\n\n");
    printf("          Id  Descripcion \n");
    printf("--------------------------------------------\n");

    for(int i=0; i<tam; i++)
    {
        mostrarTipo(tipos[i]);
    }

}

void mostrarTipo(eTipo unTipo)
{
    printf(" %d    %10s   \n", unTipo.id,unTipo.descripcion );
}

int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char descrip[])
{
    int todoOk=0;

    if(id >=5000 && id <=5004 && tipos != NULL && tam >0 && descrip !=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id == id)
            {
                strcpy(descrip, tipos[i].descripcion);
                int todoOk=1;
                break;
            }
        }
    }

    return todoOk;

}

int validarIdTipo(int id, eTipo tipos[], int tam)
{
    int valido=0;

    if(tipos != NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id==id)
            {
                valido=1;
                break;
            }
        }
    }

    return valido;
}
int buscarTipo(int id, eTipo tipos[], int tam)
{
    int valido=0;

    if( tipos!= NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id==id)
            {
                valido=i;
                break;
            }
        }
    }

    return valido;
}
