#include <stdio.h>
#include <string.h>
#include "filterfunc.h"
#pragma once

char tmp[99]="";
char head[12]="";

int arr[165636];
int arrC = 0;
int cnt=0;

int read_ppm_color_bitmap(char* filename, Pixel_Data* picture)
{
    FILE* f = fopen(filename, "r");

    int cur_num;

    for(int i=0; i<3; i++)
    {
        fgets(tmp, 99, f);
        strcat(head, tmp);
    }

    while(fscanf(f, "%d", &cur_num) != EOF) {
        if(cnt==0)
        {
            picture[arrC].r=cur_num;
            cnt=1;
        } else if(cnt==1)
        {
            picture[arrC].g=cur_num;
            cnt=2;
        } else if(cnt==2)
        {
            picture[arrC].b=cur_num;
            cnt=0;
        }
        if(cnt==0){arrC++;}
    }
    fclose(f);
    return 0;
}

int write_ppm_color_bitmap(char *filename, Pixel_Data* picture)
{
    FILE* f2 = fopen(filename, "w");
    fprintf(f2, "%s", head);
    for(int i=0; i<arrC;i++)
    {
        fprintf(f2, "%d %d %d\n", picture[i].r, picture[i].g, picture[i].b);
    }
    fclose(f2);
}

void filter_color_component(Pixel_Data* buf, int rgb_mask)
{
    switch(rgb_mask)
    {
        case 1:
            for(int i=0; i<arrC; i++)
            {
                buf[i].b=0;
                buf[i].g=0; //r
            }
            break;
        case 2:
            for(int i=0; i<arrC; i++)
            {
                buf[i].b=0;
                buf[i].r=0; //g
            }
            break;
        case 3:
            for(int i=0; i<arrC; i++)
            {
                buf[i].r=0;
                buf[i].g=0; //b
            }
            break;
        case 4:
            for(int i=0; i<arrC; i++)
            {
                buf[i].b=0; //rg            
            }
            break;
        case 5:
            for(int i=0; i<arrC; i++)
            {
                buf[i].g=0; //rb              
            }
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            break;
    }
}

void convert_to_grayscale(Pixel_Data* buf)
{
    int gray;
    for(int i=0; i<arrC; i++)
    {
        gray=(buf[i].r+buf[i].g+buf[i].g)/3;
        buf[i].r=gray;
        buf[i].g=gray;
        buf[i].b=gray;
    }
}