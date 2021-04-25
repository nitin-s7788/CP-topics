#include<iostream>

using namespace std;

/* 
this (catalan series) is a very very important series, first few catalan numbers for n = 0,1,2,3,4,... are
1, 1, 2, 5, 14, 42, 132, 429, 1430.....

formula ->
catalan numbers satisfy the given recursive relation/formula ->

F(n+1) = sum( F(i)*F(n-i) ) for i=0 to i=n,     F(0) =1     ,F(n) = nth catalan number,   F(i) = ith catalan number.
for eg. for n = 3
F(4) = F(0).F(3) + F(1).F(2) + F(2).F(1) + F(3).F(0)

general formula for nth catalan number is ->
F(n) = (2n_C_n)/n+1  =  (2n!)/ ((n+1)!*(n)!)      , where  n_C_r  = n!/(n-r)!(r)!

better use DP/recursive solution, to find catalan numbers, than using the general formula, as both will take O(n) time,
but for bigger values of (2n)! and other factorial terms will easily go out of range of long long int.
*/


/*
catalan numbers/series is the answer of many interesting counting problems like ->

question 1 ->
count the number of possible binary search trees with n keys.   (i.e. n nodes)
for n = 1, ans = 1          for n=2,  ans = 2                         for n=3,  ans = 5
.      O                        1        0                            2      2        1        0        0     
.                              /          \                          /      /        / \        \        \
.                             0            1                        1      0        0   2        2        1
.                                                                  /        \                   /          \
.                                                                 0          1                 1            2

way of thinking,    total ways = n(left_sub_tree has 0 nodes) * n(right_sub_tree has n-1 nodes)  +  n(LST 1 node) * n(RST n-2 nodes) + ...... + n(LST has n-1 nodes) * n(RST has 0 nodes)


question 2 ->
count number of rooted full binary trees with n+1 "LEAVEs"/"LEAFs". (full binary tree = each root have 2 child or no child) 
for n = 0, ans = 1     for n=1,  ans = 1     for n=2,  ans = 2                                 for n=3,    ans = 5
.      O                   O                   O            O                 O          O             O           O          O     
.                         / \                 / \          / \               / \        / \           / \         / \        / \
.                        O   O               O   O        O   O             O   O      O   O         O   O       O   O      O   O
.                                               / \      / \               / \        / \           / \ / \         / \        / \
.                                              O   O    O   O             O   O      O   O         O  O O  O       O   O      O   O
.                                                                        / \            / \                       / \            / \
.                                                                       O   O          O   O                     O   O          O   O


way of thinking,     total ways = n(left_sub_tree has 1 leaf) * n(right_sub_tree has n leafs) + n(LST 2 leaf) * n(RST n-1 leaf) + ........ + n(LST has n leaf) * n(RST has 1 leaf)      [no node can have some leafs on one side and 0 leafs on another side, as than it wont be complete binary tree]


question 3 ->
count number of expressions containing n pairs of parentheses which are correctly matched.
for n = 1, ans = 1          for n=2, ans = 2                         for n=3, ans = 5
.       ()                      ()(),  (())                ()()(), ()(()), (())(), (()()), ((()))  



question 4 ->
given 2n lines (n '/' and n '\') draw mountain ranges using these, such that you can't go below horizon.
for n = 1, ans = 1           for n=2, ans = 2                         for n=3, ans = 5
.      /\                       /\/\  ,  /\                     /\/\/\   /\          /\     /\/\       /\
.                                       /  \                            /  \/\    /\/  \   /    \     /  \
.                                                                                                    /    \


question 5 ->
given n, return no. of ways you can draw n chodes in a circle with 2*n points, such that no 2 chordes intersect.


there are many more such questions
*/

/* 
question done ->
given n,  find first n catalan numbers.  if num is very big find it modulo 1000000007
*/

long long int catalan_number(int n, long long int *arr)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        if(arr[n] != -1)
        {
            return arr[n];
        }

        long long int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans = ans + ( ( catalan_number(i, arr) % 1000000007) * ( catalan_number(n-1-i, arr)%1000000007)) % 1000000007;
        }
        arr[n] = ans;
        return ans;
    }
    
}
int main ()
{
    int n;
    cin>>n;
    long long int *arr = new long long int[n+1];      // to impliment DP
    for(int i=0; i<=n; i++)
    {
        arr[i] = -1;
    }

    for(int i=1; i<=n; i++)
    {
        long long int ans = catalan_number(i, arr);
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}