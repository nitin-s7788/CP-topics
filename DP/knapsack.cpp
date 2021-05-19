/*

Question : A thief is robbing a store and can carry a maximal weight of W into his knapsack (bag). There are N items and ith item weighs wi 
and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value 
that thief can generate by stealing items.

Constraints :
    1 <= N <= 10^4
    1<= wi <= 100
    1 <= vi <= 100

Approach :

BruteForce : We can either pick a item (if space in bag) or leave it, using this we can solve above question in O(2^n).

DP Wrong approach : One may think, we can Find Ans[Knapsack_weight] if we have Ans[1], Ans[2], Ans[3], ... Ans[Knapsack_weight-1], but this is 
wrong as, using this we can't determine weather we can pick a item or not.

   or we can say that :
   Ans[wight_left, N items] = max( getAns[weight_left, next N-1 items], v[i] + getAns[weight_left - wi], next N-1 items )
   This recrence relation is wrong.


DP Right approach : Here, we can't define the current state of the problem, with only one variable (weight left in knapsack), but actually, 
we need to consider 2 varibles i.e., Weight left, items left.

    Ans[weight_left][No_of_items] = max(Ans[weight_left][No_of_items-1], v[i] + Ans[weight_left - wi][No_of_items-1])


*/


#include<bits/stdc++.h>

using namespace std;

int main ()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cout<<"Enter the no. of items : ";
    cin>>n;

    int W;
    vector<int> weights(n);
    vector<int> values(n);

    cout<<"Enter the weights of items : ";
    for(int i=0; i<n; i++)
        cin>>weights[i];

    cout<<"Enter the values of items : ";
    for(int i=0; i<n; i++)
        cin>>values[i];

    cout<<"Enter the capacity of knapsack (bag) : ";
    cin>>W;

    // vector<vector<int>> Ans(n+1, vector<int> (W+1, -1));

    // for(int i=0; i<=W; i++)
    //     Ans[0][i] = 0;

    // for(int i=0; i<=n; i++)
    //     Ans[i][0] = 0;

    
    // for(int i=1; i<=n; i++)
    // {
    //     for(int j=1; j<=W; j++)
    //     {
    //         if(j >= weights[i-1])
    //             Ans[i][j] = max( Ans[i-1][j], values[i-1] + Ans[i-1][j-weights[i-1]] );
    //         else
    //             Ans[i][j] = Ans[i-1][j];
    //     }
    // }

    // cout<<"Maximum value to steal : "<<Ans[n][W]<<endl;
    
    // Improvement : clearly at any time, we need values row current row and the row above it, so actually we dont need n x W array, but 2 x W array.

    vector<vector<int>> Ans(2, vector<int> (W+1, -1));

    for(int i=0; i<=W; i++)
        Ans[0][i] = 0;

    for(int i=0; i<2; i++)
        Ans[i][0] = 0;

    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=W; j++)
        {
            if(i%2 == 1)     // In this case the first row contains the values of required previous row
            {
                if(j >= weights[i-1])
                    Ans[1][j] = max( Ans[0][j], values[i-1] + Ans[0][j-weights[i-1]] );
                else
                    Ans[1][j] = Ans[0][j];
            }
            else             // In this case the second row contains the values of required previous row
            {
                if(j >= weights[i-1])
                    Ans[0][j] = max( Ans[1][j], values[i-1] + Ans[1][j-weights[i-1]] );
                else
                    Ans[0][j] = Ans[1][j];
            }
            
        }
    }

    cout<<"Maximum value of Steal : "<<Ans[n%2][W]<<endl;
 
    return 0;
}