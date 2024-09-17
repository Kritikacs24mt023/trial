#include "../hdr/matmul.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
//#include <cblas.h> // For BLAS functions



//  blass code 



/*
// Use BLAS for matrix multiplication and dot product (only for single precision)
#ifdef SINGLE
void matmul_blas(int n, data_t* A, data_t* B, data_t* C) {
    float alpha = 1.0f, beta = 0.0f;
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                n, n, n, alpha, A, n, B, n, beta, C, n);
}

data_t dot_product_blas(int n, data_t* A, data_t* B) {
    return cblas_sdot(n, A, 1, B, 1);
}
#else
// BLAS functions are not used for double precision, so these are empty
void matmul_blas(int, data_t*, data_t*, data_t*) {
    std::cerr << "BLAS is not supported for double precision." << std::endl;
}

data_t dot_product_blas(int, data_t*, data_t*) {
    std::cerr << "BLAS is not supported for double precision." << std::endl;
    return 0;
}
#endif

*/






// Loop order IJK
void matmul_ijk(int n, data_t *A, data_t *B, data_t *C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
}

// Loop order IKJ
void matmul_ikj(int n, data_t *A, data_t *B, data_t *C) {
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
}

// Loop order JIK
void matmul_jik(int n, data_t *A, data_t *B, data_t *C) {
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
}

// Loop order JKI
void matmul_jki(int n, data_t *A, data_t *B, data_t *C) {
    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
}

// Loop order KIJ
void matmul_kij(int n, data_t *A, data_t *B, data_t *C) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
}

// Loop order KJI
void matmul_kji(int n, data_t *A, data_t *B, data_t *C) {
    for (int k = 0; k < n; k++)
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <matrix size>" << std::endl;
        return 1;
    }

    int n = atoi(argv[1]);
    data_t *A = new data_t[n * n];
    data_t *B = new data_t[n * n];
    data_t *C = new data_t[n * n];

    std::srand(std::time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i * n + j] = std::rand() / (data_t)(RAND_MAX);
            B[i * n + j] = std::rand() / (data_t)(RAND_MAX);
            C[i * n + j] = 0;
        }
    }

    const auto start = std::chrono::steady_clock::now();

#ifdef LOOP_ORDER_IJK
    matmul_ijk(n, A, B, C);
#elif defined(LOOP_ORDER_IKJ)
    matmul_ikj(n, A, B, C);
#elif defined(LOOP_ORDER_JIK)
    matmul_jik(n, A, B, C);
#elif defined(LOOP_ORDER_JKI)
    matmul_jki(n, A, B, C);
#elif defined(LOOP_ORDER_KIJ)
    matmul_kij(n, A, B, C);
#elif defined(LOOP_ORDER_KJI)
    matmul_kji(n, A, B, C);
//#elif defined(USE_BLAS)  // Use BLAS sgemm for matrix multiplication
  //  matmul_blas(n, A, B, C);
#endif

    const auto end = std::chrono::steady_clock::now();
    const std::chrono::duration<float> elapsedtime = end - start;

    std::cout << "Elapsed time: " << elapsedtime.count() << " seconds" << std::endl;





    //   code with blas  
    /* 

    // Optional: Perform a dot product between two random rows/columns of A and B
    int random_row = std::rand() % n;
    int random_col = std::rand() % n;

    data_t dot_product_result = 0;
#ifdef SINGLE
    dot_product_result = dot_product_blas(n, &A[random_row * n], &B[random_col]);
    std::cout << "Dot product of row " << random_row << " of A and column " << random_col << " of B: " << dot_product_result << std::endl;
#else
    std::cerr << "Dot product with BLAS is only available for single precision." << std::endl;
#endif

    
   */

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}

