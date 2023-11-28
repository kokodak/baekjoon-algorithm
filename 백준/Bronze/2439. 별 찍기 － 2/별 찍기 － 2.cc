#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int INF = 9999999;
const int MAX = 1000001;
const int MOD = 1000000000;

/*
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}