#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Bmp_Header.h"

float Gamma = 0.2;
#define GAMMA(x) pow(x/255,1/Gamma)*255

int main(){
    FILE *fp;
    fp = fopen("image/in/sample.bmp","rb");
    if(fp == NULL){
        printf("Couldn't open input file");
        abort();
    }


    BMP_header bh;

    //Read File Header
    fread(&bh,1,54,fp);

    int height = bh.height;
    int width = bh.width;

    char *Image = calloc(height*width,sizeof(int));
    if(Image == NULL){
        printf("Coudn't execute calloc");
        return 2;
    }

    for(int i = 0; i < height*width*sizeof(int);i++)
        Image[i] = GAMMA((float)fgetc(fp));

    FILE *output_fp;
    output_fp = fopen("image/out/sample_out.bmp","wb");
    if(output_fp == NULL){
        printf("Couldn't write file");
        abort();
    }
    
    //Write File Header
    fwrite(&bh,1,54,output_fp);
    //Write Image Data
    fwrite(Image,bh.height*bh.width,sizeof(int),output_fp);

    free(Image);
    fclose(fp);
    fclose(output_fp);

    return 0;
}