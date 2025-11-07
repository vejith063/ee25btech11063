#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main() {
    int width, height, channels;
    unsigned char *img = stbi_load("greyscale.png", &width, &height, &channels, 1);
    if (img == NULL) {
        perror("Unable to load greyscale.png\n");
        return 1;
    }
    FILE *fp = fopen("matrix.txt", "w");
    if (fp == NULL) {
        perror("Cannot open file file matrix.txt.\n");
        stbi_image_free(img);
        return 0;
    }
    fprintf(fp, "%d %d\n", height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = img[i * width + j];
            fprintf(fp, "%3d ", pixel);
        }
        fprintf(fp, "\n");
    }
     fclose(fp);
    stbi_image_free(img);

    printf("\nPixel intensity matrix saved as matrix.txt\n");
    return 0;
}

