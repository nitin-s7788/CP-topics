#include<iostream>

/*
question ->
t test cases
in each test case, find x^n
print answer % 1000000007

native approach -> O(n)

better approach -> O(log(n))
we know that (x^n1)^2 = x^(n1) * x^(n1)
i.e. to find x^10 -> we will do -> x^10 = x^5 * x^5,  x^5  = x^2 * x^2 * x ,  x^2 = x*x

*/

using namespace std;

long int power(long long int x, long long int n)
{
    if(n == 1)
    {
        return x;
    }

    long long int temp = power(x, n/2) % 1000000007;

    if(n%2 == 0)
    {
        return (temp * temp) % 1000000007;
    }
    else
    {
        return ( ((temp * temp)%1000000007) * x) % 1000000007;
    }
}

int main ()
{
    int t;
    cin>>t;

    for(int i=0; i<t; i++)
    {
        long  long int x, n, ans;
        cin>>x>>n;

        ans = power(x,n);

        cout<<ans<<endl;

    }

    return 0;
}