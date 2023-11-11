#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	if (k >= 90) cout << 'A';
	else if (k >= 80) cout << 'B';
	else if (k >= 70) cout << 'C';
	else if (k >= 60) cout << 'D';
	else cout << 'F';
	return 0;
}