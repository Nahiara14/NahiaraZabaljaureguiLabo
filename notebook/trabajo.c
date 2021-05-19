#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
int altaTrabajo(eTrabajo trabajos[], int tamtrabajo , eNotebook lista[], int tamcomp, eMarca marca[], int tammarc, eTipo tipos[], int tamtip, int* pIdTrabajo)
{
    int todoOk=0;
    int indice;
    eTrabajo nuevoTrabajo;
    int id;
    int idMarca;
    int idTipo;

    if(trabajos != NULL && marca != NULL && lista != NULL && tipos != NULL && pIdTrabajo != NULL && tamcomp >0 && tammarc>0 && tamtip>0 && tamtrabajo>0)
    {
        printf("   <<<<<Alta Trabajo<<<<<< \n");
        indice=buscarLibreTrabajo(trabajos, tamtrabajo);
        if(indice== -1)
        {
            printf("No hay lugar en el sistema para trabajos\n\n");
        }
        else
        {
            mostrarNotebook(lista, tamcomp, tipos, tamtip, marca,tammarc);
            printf("Ingrese id de la notebook: ");
            scanf("%d", &id);

            while(buscarNotebook(lista, tamcomp, id) ==-1)
            {
                printf("No existe una notebook con ese ID. Reingrese ID: ");
                scanf("%d", &id);
            }
            nuevoTrabajo.id=id;
            mostrarMarca(marca, tammarc);

            printf("Ingrese Id marca: ");
            scanf("%d", &idMarca);
            while(!validarIdMarcas(idMarca, marca, tammarc))
            {
                printf(" Id invalido, reingrese Id de la marca: ");
                scanf("%d", &idMarca);
            }

            nuevoTrabajo.id=idTipo;
            printf("Ingrese tipo: ");
            scanf("%d", &idTipo);

            nuevoTrabajo.id=*pIdTrabajo;
            (*pIdTrabajo)++;
            nuevoTrabajo.isEmpty=0;
            trabajos[indice]=nuevoTrabajo;
            todoOk=1;
        }
    }

    return todoOk;
}
void mostrarTrabajo(eTrabajo trabajos[], int tamtrabajo , eNotebook lista[], int tamcomp, eServicio servicio[], int tamservi)
{
    int flag=1;

    printf("-------------------------------------------\n");
    printf("   <<<<<   Listado de Trabajos   >>>>>\n\n");
    printf("--------------------------------------------\n");
    printf("    IdTrabajo  IdNotebook  IdServicio  Fecha  \n\n");
    for(int i=0; i<tamalq; i++)
    {
        if( !trabajos[i].isEmpty)
        {
             mostrarTrabajo(trabajos[i], lista, tamcomp, servicio, tamservi, );
            flag=0;
        }

    }
    if(flag)
    {
        printf("No hay alquileres que mostrar\n");
    }
    printf("\n\n");
}
void mostrarTrabajos(eTrabajo unTrabajo , int tamtrabajo , eNotebook lista[], int tamcomp, eMarca marca[], int tammarc, eTipo tipos[], int tamtip)
{
    char nombreNotebook[20];//sacarlo de nombrecliente
    char DescripcionMarca[20];
    char DescripcionTipo[20];
    if(cargarNombreNotebook( unTrabajo.id , lista , tamcomp, nombreNotebook)
    {
        printf("   %d   %d    %10s  %d  %02d/%02d/%d \n",
               unTrabajo.id,
               unTrabajo.idNotebook,
               nombreNotebook,
               unTrabajo.idServicio
               unTrabajo.fecha.dia,
               unTrabajo.fecha.mes,
               unTrabajo.fecha.anio);
    }

}
int buscarLibreTrabajo(eTrabajo trabajo[], int tamtrabajo)
{
    int indice=-1;

    for(int i=0; i<tamtrabajo; i++)
    {
        if(trabajo[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void inicializarTrabajo(eTrabajo trabajos[], int tamtrabajo)
{
    for(int i=0; i<tamtrabajo; i++)
    {
        trabajos[i].isEmpty=1;
    }
}
