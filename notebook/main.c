#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"


#define TAMMARC 4
#define TAMTIP 4
#define TAMS 4
#define TAMCOMP 4
#define TAMTRAB 4

int main()
{
    int idTrabajo=500;
    int idNotebook=600;

    eMarca marcas[TAMMARC]=
    {
        {1000, "Compaq"},
        {1001, "Asus"},
        {1002, "Acer"},
        {1003, "HP"}
    };

    eTipo tipo[TAMTIP]=
    {
        {5000, "Gamer"},
        {5001, "Disenio"},
        {5002, "Ultrabook"},
        {5003, "Normalita"}
    };

    eServicio servicios[TAMS]=
    {
        {20000, "Bateria",250},
        {20001, "Antivirus",300},
        {20002, "Actualizacion", 400},
        {20003, "Fuente", 600}
    };

    eNotebook computadoras;
    eTrabajo trabajos;



    char salir='n';

    do
    {
        switch(menu())
        {


        case 1:

            if(altaNotebook(computadoras, TAMCOMP, tipo,TAMTIP, marcas,TAMMARC, &idNotebook))
            {
                printf("Alta exitosa!!!\n");
                flag=1;
            }
            else
            {
                printf("Sucedio un problema al realizar el alta de la notebook\n");
            }
            break;
        case 2:
            if(flag!=0)
            {
                modificarNotebook(computadoras,TAMCOMP, tipo, TAMTIP);
            }
            else
            {
                printf("Error, primero deberia dar de alta una notebook \n");
            }
            break;
        case 3:
            system("cls");
            if (bajaNotebook(computadoras,TAMCOMP,tipo,TAMTIP))
            {
                printf("Baja exitosa!!\n");
                flag --;
            }
            else
            {
                printf("Error, primero deberia dar de alta una notebook\n");
            }
            break;
        case 4:
            system("cls");
            mostrarNotebooks(computadoras,TAMCOMP, tipo, TAMTIP);
            break;
        case 5:
            mostrarMarcas(marcas,TAMMARC);
            break;
        case 6:
            system("cls");
            mostrarTipos(tipo, TAMTIP);
            break;
        case 7:
            system("cls");
            mostrarServicios(servicios,TAMS);
            break;
        case 8:
            system("cls");
            if(altaTrabajo(trabajos, TAMTRAB, computadoras, TAMCOMP, tipo,TAMTIP, marcas, TAMMARC , &idTrabajo))
            {
                printf("Alta trabajo exitosa!!!\n");
            }
            else
            {
                printf("Sucedio un problema al realizar el alta del trabajo\n");
            }
            break;
        case 9:
            system("cls");
            mostrarTrabajos(trabajos,TAMTRAB);
            break;
        case 10:
            printf("Esta seguro que quiere salir? ");
            fflush(stdin);
            scanf("%c", &salir);
            break;
        default:
            printf("Opcion invalida\n");
            system("pause");
        }
        system("pause");
    }
    while(salir=='n');


































    return 0;
}
