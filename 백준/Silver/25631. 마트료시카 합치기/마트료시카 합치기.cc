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

int arr[1001];
bool visited[1001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    int ans = 0;
    while (1) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            idx = i;
            break;
        }
        if (idx == -1) break;
        int val = arr[idx];
        visited[idx] = true;
        for (int j = idx + 1; j < n; j++) {
            if (visited[j]) continue;
            if (arr[j] == val) continue;
            visited[j] = true;
            val = arr[j];
        }
        ans++;
    }
    cout << ans;
	return 0;
}