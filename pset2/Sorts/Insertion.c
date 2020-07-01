#include <stdio.h>
void sort(int values[], int n);

int main()
{
    // Сортировка вставками.
    int s[]={4, 3, 1, 6, 5, 2};
    int index;
    for (int i=1; i<6; i++)
    {
        int j=i;
        index=s[i];
        while (j>0 && s[j-1]>index)
        {
            s[j]=s[j-1];
            j--;

        }
        s[j]=index;
    }
    for(int a=0; a<6; a++)
        printf("%d", s[a]);
    putchar('\n');
    int b[]={4, 3, 1, 6, 5, 2};
    sort(b, 6);
    for(int y=0; y<6; y++)
        printf("%d", b[y]);
    putchar('\n');

}


void sort(int values[], int n)
{
    int index;
    int j;
    for (int i=1; i<n; i++)
    {
        index=values[i];
        for(j=i; j>0 && values[j-1]>index; j--)
            values[j]=values[j-1];
        values[j]=index;
    }
}