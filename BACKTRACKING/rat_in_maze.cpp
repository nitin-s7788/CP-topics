/*
question ->
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block
is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination. The rat can move only in two
directions: forward and down.
In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination. Note 
that this is a simple version of the typical Maze problem. For example, a more complex version can be that the rat can move in 4 
directions and a more complex version can be with a limited number of moves.
*/

#include<iostream>
#include<vector>

using namespace std;

void print(int arr[][4], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

bool solve_maze(int maze[][4], int n, int solution[][4], int r, int c)
{
    
    solution[r][c] = 1;

    if(r == n-1 && c == n-1)
    {
        return true;
    }

    if(r<0 || c<0 || r>=n || c>=n)
    {
        return false;
    }

    if(maze[r][c] == 0)
    {
        return false;
    }

  //  solution[r][c] = 1;

    bool b;

    if ( solve_maze(maze, n, solution, r+1, c) == true)
    {
        return true;
    }
    else
    {
        solution[r+1][c] = 0;
    }

    if( solve_maze(maze, n, solution, r, c+1) == true)
    {
        return true;
    }
    else
    {
        solution[r][c+1] = 0;
    }
    
    
    return false;

}

int main ()
{
    int maze[4][4] = {  { 1, 0, 0, 0 }, 
                        { 1, 1, 0, 1 }, 
                        { 0, 1, 0, 0 }, 
                        { 1, 1, 1, 1 }   }; 

    
    int solution[4][4];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            solution[i][j] = 0;
    }

    bool b = solve_maze(maze, 4, solution, 0, 0);

    if(b == false)
    {
        cout<<"NOT POSSIBLE"<<endl;
    }
    else
    {
        print(solution, 4);
    }
    
    return 0;
}