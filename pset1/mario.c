#include <stdio.h>
int main(void)
{
    int a, b, c, o, e;
    do
    {
    printf("height: ");
    scanf(" %d", &a);
    }
    while (a>23 || a<0);
    if (a == 0)
    {
    printf("");
    }
    else
    {
    o=a;
    while (o>0)
    {
        for (c=1; c<o; c++)
        {
        printf(" ");
        }
        for (e=o, b=a; b>e; e++)
        {
        printf("#");
        }
        printf("##\n");
        o--;
    }
    }
}

