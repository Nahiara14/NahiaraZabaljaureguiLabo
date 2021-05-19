#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[20];

} eMarca;
#endif // MARCA_H_INCLUDED
void mostrarMarcas(eMarca marcas[], int tam);
void mostrarMarca(eMarca unaMarca);
int cargarDescripcionMarca(int id, eMarca marcas[], int tam, char descrip[]);
int validarIdMarcas(int id, eMarca marcas[], int tam);
int buscarMarca(int id, eMarca marcas[], int tam);

