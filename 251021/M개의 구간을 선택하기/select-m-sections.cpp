#include <iostream>
#include <vector>
using namespace std;

int N, M;
int numbers[500];
vector<vector<vector<int>>> dp;
int main() {
    cin >> N >> M;
    dp.resize(N, vector<vector<int>>(M+1, vector<int>(2, -1e9)));
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }


    // dp[d][r][c]: d번째 원소를 r번째 그룹 차례에 대하여,
    // c = 0: r번째 그룹에 d번째 원소를 넣어 이어간다
    // c = 1: d번째 원소를 버려서 r번째 그룹을 마친다
    dp[0][0][1] = 0;
    dp[0][1][0] = numbers[0];

    // Please write your code here.
    for (int d = 1; d < N; d++) {
        for (int r = 1; r <= M; r++) {
            for (int c = 0; c < 2; c++) {
                if (c == 0) {
                    // 원소를 r번째 그룹에 넣어 이어가기
                    dp[d][r][c] = max(dp[d-1][r][c]+numbers[d], dp[d-1][r-1][c+1]+numbers[d]);
                }
                else {
                    // 현재 원소를 포기해 r번째 그룹을 완성하기
                    dp[d][r][c] = dp[d-1][r][c-1];
                }
            }
        }
    }

    // for (auto d : dp) {
    //     for (auto r : d) {
    //         for (auto c : r) cout << c << ' ';
    //         cout << '\n';
    //     }
    //     cout << "\n\n";
    // }


    int answer = -1e9;
    for (auto c : dp[N-1][M]) answer = max(answer, c); 
    

    cout << answer;
    return 0;
}
