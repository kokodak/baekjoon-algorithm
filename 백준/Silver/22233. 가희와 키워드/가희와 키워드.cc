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

bool visited[200001];

vector<string> split(string s, char delimiter) {
    vector<string> answer;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, delimiter)) {
        answer.push_back(tmp);
    }
    return answer;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
    cin >> n >> m;
    map<string, int> s;
    for (int i = 0; i < n; i++) {
        string ss;
        cin >> ss; 
        s.insert({ss, i});
    }
    int ans = n;
    for (int i = 0; i < m; i++) {
        string ss;
        cin >> ss;
        vector<string> v = split(ss, ',');
        int vSize = v.size();
        for (int j = 0; j < vSize; j++) {
            auto it = s.find(v[j]);
            if (it == s.end()) continue;
            if (visited[it->Y]) continue;
            ans--;
            visited[it->Y] = true;
        }
        cout << ans << '\n';
    }
	return 0;
}