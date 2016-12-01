/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 11.2
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <Accelerate/Accelerate.h>


typedef double value_type;
typedef std::vector<value_type> matrix_type;
typedef matrix_type::size_type size_type;

//FORTRAN IMPORT
extern "C" {
    void cblas_dgemm(const enum CBLAS_ORDER __Order, const enum CBLAS_TRANSPOSE __TransA, const enum CBLAS_TRANSPOSE __TransB, const int __M, const int __N, const int __K, const double __alpha, const double *__A, const int __lda, const double *__B, const int __ldb, const double __beta, double *__C, const int __ldc);
}

void set(matrix_type& A, const size_type n)
{
    for (size_type i=0; i<n*n; ++i)
        A[i] = drand48();
}

void multiply_simple(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
    for (size_type i = 0; i<n; ++i) {
        for (size_type j = 0; j<n; ++j) {
            for (size_type k = 0; k < n; ++k) {
                C[i*n+j] = A[i*n+k]*B[k*n+j];
            }
        }
    }
}

void print(const matrix_type& A, const size_type n)
{
    for (size_type i=0; i<n; ++i) {
        for (size_type j=0; j<n; ++j) {
            std::cout << A[i*n+j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    srand48(42);
    const size_type n = 1024/2;
    const unsigned num_iter = 8;
    matrix_type A(n*n), B(n*n), C(n*n);
    set(A,n);
    set(B,n);
    std::chrono::time_point< std::chrono::high_resolution_clock > t_start, t_end;
    t_start = std::chrono::high_resolution_clock::now();

    for (unsigned i = 0; i < num_iter; ++i)
        multiply_simple(A, B, C, n);

    t_end = std::chrono::high_resolution_clock::now();
    std::cout << "Own solution :" << std::endl;
    std::cout << n << " " << static_cast<std::chrono::duration<double> >(t_end - t_start).count()  << std::endl;

    t_start = std::chrono::high_resolution_clock::now();

    for (unsigned i = 0; i < num_iter; ++i)
        cblas_dgemm(CblasRowMajor,CblasNoTrans, CblasNoTrans, n, n, n, 0, &A[0], n, &B[0], n, 0, &C[0], n);

    t_end = std::chrono::high_resolution_clock::now();
    std::cout << "FORTRAN solution :" << std::endl;
    std::cout << n << " " << static_cast<std::chrono::duration<double> >(t_end - t_start).count()  << std::endl;

}
