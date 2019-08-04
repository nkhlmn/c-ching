#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "coin_throw.c"

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
