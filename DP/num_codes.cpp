/*

Question : You are given a big number (in form of string), a number can be converted into multiple codes.
Rule for converting number into code : replace 1 by A, 2 by B, 3 by C .... 26 by Z.

for eg.  1146 can be converted into  AADF, KDF, ANF.
         2314 can be converted into BCAD, WAD, BCN, WN

The given number will not contain the digit 0.

You have to tell the total no. of codes into which a given number can be changed.

Constraints :
1 <= len(N) <= 10^5  (assume given number not contain digit 0, this will not create any problem is we assign a character to 0 also).

BruteForce approach : start from index 0, at each point convert either Number[i] into alphabet or Number[i]*10 Number[i+1] (if it is <= 26).
i.e. Recrence Relation = Ans[i] = Ans[i+1] + Ans[i+2] (if Number[i]*10 + Number[i+1] <= 26).  

DP : clearly here we have overlapping problems, so will use DP to store Sub answers.
Clearly to find the answer of any state, we only require the answer of next 2 states. and Ans[n-1]/ Ans[n] = 1.

*/

#include<bits/stdc++.h>

using namespace std;

int main ()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cout<<"Enter no. of test cases : ";
    int t;
    cin>>t;
    for(int test=0; test<t; test++)
    {
        cout<<"Enter the Number(string) : ";
        string s;
        cin>>s;

        int n = s.size();

        vector<int> ans(n+1, -1);
        ans[n-1] = 1;                // only 1 digit
        ans[n] = 1;                  // zero digits

        for(int i=n-2; i>=0; i--)
        {
            int num = (s[i]-'0')*10 + (s[i]-'0');

            if(num <= 26)
            {
                ans[i] = ans[i+1] + ans[i+2];
            }
            else
            {
                ans[i] = ans[i+1];
            }
        }

        cout<<"Total number of codes = "<<ans[0]<<endl;

        /* space optimization : as we need only next 2 sub answers so, we can have a array of size 2 instead of n.

        vector<int> ans(2, 1);    // currently Ans[0] means actual Ans[n-1], and Ans[1] means actual Ans[n]

        int current_ans;
        for(int i=n-2; i>=0; i--)
        {
            int num = (s[i]-'0')*10 + (s[i]-'0');

            if(num <= 26)
            {
                current_ans = ans[0] + ans[1];
            }
            else
            {
                current_ans = ans[0];
            }

            ans[1] = ans[0];
            ans[0] = current_ans;
        }

        cout<<"Total number of codes = "<<ans[0]<<endl;  // or current_ans        

        */

        
    }
    return 0;
}