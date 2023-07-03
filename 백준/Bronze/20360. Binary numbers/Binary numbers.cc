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
    for (int i = 0; i < (int) log2(n) + 2; i++) {
        int bit = 1;
        if (n & bit << i) cout << i << " ";
    }
	return 0;
}