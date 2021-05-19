#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"

#define TAMMAR 5
#define TAMCOL 5
#define TAMSERV 10
#define TAMAUTO 10
#define TAMTRABA 10

int main()
{
    int nextIdServicio = 20000;
    int nextIdTrabajo = 200000;
    int flag = 0;
    int flagTrabajo = 0;

    eMarca marcas[TAMMAR] = {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
        };
    eColor colores[TAMCOL] = {
        {20000, "Negro"},
        {20001, "Blanco"},
        {20002, "Gris"},
        {20003, "Rojo"},
        {20004, "Azul"}
        };
    eServicio lavados[TAMSERV] = {
        {50,"Lavado", 250},
        {51,"Pulido", 300},
        {52,"Encerado", 400},
        {53,"Completo", 600}
    };

    eAuto autos[TAMAUTO];
    eTrabajo trabajos[TAMTRABA];
    eServicio servicios[TAMSERV];

    inicializarAutos(autos, TAMAUTO);
    inicializarTrabajos(trabajos,TAMTRABA);
    inicializarServicios(servicios, TAMSERV);


    char salir = 'z';

    while(salir == 'z')
    {
        switch(menu())
        {
        case 'a': // ALTA AUTO
            if(altaAuto(autos,TAMAUTO,colores, TAMCOL, marcas, TAMMAR, &flag))
            {
                printf("Alta exitosa!\n\n");
            }
            else
            {
                printf("Hubo un problema al realizar el alta.\n\n");
            }
            break;

        case 'b': // MODIFICAR AUTO
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                modificarAuto(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL);
            }
            break;

        case 'c': // BAJA AUTO
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                bajaAuto(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL);
            }
            break;

        case 'd': // LISTAR AUTOS
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                system("cls");
                ordenarAutos(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL);
                mostrarAutos(autos, TAMAUTO, marcas, TAMMAR, colores, TAMCOL);
            }
            break;

        case 'e': // LISTAR MARCAS
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                system("cls");
                listarMarcas(marcas, TAMMAR);
            }
            break;

        case 'f': // LISTAR COLORES
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                system("cls");
                listarColores(colores, TAMCOL);
            }
            break;

        case 'g': // LISTAR SERVICIOS
            if(flag == 0)
            {
                printf("Primero debe dar de alta un auto\n");
            }else{
                system("cls");
                listarMarcas(marcas, TAMMAR);
            }
            break;

       case 'h': // ALTA TRABAJO
            if(altaTrabajo(trabajos, TAMTRABA, servicios, TAMSERV, autos, TAMAUTO, colores, TAMCOL, marcas, TAMMAR, &nextIdTrabajo, &flagTrabajo))
            {
                printf("Alta exitosa!\n\n");
            }
            else
            {
                printf("Hubo un problema al realizar el alta.\n\n");
            }
            break;

       case 'i': // LISTAR TRABAJOS

            if(flagTrabajo == 0)
            {
                printf("Primero debe dar de alta un Trabajo\n");
            }else{
                system("cls");
                listarTrabajos(trabajos, TAMTRABA);
            }
            break;

        case 'j':
            salir = confirmar();
            break;

        default:
            printf("Opcion invalida!\n");
            break;
        }
        system("pause");
    }

    return 0;
}
