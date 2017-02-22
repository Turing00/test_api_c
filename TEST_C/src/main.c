/*App v 0.1.1*/
/*Author : kokou koumagna-gottoh*/

/*The system libraries*/
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../TEST_LIB_C/include/greeting_lib.h"

/*
*Desciption : Say hello to everyone 
*@Param in  :
*@Param out :
*/


int main(int argc, char* argv[]) {
    /*print my first hello anything app !!!*/
    
    int argc_real = argc - 1;
    if (argc_real == 1) {
        Greeting *greeting = New_Greeting();
        puts("");
        puts("******************");
        greeting->Hello(argv[1]);
        puts("******************");
        greeting->Goodbye();
        puts("******************");
        puts("");
        Greeting_New_Free(greeting);
        greeting = NULL;
    }
    else {
        printf("\n\033[31;01mUsage : %s [Param].\033[00m\n\n", basename(argv[0]));
    }
        
    return EXIT_SUCCESS;
    
    /* system("PAUSE"); */
}
