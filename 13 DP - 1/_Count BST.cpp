/*
Count BSTs

Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.

Input Format :
Integer n 

Output Format :
Count of BSTs

Contraints :
1<= N <=1000

Sample Input 1:
8
Sample Output 1:
1430

Sample Input 2:
3
Sample Output 2:
5
*/

#include <bits/stdc++.h>
using namespace std;

int countBST( int n){
    long long int *output = new long long int[n + 1];
    int MOD = 1000000007;
	output[0] = 1;
    output[1] = 1;
    
    for(int i = 2 ; i <= n; i++){
        long long int curr_ans = 0;
        for(int j = 1; j <= i; j++){
         curr_ans = (curr_ans + (output[j - 1] * output[i - j]) % MOD) % MOD;   
        }
        output[i] = curr_ans;
    }
    
	return output[n];
}

int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
