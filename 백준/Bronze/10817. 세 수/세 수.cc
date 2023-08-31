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
	
	vector<int> v;
	for (int i = 0; i < 3; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	cout << v[1];
	
	return 0;
}