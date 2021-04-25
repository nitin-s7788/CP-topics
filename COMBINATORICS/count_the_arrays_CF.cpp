#include<iostream>

/*
question -> code forces
Your task is to calculate the number of arrays such that:

> each array contains n elements;
> each element is an integer from 1 to m;
> for each array, there is exactly one pair of equal elements;
> for each array a, there exists an index i such that the array is strictly ascending before the i-th element and strictly
  descending after it (formally, it means that aj<aj+1, if j<i, and aj>aj+1, if j≥i).

Input ->
The first line contains two integers n and m (2≤n≤m≤2*10^5).

Output ->
Print one integer — the number of arrays that meet all of the aforementioned conditions, taken modulo 998244353.

For example -> 3,4 -> 6    -> [1,2,1], [1,3,1], [1,4,1], [2,3,2], [2,4,2], [3,4,3].


ANSWER ->  mC(n-1) * (n-2) * 2^(n-3)

approach ->
> STEP 1 -> clearly, we are given m numbers (from 1 to m) and we require n-1 distinct numbers out of these (as 1 number will be
 repeated) so, no. of ways of selecting n-1 numbers out of m numbers = mC(n-1).
> now, the greatest number out of all these n-1 numbers, will be the number at i th position, i.e. between increasing and decreasing
  sequence, this number cannot be repeated (as than sequences will not be strictly increasing/decreasing)
> STEP 2 -> now, we will select a number out of the remaining n-2 numbers, which will be repeated -> we can do this in (n-2) ways.

> now, if the index/position of numbers start from 1 to n. than ->
> the index of the greatest number will varry from 2 to n-1,
> for index = 2, -> after doing STEP 1&2 -> 1 number at index i=2 is done -> 1 number at each of i=2 is done (the repeated number),
. now we just need to select zero numbers out of remaining n-3 numbers which will come to left side of i=2. -> (n-3)C(0) ways.
> for index = 3, -> after doing STEP 1&2 -> 1 number at index i=3 is done -> 1 number at each of i=3 is done (the repeated number),
. now we just need to select 1 numbers out of remaining n-3 numbers which will come to left side of i=3. -> (n-3)C(1) ways.
> for index = 4, -> after doing STEP 1&2 -> 1 number at index i=4 is done -> 1 number at each of i=4 is done (the repeated number),
. now we just need to select 2 numbers out of remaining n-3 numbers which will come to left side of i=4. -> (n-3)C(2) ways.


so, total ways = mC(n-1) * (n-2) * [ (n-3)C0 + (n-3)C1 + (n-3)C2 + ......  (n-3)C(n-3)]
.                mC(n-1) * (n-2) * 2^(n-3)

*/
using namespace std;

// finding (a^n)%m
long long modulo_inverse(long long a, long long n, long long m)
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return a;
    }
    long long temp = modulo_inverse(a,n/2,m) % m;
    if(n%2 == 0)
    {
        temp = (temp*temp)%m;
        return temp;
    }
    else
    {
        temp = (temp*temp)%m;
        temp = (temp*a)%m;
        return temp;
    }
}

long long factorial(long long n, long long M)
{
    long long ans = 1;
    for(int i=2; i <= n; i++)
    {
        ans = (ans*i) % M;
    }
    return ans;
}

long long combinations(long long n, long long r, long long M)
{
    // To be done
    long long a,b,c, M1, M2, ans;
    a = factorial(n, M);
    b = factorial(r, M);
    c = factorial(n-r, M);
    M1 = modulo_inverse(b, M-2, M);
    M2 = modulo_inverse(c, M-2, M);

    ans = ((a%M) * (M1%M)) % M;
    ans = ((ans%M) * (M2%M)) % M;
    return ans;

}

int main ()
{
    int n,m;
    cin>>n>>m;
    int N = 998244353;
    long long ans = combinations(m,n-1,N) % N;
    ans = (ans * (n-2)) % N;
    ans = (ans * modulo_inverse(2,n-3, N)) % N;     //modulo_inverse function is actually power function.
    cout<<ans<<endl;
    return 0;
}