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
	
	int s, c;
    cin >> s >> c;
    ll summ = 0;
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
        summ += arr[i];
    }
    ll lo = 1;
    ll hi = 1e9;
    ll mid;
    while (lo <= hi) {
        mid = (lo + hi) >> 1; // 파의 길이
        int tmp = 0;
        for (int i = 0; i < s; i++) {
            tmp += arr[i] / mid;
        }
        if (tmp >= c) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << summ - (hi * c);
	return 0;
}