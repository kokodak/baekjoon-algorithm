#include <bits/stdc++.h> 
using namespace std;

const int INF = 2e9;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (1) {
		string name;
		int a, w;
		cin >> name >> a >> w;
		if (name == "#" && a == 0 && w == 0) break;
		if (a > 17 || w >= 80) cout << name << " Senior\n";
		else cout << name << " Junior\n";
	}
	
	return 0;
}