/*
Unset ith bit

You are given two integers N and i. You need to make ith bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.

Input Format :
Two integers N and i (separated by space)

Output Format :
Updated N

Sample Input 1 :
7 2
Sample Output 1 :
3
Sample Input 2 :
12 1
Sample Output 2 :
12
*/

#include <iostream>
using namespace std;

int turnOffIthBit(int n, int i){
  // For this we need to use the and operator
  return n & (~(1 << i)); // That expression gives us the number of form 11111110111 for takng and with.     
}

int main() {
	int n, i;

	cin >> n >> i;
	
	cout<< turnOffIthBit(n, i) <<endl;
		
	return 0;
}

