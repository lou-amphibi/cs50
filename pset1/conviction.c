#include <stdio.h>
int main(void)
{
float a;
int b=0, tab=25, lok=0, rez=0, n=0, crk[3]={10, 5, 1};
printf("Hello! How many conviction u spend?\n");
scanf(" %f", &a);
if (a<0)
{
do
{
printf("Convictions still shine\n");
scanf(" %f", &a);
b++;
}
while (b<2);
  if (b==2)
    {
    printf("Foo\n");
    }
}
else if (a>0)
{
a=a*100;
a+=0.5;
a=(int)a;
while (a>0)
{
  if (a>=tab)
  {
    lok=a/tab;
    a=a-(tab*lok);
    rez+=lok;
  }
  else
  {
    tab=crk[n];
    n++;
  }
}
printf("%d\n", rez);
}
else
{
    printf("0\n");
}
}



