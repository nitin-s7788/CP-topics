#include<iostream>

/*
question ->
t test cases
given a number n, find all it's divisors

native approach -> O(n) for each n.

vector<int> v;
for(int i=1; i<=n; i++)
{
    if(n%i == 0)
    {
        v.push_back(i);
    }
}


better approach  -> O(sqrt(n))
we know that all divisors of a number occurs in pairs (half divisors between 1 to sqrt(n) and other half between sqrt(n) to n )
for eg.
100 = (1,100) , (2,50), (4,25), (5,20), (10, 10)
so, we can iterate from 1 to sqrt(n) and in each time we will print a pair of divisors (2 divisors)
edge case -> here note that at i = sqrt(n), both divisors will be same (10,10), so print only 1.

drawback -> the only problem here is that we dont get the divisors in a sorted format, by default

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
        for(int i=1; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                if(i*i == n)
                {
                    cout<<i<<" ";
                    break;
                }
                else
                {
                    cout<<i<<" "<<n/i<<" ";
                }
                
            }
        }
        cout<<endl;
    }

    return 0;
}