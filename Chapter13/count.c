#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
  char ch;
  FILE * fp;
  if(2 != argc)
  {
    printf("usage: %s filename.\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if((fp = fopen(argv[1],"r")) == NULL)
  {
    printf("Can not open the file %s.\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  while(EOF !=(ch = getc(fp)))
  {
    putc(ch,stdout);
  }
  puts("");
  return 0;
}