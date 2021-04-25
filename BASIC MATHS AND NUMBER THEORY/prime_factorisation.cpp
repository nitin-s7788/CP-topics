#include<iostream>

using namespace std;

/*
question ->
t test cases
in each test case given a number n (n <= 10^6)
find it's prime factorisation


native approach -> O(sqrt(n)), to find prime factorisation of n
vector<int> prime_factors;
for(int i=2; i*i <= n; i++)
{
    if(i%2 == 0)
    {
        while(n%i == 0)
        {
            n = n/i;
            prime_factors.push_back(i);
        }
    }
}
if(n != 1)                        // executed if after above operations n has become a prime number (greater than 1)
{ 
    prime_factors.push_back(i);   
}



better approach -> we can use seive to do this work in roughly O(nlog(n)) for finding prime factorisation of first n natural numbers.

in this approach we will find the lowest prime factor of each number, and than when required to tell prime factorisation of a number
we will print the lowest/smallest prime factor of that number and divide that number by that factor, now we will print the lowest
prime factor of the new number and than divide it also, we will keep doing this till the number becomes 1

*/


// actually this class is not required, as we can also work with a normal int array, by doing if(arr[i] == i), to check that number is prime or not.
class number
{
    public :
    int num;
    bool is_prime;
    number()
    {
        is_prime = true;
    }
};


int main ()
{
    int t;
    cin>>t;
    
    number *arr = new number[1000000+1];
    for(int i=0; i<=1000000; i++)
    {
        arr[i].num = i;
    }

    for(int i=2; i*i <= 1000000; i++)
    {
        for(int j=i; j<=1000000; j+= i)
        {
            if(arr[j].is_prime == false)
            {
                continue;
            }
            else
            {
                arr[j].is_prime = false;
                arr[j].num = i;               // smallest prime_factor
            }
            
        }
    }


    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        if(n == 1)
        {
            cout<<1<<endl;
            continue;
        }

        while(n != 1)
        {
            cout<<arr[n].num<<" ";
            n = n/arr[n].num;
        }
        cout<<endl;
    }

    return 0;
}