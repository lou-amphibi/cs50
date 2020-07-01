#include <stdio.h>

int main(void)
{
float a, c=0.45689, k=0.01, g=0;
int b;
printf("Флоат: ");
scanf(" %f", &a);
b = (int)a;
printf("целое число из Флоат: %d\n", b);
printf("%.3f, %.2f, %.4f\n", c, c, c);

if (a >= k)
{
  g = a/k;
  a = a-(k*(int)g);
  printf("%d\n", (int)g);
}
}





