#ifndef MATMUL_H
#define MATMUL_H

#ifdef SINGLE
typedef float data_t;
#else
typedef double data_t;
#endif


void matmul_ijk(int n, data_t *A, data_t *B, data_t *C);
void matmul_ikj(int n, data_t *A, data_t *B, data_t *C);
void matmul_jik(int n, data_t *A, data_t *B, data_t *C);
void matmul_jki(int n, data_t *A, data_t *B, data_t *C);
void matmul_kij(int n, data_t *A, data_t *B, data_t *C);
void matmul_kji(int n, data_t *A, data_t *B, data_t *C);

#ifdef SINGLE
void matmul_blas(int n, data_t* A, data_t* B, data_t* C);
data_t dot_product_blas(int n, data_t* A, data_t* B);
#endif


#endif // MATMUL_H

