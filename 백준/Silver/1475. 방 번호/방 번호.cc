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

int cnt[10];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < 10; i++) cnt[i]++;
    while (n != 0) {
        int k = n % 10;
        n /= 10;
        if (cnt[k]) cnt[k]--;
        else {
            if (k == 6 && cnt[9]) cnt[9]--;
            else if (k == 9 && cnt[6]) cnt[6]--;
            else {
                for (int i = 0; i < 10; i++) cnt[i]++;
                ans++;
                cnt[k]--;
            }
        }
    }
    cout << ans;
	return 0;
}