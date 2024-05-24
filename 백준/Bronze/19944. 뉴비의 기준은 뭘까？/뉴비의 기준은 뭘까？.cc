#include <bits/stdc++.h> 
using namespace std;

const int INF = 2e9;
const int inf = 1e9;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	if (m == 1 || m == 2) cout << "NEWBIE!";
	else {
		if (m <= n) cout << "OLDBIE!";
		else {
			cout << "TLE!";
		}
	}
	
	return 0;
}