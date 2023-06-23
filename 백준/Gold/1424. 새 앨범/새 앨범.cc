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
	
	int n, l, c;
    cin >> n >> l >> c;
    int x = (c + 1) / (l + 1); // cd 하나에 수록하는 최대 곡 수
    if (x % 13 == 0) x--;
    if (n < x && n % 13 == 0) cout << 2; 
    else if (n % x == 0) cout << n / x;
    else if ((n % x) % 13 == 0 && (n % x) + 1 == x) cout << n / x + 2;
    else cout << n / x + 1;
	return 0;
}
