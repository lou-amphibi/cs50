#include <stdio.h>
int sigma(int n);

int main()
{
    int x;
    int y;
    printf("WHUUU: ");
    x=(getchar())-'0';

    y=sigma(x);
    printf("%d\n", y);
}

int sigma(int n)
{
    if (n<=0)
        return 0;
    return (n+sigma(n-1));
}