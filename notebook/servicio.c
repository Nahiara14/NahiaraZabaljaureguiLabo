#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"

void mostrarServicios(eServicio servicios[], int tam)
{
    printf("-------------------------------------------\n");
    printf("   <<<<<   Listado de Servicios >>>>>\n\n");
    printf("          Id  Descripcion  precio \n");
    printf("--------------------------------------------\n");

    for(int i=0; i<tam; i++)
    {
        mostrarServicio(servicios[i]);
    }

}

void mostrarServicio(eServicio unServicio)
{
    printf(" %d    %10s  %f \n", unServicio.id, unServicio.descripcion, unServicio.precio);
}

int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char descrip[])
{
    int todoOk=0;

    if(id >=20000 && id <=20004 && servicios != NULL && tam >0 && descrip !=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(descrip, servicios[i].descripcion);
                int todoOk=1;
                break;
            }
        }
    }

    return todoOk;

}

int validarIdServicios(int id, eServicio servicios[], int tam)
{
    int valido=0;

    if(servicios != NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id==id)
            {
                valido=1;
                break;
            }
        }
    }

    return valido;
}
int buscarServicio(int id, eServicio servicios[], int tam)
{
    int valido=0;

    if( servicios!= NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id==id)
            {
                valido=i;
                break;
            }
        }
    }

    return valido;
}
