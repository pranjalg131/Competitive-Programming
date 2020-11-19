/*
Crossword Problem
Send Feedback
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

#include <bits/stdc++.h>
using namespace std;

#define N 10

vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

bool isValidVertical(char board[N][N],int row, int col, vector<string>& words, int index){
  string s = words[index];

  for(int i = row; i < row + s.length(); i++){
    if(!(board[i][col] == '-' || board[i][col] == s[i - row])){
      return false;
    }
  }

  return true;
}

bool isValidHorizontal(char board[N][N],int row, int col, vector<string>& words, int index){
  string s = words[index];

  for(int i = col; i < col + s.length(); i++){
    if(!(board[row][i] == '-' || board[row][i] == s[i - col])){
      return false;
    }
  }

  return true;
}

void setVertical(char board[N][N], bool helper[], int row, int col, vector<string>& words, int index){
  string s = words[index];

  for(int i = row; i < row + s.length(); i++){
    if(board[i][col] == '-'){
      board[i][col] = s[i - row];
      helper[i - row] = true;
    }
  }
}

void setHorizontal(char board[N][N], bool helper[], int row, int col, vector<string>& words, int index){
  string s = words[index];

  for(int i = col; i < col + s.length(); i++){
    if(board[row][i] == '-'){
      board[row][i] = s[i - col];
      helper[i - col] = true;
    }
  }
}

void resetVertical(char board[N][N], bool helper[], int row, int col, vector<string>& words, int index){
  string s = words[index];

  for(int i = row; i < row + s.length(); i++){
    if(helper[i - row]){
      board[i][col] = '-';
    }
  }
}

void resetHorizontal(char board[N][N], bool helper[], int row, int col, vector<string>& words, int index){
  string s = words[index];

  for(int i = col; i < col + s.length(); i++){
    if(helper[i - col]){
      board[row][i] = '-';
    }
  }
}


bool solveBoard(char board[N][N], vector<string>& words, int index){

  if(index == words.size()){
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cout << board[i][j];
      }
      cout << endl;
    }
    return true;
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if(board[i][j] == '-' || board[i][j] == words[index][0]){
        if(isValidVertical(board,i,j,words,index)){
          string s = words[index];
          bool helper[s.length()] = {0};
          setVertical(board,helper,i,j,words,index);
          if(solveBoard(board,words,index + 1)){
            return true;
          }
          resetVertical(board,helper,i,j,words,index);
        }

        if(isValidHorizontal(board,i,j,words,index)){
          string s = words[index];
          bool helper[s.length()] = {0};
          setHorizontal(board,helper,i,j,words,index);
          if(solveBoard(board,words,index + 1)){
            return true;
          }
          resetHorizontal(board,helper,i,j,words,index);
        }

      }
    }
  }
  return false;
}

int main(){

  char board[N][N];
  for (int i = 0; i < N; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++)
    {
      board[i][j] = s[j];
    }
  }

  string line;
  cin >> line;
  vector<string> words = split(line,';');


  solveBoard(board,words,0);

  return 0;
}