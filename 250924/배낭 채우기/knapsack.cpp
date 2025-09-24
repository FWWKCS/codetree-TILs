#include <iostream>
#include <vector>
using namespace std;

int N, M;
int w[100], v[100];

vector<int> dp;

int main() {
    cin >> N >> M;
    dp.resize(M+1, -1);

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    dp[0] = 0;
    // Please write your code here.
    for (int i = 0; i < N; i++) {
        for (int j = M; j > -1; j--) {
            if (j-w[i] >= 0 && dp[j-w[i]] > -1) dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }

    int answer = 0;
    for (auto x : dp) answer = max(answer, x);
    cout << answer;

    return 0;
}
