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

int _gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        int gcd = _gcd(a, b);
        cout << (a * b) / gcd << " " << gcd << '\n';
    }
	return 0;
}