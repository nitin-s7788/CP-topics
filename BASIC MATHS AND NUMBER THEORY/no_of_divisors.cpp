#include<iostream>

/*
question ->
t test cases
given a no. n, find the number of divisors of n.

native approach -> O(n) for each test case.

better approach -> O(sqrt(n)) for each case.  (by finding all divisors [divisors occur in pairs])

best approach -> O(nlog(n)) for all numbers from 1 to n.
if n = (P1^x1)*(p2^x2)*(p3^x3)...   (prime factorisation) , than no. of divisors of n, is (x1+1)*(x2+1)*(x3+1)...
*/

using namespace std;

int main ()
{
    int t;
    cin>>t;

    int *arr = new int[1000001];

    for(int i=0; i <= 1000000; i++)
        arr[i] = i;
    
    for(int i=2; i*i <= 1000000; i++)
    {
        if(arr[i] != i)   // i.e. not prime
        {
            continue;
        }

        for(int j=i; j<=1000000; j += i)
        {
            arr[j] = i;
        }
    }
    // now arr[j] contains smallest/least prime factor of j.

    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;

        int Pi = arr[n], xi = 0, ans = 1;      // Pi = ith prime_factor , xi = no. of times Pi is their

        while(n != 1)
        {
            while(arr[n] == Pi)
            {
                xi++;
                n=n/Pi;
            }
            Pi = arr[n];
            ans = ans*(xi+1);
            xi = 0;
        }

        cout<<ans<<endl;

    }

    return 0;
}