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
    string s;
    cin >> s;
    string exp;
    cin >> exp;
    int ans1 = 0, ans2 = 0;
    string tmp = s;
    for (int i = 1; i < n; i++) {
        if (tmp[i - 1] == exp[i - 1]) continue;
        tmp[i - 1] = tmp[i - 1] == '0' ? '1' : '0';
        tmp[i] = tmp[i] == '0' ? '1' : '0';
        tmp[i + 1] = tmp[i + 1] == '0' ? '1' : '0';
        ans1++;
    }
    if (exp != tmp) ans1 = inf;
    tmp = s;
    tmp[0] = tmp[0] == '0' ? '1' : '0';
    tmp[1] = tmp[1] == '0' ? '1' : '0';
    ans2++;
    for (int i = 1; i < n; i++) {
        if (tmp[i - 1] == exp[i - 1]) continue;
        tmp[i - 1] = tmp[i - 1] == '0' ? '1' : '0';
        tmp[i] = tmp[i] == '0' ? '1' : '0';
        tmp[i + 1] = tmp[i + 1] == '0' ? '1' : '0';
        ans2++;
    }
    if (exp != tmp) ans2 = inf;
    int ans = min(ans1, ans2);
    if (ans == inf) cout << -1;
    else cout << ans;
	return 0;
}