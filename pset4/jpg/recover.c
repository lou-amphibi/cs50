/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(int argc, char* argv[])
{
    if (argc!=3)
    {
        puts("Usage input-output file");
    }
    char *input=argv[1];
    char *output=argv[2];

    FILE *inptr=fopen(input, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", input);
        return 2;
    }

    FILE *outptr=fopen(output, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", output);
        return 3;
    }

    int s=0;
    int s1=0;
    int s2=0;
    int n=1;
    int c=1;
    int howf=0;
    char title[]="000000";

    while(s!=255)
        {
            fread(&s, 1, 1, inptr);
        }
    fwrite(&s, 1, 1, outptr);

    fread(&s, 1, 1, inptr);
    fwrite(&s, 1, 1, outptr);


    fread(&s, 1, 1, inptr);
    fwrite(&s, 1, 1, outptr);
    s=1;
    while(n)
    {
        c=fread(&s, 1, 1, inptr);
        if (c==0)
            break;
        if (s!=255)
            fwrite(&s, 1, 1, outptr);
        else
        {
            c=fread(&s1, 1, 1, inptr);
            if (c==0)
                break;
            if (s1==216)
            {
                c=fread(&s2, 1, 1, inptr);
                if (c==0)
                    break;
                if (s2==255)
                {
                    howf++;
                    sprintf(title, "%d.jpg", howf);
                    fclose(outptr);
                    outptr=fopen(title, "w");
                    fwrite(&s, 1, 1, outptr);
                    fwrite(&s1, 1, 1, outptr);
                    fwrite(&s2, 1, 1, outptr);

                }
                else
                {
                    fwrite(&s, 1, 1, outptr);
                    fwrite(&s1, 1, 1, outptr);
                    fwrite(&s2, 1, 1, outptr);
                }
            }
            else
           {
                    fwrite(&s, 1, 1, outptr);
                    fwrite(&s1, 1, 1, outptr);
            }

        }
    }
    fclose(inptr);
    fclose(outptr);
}

