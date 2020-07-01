#include <stdio.h>
#include <stdlib.h>

typedef struct node {
        int n;
        struct node *next;
}node;

node* search(node *p, int k);
node* add(node *p, int k);

int main()
{
    int i=4;
    node *p=(node *)malloc(sizeof(node));;
    p->n=i;
    p->next=NULL;
    node *p2=p;
    node *p3=p;
    node *p4=p;
    while(i>0)
    {
       if (p->next==NULL)
       {
          p->next=(node *)malloc(sizeof(node));
          p=p->next;
          p->n=--i;
          p->next=NULL;
       }
    }
    for (int j=0; j<4; j++)
    {
        printf("%d\n", p2->n);
        p2=p2->next;
    }
    p3=search(p3, 2);

    puts("Released");
    p3=add(p3, 7);
    for (int j=0; j<5; j++)
    {
        printf("%d\n", p4->n);
        p4=p4->next;
    }
    free(p);
;
}


node* search(node *p, int k)
{
    while(p!=NULL || p->next!=NULL)
    {
        if (p->next->n==k || p->n==k)
            return p;
        p=p->next;
    }
    return NULL;
}

node* add(node *p, int k)
{
    node* temp=(node *)malloc(sizeof(node));
    node* l;

    temp->next=p->next;
    temp->n=k;
    p->next=temp;
/*
    l=p->next;
    p->next=temp; Иной вариант через дополнительную переменную
    temp->n=k;
    temp->next=l; */
    return temp;
}


