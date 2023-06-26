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

int dp[61][61][61];

int cache(int a, int b, int c) { // 각각 체력이 a, b, c일때 모두 파괴되기 위한 공격의 최소 횟수
    if (a <= 0 && b <= 0 && c <= 0) return 0;
    if (a < 0) a = 0;
    if (b < 0) b = 0;
    if (c < 0) c = 0;
    int& ret = dp[a][b][c];
    if (ret != -1) return ret;
    int ans1 = min(cache(a - 1, b - 9, c - 3), cache(a - 1, b - 3, c - 9));
    int ans2 = min(cache(a - 3, b - 1, c - 9), cache(a - 3, b - 9, c - 1));
    int ans3 = min(cache(a - 9, b - 3, c - 1), cache(a - 9, b - 1, c - 3));
    return ret = min(min(ans1, ans2), ans3) + 1;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    int arr[3] = {0,};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << cache(arr[0], arr[1], arr[2]);
	return 0;
}