# filter_image
Simple .ppm image filtering program in C. Project for MMS Star Camp.

Usage:
./filter_image *input_file* *output_file* *parameters*

Parameters:
-g - grayscale
-f - filter image by color channel: r, g, b, rg, rb

Usage example:
./filter_image tux.ppm output.ppm -f rb

![image](https://user-images.githubusercontent.com/57728039/182178550-c9f3d342-e806-438d-8308-a2ccbd1eb2c2.png)

turns into:

![image](https://user-images.githubusercontent.com/57728039/182178630-7c61bfe3-d56d-4b5b-9c8e-495c41602a0a.png)
