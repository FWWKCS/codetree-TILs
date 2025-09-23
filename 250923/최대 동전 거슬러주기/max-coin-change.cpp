#include <iostream>
#include <vector>
using namespace std;

int N, M;
int coin[100];
vector<int> dp;

int main() {
    cin >> N >> M;
    dp.resize(M+1, -1);
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    dp[0] = 0;

    // Please write your code here.
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            if (i-coin[j] >= 0) dp[i] = max(dp[i], dp[i-coin[j]]+1);
        }
    }

    // for (auto x : dp) {
    //     cout << x << ' ';
    // }
    cout << dp[M];
    return 0;
}
