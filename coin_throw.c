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

    char* coin = random_num == 0 ? "Tails" : "Heads";

    printf("%s ", coin);
  }
  printf(" (%d)\n", total);
  return total;
}

