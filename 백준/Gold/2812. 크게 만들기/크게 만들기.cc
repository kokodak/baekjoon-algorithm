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
	
	int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v;
    v.push_back(s[0] - '0');
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        while (!v.empty()) {
            if (v.back() < s[i] - '0' && cnt != k) {
                cnt++;
                v.pop_back();
                continue;
            }
            break;
        }
        v.push_back(s[i] - '0');
    }
    int vSize = v.size();
    for (int i = 0; i < vSize - (k - cnt); i++) {
        cout << v[i];
    }
	return 0;
}