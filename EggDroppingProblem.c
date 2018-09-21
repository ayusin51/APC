#include <stdio.h>

int max(int a, int b) {

  return (a > b) ? a : b;
}

int minTries(int floors, int eggs, int x) {

  if(floors < 0) return 0;
  if(floors == 1) return 1;
  if(eggs == 1) return floors;
  ///printf("%d %d\n", floors, eggs);
  return (max(minTries(floors - x, eggs, x), minTries(x - 1, eggs - 1, x)) + 1);
}

int main() {

  for(int i = 1; i <= 10; i++)  // varying floors for i
  printf("%d - %d\n", minTries(10, 2, i), i);
}

// Actual Solution : vary i for different floors..
