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

double arr[10001];
double dp[10001][2];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // dp[i][j] = i번째까지 연속 곱의 최대, i번째 포함/미포함
    // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
    // dp[i][1] = max(arr[i], dp[i - 1][1] * arr[i])
    dp[0][0] = 0;
    dp[0][1] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(arr[i], dp[i - 1][1] * arr[i]);
    }
    double ans = max(dp[n - 1][0], dp[n - 1][1]);
    cout << fixed;
    cout.precision(3);
    cout << ans;
	return 0;
}