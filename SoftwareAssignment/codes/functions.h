//Function prototypes
double **creatematrix(int m,int n);
void freematrix(double **A, int m);
int readmatrix(char *name,double ***A,int *m,int n);
void writematrix(char *name,double **A,int *m,int n);
double **matmul(double **A,double **B,int m,int p,int n);
double **transpose(double **A, int m, int n);
double **randommatrix(int m,int n);
void Gram-schmidt(double **A,int m,int n);


//function definitions 

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
 
int readmatrix(char *name,double ***A,int *m,int n){
  FILE *fp = fopen("fname","r");
  if (fscanf(f, "%d %d", m, n) != 2) {
        fclose(f);
        return 0;
    }
    *A = creatematrix(*m, *n);
    for(int i=0;i<*m;i++){
       for(int j=0;j<*n;j++){
          fscanf(fp,"%lf",&(*A)[i][j]);
          }}
          fclose(fp);
          return 0;
  }
  
  void writematrix(char *name,double **A,int *m,int n){
    FILE *fp = fopen("fname","w");
    fprintf(fp,"%d %d\n",m,n);
    for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
       fprintf(fp,"%lf",A[i][j]);
       }
       fprintf("\n);
       }
       fclose(fp);}
       
double **matmul(double **A,double **B,int m,int p,int n){
  double **c =creatematrix(m,n);
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      double temp =0;
      for(int k=0;k<p;k++){
       temp+=A[i][k] *B[k][j];
       }
       c[i][j] = temp;
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
 double **rand = creatematrix(m,n);
  for(int i=0;i<m;i++){
   for(int j=0;j<n;j++){
     rand[i][j] = ((double)rand()/ RAND_MAX);
     }}
     return rand;
}

void Gram-schmidt(double **A,int m,int n){
 for(int i=0;i<n;i++){
   for(int j=0;j<i;j++){
     double res=0;
     for (int k = 0; k < m; k++)
                res += A[k][i] * A[k][j];
            for (int k = 0; k < m; k++)
                A[k][i] -= res * A[k][j];
      }
      double nm =0;
      for(int p=0;p<m;p++){
        nm += A[p][i] *A[p][i];
        }
        nm =sqrt(nm);
    for (int k = 0; k < m; k++){
                A[i][j] = A[i][j]/nm;
    }
    }}
    
