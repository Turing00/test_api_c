#ifndef _GREETING_LIB_
#define _GREETING_LIB_

/* #define SEASON_GREETING "Aloha" */

typedef int (* ptr_Hello) (char*);
typedef int (* ptr_Goodbye) (void);

typedef struct greeting_api {
    ptr_Hello Hello;
    ptr_Goodbye Goodbye;
    void (* Free) (struct greeting_api*);
} Greeting;

/* extern char* EOL; */

extern Greeting* New_Greeting (void);

extern int Greeting_Hello (char*);

extern int Greeting_Goodbye (void);

extern void Greeting_New_Free (Greeting*);

#endif /* _GREETING_LIB_ */
