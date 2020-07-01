#include <stdio.h>
int *binarys(int s[], int start, int end, int key);

int main()
{
    int s[]={1, 2, 3, 4, 5};
    int *ps=NULL;
    ps=binarys(s, 0, 5, 2);
    printf("%d\n", *ps);
}

int *binarys(int s[], int start, int end, int key)
{
    if (start>end)
        return NULL;
    int mid=(start+end)/2;

    if (key>s[mid])
        return binarys(s, mid+1, end, key);
    else if (key<s[mid])
        return binarys(s, start, mid, key);
    else
        return (s+mid);
}