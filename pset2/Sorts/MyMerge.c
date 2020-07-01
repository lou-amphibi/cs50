#include <stdio.h>
void sort(int s[], int start, int end);
void merge(int s[], int start, int middle, int middle1, int end);

int main()
{
    int s[]={4, 3, 1, 6, 5, 2};
    sort(s, 0, 5);
    for (int i=0; i<6; i++)
        printf("%d", s[i]);
    putchar('\n');
}

// Сортировка слиянием.
void sort(int s[], int start, int end)
{
    if (end>start)
    {
        int mid=(start+end)/2;
        sort(s, start, mid);
        sort(s, mid+1, end);
        merge(s, start, mid, mid+1, end);
    }
}


void merge(int s[], int start, int middle, int middle1, int end)
{
    int buf[start+end+1];
    int i=start;
    int j=middle1;
    int y=start;
    while(i<=middle && j<=end)
    {
        if(s[i]<s[j])
        {
            buf[y++]=s[i];
            i++;
        }
        else
        {
            buf[y++]=s[j];
            j++;
        }
    }
    int a=(i>middle) ? j : i;
    int b=(i>middle) ? end : middle;
    for (; a<=b; a++, y++)
    {
        buf[y]=s[a];
    }
    for (int t=start; t<=end; t++)
        s[t]=buf[t];
}