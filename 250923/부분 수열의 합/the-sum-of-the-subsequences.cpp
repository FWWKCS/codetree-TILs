#include <iostream>
#include <vector>
using namespace std;

int n, m;
int A[100];
vector<int> dp;

int main() {
    cin >> n >> m;
    dp.resize(m+1, -1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    dp[0] = 1;

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        int cur = A[i];
        for (int j = m; j > -1; j--) {
            if (j-cur >= 0 && dp[j-cur] > -1) dp[j] = dp[j-cur]+1;
        }
    }

    cout << (dp[m] > -1 ? "Yes" : "No");
    return 0;
}
