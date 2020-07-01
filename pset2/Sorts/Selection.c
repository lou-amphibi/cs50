#include <stdio.h>


int main()
{
    // Сортировка выбором.
    int s[]={3, 1, 4, 5, 2};
    int index;
    int min;
    int tab;
    for (int j=0; j<4; j++)
    {
        index=s[j];
        for (int i=j+1; i<5; i++)
        {
            if (s[i]<index)
            {
                index=s[j];
                min=i;
            }
        }
        if (s[index]!=s[j])
        {
            tab=s[j];
            s[j]=s[index];
            s[min]=tab;
        }
    }
    for(int a=0; a<5; a++)
        printf("%d", s[a]);
    putchar('\n');
}