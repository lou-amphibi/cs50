/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    int al=strlen(argv[3]);
    for (int i=0; i<al; i++)
    {
        if(!isdigit(argv[3][i]))
        {
            puts("Only a integer digital");
            exit(1);
        }
    }
    int n=atoi(argv[3]);
    if (n<1 || n>100)
    {
        puts("Coverage 1-100");
        exit(2);
    }
    // remember filenames
    char* infile = argv[1];
    char* outfile = argv[2];

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    // BIT STRUCTURE
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biWidth=(bi.biWidth-padding)*n;
    bi.biHeight*=n;

    bi.biSizeImage = (biWidth * sizeof(RGBTRIPLE) + padding) * abs(biHeight)

    bfSize = biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines

    int bits=(-bi.biWidth/n);
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i <biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int a=0; a<n; a++)
        {
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                // write RGB triple to outfile
                for (int y=n; y>0; y--)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                j=j+(n-1);
            }
            // then add it back (to demonstrate how)
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }

            if (a!=n-1)
            {
                fseek(inptr, sizeof(RGBTRIPLE)*bits, SEEK_CUR);
            }
        }
        i=i+(n-1);

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);


    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
