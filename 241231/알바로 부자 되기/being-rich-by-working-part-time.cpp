#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    int N; cin >> N;
    vector<tuple<int, int, int>> work;
    vector<int> dp(N, 0);
    int answer = 0;
    for (int i = 0; i < N; i++) {
        int s, e, p; cin >> s >> e >> p;
        tuple<int, int, int> tmp = {s, e, p};
        work.push_back(tmp);
        dp[i] = p;
        answer = max(answer, p);
    }


    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (get<1>(work[i]) < get<0>(work[j])) dp[j] = max(dp[j], dp[i]+get<2>(work[j]));
            answer = max(answer, dp[j]);
        }
    }

    cout << answer;
    return 0;
}