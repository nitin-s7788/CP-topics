#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main ()
{
    int n, s;
    cout<<"Enter the number of books : ";
    cin>>n;
    cout<<"Enter the number of students : ";
    cin>>s;

    vector<int> v(n,0);
    int sum = 0, max = 0;

    cout<<"Enter the number of pages in the books : ";
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        sum += v[i];
        if(v[i] > max)
            max = v[i];
    }

    int ans = -1;
    int start = 0, end = sum;
    int mid;

    while(start <= end)
    {
        
        mid = (start + end)/2;
        int count = 1, temp_sum = 0;
        if(mid < max)
        {
            start = mid+1;
            continue;
        }

        for(int i=0; i<n; i++)
        {
            if(temp_sum + v[i] <= mid)
            {
                temp_sum += v[i];
            }
            else
            {
                temp_sum = v[i];
                count++;
            }
        }
        
        
        if(start == end)
        {
            ans = mid;
            break;
        }
        if(count > s)
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }

        
    } 

    cout<<"maximum pages for a student : "<<mid<<endl;
    
    return 0;
}