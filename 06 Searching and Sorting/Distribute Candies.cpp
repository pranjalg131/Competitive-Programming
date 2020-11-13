/*
Distribute Candies

Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.

Input
First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.

Output
For each test case print the required answer in a seperate line.

Sample Input:
2
3 2 
3 1 4
4 1
3 2 3 9
Sample Output:
3
9
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkCandy(ll *boxes, ll n, ll k, ll mid){
  ll count = 0;
  for(int i = 0; i < n; i++){
    count += boxes[i] / mid;
  }

  if(count >= k)
    return true;
  else return false;
}

void solve(){
  long long n,k;
  cin >> n >> k;
  ll boxes[n];

  for(int i = 0; i < n; i++)
    cin >> boxes[i];
  
  sort(boxes,boxes+n);

  ll start = boxes[0];
  ll end = boxes[n-1];
  ll ans = -1;

  while(start <= end){
    ll mid = start + (end - start) / 2;

    if(checkCandy(boxes,n,k,mid)){
      start = mid + 1;
      ans = mid;
    }else{
      end = mid - 1; 
    }
  }

  cout << ans << "\n";

}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}