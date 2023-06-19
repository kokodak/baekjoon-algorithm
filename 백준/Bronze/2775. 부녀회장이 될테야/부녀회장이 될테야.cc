#include <bits/stdc++.h> 
using namespace std;

const int INF =  987654321;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

int apart[15][15];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--){
		int n, k;
		cin >> k >> n;
		
		
		for (int i = 1; i <= n; i++){
			apart[0][i] = i;
		}
		
		for (int i = 1; i <= k; i++){
			for (int j = 1; j <= n; j++){
				int p = 0;
				for (int k = 1; k <= j; k++){
					p += apart[i - 1][k];
				}
				apart[i][j] = p;
			}
		}
	
		cout << apart[k][n] << "\n";
	}
	return 0;
}