#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<long long> time(2*n);
    for(int i = 0; i < 2*n; i++){
        cin >> time[i];
    }

    sort(time.begin(),time.end());

    while(m--){
        long long present;
        cin >> present;
        auto lower = lower_bound(time.begin(),time.end(),present);

        if(lower == time.end()){
            cout << "-1" << "\n";
            continue;
        }

        int pos = (lower - time.begin());

        if(pos % 2){
            // odd
            if((*lower) > present){
                cout << "0\n";
                continue;
            }else{
                if((lower) == (time.end() - 1)){ // If lower is the last element
                    if((*lower) > present){
                        cout << "0\n";
                        continue; 
                    }else{
                        cout << "-1\n";
                        continue;
                    }
                }else{
                    cout << *(lower + 1) - present << "\n";
                    continue;
                }
            }
        }else{
            // even
            if((*lower) >= present){
                cout << (*lower) - present << "\n";
                continue;
            }

        }
    }

}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}