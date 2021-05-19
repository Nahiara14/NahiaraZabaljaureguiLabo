#include "marca.h"
#include "tipo.h"
#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int  id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;


} eNotebook;

#endif // NOTEBOOK_H_INCLUDED
int menu();
int altaNotebook(eNotebook notebook[],eMarca marcas[],eTipo tipos[],int tam,int tamMarca ,int tamTipo,int id);
void mostrarNotebook(eNotebook unaNotebook, eTipo tipos[], int tamtip);
void mostrarNotebooks(eNotebook lista[], int tam, eTipo tipos[], int tamtipos);
void inicializarNotebook(eNotebook notebook[], int tam);
int bajaNotebook(eNotebook lista[], int tam, eTipo tipos[], int tamtipos);
int cargarNombreNotebook(int id, eNotebook lista[], int tam, char nombre[]);
int modificarNotebook(eNotebook lista[], int tam, eTipo tipos[], int tamtipos);

