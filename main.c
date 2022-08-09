#include <stdio.h>
#include <string.h>
#include "filterfunc.h"


int main(int argc, char *argp[]) {

    Pixel_Data pix[165636];

    read_ppm_color_bitmap(argp[1], pix);

    
    if(strcmp(argp[3], "-f")==0)
    {
        if(strcmp(argp[4], "r")==0)
        {
            filter_color_component(pix, 1);
        } else if(strcmp(argp[4], "g")==0)
        {
            filter_color_component(pix, 2);
        } else if(strcmp(argp[4], "b")==0)
        {
            filter_color_component(pix, 3);
        } else if(strcmp(argp[4], "rg")==0)
        {
            filter_color_component(pix, 4);
        } else if(strcmp(argp[4], "rb")==0)
        {
            filter_color_component(pix, 5);
        } else filter_color_component(pix, 0);
    }
    else if (strcmp(argp[3], "-g")==0)
    {
        convert_to_grayscale(pix);
    }
    
    write_ppm_color_bitmap(argp[2], pix);

    return 0;
}