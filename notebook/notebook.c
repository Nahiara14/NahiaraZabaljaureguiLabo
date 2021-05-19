#include <stdio.h>
#include <stdlib.h>
#include "notebook.h"


int menu()
{
    int opcion;

    system("cls");//limpiamos la pantalla
    printf("   *** SERVICE DE NOTEBOOKS ***\n\n");
    printf("1.Alta notebook\n");
    printf("2.Modificar notebook\n");
    printf("3.Baja notebook\n");
    printf("4.Listar marcas\n");
    printf("5.Listar tipos\n");
    printf("6.Listar Servicios\n");
    printf("7.Alta trabajo\n");
    printf("8.Listar trabajos\n");
    printf("9.Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
void mostrarNotebook(eNotebook unaNotebook, eTipo tipos[], int tamtip, eMarca marca[], int tamMarc)
{


        printf(" %d %10s %d %10s %9.2f %s\n",
               unaNotebook.id,
               unaNotebook.modelo,
               unaNotebook.idMarca,
               unaNotebook.idTipo,
               unaNotebook.precio,
              );


}

void mostrarNotebooks(eNotebook lista[], int tam, eTipo tipos[], eMarca, int tamMarc, int tamtipos)
{
    int flag=1;

    printf("-------------------------------------------\n");
    printf("   <<<<<   Listado de Notebooks   >>>>>\n\n");
    printf("--------------------------------------------\n");
    printf(" Id   Modelo    idMarca    idTipo   Precio \n\n");
    for(int i=0; i<tam; i++)
    {
        if( !lista[i].isEmpty)
        {
            mostrarNotebook(lista[i], tipos, tamtipos);
            flag=0;
        }

    }
    if(flag)
    {
        printf("No hay notebooks que mostrar\n");
    }
    printf("\n\n");
}


void inicializarNotebook(eNotebook notebook[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        lista[i].isEmpty=1;
    }
}


int altaNotebook(eNotebook notebook[],eMarca marcas[],eTipo tipos[],int tam,int tamMarca ,int tamTipo,int id)
{
    int retorno = 0;

    for(int i = 0; i<tam; i++)
    {
        if(notebook[i].isEmpty == 1)
        {
            printf("ID: %d\n",id);
            notebook[i].id = id;

            printf("Ingrese modelo: ");
            fflush(stdin);
            scanf("%s",&notebook[i].modelo);

            mostrarMarcas(marcas,tamMarca);
            printf("Ingrese el ID de la marca de su notebook: ");
            scanf("%d",&notebook[i].idMarca);

            while(notebook[i].idMarca > 5 || notebook[i].idMarca < 1)
            {
                printf("Error. Ingrese el ID de la marca de su notebook: ");
                scanf("%d",&notebook[i].idMarca);
            }

            mostrarTipo(tipos,tamTipo);
            printf("Ingrese el ID del tipo de su notebook: ");
            scanf("%d",&notebook[i].idTipo);

            while(notebook[i].idTipo > 4 || notebook[i].idTipo < 1)
            {
                printf("Error. Ingrese el ID del tipo de su notebook ");
                scanf("%d",&notebook[i].idTipo);
            }

            printf("Ingrese el precio de su notebook: ");
            scanf("%d",&notebook[i].precio);


            notebook[i].isEmpty = 0;
            retorno = 1;

            break;
        }
    }

    return retorno;
}
int buscarLibre(eNotebook lista[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarNotebook(eNotebook lista[], int tam, int id)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].id == id && lista[i].isEmpty==0)
        {
            indice=i;
            break;
        }
   }
   return indice;
}
int bajaNotebook(eNotebook lista[], int tam, eTipo tipos[], int tamtipos)
{
    int todoOk=0;
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("     Baja de notebook   ");
    mostrarNotebooks(lista,tam, tipos, tamtipos);
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice= buscarNotebook(lista,tam, id);

    if(indice== -1)
    {
        printf("No hay ninguna notebook registrada con el id %d", id);
    }
    else
    {
        mostrarNotebook(lista[indice], tipos, tamtipos);
        printf("confirma baja?\n");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma== 's')
        {
            lista[indice].isEmpty=1;
            todoOk=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }


    return todoOk;
}


int cargarNombreNotebook(int id, eNotebook lista[], int tam, char nombre[])
{
    int todoOk=0;
    int indice;

    if( lista != NULL && tam >0 && nombre !=NULL)
    {
        indice=buscarNotebook(lista,tam,id);
        if(indice != -1)
        {
            strcpy(nombre, lista[indice].nombre);
            todoOk=1;
        }
    }

    return todoOk;

}

int modificarNotebook(eNotebook lista[], int tam, eTipo tipos[], int tamtipos)
{
    int todoOk=0;
    int id;
    int indice;
    int retorno;

    if(lista!= NULL && tam>0)
    {

    mostrarNotebooks(lista, tam, tipos,tamtipos);
    printf("Ingrese el ID de la notebook a modificar:\n ");
    scanf("%d", &id);
    }

    indice=buscarNotebook(lista,tam,id);

    if(indice==-1)
    {
        printf("Id no existente\n");
    }
    else
    {
        printf("Bienvenido a la modificacion de notebooks\n");
        printf("¿Que quiere modificar?\n");
        printf("1.Precio:\n");
        printf("2.Tipo:\n");

        printf("Ingrese opcion: ");
        scanf("%d",&retorno);

        switch(retorno)
        {
        case 1:
            printf("Ingrese precio: ");
            scanf("%f", &lista[indice].precio);
            todoOk=1;
            break;
        case 2:
            printf("Ingrese Tipo: ");
            fflush(stdin);
            gets(lista[indice].idTipo);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

