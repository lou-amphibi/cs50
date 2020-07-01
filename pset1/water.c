#include <stdio.h>
int water(int a)
{
    int b;
    b = a*12;
    return b;
}

int main(void)
{
    int c;
    printf("waterminutes: ");
    scanf("%i", &c);
    printf("%i bottels\n", water(c));
}