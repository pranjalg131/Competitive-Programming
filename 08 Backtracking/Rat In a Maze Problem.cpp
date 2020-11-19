/*
Rat In A Maze Problem

You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.

Input Format
The first line of input contains an integer 'N' representing 
the dimension of the maze.
The next N lines of input contain N space-separated 
integers representing the type of the cell.

Output Format :
For each test case, print the path from start position to destination position and only cells that are part of the solution path should be 1, rest all cells should be 0.
Output for every test case will be printed in a separate line.

Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.

Constraints:
0 < N < 11 0 <= Maze[i][j] <=1

Time Limit: 1sec

Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Sample Output 1 Explanation :
Only 1 path is possible

1 0 0
1 0 0
1 1 1
Which is printed from left to right and then top to bottom in one line.

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Sample Output 2 Explanation :
4 paths are possible which are printed in the required format.
*/
#include <bits/stdc++.h>
using namespace std;

int answer[20][20];

void printAnswer(int n){
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << answer[i][j] << " ";
    }
    
  }
  cout << endl;
}

void mazeHelper(int maze [][20], int n, int x, int y){

  if(x == n-1 && y == n-1){
    answer[x][y] = 1;
    printAnswer(n);
    return;
  }

  if(x >= n || y >= n || x < 0 || y < 0 || maze[x][y] == 0 || answer[x][y] == 1){
    return;
  }

  answer[x][y] = 1;
  mazeHelper(maze,n,x-1,y);
  mazeHelper(maze,n,x+1,y);
  mazeHelper(maze,n,x,y-1);
  mazeHelper(maze,n,x,y+1);
  answer[x][y] = 0;

  return;
}

void ratInAMaze(int maze[][20], int n){

  memset(answer,20*20,sizeof(int));

  mazeHelper(maze,n,0,0);


}

int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}

