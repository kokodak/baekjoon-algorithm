#include <bits/stdc++.h> 
using namespace std;

const int INF =  987654321;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k;
	cin >> k;
	int n = 1000 - k;
	vector<int> v = {500, 100, 50, 10, 5, 1};
	int cnt = 0;
	int idx = 0;
	while (1) {
		if (n == 0) break;
		if (n >= v[idx]) {
			n -= v[idx];
			cnt++;
		}
		else {
			idx++;
		}
	}
	cout << cnt;
	return 0;
}