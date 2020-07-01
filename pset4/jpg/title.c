#include <stdio.h>

int main()
{
    char title[]="000";
    int n=0;
    while(n<20)
    {
    n++;
    sprintf(title, "%d.jpg", n);
    printf("%s\n", title);
    }
}