/*
question ->
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also 
given that every job takes single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if 
only one job can be scheduled at a time -> print the which jobs will be done.

sample test cases ->

JobID  Deadline  Profit
  a      4        20        // i.e. task 'a' must be done before t=4.   
  b      1        10
  c      1        40  
  d      1        30

  output -> a,c          (at t=0, do 'c', at t=1, do 'a' )


JobID   Deadline  Profit
  a       2        100
  b       1        19
  c       2        27
  d       1        25
  e       3        15

  output -> c,a,e
*/

/*
approach / logic ->
we will sort jobs on the basis of profit. everytime we encounter a job, we will schedule it at the greatest time available before it's
deadline.
we will make a unordered map, storing if at a given time some activity is scheduled or not.
*/



#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Pair
{
    public :
    char job_ID;
    int deadline;
    int profit;
};

bool compare(Pair p1, Pair p2)
{
    if(p1.profit >= p2.profit)
        return true;
    return false;
}

int main ()
{
    int t;
    cin>>t;
    for(int test=0; test<t; test++)
    {
        int n;
        cin>>n;

        vector<Pair> v(n);
        vector<char> answers;

        for(int i=0; i<n; i++)
        {
            cin>>v[i].job_ID>>v[i].deadline>>v[i].profit;
        }

        sort(v.begin(), v.end(), compare);

        unordered_map<int, bool> m;

        for(int i=0; i<n; i++)
        {
            for(int j=v[i].deadline-1; j>=0; j--)
            {
                if(m.count(j) == 0)
                {
                    m[j] = true;
                    answers.push_back(v[i].job_ID);
                    break;
                }
            }
        }

        for(int i=0; i<answers.size(); i++)
            cout<<answers[i]<<" ";
        cout<<endl;

    }
    return 0;
}