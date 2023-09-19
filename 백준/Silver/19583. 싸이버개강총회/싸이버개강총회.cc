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
	
	string s, e, q;
    cin >> s >> e >> q;
    set<string> s1, s2;
    vector<string> v;
    while (!cin.eof()) {
        string time, name;
        cin >> time >> name;
        if (time <= s) {
            if (s1.find(name) == s1.end()) v.push_back(name);
            s1.insert(name);
        }
        else if (time >= e && time <= q) s2.insert(name);
    }
    int vSize = v.size();
    int ans = 0;
    for (int i = 0; i < vSize; i++) {
        if (s2.find(v[i]) != s2.end()) ans++;
    }
    cout << ans;
	return 0;
}