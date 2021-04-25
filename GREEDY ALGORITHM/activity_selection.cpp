/*
question ->
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a
single person, assuming that a person can only work on a single activity at a time.

sample test case ->
start[]  =  {10, 12, 20};
finish[] =  {20, 25, 30};

output -> 2 


start[]  =  {1, 3, 0, 5, 8, 5};
finish[] =  {2, 4, 6, 7, 9, 9};
output -> 4
*/

/*
approach ->
we make pair class (start + finish) array, and than sort it according to finishing time. if the start time of a activity is greater
than or equal to the finishing time of previously done activity than we will do that activity.
*/


#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Pair
{
    public :
    int start;
    int finish;
};

bool compare(Pair p1, Pair p2)
{
    if(p1.finish <= p2.finish)
        return true;
    return false;
}

int main ()
{
    int t;
    cin>>t;
    for(int test = 0; test<t; test++)
    {
        int n;
        cin>>n;
        vector<Pair> v(n);
        for(int i=0; i<n; i++)
        {
            cin>>v[i].start;
        }
        for(int i=0; i<n; i++)
        {
            cin>>v[i].finish;
        }

        sort(v.begin(), v.end(), compare);

        int ans = 0, prev_end = 0;
        for(int i=0; i<n; i++)
        {
            if(v[i].start >= prev_end)
            {
                ans++;
                prev_end = v[i].finish;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}