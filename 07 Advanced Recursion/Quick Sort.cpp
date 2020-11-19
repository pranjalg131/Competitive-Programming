/*
Quick Sort Code

Sort an array A using Quick Sort.
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
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int input[], int x, int y){
    int temp = input[x];
    input[x] = input[y];
    input[y] = temp;
}

int partition(int input[], int left, int right){
    int count = 0;
    int pivot = input[left];
    for(int i = left+1 ; i <= right; i++){
        if(input[i] < pivot)
            count++;
    }
    
    int pivot_index = left + count;
    swap(input,left,pivot_index);
    
    int i = left,j = right;
    
    while(i < pivot_index && j > pivot_index){
        if(input[i] >= pivot && input[j] < pivot){
            swap(input,i,j);
            i++;
            j--;
        }else if(input[i] >= pivot){
            j--;
        }else if(input[j] < pivot){
            i++;
        }else{
            i++;
            j--;
        }
    }
    
    return pivot_index;
    
}

void helper(int input[], int left, int right){
    if(right > left){
        int c = partition(input, left , right);        
        helper(input,left,c-1);
        helper(input,c+1,right);
    }
}

void quickSort(int input[], int size) {
  helper(input,0,size-1);
}

// Else if me do condition hogi aur = waale conditions sahi se check karo 

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


