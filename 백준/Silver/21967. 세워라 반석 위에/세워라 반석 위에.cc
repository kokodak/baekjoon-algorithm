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

int arr[1000000];
int A[11];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = -inf;
    int minn, maxx;
    A[arr[0]]++;
    for (int l = 0, r = 0; l < n && r < n;) {
        for (int i = 1; i <= 10; i++) {
            if (A[i] != 0) {
                minn = i;
                break;
            }
        }
        for (int i = 10; i >= 1; i--) {
            if (A[i] != 0) {
                maxx = i;
                break;
            }
        }
        if (maxx - minn <= 2) {
            ans = max(ans, r - l + 1);
            r++;
            A[arr[r]]++;
        }
        else {
            A[arr[l]]--;
            l++;
        }
    }
    cout << ans;
	return 0;
}