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
	
	int a, b, c;
	cin >> a >> b >> c;
	double lo = 0.0;
	double hi = 100000.0;
	double mid;
	while (lo + 0.000000001 < hi) {
		mid = (lo + hi) / 2;
		double fx = a * mid + b * sin(mid);
		if (fx > c) {	
			hi = mid;
		}
		else if (fx < c) {
			lo = mid;
		}
	}
	cout.precision(19);
	cout << mid;
	return 0;
}