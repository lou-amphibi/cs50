#include <stdio.h>
#include <ctype.h>
int main (void)
{
    int i=0, h=0, dogs[5];
    char n[]="dog";
    char title[40];
    putchar(n[2]);
    putchar('\n');
    printf("how many dogs? If dogs is over print \"+\"\n");
    for (i=0; i<5; i++)
    {
    dogs[i]=getchar();
    if (dogs[i]=='\n')
    {
        i--;
    }
    else if (dogs[i]=='+')
    {
        break;
    }
    }
    putchar('\n');
    for (h=0; h<i; h++)
    {
    putchar(dogs[h]);
    putchar('\n');
    }
printf("Книга?\n");
scanf("%s", title);
printf("Это %s\n", title);

}
