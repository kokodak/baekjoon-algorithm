#include <bits/stdc++.h> 
using namespace std;

const int INF =  987654321;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

int gcd(int a, int b){
	while (b != 0){
		int k = a % b;
		a = b;
		b = k;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}
	
	return 0;
}