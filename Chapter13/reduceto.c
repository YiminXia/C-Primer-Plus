#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN 40

int main(int argc, char * argv[])
{ 
  int count = 0;
  FILE * in, * out;
  int ch;
  char name[LEN]; 
  if( 2 > argc)
  {
    fprintf(stderr, "the filename:%s's number of argc is wrong.\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if(NULL == (in = fopen(argv[1], "r")))
  {
    fprintf(stderr, "open the filename:%s failed.\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  strncpy(name, argv[2], LEN - 5);
  name[LEN - 5] = '\0';
  strncat(name, ".red", 4);
  if(NULL == (out = fopen(name, "w")))
  {
    fprintf(stderr, "open the filename:%s's failed.\n", name);
    exit(EXIT_FAILURE);
  }

  while(EOF != (ch = getc(in)))
  {
    count ++;
    if(count % 3 == 0)
    {
      count = 0;
      putc(ch, out);
    }
  }

  if(fclose(in) != 0 || fclose(out) != 0)
  {
    fprintf(stderr, "close the FILE pointer is failed.\n");
    exit(EXIT_FAILURE);
  }
  return 0;
}