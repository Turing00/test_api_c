/*App v 0.1.1*/
/*Author : kokou koumagna-gottoh*/

/**********************************************************************/
/*** fichier: main.c                                                ***/
/*** effectue des opération de salutation et mathématiques          ***/
/**********************************************************************/

/*The system libraries*/
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Custom libraries*/
#include "../../GREET_API_C/include/greeting_lib.h"
#include "../../MATH_API_C/include/math_lib.h"

/*
*
*Desciption : Say hello to everyone and do some math
*@Param in  :
*@Param out :
*/


int main (int argc, char **argv) 
{
    /*print my first hello anything app !!!*/
    
    int argc_real = argc - 1;
    if (argc_real == 1) {
        Greeting *greeting = New_Greeting ();
        Math *math = New_Math ();
        int op1 = 0, op2 = 0, a = 0, b = 0, c = 0, d = 0, e = 0;

        math->Set_First_Operand (math, 25);
        math->Set_Second_Operand (math, 7);
        
        op1 = math->Get_First_Operand (math);
        op2 = math->Get_Second_Operand (math);

        a = math->Add (op1, op2);
        b = math->Substract (op1, op2);
        c = math->Multiply (op1, op2);
        d = math->Divide (op1, op2);
        e = math->Modulo (op1, op2);
        puts("");
        puts ("******************");
        greeting->Hello (argv[1]);
        puts ("******************");
        greeting->Goodbye ();
        puts ("******************");
        puts ("");
        printf ("\033[32;05m op1 = %d, op2 = %d, a = %d, b = %d, c = %d, d = %d, e = %d\033[00m\n", op1, op2, a, b, c, d, e);
        puts ("");
        greeting->Free (greeting);
        greeting = NULL;
        math->Free (math);
        math = NULL;
    } else {
        printf ("\n\033[31;05mUsage : %s [Param].\033[00m\n\n", basename(argv[0]));
    }
        
    return EXIT_SUCCESS;
    
    /* system("PAUSE"); */
}
