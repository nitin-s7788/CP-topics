/*
In some questions related to queries/ ranged queries, our work becomes simplified if the first take all the queries and than sort them, and than 
process each query.  This techinique is called offline queries.


Question :

given an array of size n, and q queries.
a query(l, r, k) means tell the count of elements in range l to r (both inclusive), whose values are greater than K.

constraints :
1 <= n <= 10^5
1 <= q <= 10^5
1 <= arr[i], K <= 10^6


Approch : we can do this easily in O(n*q) using brute force, but we will use BIT with offline queries to do it in O(nlog(n) + qlog(q)).

we can get ans of : count of numbers between l to r easily (by maintaining a BIT [ BIT(i) = no. of elements in array till index i]),   
the only problem is we have to take sum of only the elements greater than K.
To do this we will sort the queries in decreasing order w.r.t. the value of K, and before performing a query with value K, we will only insert 
the values greater than K, into the BIT, this will insure that our answer will contain only the sum of elements greater than K.


*/



#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Query
{
    public :
    int index;
    int l;
    int r;
    int k;
};

bool compare(Query a, Query b)
{
    if(a.k >= b.k)
        return true;
    return false;
}

void updateBIT(vector<int> &BIT, int size, int index)  // no need of value as value is always +1 to increase element count
{
    for(int i=index; i<= size; i += (i&(-i)) )
    {
        BIT[i] += 1;
    }
}

int getAns(vector<int> &BIT, int index)
{
    int ans = 0;
    for(int i=index; i>0; i -= (index & (-index)) )
    {
        ans += BIT[i];
    }

    return ans;
}

class Pair
{
    public :
    int index;
    int val;
};

bool compare2(Pair a, Pair b)
{
    if(a.val >= b.val)
    {
        return true;
    }
    return false;
}

int main ()
{
    int n;
    cout<<"Enter the no. of elements in the array : ";
    cin>>n;

    vector<Pair> v(n);
    vector<int> BIT(n+1, 0);

    cout<<"Enter the elements : ";

    for(int i=0; i<n; i++)
    {
        cin>>v[i].val;
        v[i].index = i;
    }

    int q;
    cout<<"Enter the no. of queries : ";
    cin>>q;

    cout<<"Enter the queries (l, r, k) : "<<endl;
    vector<Query> queries(q);
    for(int i=0; i<q; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        Query temp;
        temp.index = i;
        temp.l = a;
        temp.r = b;
        temp.k = c;

        queries[i] = temp;
    }

    sort(queries.begin(), queries.end(), compare);

    sort(v.begin(), v.end(), compare2);

    vector<int> ans(n,0);

    int j = 0;

    for(int i=0; i<q; i++)
    {
        int cur_K = queries[i].k;

        for( ; j < n && v[j].val > cur_K  ; j++)
        {
            updateBIT(BIT, n, v[j].index+1);
        }

        ans[queries[i].index] = getAns(BIT, queries[i].r) - getAns(BIT, queries[i].l - 1);

    }

    cout<<"The answer of queries are : ";
    for(int i=0; i<q; i++)
        cout<<ans[i]<<" ";

    cout<<endl;




    return 0;
}