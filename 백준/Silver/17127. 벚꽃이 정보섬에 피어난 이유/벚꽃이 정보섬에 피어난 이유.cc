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
	int arr[11];
	for (int i = 0; i < n; i++) cin >> arr[i];
	int maxx = -inf;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int a1 = 1, a2 = 1, a3 = 1, a4 = 1;
				for (int idx = 0; idx < i; idx++) {
					a1 *= arr[idx];
				}
				for (int idx = i; idx < j; idx++) {
					a2 *= arr[idx];
				}
				for (int idx = j; idx < k; idx++) {
					a3 *= arr[idx];
				}
				for (int idx = k; idx < n; idx++) {
					a4 *= arr[idx];
				}
				maxx = max(maxx, a1 + a2 + a3 + a4);
			}
		}
	}
	cout << maxx;
	return 0;
}