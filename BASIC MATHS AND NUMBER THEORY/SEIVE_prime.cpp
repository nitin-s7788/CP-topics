/*
question
t number of test cases
in each test case input a number n and print first n prime numbers

t <= 100
n <= 10^6

*/

#include<iostream>
#include<vector>

using namespace std;

int main ()
{
    int t;
    cout<<"Enter the no. of test cases : ";
    cin>>t;

    //time complexity = O(nloglogn)  almost O(n) with a big constant
    //this method will work only if we want to generate prime numbers till 10^8 at max  

    vector<bool> numbers(10000000, true);  // in this vector each index represent it is prime or not. (ignore index 0 & 1)

    for(int i=2; i*i <= 10000000; i++)
    {
        if(numbers[i] == false)
        {
            continue;
        }
        else
        {
            for(int j= i*i; j<= 10000000; j += i)
            {
                numbers[j] = false;
            }
        }
        
    }

    vector<int> primes;
    for(int i=2; i<=10000000; i++)
    {
        if(numbers[i] == true)
        {
            primes.push_back(i);
        }
    }



    for(int i=0; i<t; i++)
    {
        int n;
        cout<<"Enter n (we will print first n prime numbers : ";
        cin>>n;
        for(int j=0; j<n; j++)
        {
            cout<<primes[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}