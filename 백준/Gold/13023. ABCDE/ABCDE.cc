#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e18;
const int inf = 2e9;
const int SIZE = 1 << 18;
const int MOD = 1e9 + 7;
const int MAX = 2000;

vector<int> graph[MAX];
bool visited[MAX];
bool found = false;

void dfs(int curr, int depth) {
    if (depth == 5) {
        found = true;
        return;
    }

    visited[curr] = true;
    for (int next : graph[curr]) {
        if (!visited[next]) {
            dfs(next, depth + 1);
            if (found) return;
        }
    }
    visited[curr] = false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < N; ++i) {
        fill(visited, visited + N, false);
        dfs(i, 1);
        if (found) break;
    }

    cout << (found ? 1 : 0);

    return 0;
}
