#include <stdio.h>

int main()
{
    // Пузырьковая сортировка.
    int s[]={4, 3, 1, 6, 5, 2};
    int flag;
    int tab;
    for (int i=5; i>0; i--)
    {
        flag=0;
        for(int j=0; j<i; j++)
        {
            if (s[j]>s[j+1])
            {
                tab=s[j];
                s[j]=s[j+1];
                s[j+1]=tab;
                flag=1;
            }
        }
        if (flag==0)
            break;
    }
    for(int a=0; a<6; a++)
        printf("%d", s[a]);
    putchar('\n');
}
