#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  char * stringPtr = "12345";

  printf("===================================================\n");
  printf("the address of 12345 is:       %p\n", "12345");
  printf("the address of 12345 + 1 is:   %p\n", "12345" + 1);
  printf("===================================================\n");

  printf("the value of stringPtr is:     %p\n", stringPtr);
  printf("the value of stringPtr + 1 is: %p\n", stringPtr + 1);
  printf("the sizeof(stringPtr)is        %d\n", sizeof(stringPtr));
  printf("===================================================\n");
  
  printf("the address of stringPtr is:   %p\n", &stringPtr);
  printf("the address of &stringPtr+1 is:%p\n", &stringPtr + 1);
  printf("the &12345 + 1 is :            %p\n", &"12345" + 1);
  printf("===================================================\n");
  

  char stringArr[] = "12345";
  printf("the value of stringArr is :    %p\n", stringArr);
  printf("the value of &stringArr+1 is:  %p\n", &stringArr +1);
  printf("===================================================\n");


  int * a;
  printf("&a is                          %p\n", &a);
  printf("&a + 1 is                      %p\n", &a + 1);
  printf("===================================================\n");

  int b = 1;
  printf("&b is                          %p\n", &b);
  printf("&b + 1 is                      %p\n", &b + 1);
  printf("===================================================\n");

  return 0;
}