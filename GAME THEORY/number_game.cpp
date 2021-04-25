/*
question ->
Ashishgup and FastestFinger play a game.

They start with a number n and play in turns. In each turn, a player can make any one of the following moves:

Divide n by any of its odd divisors greater than 1.
Subtract 1 from n if n is greater than 1.
Divisors of a number include the number itself.

The player who is unable to make a move loses the game. (if a player gets 1 in front of him he lose).

Ashishgup moves first. Determine the winner of the game if both of them play optimally.

Input
The first line contains a single integer t (1≤t≤100)  — the number of test cases. The description of the test cases follows.

The only line of each test case contains a single integer  — n (1≤n≤109).

Output
For each test case, print "Ashishgup" if he wins, and "FastestFinger" otherwise (without quotes).

sample test cases ->

7
1          FastestFinger
2          Ashishgup
3          Ashishgup
4          FastestFinger
5          Ashishgup
6          FastestFinger
12         Ashishgup

*/

/*
solution logic ->

clearly, if the number is odd Ashishgup will always win, as he will divide the number by itself and FastestFinger will get 1. except
when n = 1 (exception).

if n is even then ->
if he send (n-1) to other player he will lose (as than other player will get odd number and he will divide it by itself, except when n=2)
so, Ash will try to find a odd divisor of the number to divide it.

if the even number as no odd divisor(i.e. number of the form 2^n than Ash lose and fastfinger win)
if the even number has a odd divisor than, we will simply divide the number by the biggest odd divisor and send a even number with 
no odd divisor (2^x) to fastfinger and ash will win (except when after dividing the number by the biggest odd number it becomes 2)

so, final stratigy ->
if n is odd except 1 or n==2 -> ash win
// now even case
if n is 1 or of the form 2^x except 2 -> fastfinger win
if n is of the form 4*odd or 4*odd*even / (4 or any bigger even number)*odd   ->ash win as we will send 4 or any bigger even number to fastfinger
if n is of the form 2*odd than ->if odd number is prime fastfinger win else ash win, 
because let odd = prime -> ash divide by prime -> fastfinger gets 2 -> fastfinger wins
.       let odd = odd1*prime -> ash divide by odd1 -> fastfinger divide by prime -> ash gets 2 -> ash wins


or
fastfinger wins if -> n==1, n=2^x (except 2), n=2*prime ->else ash wins

*/


#include<iostream>
#include<vector>

using namespace std;

int main ()
{
    int t;
    cin>>t;

    for(int test=0; test<t; test++)
    {
        int n;
        cin>>n;

        if(n==1)
        {
            cout<<"FastestFinger"<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<"Ashishgup"<<endl;
            continue;
        }
        int temp = n;
        while(n%2 == 0)
        {
            n = n/2;
        }

        if(n==1 )
        {
            cout<<"FastestFinger"<<endl;
            continue;
        }


        if(temp%2 == 0)
        {
            temp = temp/2;
            bool b = true;
            for(int i=2; i*i <= temp; i++)
            {
                if(temp%i == 0)
                {
                    b = false;
                    break;
                }
            }

            if(b == true)
            {
                cout<<"FastestFinger"<<endl;
                continue;
            }
        }
    
        cout<<"Ashishgup"<<endl;

    }

    return 0;
}