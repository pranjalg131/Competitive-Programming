#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadaneSum(ll* arr,int n){
    ll current_sum = 0;
    ll best_sum = INT_MIN;
    for(int i = 0; i < n; i++){
        current_sum += arr[i];

        if(best_sum < current_sum)
            best_sum = current_sum;
        
        if(current_sum < 0)
            current_sum = 0;
    }
    return best_sum;
}

ll prefixSum(ll* arr, int n){
    ll current_sum = 0;
    ll best_sum = INT_MIN;
    for(int i = n-1; i >= 0; i--){
        current_sum += arr[i];

        if(best_sum < current_sum)
            best_sum = current_sum;

    }
    return best_sum;
}

ll suffixSum(ll* arr, int n){
    ll current_sum = 0;
    ll best_sum = INT_MIN;
    for(int i = 0; i < n; i++){
        current_sum += arr[i];

        if(best_sum < current_sum)
            best_sum = current_sum;
    }
    return best_sum;
}

ll normalSum(ll* arr, int n){
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    
    return sum;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        ll arr[n];
        
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        ll sum = normalSum(arr,n);
        ll ks = kadaneSum(arr,n);
        ll s = suffixSum(arr,n);
        ll p = prefixSum(arr,n);

        // cout << sum << "\n";
        // cout << ks << "\n";
        // cout << s << "\n";
        // cout << p << "\n";

        ll ans = 0;
        if(sum >= 0){
            if(k == 1)
                ans = ks;
            else{
                ans = max((p + s + (k-2)*sum),ks);
            }
        }else{
            if(k == 1)
                ans = ks;
            else
                ans = max(p+s,ks);
            
        }
        cout << ans << "\n";
    }
    return 0;
}