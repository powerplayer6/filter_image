#include <stdio.h>
#include <string.h>
#pragma once

typedef struct Pixel_Data
{
    int r, g, b;
}Pixel_Data;

/*char tmp[99]="";
char head[12]="";

int arr[165636];
int arrC = 0;
int cnt=0;*/

int read_ppm_color_bitmap(char* filename, Pixel_Data* picture);
int write_ppm_color_bitmap(char *filename, Pixel_Data* picture);
void filter_color_component(Pixel_Data* buf, int rgb_mask);
void convert_to_grayscale(Pixel_Data* buf);