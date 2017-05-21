#include <stdlib.h>
#include <stdio.h>

#include "../include/greeting_lib.h"

static void Greeting_Init (Greeting *);

Greeting *New_Greeting (void)
{
    Greeting *This = malloc(sizeof(Greeting));
    if(!This) return NULL;
    Greeting_Init (This);
    This->Free = Greeting_New_Free;
    puts("Creation de la pile dynamique.\n");
    return This;
}

int Greeting_Hello (char *name)
{
    printf("Hello %s ! \n", name);
    return EXIT_SUCCESS;
}

int Greeting_Goodbye (void)
{
    puts("Goodbye !");
    return EXIT_SUCCESS;
}

static void Greeting_Init (Greeting *This)
{
    This->Hello = Greeting_Hello;
    This->Goodbye = Greeting_Goodbye;
}

void Greeting_New_Free (Greeting *This)
{
    if(This) free(This);
    puts("Destuction de la pile dynamique.\n");
}
