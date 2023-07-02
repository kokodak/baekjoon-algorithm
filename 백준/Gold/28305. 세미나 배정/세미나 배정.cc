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

int arr[200001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int lo = 1;
    int hi = n;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) >> 1; // 회의실 개수
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        bool ok = true;
        for (int i = 0; i < mid; i++) {
            pq.push(0);
        }
        for (int i = 0; i < n; i++) {
            int endTime = pq.top();
            if (endTime >= arr[i]) {
                ok = false;
                break;
            }
            pq.pop();
            pq.push(max(arr[i], endTime + t));
        }
        if (ok) hi = mid - 1; // 가능할 경우 회의실 줄이기
        else lo = mid + 1; // 안될 경우 회의실 늘리기
    }
    cout << lo;
	return 0;
}