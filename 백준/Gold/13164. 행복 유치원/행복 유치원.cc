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

int arr[300001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> v;
    for (int i = 1; i < n; i++) {
        v.push_back(arr[i] - arr[i - 1]);
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for (int i = k - 1; i < n; i++) {
        ans += v[i];
    }
    cout << ans;
	return 0;
}