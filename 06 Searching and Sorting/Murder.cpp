/*
Murder

Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.

Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.

Output
For each test case output one line giving the final sum for each test case.

Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.

Sample Input:
1
5
1 5 3 6 4
Sample Output:
15

Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
*/

#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, int left , int mid , int right){
  int i = left,j = mid,k = 0;
  long long temp[right - left + 1];
  long long count = 0;

  while(i < mid && j <= right){
    if(arr[j] > arr[i]){
      count += (arr[i] * (right - j + 1));
      temp[k++] = arr[i++];
    }else{
      temp[k++] = arr[j++];
    }
  }

  while(i < mid)
    temp[k++] = arr[i++];
  
  while(j <= right)
    temp[k++] = arr[j++];
  
  for (int i = left,k = 0; i <= right; i++,k++)
  {
    arr[i] = temp[k];
  }
  return count;
}

long long getSum(long long *arr, int left, int right){
  long long count = 0;

  if(right > left){
    
    int mid = (right + left) / 2;
    long long leftCount = getSum(arr,left,mid);
    long long rightCount = getSum(arr,mid + 1,right);
    count = merge(arr,left,mid+1,right);
    return (count + leftCount + rightCount); 
  }

  return count;
}

int main(){
  int t,n;
  cin >> t;
  
  while(t--){
    cin >> n;
    long long arr[n];
  
    for (int i = 0; i < n; i++)
      cin >> arr[i];
  
    long long sum = getSum(arr,0,n-1);

    cout << sum << "\n";
  }

  return 0;
}