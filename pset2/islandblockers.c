#include <stdio.h>
#include <string.h>

int main(void)
{
 char blockers[50];
 int letters[200];
 int a, b, c=-1;
 do
 {
  printf("how many yellow blockers on your island and they have some names?\n");
  scanf("%d", &a);
 }
 while(a<1);
 if (a<=0)
 {
     printf("Nevermind, kid\n");
 }
 else if (a>0)
 {
     int n=1;
     for (n=1; n<=a; n++)
     {
         printf("name %d:", n);
         scanf("%s", blockers);
         b=strlen(blockers);
         c++;
         letters[c]=b;

     }
    for (int k=0; k<=c; k++)
    {
    printf("The number of letters in the name of the blocker %d - %d\n", k+1, letters[k]);
    }
 }
}