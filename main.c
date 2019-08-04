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
  printf(" (%d)\n", total);
  return total;
}

int main()
{
  printf("\n -- The C-Ching --\n\n");
  char trigram[100];
  int throws[6];
  int total;

  // Throw coin 6 times
  for (int i = 0; i <= 6; i++) {
    printf("Throw %d: ", i);
    total = coin_throw();
    throws[i] = total;
    // Sleep between throws or else random number
    // will be the same for each throw.
    sleep(1);
  }
  printf("\n");

  for (int j = 5; j >= 0; j--) {
    if (throws[j] % 2 == 0) {
      strcat(trigram, "---------");
    }
    else {
      strcat(trigram, "---   ---");
    }

    if (throws[j] % 3 == 0) {
      strcat(trigram, " *");
    }

    strcat(trigram, "\n");
  }

  printf("%s\n", trigram);
  return 0;
}
