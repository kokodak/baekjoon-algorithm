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

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        double summ = 0;
        int arr[1001];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            summ += arr[i];
        }
        double avg = summ / n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > avg) {
                cnt++;
            }
        }
        cout << fixed;
        cout.precision(3);
        cout << round(cnt / (double) n * 100000) / 1000 << "%\n";
    }
	return 0;
}