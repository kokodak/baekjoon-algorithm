#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

const int INF = 987654321;
const int MAX = 32767;
const int MOD = 1000000000;

/*
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, less<int>> pqmax; //max heap
	priority_queue<int, vector<int>, greater<int>> pqmin; //min heap
	long long result = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k > 0) pqmax.push(k);
		else pqmin.push(k);
	}

	int q = pqmax.size();
	int w = pqmin.size();

	for (int i = 0; i < q; i++) {
		if (pqmax.empty()) break;

		if (pqmax.size() >= 2) {
			int a = pqmax.top();
			pqmax.pop();
			int b = pqmax.top();
			pqmax.pop();
			int pp = a + b;
			int gg = a * b;
			if (pp >= gg) result += pp;
			else result += gg;
		}

		else {
			result += pqmax.top();
			pqmax.pop();
		}
	}

	for (int i = 0; i < w; i++) {
		if (pqmin.empty()) break;

		if (pqmin.size() >= 2) {
			int a = pqmin.top();
			pqmin.pop();
			int b = pqmin.top();
			pqmin.pop();
			result += a * b;
		}

		else {
			result += pqmin.top();
			pqmin.pop();
		}
	}

	cout << result;
}