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

int mmap[1001][1001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        mmap[i][0] = k;
    }
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        mmap[0][i] = k;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mmap[i][j] = mmap[i - 1][j] == mmap[i][j - 1] ? 0 : 1;
        }
    }
    cout << mmap[n][m];
	return 0;
}