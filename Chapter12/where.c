#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int static_store = 30;
char * pcg = "static string";

int main()
{
  int auto_store = 40;
  char  auto_string[] = "auto string";
  int * pi;
  char * pcl;

  pi = (int *)malloc(sizeof(int));
  *pi = 35;
  
  pcl = (char *)malloc(sizeof("Quoted string"));
  pcl = "Quoted string";

  printf("static_store  is %15d and the position is %p\n", static_store, &static_store);
  printf("         pcg  is %15s and the position is %p\n", pcg, &pcg);
  printf("  auto_store  is %15d and the position is %p\n", auto_store , &auto_store);
  printf(" auto_string  is %15s and the position is %p\n", auto_string, &auto_string);
  printf("         *pi  is %15d and the position is %p\n", *pi, pi);
  printf("         pcl  is %15s and the position is %p\n", pcl, pcl);
  printf("Quoted string is %15s and the position is %p\n", "Quoted string", "Quoted string");

  return 0;
}