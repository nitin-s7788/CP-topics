#include<iostream>

using namespace std;

/*
**hcf(0,a) = a

finding hcf and lcm in log(n) time.
use -> hcf x lcm = m x n (for 2 numbers m and n) (only for 2 numbers)
to find hcf use -> euclid division lemma.
n = p*m + r
m = q*r + r1
q = s*r1 + 0

for eg. n=85, m=55
85 = 1*55 + 30
55 = 1*30 + 25
30 = 1*25 + 5
25 = 5*5 + 0
hcf = 5

keep on doing this till reminder (r1) != 0
after that time,  ans/hcf = r1 (the quotent of last step, when reminder = 0) or reminder of second last step

*/

int HCF(int, int);

int main ()
{
    int a,b, ans, r,q;
    cout<<"Enter numbers whose hcf and lcm are required : "<<endl;
    cin>>a>>b;
    int s,l;
    s = a<b ? a : b;
    l = a>b ? a : b;

    while(true)
    {
        q = l/s;
        r = l%s;
        if(r == 0)
        {
            ans = s;  // dont do ans = q
            break;
        }
        else
        {
            l = s;    // dont do l = q, actually their is no need of q variable, unless you want to show steps of euclid division lemma.
            s = r;
        }
        
    }
    ans = HCF(l,s);
    cout<<"HCF = "<<ans<<endl;
    cout<<"LCM = "<<(a*b)/ans<<endl;
    
    return 0;
}

// recursive form of LCM function. (note here we can also pass (a,b) / (small, large), as than after first pass/round it will
//  automatically become (large, small)  as small % large = small ).
int HCF(int l, int s)
{
    if(l%s == 0)
    {
        return s;
    }
    else
    {
        return HCF(s, l%s);
    }
    
}