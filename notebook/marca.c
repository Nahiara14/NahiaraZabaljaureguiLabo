#include <stdio.h>
#include <stdlib.h>
#include "marca.h"

void mostrarMarcas(eMarca marcas[], int tam)
{
    printf("-------------------------------------------\n");
    printf("   <<<<<   Listado de Marcas  >>>>>\n\n");
    printf("          Id  Descripcion \n");
    printf("--------------------------------------------\n");

    for(int i=0; i<tam; i++)
    {
        mostrarMarca(marcas[i]);
    }

}

void mostrarMarca(eMarca unaMarca)
{
    printf(" %d    %10s   \n", unaMarca.id, unaMarca.descripcion);
}

int cargarDescripcionMarca(int id, eMarca marcas[], int tam, char descrip[])
{
    int todoOk=0;

    if(id >=1000 && id <=1004 && marcas != NULL && tam >0 && descrip !=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(marcas[i].id == id)
            {
                strcpy(descrip, marcas[i].descripcion);
                int todoOk=1;
                break;
            }
        }
    }

    return todoOk;

}

int validarIdMarcas(int id, eMarca marcas[], int tam)
{
    int valido=0;

    if(marcas != NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            if(marcas[i].id==id)
            {
                valido=1;
                break;
            }
        }
    }

    return valido;
}
int buscarMarca(int id, eMarca marcas[], int tam)
{
    int valido=0;

    if( marcas!= NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            if(marcas[i].id==id)
            {
                valido=i;
                break;
            }
        }
    }

    return valido;
}
