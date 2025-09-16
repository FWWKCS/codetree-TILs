#include <iostream>
#define INF 1e9
#define MAX 10'000
using namespace std;

int N, M;
int coin[100];

int dp[MAX+1];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    // Please write your code here.
    for (int i = 1; i <= MAX; i++) {
        dp[i] = INF;
    }

    dp[0] = 0;
    for (int i = 1; i <= MAX; i++) {
        for (int k : coin) {
            if (i >= k) dp[i] = min(dp[i], dp[i-k]+1);
        }
    }

    cout << dp[M];
 
    return 0;
}
