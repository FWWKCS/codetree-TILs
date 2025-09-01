#include <iostream>
#include <vector>
#include <queue>
#define MAX 1'000'000
using namespace std;

int N;
vector<int> answer(MAX+1, 1e9);

void bfs() {
    answer[N] = 0;
    queue<pair<int, int>> q;
    q.push({N, 0});

    while (!q.empty()) {
        int cur = q.front().first;
        int ct = q.front().second;

        q.pop();

        if (cur <= MAX && answer[cur+1] > ct+1) {
            q.push({cur+1, ct+1});
            answer[cur+1] = ct+1;
        }
        if (cur > 0 && answer[cur-1] > ct+1) {
            q.push({cur-1, ct+1});
            answer[cur-1] = ct+1;
        }
        if (cur % 2 == 0 && answer[cur/2] > ct+1) {
            q.push({cur/2, ct+1});
            answer[cur/2] = ct+1;
        }
        if (cur % 3 == 0 && answer[cur/3] > ct+1) {
            q.push({cur/3, ct+1});
            answer[cur/3] = ct+1;
        }
    }
}

int main() {
    cin >> N;

    // Please write your code here.
    bfs();
    cout << answer[1];
    return 0;
}
