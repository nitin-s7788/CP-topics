/*
question ->
their are n number of queens, your task is to place them on a N x N, chess board such that no 2 queens can attack/cut each other.
if their is a queen on a position print 1 else zero.
print any of the possible answers in case of multiple answers.

(n <= 18)
*/


#include<iostream>
#include<vector>

using namespace std;

bool is_valid(vector< vector<int> > v, int n)
{
    bool b = true;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(v[i][j] == 1)
            {
                int i1 = i-1, j1 = j-1;
                
                while(i1 >= 0 && j1 >= 0)
                {
                    if(v[i1][j1] == 1)
                    {
                        b = false;
                        break;
                    }
                    i1--, j1--;
                }

                i1 = i+1, j1 = j+1;
                while(i1<n && j1<n)
                {
                    if(v[i1][j1] == 1)
                    {
                        b = false;
                        break;
                    }
                    i1++, j1++;
                }

                i1 = i-1, j1 = j+1;
                while(i1 >= 0 && j1<n)
                {
                    if(v[i1][j1] == 1)
                    {
                        b = false;
                        break;
                    }
                    i1--, j1++;
                }

                i1 = i+1, j1 = j-1;
                while(i1<n && j1>=0)
                {
                    if(v[i1][j1] == 1)
                    {
                        b = false;
                        break;
                    }
                    i1++, j1--;
                }

            }

            if(b == false)
            {
                break;
            }

        }
        if(b == false)
        {
            break;
        }
    }

    return b;

}


bool set_queens(vector< vector<int> > &v, int n, int queen_number, vector<bool> &arr)
{
    
    if(is_valid(v, n) == false)
    {
        return false;
    }

    if(queen_number == n+1)
    {
        return true;
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i] != true)
        {
            arr[i] = true;
            v[queen_number-1][i] = 1;
            bool b = set_queens(v, n, queen_number+1, arr);
            if(b == true)
            {
                return true;
            }
            else
            {
                v[queen_number-1][i] = 0;
                arr[i] = false;
            }
            
        }
    }

    return false;
}

int main ()
{
    int n;
    cout<<"Enter the dimension of chess board : ";
    cin>>n;

    vector< vector<int> >  v(n, vector<int>(n,0));
    vector<bool> arr(n,false);

    bool b = set_queens(v, n, 1, arr);

    if(b == false)
    {
        cout<<"NOT POSSIBLE"<<endl;
        return 0;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}