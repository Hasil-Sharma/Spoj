#include<iostream>
#include <cstdio>
using namespace std;
 
template< class T >
class Matrix
{
    public:
        int m,n,mod;
        T *data;
 
        Matrix( int m, int n );
        Matrix( const Matrix< T > &matrix );
 
        const Matrix< T > &operator=( const Matrix< T > &A );
        const Matrix< T > operator*( const Matrix< T > &A );
        const Matrix< T > operator%( const Matrix< T > &A );
        const Matrix< T > operator^( int P );
 
        ~Matrix();
};
 
template< class T >
Matrix< T >::Matrix( int m, int n )
{
    this->m = m;
    this->n = n;
    data = new T[m*n];
}
 
template< class T >
Matrix< T >::Matrix( const Matrix< T > &A )
{
    this->m = A.m;
    this->n = A.n;
    data = new T[m*n];
    for( int i = 0; i < m * n; i++ )
        data[i] = A.data[i];
}
 
template< class T >
Matrix< T >::~Matrix()
{
    delete [] data;
}
 
template< class T >
const Matrix< T > &Matrix< T >::operator=( const Matrix< T > &A )
{
    if( &A != this )
    {
        delete [] data;
        m = A.m;
        n = A.n;
        data = new T[m*n];
        for( int i = 0; i < m * n; i++ )
            data[i] = A.data[i];
    }
    return *this;
}
 
template< class T >
const Matrix< T > Matrix< T >::operator*( const Matrix< T > &A )
{
    Matrix C( m, A.n );
    for( int i = 0; i < m; ++i )
        for( int j = 0; j < A.n; ++j )
        {
            C.data[i*C.n+j]=0;
            for( int k = 0; k < n; ++k )
                C.data[i*C.n+j] = C.data[i*C.n+j] + data[i*n+k]*A.data[k*A.n+j];
        }
    return C;
}
 
template< class T >
const Matrix< T > Matrix< T >::operator^( int P)
{
    if( P == 1 ) return (*this);
    if( P & 1 ) return (*this) * ((*this) ^ (P-1));
    Matrix B = (*this) ^ (P/2);
    return B*B;
}
template< class T >
const Matrix< T > Matrix< T >::operator%( const Matrix< T > &A)
{
    Matrix C(4,4);
    for( int i = 0; i < m; ++i )
        for( int j = 0; j < A.n; ++j )
        {
            C.data[i*m + j] = A.data[i*m + j]%A.mod;
        }
    return C
}
int main()
{
    Matrix<int> M(4,4);
    M.data[0] = 1;M.data[1] = 1;M.data[2] = 1;M.data[3] = 0;
    M.data[4] = 1;M.data[5] = M.data[6] = M.data[7] = 0;
    M.data[8] = M.data[9] = 0; M.data[10] = 2; M.data[11] = -1;
    M.data[12] = M.data[13] = M.data[15] = 0; M.data[14] = 1;
 
    int F[2]={0,1};
    int N;
    while (~scanf("%d",&N))
       {
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    printf("%d ",(M^N).data[i*4+j]);
                }   
                printf("\n");
            }
                

       }
}