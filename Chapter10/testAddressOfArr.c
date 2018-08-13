#include <stdio.h>
#include <stdlib.h>

#define LEN 10

void showAddress(int *, char *);



int staticArrayWithoutIni[LEN];

int main()
{
    int arrayWithIni[LEN] = {1,1,2,3,4,5,6,7,8,9};
    int arrayWithoutIni1[LEN];

    int  * ar;
    printf("the value of ar is %p\n", ar);
    printf("the address of ar is %p\n", &ar);


    printf("I think the name of a array is a const pointer\n");
    printf("===========================================================\n");
    /*
    if(staticArrayWithoutIni == &staticArrayWithoutIni && staticArrayWithoutIni == &staticArrayWithoutIni[0])
    {
      printf("staticArrayWithoutIni == &staticArrayWithoutIni == &staticArrayWithoutIni[0] = %p\n",staticArrayWithoutIni);
    }
    */
    printf("           staticArrayWithoutIni = %p\n", staticArrayWithoutIni);
    printf("          &staticArrayWithoutIni = %p\n", &staticArrayWithoutIni);
    printf("        &staticArrayWithoutIni[0]= %p\n", &staticArrayWithoutIni[0]);
    printf("   sizeof(staticArrayWithoutIni) = %d\n", sizeof(staticArrayWithoutIni));
    printf("   sizeof(&staticArrayWithoutIni)= %d\n", sizeof(&staticArrayWithoutIni));
    printf("sizeof(&staticArrayWithoutIni[0])= %d\n", sizeof(&staticArrayWithoutIni[0]));


    printf("     staticArrayWithoutIni   + 1 = %p\n", staticArrayWithoutIni + 1);
    printf("    &staticArrayWithoutIni[0]+ 1 = %p\n", &staticArrayWithoutIni[0] + 1);

    printf("      &staticArrayWithoutIni + 1 = %p\n", &staticArrayWithoutIni + 1);


    //printf("the address of %s is %p\n", "staticArrayWithoutIni", &staticArrayWithoutIni);
    printf("===========================================================\n");
    showAddress(arrayWithIni,"arrayWithoutIni[0]");
    printf("the address of arrayWithoutIni is %p\n", &arrayWithIni);

    printf("===========================================================\n");
    showAddress(arrayWithoutIni1,"arrayWithoutIni1[0]");
    printf("the address of arrayWithoutIni1 is %p\n", &arrayWithoutIni1);
    printf("=============================================================\n");

    int (*addressOfArray)[10];
    //int array[10];
    addressOfArray = &arrayWithIni;
    printf("&addressOfArray is : %p\n", &addressOfArray);



    printf("the value of addressOfArray is : %p\n", addressOfArray);
    printf("整数形式 * addressOfArray is %d\n", * addressOfArray);
    printf("地址形式 * addressOfArray is %p\n", * addressOfArray);

    printf("*((int *)addressOfArray + 5) = %d\n", *((int *)addressOfArray + 5));


    printf("===============================================================\n");

    int * addressOfValue;
    
    addressOfValue = &arrayWithIni[0];/*int类型的指针指向，与指向数组的指针，尽管value值一样，但是解引用*之后却大不一样*/

    printf("the value of addressOfValue is : %p\n", addressOfValue);
    printf("整数形式 * addressOfValue is %d\n", * addressOfValue);
    printf("地址形式 * addressOfValue is %p\n", * addressOfValue);


    return 0;

}

void showAddress(int * address, char * nameOfVariable)
{
  printf("the address of %s is %p\n", nameOfVariable, address);
}


