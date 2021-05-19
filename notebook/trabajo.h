#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int  id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;


} eTrabajo;


#endif // TRABAJO_H_INCLUDED
int altaTrabajo(eTrabajo trabajos[], int tamtrabajo , eNotebook lista[], int tamcomp, eMarca marca[], int tammarc, eTipo tipos[], int tamtip, int* pIdTrabajo);
void mostrarTrabajo(eTrabajo trabajos[], int tamtrabajo , eNotebook lista[], int tamcomp, eServicio servicio[], int tamservi);
void mostrarTrabajos(eTrabajo unTrabajo , int tamtrabajo , eNotebook lista[], int tamcomp, eMarca marca[], int tammarc, eTipo tipos[], int tamtip);
int buscarLibreTrabajo(eTrabajo trabajos[], int tamtrabajo);
void inicializarTrabajo(eTrabajo trabajos[], int tamtrabajo);
