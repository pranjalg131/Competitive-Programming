/*
Minimum Count

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Input format :
The first and the only line of input contains an integer value, 'N'.

Output format :
Print the minimum count of numbers required.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)

B) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)  + (2 ^ 2)

C) (1^1) + (1^1) + (1^1) + (1^1) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.

Sample Input 2 :
9
Sample Output 2 :
1
*/

#include <bits/stdc++.h>
using namespace std;

int minCount(int n){
	vector<int> dp(n + 1);
    vector<int> square;
    
    square.push_back(1);
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++){
        int min = INT_MAX;
        for(int j = 0; j < square.size(); j++){
            double root = sqrt(i);
            if(root - floor(root) == 0){
                square.push_back(i);
                min = 1;
                break;
            }
            
            if(dp[i - square[j]] + 1 < min)
                min = dp[i - square[j]] + 1;
        }
        dp[i] = min;
    }
        
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}