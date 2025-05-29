#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N;
char grid[20][20];
vector<tuple<int, int, int>> pos;

int sr, sc, er, ec;

int answer = 1e9;
void route(int steps, int cr, int cc, int last, int depth) {
    if (depth >= 3) {
        // E까지의 유클리디안 거리
        answer = min(answer,
                    steps + abs(er-cr) + abs(ec-cc));
    }

    for (int i = last+1; i < pos.size(); i++) {
        int nr = get<1>(pos[i]), nc = get<2>(pos[i]);
        route(steps+abs(nr-cr)+abs(nc-cc), nr, nc, i, depth+1);
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != '.') {
                if (grid[i][j] == 'S') sr = i, sc = j;
                else if (grid[i][j] == 'E') er = i, ec = j;
                else pos.push_back(make_tuple(grid[i][j]-'0', i, j));
            }
        }
    }

    // Please write your code here.
    sort(pos.begin(), pos.end());

    route(0, sr, sc, -1, 0);
    cout << (answer < 1e9 ? answer : -1);
    return 0;
}
