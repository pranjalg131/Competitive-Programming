/*
Merge Sort Code

Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

#include <iostream>
using namespace std;

void merge(int input[], int left, int mid, int right){
    int i = left, j = mid, k = 0;
    
    int temp[right - left + 1];
    
    while(i < mid && j <= right){
        if(input[j] > input[i]){
            temp[k++] = input[i++];
        }
        else{
            temp[k++] = input[j++];
        }
    }
    
    while(i < mid)
        temp[k++] = input[i++];
    
    while(j <= right)
        temp[k++] = input[j++];
    
    for(int i = left,k = 0; i <= right; i++,k++)
        input[i] = temp[k];
}

void helper(int input[], int left , int right){
    if(right > left){
        int mid = (left + right) / 2;
    	helper(input, left ,mid);
    	helper(input, mid + 1, right);
    	merge(input, left, mid + 1, right);
    }
}

void mergeSort(int input[], int size){
	helper(input,0,size-1);
        
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}