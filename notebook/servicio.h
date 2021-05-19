#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

    int  id;
    char descripcion[20];
    float precio;

} eServicio;
#endif // SERVICIO_H_INCLUDED
void mostrarServicios(eServicio servicios[], int tam);
void mostrarServicio(eServicio unServicio);
int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char descrip[]);
int validarIdServicios(int id, eServicio servicios[], int tam);
int buscarServicio(int id, eServicio servicios[], int tam);
