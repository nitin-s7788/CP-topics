/*

Question : Given 2 strings find the length of there longest common sub sequence (not sub string).
for eg :  abacad,  bcaad => ans = 4 (bcad or baad).

Constraints : 
Length of both strings  <= 10^3

Approach :
BruteForce_1 : make all possible sub strings of string1 (from length n to 1), and than search them in string2. Time Complexity : O(n! . n) [worst]

BruteForce_2 : we use the logic if Str1[i] == Str2[j] than, ans = 1 + getAns(Str1[i+1], Str2[j+1]),
.                           and if Str1[i] != Str2[j] than, ans = max( getAns(Str1[i+1], Str2[j]), getAns(Str1[i], Str2[j+1]) )
.                                                                 (i.e. we can either remove Str1[i] from Str1 and find remaining or we can do same with Str2)


DP : clear There will be many repeating problems in BruteForce_2, we will use this for our DP.
At any point we can represent our ans using index of Str1 used (i) and Str2 used (j). 

recrence relation : Ans[i][j] = 1 + Ans[i+1][j+1] , if Str1[i] == Str2[j]
.                             = max( Ans[i+1][j],  Ans[i][j+1] ) , if Str1[i] != Str2[j]

clearly if i == n1 or j == n2 (no character left), than ans = 0 [sides of the square DP array]

*/

#include<bits/stdc++.h>

using namespace std;

int main ()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    string s1, s2;
    cout<<"Enter the first String : ";
    cin>>s1;
    cout<<"Enter the second String : ";
    cin>>s2;

    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> ans(n1+1, vector<int> (n2+1, -1));

    for(int i=0; i<=n1; i++)              // make end column zero
        ans[i][n2] = 0;

    for(int i=0; i<=n2; i++)              // make end row zero
        ans[n1][i] = 0;

    
    // we will start filling the DP/ans array from the bottom right corner,  we will fill each row from last (and filling each row, each column from end)

    for(int i=n1-1; i>=0; i--) // row / String1
    {
        for(int j=n2-1; j>=0; j--)  // columns / string2
        {
            if(s1[i] == s2[j])
            {
                ans[i][j] = 1 + ans[i+1][j+1];
            }
            else
            {
                ans[i][j] = max( ans[i+1][j], ans[i][j+1] );
            }
            
        }
    }

    cout<<"Length of longest common sub sequence : "<<ans[0][0]<<endl;


    // Space complexity improvement, note that at anytime, here we need answers of only, current row, and row behind it. 
    // We can use this to reduce our space complexity.

     
    return 0;
}