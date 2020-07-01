#include <stdio.h>
int main(void)
{
    int b, d;
    printf("waterminutes: ");
    scanf("%d", &b);
    d = b*12;
    if (d>140)
    printf("stop waste water!\n");
    else printf("%d bottels\n", d);
}