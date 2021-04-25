/*
Fenwick tree or BIT (binary indexed tree) is generally used for ranged queries. It is alternative of segment tree which is complex and hard to impliment.

To implement a BIT, we have to construct a array of size n+1 (not a actual tree), initize all elements of array to 0 (or zero equivalent object 
in case of some class). The index 0 element always remains zero and act as a dummy node/element of tree.

To impliment BIT we have to make only 2 functions update (insert is also a type of update) and getans (return ans of some index).



Question :
Given an array of integers and Q queries, there are 2 types of queries :
type 1 : get sum of element in range(l, r) (both inclusive).
type 2 : modify a element of the array.




In normal case we can get array sum in O(1) and modify array in O(n) [as need update the whole array_sum array whenever element is updated].

Using BIT, we will perform both operations in O(logn) time.

.                                                   BIT  Representation of tree of size 15
.                                                                   0                                 lvl 0   (zero, 1s in binary rep)
.                                                         /       /  \       \                        
.                                                        1       2    4       8                       lvl 1   (one 1s, in binary rep)
.                                                               /    / \     / \   \
.                                                              3    5   6   9   10  12                lvl 2   (two 1s, in binary rep)                               
.                                                                      /       /    / \
.                                                                     7       11   13  14             lvl 3
.                                                                                      /
.                                                                                     15              lvl 4

Here each node contain the sum of numbers from index (parent, itself] (indexing start from 1). for eg. node 14 contain sum of elements no. 13 and 14.

When we will do getAns(n) -> we will get sum of first n elements, to do this we will make a variable ans in getAns(), add to it element no. n, 
and than update the value of n to n's parent and do this till n == 0.  [this will take log(n) time].
for eg. getAns(14) : 14 -> 12 -> 8 -> 0

let size of array/BIT is 'size'.
When we will do update(n, val) -> first we will in increase value of arr[n] by val, than we will update n (n will increase) to all those nodes,
whose value also need to be increased, we will do this will n <= size.
for eg. update(3) : 3 -> 4 -> 8,  update(6) : 6 -> 8 ,  update(11) : 11 -> 12,  update(13) : 13 -> 14

for updating the value of n in getAns/ to reach parent of n, we just need to remove the right most 1 from Binary rep of n : 
To do this do : n = n - (n & (-n))

for updating the value of n in update(), do  :  n = n + (n & (-n))
 
*/



#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void update(vector<int> &BIT, int size, int index, int val)
{
    if(index > size)
    {
        return ;
    }

    BIT[index] += val;
    index = index + (index & (-index));
    cout<<index<<endl;
    update(BIT, size, index, val);

    /*
        we could have also used this loop instead of recursion

        for(int i=index; i<=size; i += (i & (-i)) )
        {
            BIT[i] += val;
        }
        
        // remember here indexing starts from 1, else we would first have to do index++ before starting above loop.
    */
}


int getAns(vector<int> &BIT, int index)
{
    if(index == 0)
    {
        return 0;
    }

    return ( BIT[index] + getAns(BIT, index - (index & (-index))) );

    /*
        we could have also used this loop instead of recursion

        long long sum = 0;
        for(int i=index; i>=0; i -= (i & (-i)) )
        {
            sum += BIT[i];
        }

        return sum;
        
        // remember here indexing starts from 1, else we would first have to do index++ before starting above loop.
    */
}

int main ()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"Enter array elements : ";
    
    vector<int> v(n);
    vector<int> BIT(n+1, 0);

    for(int i=0; i<n; i++)
    {
        cin>>v[i];

        update(BIT, n, i+1, v[i]);
    }
    
    int q;
    cout<<"Enter the no. of queries : ";
    cin>>q;
    
    for(int i=0; i<q; i++)
    {
        cout<<"Enter the type of query getSum(1, l, r) or update(2, index, val) : ";

        int queryType;
        cin>>queryType;

        if(queryType == 1)
        {
            int l, r;
            cin>>l>>r;

            cout<<getAns(BIT, r) - getAns(BIT, l-1)<<endl;
        }
        else
        {
            int index, value;
            cin>>index>>value;

            int val_to_increase = value - v[index-1];          // in v, index start from 0.
            v[index-1] =  value;
            update(BIT, n, index, val_to_increase);
        }
    }
    return 0;
}