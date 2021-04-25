#include<iostream>

/*
combinatorics or stars and bars techinque is used to solve mainly 2 types of problems
1.>  no. of integral solutions of equation of the form  -> 
.               x1 + x2 + x3 + .... + xn = K               (where all xi >= c (c is a non-negative integer))
.               for example  ->
.               X + Y + Z = 20                   (all X,Y,Z  >= 2)  (generally it is given X,Y,Z >= 0 or >= 1) 

2.>  no. of ways in which an array of n numbers can be created using k distinct numbers such that all numbers are arranged in 
.    non-increasing/ non-decreasing order (each number can be used any no. of times).
.               for example,
.               given 4 numbers -> 2, 3, 7, 11  an array of size 6 will be -> 2,2,7,7,7,11
.
.
.               the answer of both of above questions will be same (given c=0, in first case), that is ->
.               (n+k-1)C(n-1)  or  (n+k-1)C(k)
.
.
.    Explanation of case-1/problem-1 ->
.               x1 + x2 + x3 + ..... + xn = K              (where all xi >= c (c is a non-negative integer)) 
.    let us give value c to all the variables, than we have
.               x1 + x2 + x3 + ..... + xn = K1             (K1 = K - n.c )
.    now let us consider that we have K1 objects/stars, we just need to insert (n-1) spaces/bars between them to divide them into 
.    n groups, now each of the n groups represent values of xi and the initial K1 objects represent the K1 of our equation.
.    visual representation for n = 7 and k = 4 is ->
.
.               V  V  V  V  V  V  V     -> 7 objects
.              |V  V  V| V  V| V  V     -> one of the possible solutions -> x1=0, x2=3, x3=2, x4=2.
.   
.    so, the answer will be -> we have to select (n-1) positions out of (K1+n-1) positions (K1 objects/stars + (n-1) spaces/bars)
.    so, answer =  (K1+n-1)C(n-1)  or  (K1+n-1)C(K1)
.
.
.    Explanation of case-2/problem-2 ->
.               let the n given numbers be -> N1, N2, N3, ...... Nn.
.    here basically we have to decide how many times we want to take each number (may take a number zero times), as their is only 
.    1 way to arrange them after the selection is done (non-increasing/ non-decreasing)
.
.    let we take N1 -> x1 times,   N2 -> x2 times,   N3 -> x3 times  .....  Nn -> xn times.
.    than,  clearly ->             x1 + x2 + x3 + ....... + xn = K           (as we have to take K numbers in total)
.    now we know that the solution of above equation is -> 
.                                        (K+n-1)C(n-1) or (K+n-1)C(K).
.
.
.    
.    QUESTION IMPLIMENTED ->
.    t test cases
.    input n, k
.    print no. of solutions of x1 + x2 + x3 + ...... + xn = k,   modulo 1000000007
.
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
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n,k;
        cin>>n>>k;
        long long ans;
        ans = combinations(n+k-1, n-1, 1000000007);
        cout<<ans<<endl;
    }
    return 0;
}