#include <stdio.h>
#include <stdlib.h>
int main(void)
{
float a;
int b=0, m=25, n=10, l=5, k=1, c=0, f=0, r=0, g=0;
printf("Hello! How many conviction u spend?\n");
scanf(" %f", &a);
while (a<0)
{
printf("Convictions still shine\n");
scanf(" %f", &a);
b++;
  if (b == 2)
    {
    printf("Foo\n");
    exit(1);
    }
}
a=a*100;
a+=0.5;
a=(int)a;
if (a >= m)
{
  c = a/m;
  a = a-(m*c);
}
if (a >= n)
{
  f = a/n;
  a = a-(n*f);
}
if (a >= l)
{
  r = a/l;
  a = a-(l*r);
}
if (a >= k)
{
  g = a/k;
  a = a-(k*g);
}
printf("%d\n", (c+f+r+g));
}


