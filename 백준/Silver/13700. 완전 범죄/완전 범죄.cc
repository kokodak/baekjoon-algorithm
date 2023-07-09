#include <bits/stdc++.h>
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

int arr[100001];
bool visited[100001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, s, d, f, b, k;
    cin >> n >> s >> d >> f >> b >> k;
    for (int i = 0; i < k; i++) {
        int k;
        cin >> k;
        arr[k] = 2;
    }
    visited[s] = true;
    arr[d] = 1;
    queue<pii> que;
    que.push({s, 0});
    while (!que.empty()) {
        int node = que.front().X;
        int att = que.front().Y;
        if (arr[node] == 1) {
            cout << att;
            return 0;
        }
        que.pop();
        if (node + f <= n) {
            if (arr[node + f] != 2 && !visited[node + f]) {
                visited[node + f] = true;
                que.push({node + f, att + 1});
            }
        }
        if (node - b >= 1) {
            if (arr[node - b] != 2 && !visited[node - b]) {
                visited[node - b] = true;
                que.push({node - b, att + 1});
            }
        }
    }
    cout << "BUG FOUND";
	return 0;
}