#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CNTL_Z '\032'
#define LEN 80

int main()
{
  FILE * fp;
  long counter, last;
  char fileName[LEN]; 
  
  printf("Please input the filename of the file you want to reverse.\n");
  if(1 !=scanf("%s", fileName))
  {
    printf("Error in input the filename.\n");
    exit(EXIT_FAILURE);
  }

  if(NULL == (fp = fopen(fileName, "rb")))
  {
    printf("Error in open the file:%s.\n", fileName);
    exit(EXIT_FAILURE);
  }

  fseek(fp, 0L, SEEK_END);
  last = ftell(fp);
  for(counter = 1L; counter <= last; counter++)
  {
    fseek(fp, -counter, SEEK_END);
    int ch = getc(fp);
    putchar(ch);
  }
  fclose(fp);

  return 0;


}