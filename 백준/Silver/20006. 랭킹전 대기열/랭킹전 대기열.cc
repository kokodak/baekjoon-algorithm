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

struct A {
	int level;
	string name;
};

struct R {
	int level;
	int cnt;
	vector<A> a;
};

vector<R> r; // 방

bool cmp(A a, A b) {
	return a.name < b.name;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int p, m;
	cin >> p >> m;
	for (int i = 0; i < p; i++) {
		int l;
		string n;
		cin >> l >> n;
		bool flag = false;
		for (int j = 0; j < r.size(); j++) {
			if (r[j].cnt >= m) continue;
			if (r[j].level + 10 < l || r[j].level - 10 > l) continue;
			r[j].a.push_back({l, n});
			r[j].cnt++;
			flag = true;
			break;
		}
		if (!flag) {
			vector<A> v;
			v.push_back({l, n});
			r.push_back({l, 1, v});
		}
	}
	for (int i = 0; i < r.size(); i++) {
		if (r[i].cnt != m) cout << "Waiting!\n";
		else cout << "Started!\n";
		vector<A> aa = r[i].a;
		sort(aa.begin(), aa.end(), cmp);
		for (int j = 0; j < aa.size(); j++) {
			cout << aa[j].level << " " << aa[j].name << '\n';
		}
	}
	return 0;
}