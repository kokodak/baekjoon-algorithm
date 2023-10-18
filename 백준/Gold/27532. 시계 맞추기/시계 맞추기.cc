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

string addTime(string time, int t) {
	int hour = 0;
	hour += 10 * (time[0] - '0');
	hour += (time[1] - '0');
	int minute = 0;
	minute += 10 * (time[3] - '0');
	minute += (time[4] - '0');
	minute += hour * 60;
	minute += t;
	int nHour = (minute / 60) % 12;
	if (nHour == 0) nHour = 12;
	int nMinute = minute % 60;
	string ret = "";
	if (nHour < 10) {
		ret.push_back('0');
		ret.push_back('0' + nHour);
	}
	else {
		ret.push_back('1');
		ret.push_back('0' + (nHour % 10));
	}
	ret.push_back(':');
	ret.push_back('0' + (nMinute / 10));
	ret.push_back('0' + (nMinute % 10));
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	string arr[1501];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = inf;
	for (int i = 1; i <= 720; i++) {
		set<string> ss;
		for (int j = n - 1; j >= 0; j--) {
			string time = arr[j];
			string nTime = addTime(time, i * (n - 1 - j));
			ss.insert(nTime);
		}
		ans = min(ans, (int) ss.size());
	}
	cout << ans;
	return 0;
}