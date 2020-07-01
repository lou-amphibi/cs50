#include <stdio.h>
#define MAXLEN 100
int* mergesort(int s[], int buf[], int start, int end);



int main()
{
    int s[]={4, 3, 1, 6, 5, 2};
    int buf[6];
    int *pb=NULL;
    pb=mergesort(s, buf, 0, 5);
    for (int i=0; i<6; i++, pb++)
        printf("%d", *pb);
    putchar('\n');
}

// Второй вариант сортировки слиянием.
int *mergesort(int s[], int buf[], int start, int end)
{
    if (start==end)
    {
        buf[start]=s[start];
        return buf;
    }
    int middle=(start+end)/2;
    int *lbuf=mergesort(s, buf, start, middle);
    int *rbuf=mergesort(s, buf, middle+1, end);
    int i=start;
    int j=middle+1;
    int *target=(lbuf==s) ? buf : s;

    for (int y=start; y<=end; y++)
    {
        if (i<=middle && j<=end)
        {
            if (lbuf[i]<rbuf[j])
            {
                target[y]=lbuf[i];
                i++;
            }
            else
            {
                target[y]=rbuf[j];
                j++;
            }
        }
        else if (i<=middle)
        {
            target[y]=lbuf[i];
            i++;
        }
        else
        {
            target[y]=rbuf[j];
            j++;
        }
    }
    return target;
}





