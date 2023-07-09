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
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({b, c});
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].Y);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        int endTime = pq.top();
        if (v[i].X >= endTime) pq.pop();
        pq.push(v[i].Y);
        ans = max(ans, (int) pq.size());
    }
    cout << ans;
	return 0;
}