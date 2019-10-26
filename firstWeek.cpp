#include <stdio.h>
int calculation(int* a, int* b) {
  int res = *a + *b;
  printf("%d\n", res);
  return res;
}

int main() {
  int a = 2;
  int b = 3;
  calculation(&a, &b);
  return 0;
}
