#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

typedef struct{
    int id;
    char nombreColor[20];
}eColor;

typedef struct{
    int id;
    char patente[21];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}eAuto;

typedef struct{
    int id;
    char descripcion[26];
    int precio;
    int isEmpty;
}eServicio;


typedef struct{
    int id;
    char patente[21];
    int idServicio;
    int fecha;
    int isEmpty;
}eTrabajo;


#endif // FUNCIONES_H_INCLUDED

int inicializarAutos(eAuto lista[], int tam);
int inicializarTrabajos(eTrabajo trabajos[], int tama);
char menu();

void mostrarMarca(eMarca marca);
void listarMarcas(eMarca marcas[], int tam);
void mostrarColor(eColor color);
void listarColores(eColor colores[], int tam);

void mostrarAutos(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol);

int bajaAuto(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol);

int inicializarServicios(eServicio servicios[], int tama);

int altaTrabajo(eTrabajo trabajos[], int tamtraba, eServicio servicios[], int tamserv, eAuto lista[], int tam, eColor colores[], int tamcol, eMarca marcas[], int tamarcas, int* nextIdTrabajo, int* flagTrabajo)
;
