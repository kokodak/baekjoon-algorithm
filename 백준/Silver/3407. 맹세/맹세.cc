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

char c1[] = { 'h', 'b', 'c', 'n', 'o', 'f', 'p', 's', 'k', 'v', 'y', 'i', 'w', 'u' };

string c2[] = {
	"ba", "ca" , "ga", "la", "na", "pa", "ra", "ta", "db", "nb", "pb", "rb", "sb", "tb", "yb", "ac",
	"sc", "tc", "cd", "gd", "md", "nd", "pd", "be", "ce", "fe", "ge", "he", "ne", "re", "se", "te",
	"xe", "cf", "hf", "rf", "ag", "hg", "mg", "rg", "sg", "bh", "rh", "th", "bi", "li", "ni", "si",
	"ti", "bk", "al", "cl", "fl", "tl", "am", "cm", "fm", "pm", "sm", "tm", "cn", "in", "mn", "rn",
	"sn", "zn", "co", "ho", "mo", "no", "po", "np", "ar", "br", "cr", "er", "fr", "ir", "kr", "lr",
	"pr", "sr", "zr", "as", "cs", "ds", "es", "hs", "os", "at", "mt", "pt", "au", "cu", "eu", "lu",
	"pu", "ru", "lv", "dy"
	};

bool dp[50001][3]; // i번째 단어까지 발음할 수 있는가?

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        string s;
        cin >> s;
        int sSize = s.size();
        for (int i = 0; i < 14; i++) {
            if (s[0] == c1[i]) {
                dp[0][0] = true;
                break;
            }
        }
        for (int i = 0; i < 14; i++) {
            if (s[1] == c1[i]) {
                dp[1][0] = true;
                break;
            }
        }
        string tmp = "";
        tmp.push_back(s[0]);
        tmp.push_back(s[1]);
        for (int j = 0; j < 100; j++) {
            if (tmp == c2[j]) {
                dp[1][1] = true;
                dp[0][2] = true;
                break;
            }
        }
        for (int i = 2; i < sSize; i++) {
            for (int j = 0; j < 14; j++) {
                if (s[i] == c1[j]) {
                    dp[i][0] = true;
                    break;
                }
            }
            tmp = "";
            tmp.push_back(s[i - 1]);
            tmp.push_back(s[i]);
            for (int j = 0; j < 100; j++) {
                if (tmp == c2[j]) {
                    if (dp[i - 2][0] || dp[i - 2][1]) {
                        dp[i][1] = true;
                        dp[i - 1][2] = true;
                    }
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < sSize; i++) {
            if (!dp[i][0] && !dp[i][1] && !dp[i][2]) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
	return 0;
}