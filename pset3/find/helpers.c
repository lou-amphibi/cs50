/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */


/* Линейный поиск
bool search(int value, int values[], int n)
{
    for (int i=0; i<n; i++)
    {
        if (values[i]==value)
            return true;
    }
    return false;
} */

bool search(int value, int values[], int n)
{
    int start=0;
    while (start<=n)
    {
    int mid=(start+n)/2;
    if (value==values[mid])
        return true;
    else if (value<values[mid])
         n=mid;
    else
        start=mid+1;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
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