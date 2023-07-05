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

int arr[100001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll lo = 1;
    ll hi = 1e9;
    ll mid;
    while (lo <= hi) {
        mid = (lo + hi) >> 1; // 인출 금액
        ll tmp = mid;
        ll cnt = 1;
        for (int i = 0; i < n; i++) {
            if (mid < arr[i]) {
                cnt = inf;
                break;
            }
            if (tmp < arr[i]) {
                cnt++;
                tmp = mid;
            }
            tmp -= arr[i];
        }
        if (cnt > m) { // 인출 금액 높이기
            lo = mid + 1;
        }
        else { // 인출 금액 낮추기
            hi = mid - 1;
        }
    }
    cout << lo;
    return 0;
}