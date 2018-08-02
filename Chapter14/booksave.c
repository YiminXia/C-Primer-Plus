#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLELEN 40
#define AUTHORLEN 20
#define MAXBOOKS 10

struct book {
       char title[TITLELEN];
       char author[AUTHORLEN];
       float price  ;    
};
void writeTheBookInfoIntoTheFile(struct book *, int, FILE *);
void readTheBookInfoFromTheFile(struct book *, int, FILE *);
char * s_gets(char *, int );
/*
int main()
{
   char * st = (char *) malloc(AUTHORLEN);
   printf("input a name use Enter to exit\n");
   s_gets(st,AUTHORLEN);
   printf("name is %s\n",st);
   return 0;
}
*/

int main()
{
  int count = 0;
  int index, fileCount;
  FILE * pbooks;
  struct book book1;
  int theNumberOfBooks;

  
  if(NULL == (pbooks = fopen("books.dat", "a + b")))
  {
      fputs("open the file books.dat failed.\n", stderr);
      exit(0);
  }

  struct book books[1]={
   {"gone with wind",
    "whatever",
    12.87
   }
 };

 rewind(pbooks);


 writeTheBookInfoIntoTheFile(&books[0], 1, pbooks);

 struct book * books2 = (struct book *)malloc(sizeof(struct book));
 rewind(pbooks);
 readTheBookInfoFromTheFile(books2, 1, pbooks);  
 printf("name = %s author = %s and the value = %f\n", books2 -> title, books2 -> author, books2 -> price);
 free(books2);
 
  return 0;
}

void writeTheBookInfoIntoTheFile(struct book * ptr, int theNumberOfBooks, FILE * pbooks)
{
  int counter = 0; 
  int size = sizeof(struct book);
  while(counter < theNumberOfBooks && 1 == fwrite(ptr, size, 1, pbooks))
  { 
    counter++;
  }
 // printf("%d",fwrite(ptr, size, 1, pbooks));
}

void readTheBookInfoFromTheFile(struct book * ptr, int theNumberOfBooks, FILE * pbooks)
{
    int counter = 0;
    int size = sizeof(struct book);
    while(counter < theNumberOfBooks && 1 == fread(ptr, size, 1, pbooks))
    {
      counter++;
    }
}


char * s_gets(char * st, int n)
{
  char * ret_val;
  char * find;
    
  ret_val = fgets(st, n, stdin);//只录入n-1个字符，最后自动加\0
  if(NULL != ret_val)
  {
     find = strchr(st, '\n');
     if(NULL != find)
     {
         *find = '\0';
     }
     else
     {
        while(getchar() != '\n')
        {
          continue;
        }
     }
  }
  return ret_val;
}