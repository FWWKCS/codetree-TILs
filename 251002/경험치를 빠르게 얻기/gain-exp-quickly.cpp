#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n, m;
ll e[100], t[100];
vector<ll> dp;

int main() {
    cin >> n >> m;
    ll st = 0;
    for (int i = 0; i < n; i++) {
        cin >> e[i] >> t[i];
        st += t[i];
    }

    dp.resize(st+1, -1);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = st; j > -1; j--) {
            if (j-t[i] >= 0 && dp[j-t[i]] > -1) 
                dp[j] = max(dp[j], dp[j-t[i]]+e[i]);
        }
    }

    int answer = -1;
    for (int i = 0; i <= st; i++) {
        if (dp[i] >= m) {
            answer = i;
            break;
        } 
    }

    cout << answer;
    return 0;
}
