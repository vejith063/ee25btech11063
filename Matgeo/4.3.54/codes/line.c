#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("line.dat", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Final derived equation
    fprintf(fp, "The required line equation is: 107x - 32y = 92\n");

    fclose(fp);
    printf("Output written to line.dat successfully.\n");
    return 0;
}

