#include<iostream>

using namespace std;

/*
question ->
given a recursive sequence/series of order k, find the value to it's n th term.
An = C1.An-1 + C2.An-2 + C3.An-3 +...... Ck.An-k       // C1, C2 ... Ck = constants ,  An = n th term of sequence
t test cases (each test case has 4 lines of input)
first line -> k (order of recursive sequence)
second line -> k integers -> A1, A2, A3, ... Ak  (first K terms of sequence/series)
third line -> K integers -> C1, C2, C3, ....Ck   (constant cofficients of the series)
fourth line -> n (find the nth number of series)


approach (best) -> matrix exponentiation method -> O(k^3.log(n))  [k^3 is just a big constant] 

let F(1) = [ Ak ]              F(2) = [ Ak+1 ]          F(n-k+1)  =  [ An ]   
.          [ Ak-1 ]                   [ Ak ]                         [ An-1 ]
.          [ .  ]                     [ .  ]                         [ .  ]
.          [ .  ]                     [ .  ]                         [ .  ]
.          [ .  ]                     [ .  ]                         [ .  ]
.          [ A2 ]                     [ A3 ]                         [ An-k+2 ]
.          [ A1 ]                     [ A2 ]                         [ An-k+1 ]

before programming, we will find a K x K matrix T, such that ->
.                   F(2) = T. F(1)
.                   F(3) = T. F(2) = T^2. F(1)
.
.                   F(n) = T. F(n-1) = T^(n-1). F(1)

clearly, 
.                   T = [ C1 C2 C3 ..... Ck ]
.                       [ 0  1  0  0 ..   0 ]
.                       [ 0  0  1  0 ..   0 ]
.                       ....
.                       [ 0  0  0  0 ..   1 ]

so, now 
if(n <= k) -> directly print An   (as we know the first K terms)
if(n > k)  ->
.              first make the matrix A1   (using first k terms of series)
.              than make matrix T         (using the constants C1, C2, C3 ... Ck)
.              make a function to multiply 2 matrix      (takes O(k^3) time)
.              make a function to calculate the power of a matrix  (this function takes O(K^3.log(n)) time)
.              now call above funtion and find T^(n-k)
.              do T^(n-k) * A1
.              A[0][0]/ the first term of matrix so formed is our answer.
   
*/

/* 
note that arrays are passed by reference, so the recursive function will do change in original array passed.
to avoid this thing we can use vectors (as they are passed by value by default (also O(N) time is wasted in that case, to create the copy of vector.))
*/

void matrix_multiply(int *matrix1[100], int n1, int m, int *matrix2[100], int n2, int *result[100])
{
    long long int sum = 0;
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            sum = 0;
            for(int k=0; k<m; k++)
            {
                long long int a = matrix1[i][k]%1000000000, b = matrix2[k][j]%1000000000;
                sum = (sum + a*b) % 1000000000;
            }
            result[i][j] = sum;
        }
    }
}

void matrix_power(int *matrix[100], int n, int *result[100], int p)
{
    if(p == 1)
    {
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            result[i][j] = matrix[i][j];
        }
        return ;
    }

    int ** temp = new int*[n];
    for(int i=0; i<n; i++)
    {
        temp[i] = new int[n];
    }

    matrix_power(matrix, n, temp, p/2);
    if(p % 2 == 0)
    {
        matrix_multiply(temp, n, n, temp, n, result);
    }
    else
    {
        int ** temp2 = new int*[n];
        for(int i=0; i<n; i++)
        {
            temp2[i] = new int[n];
        }
        matrix_multiply(temp, n, n, temp, n, temp2);
        matrix_multiply(temp2, n, n, matrix, n, result);
    }
    
}



int main ()
{
    int t;
    cin>>t;
    for(int t1 = 0; t1<t; t1++)
    {
    int k, n;
    cin>>k;
    int *b = new int[k];
    int *c = new int[k];
    for(int i=0; i<k; i++)  
        cin>>b[i];
    for(int i=0; i<k; i++)
        cin>>c[i];

    cin>>n;

    if(n <= k)
    {
        cout<<b[n-1]<<endl;
        continue;
    }
    n = n-k;



    int **matrix1 = new int*[k];
    for(int i=0; i<k; i++)
    {
        matrix1[i] = new int[k];
    }

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(i == 0)
            {
                matrix1[i][j] = c[j];
            }
            else
            {
                if(j == i-1)
                {
                    matrix1[i][j] = 1;
                }
                else
                {
                    matrix1[i][j] = 0;
                }  
            }
        }
    }

    int **matrix2 = new int*[k];
    for(int i=0; i<k; i++)
    {
        matrix2[i] = new int[1];
    }
    for(int i=0; i<k; i++)
    {
        matrix2[i][0] = b[k-i-1];
    }

    int **power_matrix = new int*[k];
    for(int i=0; i<k; i++)
    {
        power_matrix[i] = new int[k];
    }
    int **result = new int*[k];
    for(int i=0; i<k; i++)
    {
        result[i] = new int[1];
    }

    matrix_power(matrix1, k, power_matrix, n);

    matrix_multiply(power_matrix, k, k, matrix2, 1, result);
    

    cout<<result[0][0]<<endl;

    }

    return 0;
}

