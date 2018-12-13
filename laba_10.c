#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ , . abcdefghijklmnopqrstuvwxyz";

int main(void)
{
  srand(time(0));
  printf("Enter amount of rows in array: ");
  int n;
  scanf("%d", &n);
  char **masyv = (char**)calloc(sizeof(char*), n);
  printf("\nArray:\n");
  for (int i = 0; i < n; i++)
  {
    int length = rand() % 20 + 2;
    masyv[i] = (char*)calloc(sizeof(char), length);
    for (int j = 0; j < length - 1; j++)
    {
      masyv[i][j] = symbols[rand() % strlen(symbols)];
    }
    masyv[i][length - 1] = '\0';
    printf("Length:%d\tRow%d: \"%s\"\n", length - 1, i + 1, masyv[i]);
  }
  printf("\nResult array:\n");
  for (int i = 0; i < n; i++)
  {
    if (masyv[i][0] == masyv[i][strlen(masyv[i]) - 1])
    {
      free(masyv[i]);
      masyv[i] = NULL;
      printf("Row %d deleted\n", i + 1);
    }
    else
      printf("Length:%d\tRow%d: \"%s\"\n", strlen(masyv[i]), i + 1, masyv[i]);
  }
  for (int i = 0; i < n; i++)
  {
    if (masyv[i])
      free(masyv[i]);
  }
  free(masyv);

  getchar();
  getchar();
  return 0;
}
