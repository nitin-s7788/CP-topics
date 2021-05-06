/*

Question : Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.


Constraints :  1 <= n <= 10000


Wrong Approach : The first approach which will come to anyones mind is, keep on subtracting the biggest square number from n, untill n becomes 0.
for eg. : 28 => 28 -> 19 -> 10 -> 1 -> 0 (ans = 4).

But this approch will not be always correct, for eg :
67 : by above approach => 64 + 1 + 1 + 1  (4)
67 : real ans          => 49 + 9 + 9      (3)



Now we can do it easily by using Bruteforce in exponential time.


DP solution :
clear,  ans[num] = min( ans[num - A1], ans[num - A2], ans[num - A3] ... , ans[num - Ak])+1  [where A1, A2 ... Ak are perfect squares less than num]

So, we can find ans for a number, num if we know answer of all numbers less than num.


*/


#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    vector<int> arr(n+1, -1);
    arr[0] = 0;

    for(int i=1; i<=n; i++)
    {
        int sub_ans = INT_MAX;

        for(int j = 1; j*j <= i; j++)     // generating all squares smaller than / equal to i.
        {
            int temp = arr[ i - j*j ];
            if(temp < sub_ans)
            {
                sub_ans = temp;
            }
        }

        arr[i] = sub_ans + 1;
    }

    cout<<arr[n]<<endl;
    return 0;
}