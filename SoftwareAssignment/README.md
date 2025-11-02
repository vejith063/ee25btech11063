# Software Assignment c code for truncated svd
First we have to convert the greyscale image into the pixel intensity matrix.For this we can use a library in c called "stb_image.h"

# std_image.h
The function stbi_load() in the above library  plays the major role in converting the greyscale image to pixel intensity matrix
prototype:
unsigned char *stbi_load(char *filename,int *x, int *y, int *channels_in_file,int desired_channels);
* It takes the filename of the greyscale image
* x is an pointer to integer it returns the width of the image 
* y is an pointer to integer it returns the height of the image
* channels_in_file is an pointer to integer that receives the number of color channels in the image( it is 1 for a greyscale image,3 for RGB,4 for RGBA)
* desired_channels it is an integer value which is = 1 for greyscale image, = 3 for RGB, = 4 for RGBA.
It writes the entries to a file named matrix.txt which stores the desired data 


