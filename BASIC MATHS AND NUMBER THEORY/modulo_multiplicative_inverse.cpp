#include<iostream>

/*
What is modulo multiplicative inverse of a number?
.      if   (a.x)%m = 1,    than x is called modulo multiplicative inverse of a w.r.t. m.
.
.      it is also defined as follows ->
.      (a/b)%m    =  (a * B)%m             (where B is modulo multiplicative inverse of b)
.
Need/requirement of modulo multiplicative inverse of a number?
.      if we have to find the value of  (a.b)%m  (a,b are very big numbers) than we can do it easily by using ->
.      (a.b)%m = ((a%m) * (b%m)) % m
.      but if we have to find (a/b)%m, than we CANNOT DO ->
.      (a/b)%m = ((a%m) / (b%m)) % m
.      to resolve this problem we use multiplicative modulo inverse as ->
.      (a/b)%m = ((a%m) * (B%m)) % m              (B is modulo multiplicative inverse of b)
.
.
Finding modulo multiplicative inverse of a number b.
.
.      *modulo multiplicative inverse of b exist wrt to m, if and only if a and b are co-prime/ relatively prime/ gcd(b,m) = 1.
.      *modulo multiplicative inverse of b, x ->  1 <= x < m
.
.      Method - 1 ->  brute force O(m)
.      int temp = b%m;
.      for(int i = 1; i<m; i++)
.      {
.           if( (temp*i)%m == 1)
.               return i;
.      }
.
.      
.      Method - 2 -> O(log(m))      -> in this we use extended euclidean algo  
.
.      Method - 3 -> O(log(m))            -> WORKS ONLY IF M IS A PRIME NO. (this is very useful as generally we only need % of a prime number, that too of 10^9 + 7)
.      B = b^(m-2) % m / B = b^(p-2) % p  -> B = ans/modulo inverse ,  m/p = prime no. wrt which we are finfing MMI.
.      
.      here we are using 3rd method
.    
.      Question.
.      t test cases
.      given a, p  -> find modulo multiplicative inverse of a wrt p
*/

using namespace std;

// finding (a^n)%m
long long power(long long a, long long n, int m)
{
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

int main ()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int a, n;
        cin>>a>>n;
        int ans = power(a,n-2,1000000007);
        cout<<ans<<" ";
    }
    return 0;
}