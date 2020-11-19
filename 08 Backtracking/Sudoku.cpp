#include <bits/stdc++.h>
using namespace std;

#define N 9

bool getEmptyPosition(int board[N][N], int& row, int& col){
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if(board[i][j] == 0){
        row = i;
        col = j;
        return true;
      }
    }
  }
  return false;
}

bool isSafeRow(int board[N][N], int row, int num){
  for (int i = 0; i < N; i++)
  {
    if(board[row][i] == num){
      return false;
    }
  }
  return true;
}

bool isSafeColumn(int board[N][N], int col, int num){
  for (int i = 0; i < N; i++)
  {
    if(board[i][col] == num){
      return false;
    }
  }
  return true;
}

bool isSafeGrid(int board[N][N], int row, int col, int num){

  int rowFactor = row - (row % 3);
  int colFactor = col - (col % 3);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if(board[rowFactor + i][colFactor + j] == num){
        return false;
      }
    }
  }

  return true;
}
bool isSafe(int board[N][N], int row, int col, int num){
  if(isSafeRow(board,row,num) && isSafeColumn(board,col,num) && isSafeGrid(board,row,col,num)){
    return true;
  }
  return false;
}

bool solveSudoku(int board[N][N]){

  int row;
  int col;

  if(!getEmptyPosition(board,row,col)){
    return true;
  }

  for (int i = 1; i <= 9; i++)
  {
    if(isSafe(board,row,col,i)){
      board[row][col] = i;
      if(solveSudoku(board)){
        return true;
      }
      board[row][col] = 0;
    }
  }
  return false;
}

int main(){

  int board[N][N];

  for (int i = 0; i < 9; i++)
  {
    string S;
    cin >> S;
    for (int j = 0; j < S.length(); j++)
    {
      board[i][j] = S[j] - '0';
    }
  }

  solveSudoku(board);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << board[i][j];
    }
    cout << endl;
  }
  
return 0;
}