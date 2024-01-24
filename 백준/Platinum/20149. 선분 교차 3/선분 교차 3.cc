#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int INF = 2e9;
const int inf = 1e9;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pll A, B, C, D;

ll ccw(pll a, pll b, pll c) {
	ll ret =  (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}

bool isIntersect(pll a, pll b, pll c, pll d) {
	ll ab = ccw(a, b, c) * ccw(a, b, d);
	ll cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) { // 서로 평행하거나, 끝점만 만나거나 둘 중 하나 
		// 항상 a < b, c < d인 상황을 만들어줌 
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (c <= b && a <= d) return true; // 서로 겹치거나, 끝점만 만나거나 둘 중 하나 
		else return false;
	}
	else { // 기울기가 같지 않을 때
		if (ab <= 0 && cd <= 0) return true; // 서로 교차하거나, 선분 위에 한 점만 만나거나 
		else return false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> A.X >> A.Y >> B.X >> B.Y >> C.X >> C.Y >> D.X >> D.Y;
	if (isIntersect(A, B, C, D)) {
		double x = (A.X * B.Y - A.Y * B.X) * (C.X - D.X) - (A.X - B.X) * (C.X * D.Y - C.Y * D.X);
		double y = (A.X * B.Y - A.Y * B.X) * (C.Y - D.Y) - (A.Y - B.Y) * (C.X * D.Y - C.Y * D.X);
		double z = (A.X - B.X) * (C.Y - D.Y) - (A.Y - B.Y) * (C.X - D.X);
		if (z > 0 || z < 0) { // 교차함 
			cout << fixed;
			cout.precision(9);
			cout << 1 << '\n' << x / z << " " << y / z;
		}
		else { // 평행 
			if (A > B) swap(A, B);
			if (C > D) swap(C, D);
			if (B == C && A < C) cout << 1 << '\n' << B.X << " " << B.Y;
			else if (A == D && C < A) cout << 1 << '\n' << A.X << " " << A.Y;
			else cout << 1;
		}
	}
	else cout << 0;
	return 0;
}