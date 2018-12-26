#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coin_throw()
{
  int total = 0;
  time_t t;

  srand((unsigned) time(&t));

  for (int i = 0; i < 3; i++) {
    int random_num = rand() % 2;
    if (random_num == 0)
      total += 2;
    else if (random_num == 1)
      total += 3;
    else
      printf("Error throwing coin");
    printf("Throw %d: %d\n", i+1, random_num);
  }
  printf("Total: %d\n", total);
}

int main()
{
  printf("Hello world\n");
  coin_throw();
  return 0;
}
