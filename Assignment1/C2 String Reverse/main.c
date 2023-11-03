#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

int main(void)
{
  char a[MAXLEN];
  char b[MAXLEN];
  int i = 0;
  char ch = 0;
  while ((ch = getchar()) != '\n')
  {
    a[i] = ch;
    i++;
  }
  for (int j = i - 1; j >= 0; j--)
    b[i - 1 - j] = a[j];
  b[i] = '\0';
  printf("%s", b);
  return EXIT_SUCCESS;
}
