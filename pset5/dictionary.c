/** ~cs50/pset5/speller dictionaries/small  ~cs50/pset5/texts/austinpowers.txt
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 struct nlist {
    struct nlist *next;
    char *word;
};
FILE *fp=NULL;

#define HASHSIZE 8192
static struct nlist *hashtab[HASHSIZE];
unsigned int nsize=0;
/**
 * Returns true if word is in dictionary else false.
 */
unsigned hash(char s[]);
void strclow(char s[], const char t[]);

bool check(const char* word)
{
    unsigned hashval;
    struct nlist *np;
    char word2[LENGTH+1];
    strcpy(word2, word);
    //strclow(word2, word);
    for (int i=0; word[i]!='\0'; i++)
        word2[i]=tolower(word[i]);
    hashval=hash(word2);
    for (np=hashtab[hashval]; np!=NULL; np=np->next)
        {
            if(strcmp(word2, np->word)==0)
                return true;
        }
    return false;
}

void strclow(char s[], const char t[])
{
    int i=0;
    for(; t[i]!='\0'; i++)
    {
        if (t[i]>='A' && t[i]<='Z')
            s[i]=t[i]+32;
        else
            s[i]=t[i];
    }
    s[i]='\0';
}
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
struct nlist* install(char *word, int hashval);

bool load(const char* dictionary)
{
    fp=fopen(dictionary, "r");
    if (fp!=NULL)
    {
        struct nlist *np;
        int hashval;
        char s[LENGTH+1];
        int i=0;
        for (int c=fgetc(fp); c!=EOF; c=fgetc(fp))
        {
            if (c!='\n')
                s[i++]=c;
            else
            {
                nsize++;
                s[i]='\0';
                i=0;
                hashval=hash(s);
                if ((np=install(s, hashval))==NULL)
                    return false;
            }
        }
        return true;
        }
        else
            return false;
}

char *strdup(char *s);

struct nlist* install(char *word, int hashval)
{
    struct nlist *np;
    np=(struct nlist*)malloc(sizeof(*np));
    if(np==NULL)
        return NULL;
    if ((np->word=strdup(word))==NULL)
        return NULL;
    np->next=hashtab[hashval];
    hashtab[hashval]=np;
    return np;
}

unsigned hash (char s[])
{
    unsigned hashword=0;
    for (int i=0; s[i]!='\0'; i++)
        hashword=s[i] + 31*hashword;
    return hashword%HASHSIZE;
}

char *strdup(char *s) /* делает дубликат s */
{
    char *p;

    p = (char *) malloc(strlen(s)+1); /* +1 для '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return nsize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    struct nlist *np=NULL;
    struct nlist *curr=NULL;
    for (int i=0; i<HASHSIZE; i++)
    {
        for(np=hashtab[i]; np!=NULL;)
        {
            curr=np;
            np=np->next;
            free(curr->word);
            free(curr);
        }
    }
    if (fclose(fp))
        return false;
    else
        return true;
}



