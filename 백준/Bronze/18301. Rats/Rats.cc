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
	
	int a, b, c;
	cin >> a >> b >> c;
	int k = ((a + 1) * (b + 1) / (c + 1)) - 1;
	k = floor(k);
	cout << k;
	
	return 0;
}