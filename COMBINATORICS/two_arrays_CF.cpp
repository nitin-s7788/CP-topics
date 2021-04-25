#include<iostream>

/*
code forces problem ->

You are given two integers n and m. Calculate the number of pairs of arrays (a,b) such that:

the length of both arrays is equal to m
each element of each array is an integer between 1 and n (inclusive);
ai≤bi for any index i from 1 to m;
array a is sorted in non-descending order;
array b is sorted in non-ascending order.

As the result can be very large, you should print it modulo 10^9+7.

I/O -> only line of input -> N, M       , only line of output -> ans
sample I/O -> 2,2  ->  5                 a=[1,1],b=[2,2];  a=[1,2],b=[2,2];  a=[2,2],b=[2,2];  a=[1,1],b=[2,1];  a=[1,1],b=[1,1].
.          -> 10, 1 -> 55 

solution ->
clearly,  bm (smallest element of array B) >= am (largest element of array A)
so, we can say that we require a sequence of length 2m as -> a1, a2, a3 .... am, b1, b2, b3 ..... bm,
clearly this is a unique sequence like arranging all the 2m numbers in non-increasing/ non-decreasing order. i.e. we just need to 
find the number of ways of selecting these 2.m numbers, their is only 1 permutation/arrangement possible for them.

so, the answer is same as -> selecting 2.m numbers from 1 to n. (any number can be taken any number of times)
i.e. it is same as no. of solution of -> 
.              x1 + x2 + x3 + .......  xn = 2m 
. we just need to figure out how many times we want to take each number from 1 to n (may take it zero times)
. so ans  =  (n+2m-1)C(n-1)  or  (n+2m-1)C(2m)
*/

using namespace std;

// finding (a^n)%m
long long modulo_inverse(long long a, long long n, long long m)
{
    if(n == 1)
    {
        return a;
    }
    long long temp = modulo_inverse(a,n/2,m) % m;
    if(n%2 == 0)
    {
        temp = (temp*temp)%m;
        return temp;
    }
    else
    {
        temp = (temp*temp)%m;
        temp = (temp*a)%m;
        return temp;
    }
}

long long factorial(long long n, long long M)
{
    long long ans = 1;
    for(int i=2; i <= n; i++)
    {
        ans = (ans*i) % M;
    }
    return ans;
}

long long combinations(long long n, long long r, long long M)
{
    // To be done
    long long a,b,c, M1, M2, ans;
    a = factorial(n, M);
    b = factorial(r, M);
    c = factorial(n-r, M);
    M1 = modulo_inverse(b, M-2, M);
    M2 = modulo_inverse(c, M-2, M);

    ans = ((a%M) * (M1%M)) % M;
    ans = ((ans%M) * (M2%M)) % M;
    return ans;

}

int main ()
{
    int n, m;
    cin>>n>>m;

    long long ans = combinations(n+2*m-1, n-1, 1000000007);
    cout<<ans<<endl;

    return 0;
}