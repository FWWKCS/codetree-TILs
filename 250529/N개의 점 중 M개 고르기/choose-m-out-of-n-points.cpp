#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
vector<pair<int, int>> pos;

vector<pair<int, int>> G; 
int answer = 1e9;

void findDist() {
    int d = 0;
    for (int i = 0; i < m-1; i++) {
        for (int j = i+1; j < m; j++) {
            d = max(d, int(pow(G[i].first-G[j].first, 2)+pow(G[i].second-G[j].second, 2)));
        }
    }

    answer = min(answer, d);
}

void grouping(int last) {
    if (G.size() == m) {
        // 그룹 내 가장 큰 거리 값을 찾기
        findDist();
        return;
    }

    for (int i = last+1; i < n; i++) {
        G.push_back(pos[i]);
        grouping(i);
        G.pop_back();
    }
}

int main() {
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pos.push_back({x, y});
    }

    // Please write your code here.
    grouping(-1);
    cout << answer;
    return 0;
}
