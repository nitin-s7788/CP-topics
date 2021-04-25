/*
question ->
There are n piles of stones, where the i-th pile has ai stones. Two people play a game, where they take alternating turns removing 
stones.

In a move, a player may remove a positive number of stones from the first non-empty pile (the pile with the minimal index, 
that has at least one stone). The first player who cannot make a move (because all piles are empty) loses the game. 
If both players play optimally, determine the winner of the game.

Input
The first line contains a single integer t (1≤t≤1000)  — the number of test cases. Next 2t lines contain descriptions of test cases.

The first line of each test case contains a single integer n (1≤n≤105)  — the number of piles.

The second line of each test case contains n integers a1,…,an (1≤ai≤109)  — ai is equal to the number of stones in the i-th pile.

It is guaranteed that the sum of n for all test cases does not exceed 105.

Output
For each test case, if the player who makes the first move will win, output "First". Otherwise, output "Second".
*/

/*
solution/ logic ->

this game is in full control/ domination of the current player/ first player as->
the player can remove any number of stones from the current pile(1 to all stones), if he also want to take the control of next pile,
he will simply remove (n-1) stones from the current pile so that second player have to pick up the last stone and on the next pile also
it will be the turn of first player.
in case the next odd no. of piles has 1 stones each, than the first player will take all n stones of the current pile and than after
next odd no. of piles with 1 stones it will again be the turn of 1st player.
in case the next even no. of piles has 1 stones each, than the first player will take (n-1) stones from the current pile and than after
the next even no. of piles with 1 stones it will again be the turn of 1st player.

the only exception is when their are piles with 1 stones in the starting, as the game will be domainated by the player which first
gets a pile with more than 1 stones.
so, if the first odd no. of piles are having 1 stone each, than second player will dominate the game and win.
otherwise, first player will dominate and win. (here dominate means, that the whole game will be played according to the wish of the
player and he will be able to decide how many stones the other player will pick).
[avoid the last pile]
*/

#include<iostream>
#include<vector>
 
using namespace std;
 
int main ()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        vector<int> v(n,0);
        for(int j=0; j<n; j++)
        cin>>v[j];
 
        int count = 0;
        
        while(v[count] == 1 && count<n-1)
        {
            count++;
        }
 
        if(count%2 == 0)
        {
            cout<<"First"<<endl;
        }
        else
        {
            cout<<"Second"<<endl;
        }
 
    }

    return 0;
}
  

