# Software Assignment
First we have to convert the  image into the pixel intensity matrix.For this we can use a library in c called "stb_image.h"
* Include the macro The macro STB_IMAGE_IMPLEMENTATION must be included before the header. This tells the compiler to include the function implementations (actual code) from the header file, allowing functions like stbi_load() and stbi_image_free()
* Include the header file of the library stb_image.h in the same directory where we execute the code
* After this the file named matrix.txt is produced in which stores the intensity matrix of the input file
* On implementing the truncated SVD code on matrix.txt it will produce reconstructed.txt 
* Enter the name of the output file in which reconstructed image is to be stored
* To convert the matrix into image we use a similar library as above named "stb_image_write.h"
* Include the macro The macro STB_IMAGE_WRITE_IMPLEMENTATION must be included before the header.
* Include the header file of the library stb_image_write.h in the same directory where we execute the code

* Based on the user input the code will distinguish whether it is a .png or .jpg file using a function in string.h called strrchr
# strrchr

prototype: 

                                                 char *strrchr(char *str, int ch);

* It returns a pointer to the last occurence of ch in string str and it stores it as substring 
* char *ext = strrchr(output, '.'); in this part of the code pointer ext stores the substring  last containing  '.'
* After this using strcmp function we can determine whether ext has  .png or .jpg file.
* Finally,we will obtain the reconstructed image which is formed by considering the top k singular values.
* To run the code : gcc imagecompression.c -o imagecompression -lm    followed by   ./imagecompressiom

*  The code prints the frobenious norm on the screen and saves the image in the same directory 






