#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD 100
#define ALPHABET 26
void ceasar(char word[], int key);
char *getname(char b[]);
int digarg(char *s);

int main(int argc, char *argv[])
{
    int c;
    char word[MAXWORD];
    if (argc!=2)
    {
        puts("Используйте аргумент в виде числового значения ключа");
        exit(1);
    }
    if (digarg(argv[1]))
    {
        puts("Используйте числовое значение в аргументе");
        exit(1);
    }
    int key=atof(argv[1]);
    key%=ALPHABET;
    printf("Слово для шифрования: ");
    while((getname(word))!=NULL)
    {
        ceasar(word, key);
        printf("Зашифрованное слово: %s\n", word);
        printf("Слово для шифрования: ");
    }
}

int digarg(char *s)
{
    while(*s!='\0')
    {
        if (!(isdigit(*s)))
            return 1;
        s++;
    }
    return 0;
}

char *getname(char b[])
{
    char *n;
    n=&b[0];
    int c, i=0;
    while((c=getchar())!='\n')
    {
        b[i++]=c;
    }
    b[i]='\0';
    if (c==EOF)
        return NULL;
    return n;
}


void ceasar(char word[], int key)
{
    int reserve;
    for (int i=0; word[i]!='\0'; i++)
    {
        if (isalpha(word[i]))
        {
            if (isupper(word[i]) && (word[i]+key)>'Z')
            {
                reserve=(word[i]+key) - 'Z';
                word[i]='A'+(reserve-1);
            }
            else if (islower(word[i]) && (word[i]+key)>'z')
            {
                reserve=(word[i]+key) - 'z';
                word[i]='a'+(reserve-1);
            }
            else
                word[i]+=key;
        }
    }
}