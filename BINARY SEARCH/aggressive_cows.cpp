#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int t;
    cin>>t;
    for(int test = 0; test < t; test++)
    {
        int n,c;
        cin>>n>>c;
        vector<int> v(n,0), v2;
        for(int i=0; i<n; i++)
            cin>>v[i];

        sort(v.begin(), v.end());

        v2.push_back(v[0]);

        
        int start = 0;
        int end = v[n-1] - v[0];
        int mid = (start+end)/2;

        int ans;

        while(start <= end)
        {
            int count = 1;
            int temp_distance = 0;
            mid = (start + end)/2;
            for(int i=1; i<n; i++)
            {
                if(temp_distance + v[i] - v[i-1] < mid)
                {
                    temp_distance += v[i] - v[i-1];
                    continue;
                }
                else
                {
                    count++;
                    v2.push_back(v[i]);
                    temp_distance = 0;
                }
            }

         //   cout<<start<<" "<<end<<" "<<mid<<endl;

            if(count < c)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
                ans = mid;
            }

        }

        cout<<ans<<endl;
        /*
        for(int i=0; i<v2.size(); i++)
        {
            cout<<v2[i]<<" ";
        }
        cout<<endl;
        */
    }
    return 0;
}