#include <stdio.h>
int *binsearch(int s[], int key, int start, int end);

int main()
{
    int s[]={1, 2, 3, 4, 5};
    int *ps=binsearch(s, 2, 0, 5);
    printf("%d %d\n", *ps, *(ps+1));
}


int *binsearch(int s[], int key, int start, int end)
{
    int mid=(start+end)/2;
    while (start<=end)
    {
    mid=(start+end)/2;
    if (key==s[mid])
        return (s+mid);
    if (key>s[mid])
        start=mid+1;
    else
        end=mid;
    }
    return NULL;
}