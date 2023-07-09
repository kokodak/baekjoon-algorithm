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
	
    int n, k;
    cin >> n >> k;
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) cout << 30;
    else cout << 29;
	return 0;
}