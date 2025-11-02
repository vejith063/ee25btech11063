# Software Assignment codes
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
# c code for truncated SVD
The goal of this project is to perform svd on the intensity matrix and to reconstruct AK the image by taking the top k  eigen values and we have to calculate the ∥A − Ak ∥F where ∥ · ∥F is the Frobenius norm and the difference in the properties of image such as quality,etc.

To perform truncated svd for large matrices like intensity matrices the best method is by using Randomized SVD with Gaussian Random Matrix
# Randomized SVD with Gaussian Random Matrix
Mathematical background:

Given a real matrix A ∈ ℝ^(m×n), the Singular Value Decomposition (SVD) is:

A = UΣVᵀ

where:
* U ∈ ℝ^(m×r)  (orthonormal left singular vectors),
* Σ ∈ ℝ^(r×r)  (diagonal matrix of singular values σ₁ ≥ σ₂ ≥ ⋯ ≥ σᵣ > 0),
* V ∈ ℝ^(n×r)  (orthonormal right singular vectors),
* r = rank(A).



