#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int inicializarAutos(eAuto lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    else{
        todoOk = 0;
    }

    return todoOk;
}

int inicializarTrabajos(eTrabajo trabajos[], int tama){
    int todoOk = 0;
    if(trabajos != NULL && tama > 0)
    {
        for(int i = 0; i < tama; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    else{
        todoOk = 0;
    }

    return todoOk;
}

int inicializarServicios(eServicio servicios[], int tama){
    int todoOk = 0;
    if(servicios != NULL && tama > 0)
    {
        for(int i = 0; i < tama; i++)
        {
            servicios[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    else{
        todoOk = 0;
    }
    return todoOk;
}


char menu()
{
    char opcion;

    system ("cls");
    printf("**********LAVADERO DE AUTOS**********\n\n");
    printf("a. Alta auto\n");
    printf("b. Modificar auto\n");
    printf("c. Baja auto\n");
    printf("d. Listar autos\n");
    printf("e. listar Marcas\n");
    printf("f. Listar Colores\n");
    printf("g. Listar Servicios\n");
    printf("h. Alta Trabajo\n");
    printf("i. Listar Trabajos\n");
    printf("j. Salir\n\n");
    printf("Ingrese opcion (a-j): ");
    scanf("%c", &opcion);

    while(opcion != 'a' || opcion != 'b' ||
          opcion != 'c' || opcion != 'd' ||
          opcion != 'e' || opcion != 'f' ||
          opcion != 'g' || opcion != 'h' ||
          opcion != 'i' || opcion != 'j'  ){
        printf("ERROR. Ingrese opcion (a-j): ");
        scanf("%c", &opcion);
    }

    return opcion;
}


int buscarLibre(eAuto lista[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break; // si no se coloca break, devolveria la ultima ubicacion encontrada vacia
        }
    }
    return indice;
}

int buscarLibreTrabajo(eTrabajo lista[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break; // si no se coloca break, devolveria la ultima ubicacion encontrada vacia
        }
    }
    return indice;
}


void listarMarcas(eMarca marcas[], int tam)
{
    printf("************Lista de Marcas************\n");
    printf("    ID      Nombre\n");
        for (int i = 0;i < tam ;i++ )
        {
            mostrarMarca(marcas[i]);
        }

}

void mostrarMarca(eMarca marca)
{
    printf("    %d      %10s\n", marca.id, marca.descripcion);
}

void listarColores(eColor colores[], int tam)
{
    printf("************Lista de Marcas************\n");
    printf("    ID      NombreColor\n");
        for (int i = 0;i < tam ;i++ )
        {
            mostrarColor(colores[i]);
        }

}

void mostrarColor(eColor color)
{
    printf("    %d      %10s\n", color.id, color.nombreColor);
}

int altaAuto(eAuto lista[], int tam, eColor colores[], int tamcol, eMarca marcas[], int tamarcas,int* flag)
{
    int todoOk = 0;
    eAuto nuevoAuto;
    int indice;

    int id;
    char patente[21];
    int idMarca;
    int IdColor;
    int modelo;

    system("cls");
    printf("     Alta Auto\n\n");

    if(lista != NULL && tam > 0 && colores != NULL && tamcol > 0 && marcas != NULL && tamarcas > 0 && flag != NULL)
    {
        indice = buscarLibre(lista, tam);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            printf("Ingrese id: (entre 50000 y 60000)");
            scanf("%d", &id);
            while(validarId(id) != 1)
            {
                printf("Error.Reingrese ID: (entre 50000 y 60000)");
                scanf("%d", &id);
            }

            nuevoAuto.id = id;

            printf("Ingrese patente (max. 20 caracteres): ");
            fflush(stdin);
            gets(patente);
            while(validarPatente(patente) != 1)
            {
                printf("Error. Reingrese patente (max. 20 caracteres):");
                fflush(stdin);
                gets(patente);
            }

            strcpy(nuevoAuto.patente, patente);

            listarMarcas(marcas, tamarcas);

            printf("Ingrese ID Marca (1000/1001/1002/1003/1004): ");
            scanf("%d", &idMarca);
            while(idMarca != 1000 || idMarca != 1002 ||idMarca != 1003 ||idMarca != 1004 ||idMarca != 1005)
            {
                printf("Error.Reingrese ID marca (1000/1001/1002/1003/1004): ");
                scanf("%d", &idMarca);
            }

            nuevoAuto.idMarca = idMarca;

            listarColores(colores, tamcol);

            printf("Ingrese ID Color (1/2/3/4/5): ");
            scanf("%d", &IdColor);
            while(!IdColor >= 1 && IdColor <= 5)
            {
                printf("Error.Reingrese ID Color (1/2/3/4/5): ");
                scanf("%d", &IdColor);
            }

            nuevoAuto.idColor = IdColor;

            printf("Ingrese modelo (Anio, desde 1950 a 2021): ");
            scanf("%d", &modelo);
            while(!modelo >=1950 && modelo <= 2021)
            {
                    printf("Error. Reingrese modelo (Anio):");
                    scanf("%d", &modelo);
            }

            nuevoAuto.modelo = modelo;

            //-------- fin de ingreso de datos----------//


            nuevoAuto.isEmpty = 0;
            lista[indice] = nuevoAuto;

            *flag = 1;
            todoOk = 1;
        }
    }

    return todoOk;
}
/////

int cargarDescripcionMarca(int id, eMarca marcas[], int tam, char desc[])
{
    int todoOk = 0;

    if(id >= 50000 && id <= 60000 && marcas != NULL && tam > 0 && desc != NULL)
    {
        for (int i = 0; i< tam ;i++ )
        {
            if(marcas[i].id == id)
            {
                strcpy(desc, marcas[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

int cargarDescripcionColor(int id, eColor colores[], int tam, char color[])
{
    int todoOk = 0;

    if(id >= 50000 && id <= 60000 && colores != NULL && tam > 0 && color != NULL)
    {
        for (int i = 0; i< tam ;i++ )
        {
            if(colores[i].id == id)
            {
                strcpy(color, colores[i].nombreColor);
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamsec, eColor colores[], int tamcol)
{
    char descripcion[20];
    char color[20];

    if(cargarDescripcionMarca(unAuto.id, marcas, tamsec, descripcion)
       && cargarDescripcionColor(unAuto.id, colores, tamcol, color))
    {
        printf("%d  %d  %10s  %d  %c\n",
           unAuto.id,
           unAuto.patente,
           descripcion,
           color,
           unAuto.modelo
          );
    }
    printf("\n");
}

void mostrarAutos(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol)
{
    int flag = 0;

    printf("         Listado de Autos\n");
    printf("ID   Patente  Marca  Color   Modelo\n");

    for(int i=0; i<tam; i++)
    {
        if(!lista[i].isEmpty) // Si .isEmpty es falso (osea, tiene un empleado), los muestro
        {
            mostrarAuto(lista[i], marcas, tamsec, colores, tamcol);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("        No hay Autos que mostrar.\n");
    }
    printf("\n");
}

int buscarAuto(eAuto lista[], int tam, char patente)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].patente == patente && !lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menuModificar()
{
    int opcion;

    system ("cls");
    printf("Que desea modificar?\n\n");
    printf("1. Color\n");
    printf("2. Modelo\n");
    printf("3. Salir\n");
    printf("\n");
    printf("Ingrese opcion (1-3): ");
    scanf("%d", &opcion);
    printf("\n");

    return opcion;
}

int modificarAuto(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol)
{
    char patente[20];
    int indice;
    int salir = 'n';
    int todoOk = 0;

    system("cls");
    printf("          Modificar Auto\n\n");
    mostrarAutos(lista, tam, marcas, tamsec, colores,tamcol);
    printf("Ingrese la patente del auto a modificar: ");
    fflush(stdin);
    gets(patente);
    printf("\n");

    indice = buscarAuto(lista, tam, patente);

    if(indice == -1)
    {
        printf("La patente indicada no existe.\n\n");
    }
    else
    {
        printf("El auto a modificar es: \n");
        mostrarAuto(lista[indice], marcas, tamsec, colores, tamcol);

        if(confirmarSub() == 's')
        {
            do
            {
                switch(menuModificar())
                {
                case 1:
                    listarColores(colores,tamcol);
                    printf("Ingrese Id nuevo Color: ");
                    scanf("%d", &lista[indice].idColor);
                    todoOk = 1;
                    break;
                case 2:
                    printf("Ingrese nuevo modelo (anio): ");
                    scanf("%d", &lista[indice].modelo);
                    todoOk = 1;
                    break;
                case 3:
                    salir = confirmarSub();
                    break;
                default:
                    printf("Opcion invalida!\n");
                    break;
                }
                printf("\n");
                system("pause");
                system("cls");

                if(todoOk == 1)
                {
                    printf("Asi quedo modificado el auto:\n\n");
                    mostrarAuto(lista[indice], marcas, tamsec, colores, tamcol);

                }
            }
            while(salir == 'n');
        }
    }
    return todoOk;
}

int bajaAuto(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol)
{
    int bajaExitosa = 0;
    char patente[20];
    int indice;

    system("cls");
    printf("          Baja Auto\n\n");
    mostrarAutos(lista, tam, marcas, tamsec, colores, tamcol);
    printf("Ingrese la patente del auto a dar de baja: ");
    fflush(stdin);
    gets(patente);
    printf("\n");

    indice = buscarAuto(lista, tam, patente);

    if(indice == -1)
    {
        printf("La patente indicada (%s) no existe.\n\n", patente);
    }
    else
    {
        printf("El Auto a dar de baja es:\n");
        mostrarAuto(lista[indice],marcas, tamsec, colores, tamcol);

        if(confirmarSub() == 's')
        {
            lista[indice].isEmpty = 1;
            bajaExitosa = 1;

        }
        printf("\n");
    }

    return bajaExitosa;
}


void ordenarAutos(eAuto lista[], int tam, eMarca marcas[], int tamsec, eColor colores[], int tamcol, int* flag)
{
    eAuto auxAuto;

     //ORDENAR POR MARCA Y TAMBIEN POR PATENTE
    for(int i = 0; i < tam -1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            if(lista[i].idMarca < lista[j].idMarca || (lista[i].idMarca == lista[j].idMarca && strcmp(lista[i].patente,lista[j].patente) > 0))
            {
                auxAuto = lista[i];
                lista[i] = lista[j];
                lista[j] = auxAuto;
            }
        }
    }
}


/////////////////////////////////////////////////// ALTA SERVICIO/////////////////////////

void listarServicios(eServicio servicios[], int tam)
{
    printf("************Lista de Servicios************\n");
    printf("    ID      Descripcion   Precio\n");
        for (int i = 0;i < tam ;i++ )
        {
            mostrarServicio(servicios[i]);
        }

}

void mostrarServicio(eServicio servicio)
{
    printf("    %d      %10s   %d\n", servicio.id, servicio.descripcion, servicio.precio);
}


int altaTrabajo(eTrabajo trabajos[], int tamtraba, eServicio servicios[], int tamserv, eAuto lista[], int tam, eColor colores[], int tamcol, eMarca marcas[], int tamarcas, int* nextIdTrabajo, int* flagTrabajo)
{
    int todoOk = 0;
    eTrabajo nuevoTrabajo;
    int indice;

    int id;
    char patente[21];
    int idMarca;
    int idServicio;
    int modelo;

    eFecha fecha;
    int cant;

    system("cls");
    printf("     Alta Auto\n\n");
    printf("ID: %d\n", *nextIdTrabajo);

    if(trabajos != NULL && tamtraba > 0 && lista != NULL && tam > 0 && colores != NULL && tamcol > 0 && marcas != NULL && tamarcas > 0 && nextIdTrabajo != NULL&& flagTrabajo != NULL)
    {
        indice = buscarLibreTrabajo(lista, tam);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            printf("Ingrese patente (max. 20 caracteres): ");
            fflush(stdin);
            gets(patente);
            while(buscarAuto(lista, tam, patente) != 1)
            {
                printf("Error. Reingrese patente (max. 20 caracteres):");
                fflush(stdin);
                gets(patente);
            }

            strcpy(nuevoTrabajo.patente, patente);

//            listarMarcas(marcas, tamarcas);

//            printf("Ingrese ID Marca (100/150/200/250/300): ");
//            scanf("%d", &idMarca);
//            while(idMarca != 100 || idMarca != 150 ||idMarca != 200 ||idMarca != 250 ||idMarca != 300)
//            {
//                printf("Error.Reingrese ID marca (100/150/200/250/300): ");
//                scanf("%d", &idMarca);
//            }
//
//            nuevoTrabajo. = idMarca;

            listarServicios(servicios, tamserv);

            printf("Ingrese ID Servicio (50/51/52/53): ");
            scanf("%d", &idServicio);
            while(!idServicio >= 50 && idServicio <= 53)
            {
                printf("Error.Reingrese ID Servicio ((50/51/52/53): ");
                scanf("%d", &idServicio);
            }

            nuevoTrabajo.idServicio = idServicio;

//            printf("Ingrese modelo (Anio, desde 1950 a 2021): ");
//            scanf("%d", &modelo);
//            while(!modelo >=1950 && modelo <= 2021)
//            {
//                    printf("Error. Reingrese modelo (Anio):");
//                    scanf("%d", &modelo);
//            }
//
//            nuevoAuto.modelo = modelo;



            printf("Ingrese fecha dd/mm/aaaa: ");
            cant = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            while(cant != 3)
            {
                printf("Error. Reingrese fecha dd/mm/aaaa: ");
                cant = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
            }

            nuevoTrabajo.fecha = fecha;

            //-------- fin de ingreso de datos----------//


            nuevoTrabajo.isEmpty = 0;
            trabajos[indice] = nuevoTrabajo;

            *flagTrabajo = 1;
            todoOk = 1;
        }
    }

    return todoOk;
}

void listarTrabajos(eTrabajo trabajos[], int tam)
{
    printf("************Lista de Marcas************\n");
    printf("    ID      Patente   IdServicio   Fecha\n");
        for (int i = 0;i < tam ;i++ )
        {
            mostrarTrabajo(trabajos[i]);
        }

}

void mostrarTrabajo(eTrabajo trabajo)
{
    printf("    %d      %10s   %d   %d/%d/%d\n", trabajo.id, trabajo.patente, trabajo.idServicio, trabajo.fecha);
}
