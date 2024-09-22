#include <iostream>
#define MAX 100
using namespace std;

int n;
int table[MAX+1][MAX+1];
int dp[MAX+1][MAX+1];

void renew(int threshold) {
    // 임계값 이상의 값을 가지는 영역만 건너면서 경로의 최댓값이 최소가 되도록
    for (int i = 1; i <= n; i++) {
        if (table[1][i] < threshold) dp[1][i] = -1;
        else if (dp[1][i-1] == -1) dp[1][i] = -1;
        else dp[1][i] = max(dp[1][i-1], table[1][i]);

        if (table[i][1] < threshold) dp[i][1] = -1;
        else if (dp[i-1][1] == -1) dp[i][1] = -1;
        else dp[i][1] = max(dp[i-1][1], table[i][1]);
    } 

    for (int r = 2; r <= n; r++) {
        for (int c = 2; c <= n; c++) {
            if (table[r][c] < threshold) {
                dp[r][c] = -1;
                continue;
            }

            if (dp[r-1][c] == -1 && dp[r][c-1] == -1) {
                dp[r][c] = -1;
                continue;
            }

            if (dp[r-1][c] != -1 && dp[r][c-1] == -1) {
                dp[r][c] = max(dp[r-1][c], table[r][c]);
            }
            else if (dp[r][c-1] != -1 && dp[r-1][c] == -1) {
                dp[r][c] = max(dp[r][c-1], table[r][c]);
            }
            else {
                dp[r][c] = max(table[r][c], min(dp[r-1][c], dp[r][c-1]));
            }
        }
    } 
}

int main() {
    cin >> n;

    int minV = 100;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            table[i][j] = x;
            minV = min(minV, x);
        }
    }

    int answer = MAX;
    for (int i = minV; i <= MAX; i++) {
        renew(i);

        if (dp[n][n] == -1) continue;
        answer = min(answer, dp[n][n] - i);
    }

    cout << answer;
    return 0;
}