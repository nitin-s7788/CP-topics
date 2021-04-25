/*

We, not only use use Fenwick tree/ BIT for ranged queries, but we also use it as normal trees, for normal queries (non-ranged queries).


Question :

given an array of size n, for all i (1 <= i <= n), find the sum of elements which are to the left of arr[i] and whose value is greater than arr[i].

constraints :

1 <= n <= 10^5
1 <= arr[i] <= 10^6



Approach :

We can easily do this in O(n^2) using bruteforce, but we will use BIT to do this in O(nlogn)

We will maintain a BIT, where BIT[num], will give the sum of elements smaller than or equal to num (we can't mentain sum of elements greater than num) in the BIT. (Note that here the size of BIT is same as
the size of MAX(arr[i]) and not n).  To ensure than we take elements only to the left in sum, we will keep on computing the answer of index i,
just before inserting arr[i].  To get ans, we will do : ans[i] = sum till index (i-1) - BIT(i).

*/


#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void updateBIT(vector<int> &BIT, int size, int index, int val)
{
    for(int i=index; i<=size; i += (i & (-i)) )
    {
        BIT[i] += val;
    }
}

long long getAns(vector<int> &BIT, int index)
{
    long long ans =0;
    for(int i=index; i>0; i -= (i&(-i)) )
    {
        ans += BIT[i];
    }

    return ans;
}

int main ()
{
    int n;
    cout<<"Enter no of elements in array : ";
    cin>>n;

    cout<<"Enter the array elements : ";
    vector<int> v(n);
    vector<int> BIT(1000001, 0);              // (not n)

    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<"The answer array is : ";
    cout<<0<<" ";
    
    long long sum = v[0];
    updateBIT(BIT, n, v[0], v[0]);   // index is not 1, as BIT(index), means sum of elements with values less than index (not arr[index]).

    for(int i=1; i<n; i++)
    {
        long long ans = sum - getAns(BIT, v[i]);
        cout<<ans<<" ";
        sum += v[i];
        updateBIT(BIT, n, v[i], v[i]);     // indexing of BIT start from 1
    }
    cout<<endl;
    return 0;
}


