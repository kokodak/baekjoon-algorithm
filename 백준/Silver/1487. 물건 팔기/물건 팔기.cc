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

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int summMax = -inf;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int summ = 0;
        int sell = v[i].X;
        for (int j = 0; j < n; j++) {
            if (sell > v[j].X) continue;
            if (sell - v[j].Y <= 0) continue;
            summ += sell - v[j].Y;
        }
        if (summ != 0 && summMax < summ) {
            summMax = summ;
            ans = sell;
        }
    }
    cout << ans;
	return 0;
}