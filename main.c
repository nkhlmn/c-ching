#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

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
  printf("\n");
  return total;
}

int main()
{
  printf("\n -- C-Ching --\n");
  char trigram[100];
  int total;

  for (int i = 0; i <= 6; i++) {
    printf("Throw %d\n", i);
    total = coin_throw();
    printf("Total: %d\n\n", total);

    if (total % 2 == 0) {
      strcat(trigram, "---------");
    }
    else {
      strcat(trigram, "---   ---");
    }

    if (total % 3 == 0) {
      strcat(trigram, " *");
    }
    strcat(trigram, "\n");
    sleep(1);
  }
  printf("%s\n", trigram);
  return 0;
}
