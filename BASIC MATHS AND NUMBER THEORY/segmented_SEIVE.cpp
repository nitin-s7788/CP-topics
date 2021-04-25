#include<iostream>
#include<vector>

/*
question
t test cases
in each test case find all prime numbers between n and m
2 <= n<m <= 10^12 ,     and   m-n  <= 10^5


here we cant use normal seive as, we cant make a array of size 10^12, so we will use segmented sieve (as we can make a array of size 10^6)

plan ->
first we will find all prime numbers between 2 to 10^6  (sqrt(10^12)) (using normal seive and store them in a vector) -> benefit -> all composite numbers till n have atleast 1 devisor 
till sqrt(n),   let us name this vector as vect.  
now if for eg. m,n = 10^11 + 10^4 and 10^11 respectively.  than we make a bool array of size 10^4+1, in which 0 index will represent
10^11 and last index will represent 10^11+10^4. initially all will be true.
than we will make all multiples of v (any number inside vect) as false.
all remaining numbers will be prime.


sample input
2
1 10
3 5

sample output
2 3 5 7
3 5
*/

using namespace std;

int main ()
{
    int t;
    cin>>t;

    vector<bool> is_small_primes(1000001, true);    // ignore index 0 and 1
    for(int i=2; i*i <= 1000000; i++)
    {
        if(is_small_primes[i] == false)
        {
            continue;
        }

        for(int j=i*i; j<= 1000000; j += i)
        {
            is_small_primes[j] = false;
        }
    }

    vector<int> small_primes;
    for(int i=2; i<=1000000; i++)
    {
        if( is_small_primes[i] == true)
        {
            small_primes.push_back(i);
        }
    }
    

    for(int i=0; i<t; i++)
    {
        int n,m;
        cin>>n>>m;
        
        vector<bool> primes(m-n+1, true);      //primes[0] signifies n

        //edge case
        if(n==0)
        {
            primes[0] = false;
            primes[1] = false;
        }
        if(n == 1)
        {
            primes[0] = false;
        }


        for(int j=0; small_primes[j]*small_primes[j] <= m; j++)
        {
            int start_no, start_index;
            if( n%small_primes[j] == 0)
            {
                start_no = n;
            }
            else
            {
                start_no = n/small_primes[j];
                start_no = start_no * small_primes[j] + small_primes[j];
            }

            start_index = start_no - n;
            
            // edge case -> try to generate prime numbers between 2,10 / 3,10.
            if(start_no == small_primes[j])
            {
                start_no += small_primes[j];
                start_index += small_primes[j];
            }

            for(int k=start_no; k<=m; k += small_primes[j],  start_index += small_primes[j])
            {
                primes[start_index] = false;
            }


            
        }

        for(int k=0; k<m-n+1; k++)
        {
            
            if(primes[k] == true)
            {
                cout<<k+n<<" ";
            }
            
        }
        cout<<endl;

    }

    return 0;
}