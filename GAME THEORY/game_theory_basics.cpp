/*
their are 3 main ways to solve a game theory question (in the game rules should be same for both players)

method - 1 :  observation / pattern finding (i.e. we can find a pattern or some other observation for which a player wins)

method - 2 :  DP / memoization

method - 3 :  sproge grundy theorem (we will discuss in deep about this) -> here we use grundy numbers to tell how will win.

mex() function : it is the smallest non-negative integer not present in a set
for eg. -> mex(1,2,3,4) = 0 ,   mex(0,1,2,3) = 4,  mex(0,1,3,4,5) = 2

grundy numbers ->
grundy number of a game which is lost immediately (we can't continue the game / for n = 0) is 0.
grundy number at any state of game (any value of n) is equal to mex() of grundy numbers of all other states of game which can be
reached from the current state of game (in 1 step/move).

grundy numbers for some example games ->
game 1 ->
their is a pile of n coins,  each player can remove 1,2 or 3 coins from it, the player who cant make a move lose the game.
here,  grundy(0) = 0        //game lost immediately (generally for n = 0)
.      grundy(1) = mex( grundy(0) ) = mex(0) = 1   //as the player as only 1 option to take the game to n = 0, by removing 1 coin.
.      grundy(2) = mex( grundy(0), grundy(1) ) = mex(0,1) = 2  //as player can take game to n=1 or 0 , by removing 1 or 2 coins respectively.
.      grundy(3) = mex( grundy(2), grundy(1), grundy(0) ) = mex(2,1,0) = 3
.      grundy(4) = mex( grundy(3), grundy(2), grundy(1) ) = mex(3,2,1) = 0

similarly, for n >= 4 : grundy(n) = mex( grundy(n-1), grundy(n-2), grundy(n-3) )

so here grundy numbers are -> [0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3...]   (clearly we got a pattern)


game 2 ->
their is a non-negative/positive number n, a player can divide it by 2,3 or 6 -> we take the floor/greatest integer of the result.
the player who cant make a move (sees number = 0 in front of him) lose the game.
here,  grundy(0) = 0        //game lost immediately (generally for n = 0)
.      grundy(1) = mex(grundy(0)) = 1     // divide by any number we reach the state were n = 0
.      grundy(2) = mex(grundy(1), grundy(0)) = mex(0,1) = 2  // divide by 2 reach, n=1 else reach n=0
.      grundy(3) = mex(grundy(1), grundy(0)) = mex(0,1) = 2
.      grundy(4) = mex(grundy(2), grundy(1), grundy(0)) = mex(2,1,0) = 3 // divide by 2 reach n=2, divide by 3 reach n=1, else n=0
.      grundy(5) = mex(grundy(2), grundy(1), grundy(0)) = 3
.      grundy(6) = mex(grundy(3), grundy(2), grundy(1)) = mex(2,2,1) = 0 // divide by 6 reach n=1, divide by 2 reach n=3, else n=2
.      grundy(7) = mex(grundy(3), grundy(2), grundy(1)) = 0

similarly, for n >= 6 : grundy(n) = mex( grundy(n/6), grundy(n/3), grundy(n/2) )
(we generally use DP/pattern to find all grundy numbers till n, after figuring out the pattern/relation of grundy numbers)


sproge grundy theorem -> if the XOR of grundy numbers of all possible states of a game (that can be reached from the given initial 
values) is non-zero than first player wins otherwise 2nd player wins (if both play optimally).
*/