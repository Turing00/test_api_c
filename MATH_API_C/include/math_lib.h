#ifndef _MATH_LIB_H_
#define _MATH_LIB_H_

/* #define NULL_CONST 0 */

typedef int (* ptr_Add)       (int , int);
typedef int (* ptr_Substract) (int , int);
typedef int (* ptr_Multiply)  (int , int);
typedef int (* ptr_Divide)    (int , int);
typedef int (* ptr_Modulo)    (int , int);

typedef struct math_api {
    ptr_Add       Add;
    ptr_Substract Substract;
    ptr_Multiply  Multiply;
    ptr_Divide    Divide;
    ptr_Modulo    Modulo;

    int  (* Get_First_Operand)  (struct math_api *);
    void (* Set_First_Operand)  (struct math_api *, int);

    int  (* Get_Second_Operand) (struct math_api *);
    void (* Set_Second_Operand) (struct math_api *, int);

    void (* Free)               (struct math_api *);

    int __operand1;
    int __operand2;
} Math;

extern Math *New_Math              (void);

extern int  Math_Api_Add           (int , int);

extern int  Math_Api_Substract     (int , int);

extern int  Math_Api_Multiply      (int , int);

extern int  Math_Api_Divide        (int , int);

extern int  Math_Api_Modulo        (int , int);

extern void Math_New_Free          (Math *);

extern int Math_Api_Get_First_Operand  (Math *);
extern void Math_Api_Set_First_Operand  (Math *, int);
 
extern int Math_Api_Get_Second_Operand (Math *);
extern void Math_Api_Set_Second_Operand (Math *, int);

#endif /* _MATH_LIB_H_ */ 