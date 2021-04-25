#include<iostream>
#include<vector>

using namespace std;

int main ()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, temp = 0;
        cin>>n;
        vector<int> v(n,0), c_sum(n,0);
        for(int j=0; j<n; j++)
            cin>>v[j];
        c_sum[0] = v[0]%n;

        for(int j=0; j<n; j++)
        {
            if(v[j]%n == 0)
            {
                cout<<1<<endl;
                cout<<j+1<<endl;
                temp = 1;
                break;
            }
        }

        if(temp == 1)
        {
            continue;
        }
        
        for(int j=1; j<n; j++)
        {
            c_sum[j] = (c_sum[j-1] + v[j])%n;
            if(c_sum[j] == 0)
            {
                cout<<j+1<<endl;
                for(int k=0; k<=j; k++)
                {
                    cout<<k+1<<" ";
                }
             //   cout<<"hello";
                cout<<endl;
                temp = 1;
                break;
            }
        }
        if(temp == 1)
        {
            continue;
        }

        vector<int> reminder_count(n,0);
        int repeat = 0, repeat_count = 0, end_index = 0;
        for(int j=0; j<n; j++)
        {
            reminder_count[c_sum[j]]++;
            if(reminder_count[c_sum[j]] == 2)
            {
                repeat = c_sum[j];
                end_index = j;
                break;
            }
        }
        
        for(int j=0; j<n; j++)
        {
            if(c_sum[j] == repeat)
            {
                repeat_count++;
                if(repeat_count == 1)
                {
                    cout<<end_index-j<<endl;
                    continue;
                }
            }
            if(repeat_count >= 1)
            {
                cout<<j+1<<" ";
                if(repeat_count == 2)
                {
                    cout<<endl;
                  //  cout<<"hi"<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}