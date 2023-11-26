#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long maxConsecutiveSum(unsigned int* numbers, unsigned int length, unsigned int k) {
  unsigned long maxSum = 0;

  for (int i = 0; i <= length - k; i++) {
    unsigned long kSum = 0;

    for (int j = i; j < i+k; j++) {
      kSum += numbers[j];
    }

    if (kSum > maxSum) {
      printf("Found new highscore: %lu > %lu\n", kSum, maxSum);
      maxSum = kSum;
    }
  }

  return maxSum;
}

int main() {

  srand(time(NULL));

  const unsigned int numNumbers = 10;
  const unsigned int k = 3;

  unsigned int numbers[numNumbers]; // = {1,3,5,6,7,12,14,2,3,4};
  for (int i = 0; i < numNumbers; i++) {
    numbers[i] = rand() % 100;
    printf("%d ", numbers[i]);
  }
  printf("\ntotal: %lu\n", sizeof(numbers) / sizeof(int));
  
  printf("%lu\n", maxConsecutiveSum(numbers, sizeof(numbers) / sizeof(int), k));

  return 0;
}


