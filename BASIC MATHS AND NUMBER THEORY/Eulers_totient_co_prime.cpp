#include<iostream>
#include<vector>

/*
Eulers totient function/ eulers phi function,  F(n) = no. of integers between 1 to n, which are co-prime to n. (i.e gcd(x,n) = 1)

some properties ->
F(1) = 1
F(p) = p-1  , where p = prime no.
F(a*b) = F(a) * F(b)    , where a and b are co-prime

native approach -> O(n.logn(n))  for each n 
iterate from 1 to n, and find gcd(x, n), if gcd == 1, count++

better approach -> O(sqrt(n)) for 1 n.  / O(nlogn) for all numbers between 1 to n (using seive)

we have figured out a formula, for Eulers totient function, that is ->
for a prime number, n  , F(n) = n-1   (as 1,2,3,4,....n-1   all are co-prime to n)
for a general number,  n = (P1^x1) * (p2^x2) * (p2^x3) ....    (P1, p2 ...  = prime numbers)/(i.e. for given prime factorisation)

F(n) = n*(1-1/p1)*(1-1/p2)*(1-1/p3)...  =  n*(p1-1)*(p2-1)*(p3-1)../p1*p2*p3...

now to find F(n), 
we will find the prime factorisation of n,  in sqrt(n)  or   n.log(n) for all integers between 1 to n
and than apply the above formula.

here we are implementing O(sqrt(n)) approach, i.e.  for t test cases, O(t.sqrt(n))


question ->
t test cases
given a number n, find  F(n), i.e. no. of co-prime numbers from 1 to n, wrt n.
*/

using namespace std;

int main ()
{
    int t;
    cin>>t;
    
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        int temp =  n;
        vector<int> primes;

        for(int j=2; j*j <= n; j++)
        {
            if(n%j == 0)
            {
                primes.push_back(j);
                while(n%j == 0)
                {
                    n = n/j;
                }
            }
        }
        if(n != 1)
        {
            primes.push_back(n);
        }

        int ans = temp;
        for(int j=0; j<primes.size(); j++)
        {
            ans = ans*(primes[j]-1);
        }
        for(int j=0; j<primes.size(); j++)
        {
            ans = ans/primes[j];
        }

        cout<<ans<<endl;

    }

    return 0;
}