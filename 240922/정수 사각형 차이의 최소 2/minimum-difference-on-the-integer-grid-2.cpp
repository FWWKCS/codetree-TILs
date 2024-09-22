#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int table[MAX+1][MAX+1];
int dp[MAX+1][MAX+1];

int renew(vector<vector<pair<int, int>>> &mm, int r, int c) {
    // 받아온 값이 갱신될 수 있는지 확인
    int L_min, L_max, U_min, U_max, my_min, my_max;
    if (r == 1) {
        // 왼쪽과만 비교
        L_min = mm[r][c-1].first;
        L_max = mm[r][c-1].second;

        // 최소 갱신 검사
        if (table[r][c] < L_min) my_min = table[r][c];
        else my_min = L_min;

        // 최대 갱신 검사
        if (table[r][c] > L_max) my_max = table[r][c];
        else my_max = L_max;
    }
    else if (c == 1) {
        // 위쪽과만 비교
        U_min = mm[r-1][c].first;
        U_max = mm[r-1][c].second;

        // 최소 갱신 검사
        if (table[r][c] < U_min) my_min = table[r][c];
        else my_min = U_min;

        // 최대 갱신 검사
        if (table[r][c] > U_max) my_max = table[r][c];
        else my_max = U_max;
    }
    else {
        // 위로부터 최소최대 정보가 변할때의 차이 구하기
        int with_up;
        int tmp_min_u, tmp_max_u;

        U_min = mm[r-1][c].first;
        U_max = mm[r-1][c].second;

        // 최소 갱신 검사
        if (table[r][c] < U_min) tmp_min_u = table[r][c];
        else tmp_min_u = U_min;

        // 최대 갱신 검사
        if (table[r][c] > U_max) tmp_max_u = table[r][c];
        else tmp_max_u = U_max;

        with_up = tmp_max_u - tmp_min_u;


        // 왼쪽으로부터 최소최대 정보가 변할때의 차이 구하기
        int with_left;
        int tmp_min_l, tmp_max_l;

        L_min = mm[r][c-1].first;
        L_max = mm[r][c-1].second;

        if (table[r][c] < L_min) tmp_min_l = table[r][c];
        else tmp_min_l = L_min;

        // 최대 갱신 검사
        if (table[r][c] > L_max) tmp_max_l = table[r][c];
        else tmp_max_l = L_max;

        with_left = tmp_max_l - tmp_min_l;


        // 두 값을 비교하고 작은 것을 채택
        if (with_left < with_up) {
            my_min = tmp_min_l;
            my_max = tmp_max_l;
        }
        else {
            my_min = tmp_min_u;
            my_max = tmp_max_u;
        }
    }

    mm[r][c].first = my_min;
    mm[r][c].second = my_max;

    return my_max - my_min;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            table[i][j] = x;
        }
    }

    vector<vector<pair<int, int>>> mm(n+1, vector<pair<int, int>>(n+1));
    mm[1][1] = make_pair(table[1][1], table[1][1]);
    dp[1][1] = 0;

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (r == 1 && c == 1) continue;

            dp[r][c] = renew(mm, r, c);
        }
    }

    // for (int r = 1; r <= n; r++) {
    //     for (int c = 1; c <= n; c++) cout << dp[r][c] << ' ';
    //     cout << '\n';
    // }

    cout << dp[n][n];
    return 0;
}