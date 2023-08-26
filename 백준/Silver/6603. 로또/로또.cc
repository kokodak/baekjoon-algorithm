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

vector<int> nums;
vector<int> ans;
int k;

void go(int idx, int size) {
    // go(idx, size) = 현재 nums[idx] 값부터 ans 리스트에 넣을 예정인 상태. 또한, ans 의 사이즈는 size 이다.
    // 기저 조건
    if (size == 6) {
        for (int i = 0; i < size; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = idx; i < k; i++) {
        ans.push_back(nums[i]);
        go(i + 1, size + 1);
        ans.pop_back();
    }
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (1) {
        nums.clear();
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++) {
            int n;
            cin >> n;
            nums.push_back(n);
        }
        go(0, 0);
        cout << '\n';
    }
	return 0;
}