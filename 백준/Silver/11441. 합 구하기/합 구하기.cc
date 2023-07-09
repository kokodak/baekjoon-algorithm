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

int pfx[100001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;
    cin >> n;
    ll summ = 0;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        summ += k;
        pfx[i] = summ;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << pfx[b] - pfx[a - 1] << '\n';
    }
	return 0;
}