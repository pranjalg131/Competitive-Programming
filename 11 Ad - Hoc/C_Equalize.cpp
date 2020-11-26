#include <bits/stdc++.h>
using namespace std;

void solve(string a , string b){
  int i = 0;
  int j = 0;
  int cost = 0;

  while(i < a.length()){
    if(a[i] == b[i + 1] && a[i + 1] == b[i] && (a[i] != a[i+1])){
      char temp;
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      cost += 1;
      i++;
    }else if(a[i] != b[i]){
      a[i] = b[i];
      cost++;
    }
    i++;
  }

  cout << cost << endl;
}

int main(){
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  solve(a,b);
return 0;
}