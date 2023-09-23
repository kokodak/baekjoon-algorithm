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

struct A {
    ll s;
    ll l;
    ll o;
};

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, g, k;
    cin >> n >> g >> k;
    vector<A> v;
    for (int i = 0; i < n; i++) {
        ll s, l, o;
        cin >> s >> l >> o;
        v.push_back({s, l, o});
    }
    ll lo = 0;
    ll hi = 2e9;
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        // mid: x일 지남
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll summ = 0;
        for (int i = 0; i < n; i++) {
            ll aa = (ll) v[i].s * max((ll) 1, (ll) mid - v[i].l);
            summ += aa;
            if (v[i].o == 0) continue;
            if (pq.size() < k) pq.push(aa);
            else {
                if (!pq.empty() && pq.top() < aa) {
                    pq.pop();
                    pq.push(aa);
                }
            }
        }
        while (!pq.empty()) {
            summ -= pq.top();
            pq.pop();
        }
        if (summ <= g) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << hi;
	return 0;
}