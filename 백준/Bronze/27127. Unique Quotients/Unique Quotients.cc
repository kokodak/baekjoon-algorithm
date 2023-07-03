#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e18;
const int inf = 2e9;
const int SIZE = 1 << 18;
const int MOD = 1e9 + 7;

vector<int> v;
int n;
int nth = 0;
bool visited[10];

void go(int depth) {
    if (depth == 10) {
        int a = 0;
        for (int i = 0; i < 5; i++) {
            a *= 10;
            a += v[i];
        }
        int b = 0;
        for (int i = 5; i < 10; i++) {
            b *= 10;
            b += v[i];
        }
        if (a % b == 0 && a / b == 9) nth++;
        if (nth == n) {
            for (int i = 0; i < 5; i++) {
                cout << v[i];
            }
            cout << " ";
            for (int i = 5; i < 10; i++) {
                cout << v[i];
            }
            nth++;
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (depth == 0 && i < 5) continue;
        if (visited[i]) continue;
        v.push_back(i);
        visited[i] = true;
        go(depth + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    cin >> n;
    go(0);
	return 0;
}