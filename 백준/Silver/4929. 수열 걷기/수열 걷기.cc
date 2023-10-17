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
	
	while (1) {
		int arr1[10001] = {0,};
		int arr2[10001] = {0,};
		int cnt[20010] = {0,};
		int a;
		cin >> a;
		if (a == 0) break;
		for (int i = 0; i < a; i++) {
			cin >> arr1[i];
			cnt[arr1[i] + 10000]++;
			// cout << arr1[i] + 10000 << "qweqwe" << endl;
		}
		int b;
		cin >> b;
		for (int i = 0; i < b; i++) {
			cin >> arr2[i];
			cnt[arr2[i] + 10000]++;
		}
		vector<int> same;
		vector<int> v1;
		vector<int> v2;
		// cout << cnt[9999] << endl;
		for (int i = 0; i < 20001; i++) {
			if (cnt[i] == 2) same.push_back(i - 10000);
		}
		// cout << same.size();
		int sameSize = same.size();
		int summ = 0;
		for (int i = 0, idx = 0; i < a; i++) {
			if (sameSize != idx && same[idx] == arr1[i]) {
				v1.push_back(summ);
				idx++;
				summ = 0;
				if (i == a - 1) v1.push_back(0);
				continue;
			}
			summ += arr1[i];
			if (sameSize == idx && i == a - 1) {
				v1.push_back(summ);
				break;
			}
		}
		summ = 0;
		for (int i = 0, idx = 0; i < b; i++) {
			if (sameSize != idx && same[idx] == arr2[i]) {
				v2.push_back(summ);
				idx++;
				summ = 0;
				if (i == b - 1) v2.push_back(0);
				continue;
			}
			summ += arr2[i];
			if (sameSize == idx && i == b - 1) {
				v2.push_back(summ);
				break;
			}
		}
		// cout << v1.size() << " " << v2.size() << '\n';
		int ans = 0;
		for (int i = 0; i < sameSize + 1; i++) {
			ans += max(v1[i], v2[i]);
		}
		for (int i = 0; i < sameSize; i++) {
			ans += same[i];
		}
		cout << ans << '\n';
	}
	return 0;
}