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

int mmap[1001][1001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
    cin >> n;
    int pro_x, pro_y;
    int sung_x, sung_y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 5) {
                pro_x = i;
                pro_y = j;
            }
            else if (mmap[i][j] == 2) {
                sung_x = i;
                sung_y = j;
            }
        }
    }
    int dist = (pro_x - sung_x) * (pro_x - sung_x) + (pro_y - sung_y) * (pro_y - sung_y);
	if (dist < 25) {
        cout << 0;
        return 0;
    }
    if (pro_x == sung_x) {
        int cnt = 0;
        for (int i = min(pro_y, sung_y) + 1; i < max(pro_y, sung_y); i++) {
            if (mmap[pro_x][i] == 1) cnt++;
        }
        if (cnt < 3) {
            cout << 0;
            return 0;
        }
    }
    else if (pro_y == sung_y) {
        int cnt = 0;
        for (int i = min(pro_x, sung_x) + 1; i < max(pro_x, sung_x); i++) {
            if (mmap[i][pro_y] == 1) cnt++;
        }
        if (cnt < 3) {
            cout << 0;
            return 0;
        }
    }
    else {
        int minX = min(pro_x, sung_x);
        int minY = min(pro_y, sung_y);
        int maxX = max(pro_x, sung_x);
        int maxY = max(pro_y, sung_y);
        int cnt = 0;
        for (int i = minX; i <= maxX; i++) {
            for (int j = minY; j <= maxY; j++) {
                if (mmap[i][j] == 2 || mmap[i][j] == 5) continue;
                if (mmap[i][j] == 1) cnt++;
            }
        }
        if (cnt < 3) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}