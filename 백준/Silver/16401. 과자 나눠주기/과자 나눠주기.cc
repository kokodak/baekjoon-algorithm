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

int arr[1000001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int lo = 0;
    int hi = 1e9;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) >> 1; // 막대 과자 길이
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mid == 0) {
                cnt = inf;
                break;
            }
            if (arr[i] >= mid) cnt += arr[i] / mid;
        }
        if (cnt >= m) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << hi;
	return 0;
}