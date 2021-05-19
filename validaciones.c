#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"


char confirmar()
{
    char respuesta;

    printf("Presione j para confirmar o z para cancelar: ");
    fflush(stdin);
    respuesta = getchar();

    while(respuesta != 'j' && respuesta != 'z')
    {
        printf("Error. Presione j para confirmar o z para cancelar: ");
        fflush(stdin);
        respuesta = getchar();
    }

    return respuesta;
}

int validarId(int id){
    int todoOk = 0;
    //50000 y 60000
    if(id >=50000 && id <= 60000)
    {
        todoOk = 1;
    }
    return todoOk;
}

int validarPatente(char patente[]){
    int todoOk = -1;
    int tamanioCadena = 21;

    if(patente != NULL && strlen(patente) < tamanioCadena && patente[0] != '\0')
    {
        for(int i = 0;i < tamanioCadena; i++)
        {
            if((patente[i] < 'a' || patente[i] > 'z') && (patente[i] < 'A' || patente[i] > 'Z'))
            {
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

char confirmarSub()
{
    char respuesta;

    printf("Presione s para confirmar o n para cancelar: ");
    fflush(stdin);
    respuesta = getchar();

    while(respuesta != 's' && respuesta != 'n')
    {
        printf("Error. Presione s para confirmar o n para cancelar: ");
        fflush(stdin);
        respuesta = getchar();
    }

    return respuesta;
}

