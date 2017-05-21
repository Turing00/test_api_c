#include <stdlib.h>
#include <stdio.h>

#include "../include/math_lib.h"

static void Math_Init (Math *);

Math *New_Math (void)
{
    Math *This = malloc(sizeof(Math));
    if(!This) return NULL;
    Math_Init (This);
    This->Free = Math_New_Free;
    This->__operand1 = 0;
    This->__operand2 = 0;
    puts("Creation de la pile dynamique.\n");
    return This;
}

int Math_Api_Add (int op1, int op2)
{
    return op1 + op2;
}

int Math_Api_Substract (int op1, int op2)
{
    return op1 - op2;
}

int Math_Api_Multiply (int op1, int op2)
{
    return op1 * op2;
}

int Math_Api_Divide (int op1, int op2)
{
    return op1 / op2;
}

int Math_Api_Modulo (int op1, int op2)
{
    return op1 % op2;
}

int Math_Api_Get_First_Operand (Math *This)
{
    return This->__operand1;
}

void Math_Api_Set_First_Operand (Math *This, int op1)
{
    This->__operand1 = op1;
}

int Math_Api_Get_Second_Operand (Math *This)
{
    return This->__operand2;
}

void Math_Api_Set_Second_Operand (Math *This, int op2)
{
    This->__operand2 = op2;
}

static void Math_Init (Math *This)
{
    This->Add = Math_Api_Add;
    This->Substract = Math_Api_Substract;
    This->Multiply = Math_Api_Multiply;
    This->Divide = Math_Api_Divide;
    This->Modulo = Math_Api_Modulo;
    This->Get_First_Operand = Math_Api_Get_First_Operand;
    This->Set_First_Operand = Math_Api_Set_First_Operand;
    This->Get_Second_Operand = Math_Api_Get_Second_Operand;
    This->Set_Second_Operand = Math_Api_Set_Second_Operand;
}

void Math_New_Free (Math *This)
{
    if(This) free(This);
    puts("Destuction de la pile dynamique.\n");   
}
