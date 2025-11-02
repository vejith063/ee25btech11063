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

For a real matrix A ∈ ℝ^(m×n), the Singular Value Decomposition (SVD) is:

A = UΣVᵀ

where:
* U ∈ ℝ^(m×r)  (left singular vectors with unit norm) and U are the orthonormal eigen vectors of AAᵀ
* Σ ∈ ℝ^(r×r)  (diagonal matrix with singular values σ₁ ≥ σ₂ ≥ ⋯ ≥ σᵣ > 0) and Σ^2 are the eigen vales of AᵀA
* V ∈ ℝ^(n×r)  (right singular vectors with unit norm ), where  r = rank(A) and V are the orthonormal eigen vectors of AᵀA

goal is to reconstruct the matrix A by taking top k eigen values i.e Aₖ = UₖΣₖVₖᵀ
* Generate a gaussian random matrix:

let Ω be the random matrix generated i.e U ∈ ℝ^(n×k) whose entries are independently and choosen and Ωij​ ∼ N(0,1) this means that the average of all the entries of the random matrix is 0 and it also says that the variance of all the entries of the random matrix is 1
* Form a matrix Y such that 
                   Y = AΩ
* perform QR decomposition on Y to compute the Orthonormal  basis of Y

let 
        Q = orthonormal basis of Y and Q ∈ R^(m×k) and QᵀQ = Iₖ and A ≈ QQᵀA
* compute a smaller matrix B 

B = QᵀA and B ∈ R^(k×n)
* Now compute SVD on B as B is a much smaller matrix it is easy to compute SVD on B 

    B = ŨΣVᵀ  where 
  * Ũ are the orthonormal eigen vectors of BBᵀ , Ũ ∈ ℝ^(k×k)
  *  V are orthonormal eigen vectors of BᵀB , V ∈ ℝ^(n×k) which are thew same as orthonormal eigen vectors of AᵀA
  * Σ² are the eigen values of BᵀB which are same as the eigen values of AᵀA
  
the right unit norm vectors V are same for B and U and Ũ are the eigen vectors of the matrix B now we need to find U
* U = QŨ   where U  ∈ ℝ^(m×K) and U is the left unit norm vectors of A 

Now the goal is to find Aₖ
* Aₖ = ∑ᵢ₌₁ᵏ σᵢuᵢvᵢᵀ

This is our desired reconstructed intensity matrix Aₖ










