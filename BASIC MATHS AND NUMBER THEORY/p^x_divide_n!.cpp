#include<iostream>

/*
question ->
t test cases
input p, n   (where p is a prime number)
find the maximum value of x, such that p^x divides n!.

native approach -> find n! and max p^x , O(n) ->due to finding n!, also long long int may not be able to store n! in c++ for big n.

better approach -> Legendre's formula/method -> no need to finf n!  O(log(n))
no. of integers divisible by p in 1.2.3.4......n   = n/p
no. of integers divisible by p^2 in 1.2.3.4.....n   = n/p^2
no. of integers divisible ny p^3 in 1.2.3.4.....n   = n/p^3  and so on

our answer = sum of these numbers = n/p + n/p^2 + n/p^3 + ....  (till n/p^n >= 1)

sample input
3
5 5
3 10
3 7

sample output
1
4
2
*/

using namespace std;

int main ()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int p,n;       // p must be prime
        cin>>p>>n;

        int ans = 0, p_x = p;
        while (n/p_x > 0)
        {
            ans += n/p_x;
            p_x *= p;
        }

        cout<<ans<<endl;
    }
    return 0;
}