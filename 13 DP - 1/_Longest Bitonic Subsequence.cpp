/*
Largest Bitonic Subarray

You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.

Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 

Output Format:
Length of Largest Bitonic subsequence

Input Constraints:
1<= N <= 100000

Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/

#include<iostream>
using namespace std;

int longestBitonicSubarray(int *input, int n) {
  int output[3][n+1];
  
  output[0][1] = 1;
  for (int i = 2; i <= n; i++){
    output[0][i] = 1;
    int possibleAns = 0;
    for (int j = i-1; j >= 1; j--){
      if(input[i-1] > input[j-1]){
        possibleAns = output[0][j] + 1;
        output[0][i] = max(output[0][i],possibleAns);
      }
    }
  }
  
  output[1][n] = 1;
  for (int i = n-1; i >= 1; i--){
    output[1][i] = 1;
    int possibleAns = 0;
    for (int j = i+1; j <= n; j++){
      if(input[i-1] > input[j-1]){
        possibleAns = output[1][j] + 1;
        output[1][i] = max(output[1][i],possibleAns);
      }
    }
  }

  int best = 0;
  for (int i = 1; i <= n; i++){
    output[2][i] = output[0][i] + output[1][i] - 1;
    best = max(output[2][i],best);
  }
  return best;
}

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}
