#include <stdio.h>
#include <stdlib.h>

static unsigned int next;//默认初始化为0

unsigned int srand1();
void srand2(unsigned int seed);

unsigned int srand1()
{
  next = next * 1103515245 + 12345;
  return (unsigned int) (next / 65536) % 32768;
}

void srand2(unsigned int seed)
{
  next = seed;
}