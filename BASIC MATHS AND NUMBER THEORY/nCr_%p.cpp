#include<iostream>
#include<vector>

using namespace std;


long long power(long long a, long long n, long long m)
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return a;
    }
    long long temp = power(a,n/2,m) % m;
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
    M1 = power(b, M-2, M);
    M2 = power(c, M-2, M);

    ans = ((a%M) * (M1%M)) % M;              // explaination of this part in "modulo_multiplicative_inverse.cpp"
    ans = ((ans%M) * (M2%M)) % M;
    return ans;

}



int main ()
{
    int n,r, M = 1000000009;
    cin>>n>>r;
 
    int ans = combinations(n,r,M);
    cout<<n<<"C"<<r<<" : "<<ans<<endl;
    return 0;
}


/*
we in everyquery of finding nCr, r is constant and small (r! < 1000000009/M), that always use find nCr as nCr = n*(n-1)*(n-2)...(n-r+1) / r!  
(compute r! in start of program) for eg. if r = 3 than code should be ->

long long comb(long long n, long long M)
{
    long long ans = 1;
    for(long long i=n; i>(n-r); i--)
    {
        ans = ans*i;
        ans = ans%m;
    }
    ans = ans/r!;
    return ans;
}
*/