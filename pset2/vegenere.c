#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD 100
#define ALPHABET 26
int alpharg(char *s);
char *getname(char b[]);
void vegenere(char s[], char t[]);

int main(int argc, char *argv[])
{
    char word[MAXWORD];
    if (argc!=2)
    {
        puts("Используйте ключевоt слово как аргумент");
        exit(1);
    }
    if (alpharg(argv[1]))
    {
        puts("Ключевое слово не должно содержать какие-либо символы кроме букв");
        exit(1);
    }
    printf("Зашифровать: ");
    while(getname(word)!=NULL)
    {
        vegenere(word, argv[1]);
        printf("Зашифровано: %s\n", word);
        printf("Зашифровать: ");
    }

}


int alpharg(char *s)
{
    for (int i=0; *s!='\0'; s++)
    {
        if(!(isalpha(*s)))
            return 1;
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

void vegenere(char s[], char t[])
{
    int key;
    int reverce;
    int result;
    for (int i=0, j=0; s[i]!='\0'; j++, i++)
    {
        if (t[j]=='\0')
            j=0;
        if (isalpha(s[i]))
        {
            if (isupper(t[j]))
                key=t[j]-'A';
            else
                key=t[j]-'a';
            if (isupper(s[i]))
                reverce=s[i]-'A';
            else
                reverce=s[i]-'a';
        result=(reverce+key)%ALPHABET;
        reverce=(isupper(s[i])) ? 'A' : 'a';
        s[i]=result+reverce;
        }
        else
            j--;
    }
}