#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Path
{
    public :
    long long position;
    bool b;              // true = lose people, else gain people
    long long lose;
    long long gain;
    long long required;

};

bool compare(Path p1, Path p2)
{
    if(p1.position < p2.position)
        return true;
    return false;
}

int main ()
{
    int t;
    cin>>t;
    for(int test = 0; test < t; test++)
    {
        int X, B, C;
        cin>>X;
        cin>>B;
        long long xi, yi;
        vector<Path> v;

        long long start = 1, end = 1;
        for(int i=0; i<B; i++)
        {
            cin>>xi>>yi;
            end += yi;
            Path p;
            p.position = xi;
            p.b = true;
            p.lose = yi;
            v.push_back(p);

        }
        
        cin>>C;
        long long pi, qi, ri;
        for(int i=0; i<C; i++)
        {
            cin>>pi>>qi>>ri;
            Path p;
            p.b = false;
            p.position = pi;
            p.gain = ri;
            p.required = qi;
            v.push_back(p);
        }

        sort(v.begin(), v.end(), compare);

        long long ans;

        while(start <= end)
        {
            long long mid = (start+end)/2;
            long long remaining_people = mid;

            bool temp = true;
            for(int i=0; i<v.size(); i++)
            {
                if(v[i].b == true)
                {
                    remaining_people -= v[i].lose;
                    if(remaining_people <= 0)
                    {
                        temp = false;
                        break;
                    }
                }
                if(v[i].b == false && v[i].required <= remaining_people)
                {
                    remaining_people += v[i].gain;
                }
            }

            if(temp == true)
            {
                end = mid-1;
                ans = mid;
            }
            else
            {
                start = mid+1;
            }
            

        }

        cout<<ans<<endl;

    }
    return 0;
}