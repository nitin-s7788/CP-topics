/*
question ->
There are N Mice and N holes are placed in a straight line. Each hole can accommodate only 1 mouse. A mouse can stay at his position,
move one step right from x to x + 1, or move one step left from x to x -1. Any of these moves consumes 1 minute. Assign mice to holes
so that the time when the last mouse gets inside a hole is minimized (all mice start at same time).

sample test case ->

Input :  positions of mice are:
.          4 -4 2
.        positions of holes are:
.          4 0 5
Output :  4                            (mices go in 3rd, 2nd, 1st holes respectively)


Input :   positions of mice are:
.         -10, -79, -79, 67, 93, -85, -28, -94 
.          positions of holes are:
.         -2, 9, 69, 25, -31, 23, 50, 78 
Output : 102
*/

/*
approach -> we have to put every mouse to it's nearest hole (so that no 2 mice go in same hole), this can be achieved by sorting both
positions of mices and the positions of holes and than assign the ith hole (in sorted array) to the ith mouse (of sorted array)
*/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int t;
    cin>>t;
    for(int test=0; test<t; test++)
    {
        int n;
        cin>>n;
        vector<int> mice(n), holes(n);
        for(int i=0; i<n; i++)
            cin>>mice[i];
        for(int i=0; i<n; i++)
            cin>>holes[i];

        sort(mice.begin(), mice.end());
        sort(holes.begin(), holes.end());

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(mice[i] > holes[i] && mice[i] - holes[i] > ans)
            {
                ans = mice[i] - holes[i];
            }
            if(holes[i] > mice[i] && holes[i] - mice[i] > ans )
            {
                ans = holes[i] - mice[i];
            }
        }

        cout<<ans<<endl;

    }
    return 0;
}

