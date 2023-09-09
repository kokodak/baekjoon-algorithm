#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int inf = 1e9;

vector<long long> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	long long ans = 2e10;
	int ans1, ans2, ans3;
	for (int i = 0; i < n; i++) {
		int s = 0, e = v.size() - 1;
		while (s < e) {
			if (s == i) s++;
			if (e == i) e--;
			if (s >= e) break;
			long long tmp = v[s] + v[e];
			if (ans > abs(-tmp - v[i])) {
				ans1 = v[i];
				ans2 = v[s];
				ans3 = v[e];
				ans = abs(-tmp - v[i]);
			}
			if (tmp > -v[i]) e--;
			else s++;
		}
	}
	//cout << ans1 << ans2 << ans3 << endl;
	vector<int> vv;
	vv.push_back(ans1);
	vv.push_back(ans2);
	vv.push_back(ans3);
	sort(vv.begin(), vv.end());
	cout << vv[0] << " " << vv[1] << " " << vv[2];
	return 0;
}