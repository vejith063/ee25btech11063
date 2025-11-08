#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

double **creatematrix(int m,int n){
 double **mat = (double **)malloc(m*sizeof(double *));
 for(int i=0;i<m;i++){
  mat[i] = (double *)malloc(n*sizeof(double)); }
  return mat;
  }
  
void freematrix(double **A, int m){
 for(int i=0;i<m;i++)  free(A[i]);
 free(A);
 }
 
int readmatrix(char *fname,double ***A,int *m,int *n){
  FILE *fp = fopen(fname,"r");
  if (!fp) {
        printf("Error opening file");
        return 0;
    }
  if (fscanf(fp, "%d %d", m, n) != 2) {
        fclose(fp);
        return 0;
    }
    *A = creatematrix(*m, *n);
    for(int i=0;i<*m;i++){
       for(int j=0;j<*n;j++){
          fscanf(fp,"%lf",&(*A)[i][j]);
          }}
          fclose(fp);
          return 1;
  }
  
  void writematrix(char *fname,double **A,int m,int n){
    FILE *fp = fopen(fname,"w");
    fprintf(fp,"%d %d\n",m,n);
    for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
       fprintf(fp,"%.6f ",A[i][j]);
       }
       fprintf(fp,"\n");
       }
       fclose(fp);}
       
double **matmul(double **A,double **B,int m,int p,int n){
  double **c =creatematrix(m,n);
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      double mul =0;
      for(int k=0;k<p;k++){
       mul+=A[i][k] *B[k][j];
       }
       c[i][j] = mul;
       }}
       return c;
  }
  
  double **transpose(double **A, int m, int n) {
    double **T = creatematrix(n, m);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            T[j][i] = A[i][j];
            }}
    return T;
}

double **randommatrix(int m,int n){
 double **r = creatematrix(m,n);
  for(int i=0;i<m;i++){
   for(int j=0;j<n;j++){
   //(double)rand()/ RAND_MAX) provides a uniformly distributed pseudo random number within the range[0.0,1.0]
     r[i][j] = ((double)rand()/ RAND_MAX);
     }}
     return r;
}

void Gram_schmidt(double **A,int m,int n){
  for (int j = 0; j < n; j++) {
        for (int k = 0; k < j; k++) {
            double res = 0;
            for (int i = 0; i < m; i++)
                res += A[i][j] * A[i][k];
            for (int i = 0; i < m; i++)
                A[i][j] -= res * A[i][k];
        }
        double norm = 0;
        for (int i = 0; i < m; i++)
            norm += A[i][j] * A[i][j];
        norm = sqrt(norm);
        if (norm > 1e-12)
            for (int i = 0; i < m; i++)
                A[i][j] /= norm;
    }
}

double frobeniusnorm(double **A, double **B, int m, int n) {
    double res = 0.0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            double d = A[i][j] - B[i][j];
            res += d * d;
        }
    return sqrt(res);
}


int main() {
char file[256];
printf("Enter the filename : ");
scanf("%255s",file);
// enter input file name 
int width, height, channels;
// reads the image same for both .png and .jpg
    unsigned char *img = stbi_load(file, &width, &height, &channels, 1);
    if (img == NULL) {
        printf("Unable to load %s\n",file);
        return 1;
    }
    FILE *fp = fopen("matrix.txt", "w");
    if (fp == NULL) {
        printf("Cannot open file file matrix.txt.\n");
        stbi_image_free(img);
        return 0;
    }
    fprintf(fp, "%d %d\n", height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = img[i * width + j];
            fprintf(fp, "%3d ", pixel);
            // %3d gives a fixed space of 3spaces for the entries of the matrix
        }
        fprintf(fp, "\n");
    }
     fclose(fp);
    stbi_image_free(img);

    printf("\nPixel intensity matrix saved as matrix.txt\n");
    
      double **A;
  int m,n,k;
   if(!readmatrix("matrix.txt",&A,&m,&n)){
     printf("file not found");
     return 0;
  }
  printf("The value of k is ");
  // Takes the input value k
  scanf("%d",&k);
   // generates random matrix omega
  double **omega = randommatrix(n,k);
  // multiplies A and omega
  double **Y = matmul(A, omega, m, n, k);
  // performs power iterations 
   for(int i=0;i<2;i++){
    double **AT = transpose(A, m, n);
    double **Z = matmul(AT, Y, n, m, k);
    double **B = matmul(A, Z, m, n, k);
     freematrix(AT, n);
      freematrix(Z, n);
      freematrix(Y, m);
      // ensures that the norm is 1
       for (int r = 0; r < m; r++) {
        double norm = 0.0;
        for (int c = 0; c < k; c++) norm += B[r][c] * B[r][c];
        norm = sqrt(norm);
       for (int c = 0; c < k; c++) B[r][c] /= norm;
       
    }

    Y = B;
}
// performs QR decomposition
  Gram_schmidt(Y,m,k);
   double **Q = Y;
  double **QT = transpose(Q, m, k);
  double **c = matmul(QT, A, k, m, n);
  double **A_k = matmul(Q, c, m, k, n);
  writematrix("reconstructed.txt",A_k,m,n);
  
  printf("matrix saved to reconstructed.txt\n");
  // calculation of frobenius norm
  double f = frobeniusnorm(A, A_k, m, n);
  printf("Frobenius norm  between A and A_%d is %lf\n",k,f);
  freematrix(A, m);
  freematrix(omega, n);
  freematrix(Q, m);
  freematrix(QT, k);
  freematrix(c, k);
   freematrix(A_k, m);
   
  
  char output[256];
  printf("Enter the name of the reconstructed image :");
  scanf("%255s",output);
  // to enter the name of the output file
 FILE *fp2 = fopen("reconstructed.txt", "r");
    if (!fp2) return 1;

    int rwidth, rheight;
    fscanf(fp2, "%d %d", &rheight, &rwidth);
// rwidth and rheight are the width and heights of reconstructed image
    int total = rwidth * rheight;
    unsigned char *rimg = malloc(total);
    if (!rimg) return 1;

    double val;
    int count = 0;
    while (fscanf(fp2, " %lf", &val) == 1 && count < total)
        rimg[count++] = (unsigned char)(fmax(0, fmin(255, val)));
//fmin() ensures that no value is more than 255 and fmax() ensures that no value is less than 0 
    fclose(fp2);

    char *ext = strrchr(output, '.');
    // This will decide whether the output file is .png or .jpg
    if (ext && strcmp(ext, ".png") == 0) {
    // format for .png file
        if (stbi_write_png(output, rwidth, rheight, 1, rimg, rwidth))
            printf("Image saved as %s\n", output);
        else
            printf("Failed to save the image.\n");
    } 
    else if (ext && strcmp(ext, ".jpg") == 0) {
    // format for .jpg files
        if (stbi_write_jpg(output, rwidth, rheight, 1, rimg, 100))
            printf("Image saved as %s\n", output);
        else
            printf("Failed to save the image.\n");
    } 
    else {
        printf("Unsupported file extension. \n");
    }

    free(rimg);
    return 0;
}

    
