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
const int MOD = 1e9;

int arr[10001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (j == n - 1) continue;
            int target = -(arr[i] + arr[j]);
            ans += upper_bound(arr + j + 1, arr + n, target) - lower_bound(arr + j + 1, arr + n, target);
        }
    }
    cout << ans;
    return 0;
}