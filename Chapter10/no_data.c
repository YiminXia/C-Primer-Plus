#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LEN 10

void showArray(int *, int );

static int arrayWithoutIniStatic[LEN];

int main()
{
  int arrayWithoutIni[LEN];
  int arrayWithWrongIni[LEN] = {0,1,2,3,4,5,6,7,    8,9,10};
  
  int counter;

  printf("CHAR_BIT = %d \n", CHAR_BIT);
  /*
  for(counter = 0; counter < LEN; counter ++)
  {
    printf("arrayWithoutIni[%d] = %d\n", counter, arrayWithoutIni[counter]);
    printf("arrayWithoutIniStatic[%d] = %d\n", counter, arrayWithoutIniStatic[counter]);
    printf("arrayWithWrongIni[%d] = %d\n", counter, arrayWithWrongIni[counter]);
  }
  */
  //printf("test compute the length of array : %d\n", sizeof(arrayWithWrongIni) / sizeof(arrayWithWrongIni[0]));

  printf("============arrayWithoutIni==============================\n");
  showArray(arrayWithoutIni,LEN);
  printf("============arrayWithoutIniStaic==============================\n");
  showArray(arrayWithoutIniStatic, LEN);
  printf("============arrayWithWrongIni==============================\n");
  showArray(arrayWithWrongIni,LEN + 1);

  printf("============================================================");


  return 0;
}
void showArray(int * array, int lengthOfArray)
{
  //printf("test compute the bytes of the array : %d\n", sizeof(ar));
  //printf("test compute the bytes of a element : %d\n", sizeof(ar[0]));
  //printf("test compute the length of array : %d\n", sizeof(ar) / sizeof(ar[0]));
  int counter;
  for(counter = 0; counter < lengthOfArray; counter++)
  {
    printf("array[%d] =  %d\n", counter, array[counter]);
  }
}
