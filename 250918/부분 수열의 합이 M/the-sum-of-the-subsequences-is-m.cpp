#include <iostream>
#include <vector>
using namespace std;

int n, m;
int A[100];

vector<int> dp;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    dp.resize(m+1, 1e9);
    dp[0] = 0;
    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            if (j-A[i] >= 0) dp[j] = min(dp[j], dp[j-A[i]]+1);
        }
    }

    cout << (dp[m] >= 1e9 ? -1 : dp[m]);

    return 0;
}
