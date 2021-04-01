#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

//for printing variables when debugging
#ifdef LOCAL
#define debug(x) cout << (#x) << " is " << (x) << endl
#else
#define debug(x)
#endif // LOCAL

//Set min-max value.
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int dp[55][55];
vi v;

void dfs(int N, int pre) {
	if (N == 0) {
		for (int& i : v) cout << i << " ";
		cout << endl;
		return;
	}
	for (int i = pre; i <= N; ++i) {
		v.pb(i);
		dfs(N-i,i);
		v.pop_back();
	}
	return;
}

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int N;
	cin >> N;
	dfs(N,1);
	//dp[0][0] = 1;
	//for (int i = 1; i <= 50; ++i) for (int j = 1; j <= 50; ++j) {
	//	if (j - i >= 0) dp[i][j] += dp[i][j-i] + dp[i-1][j-i];
	//	dp[i][j] += dp[i-1][j];
	//}
	//cout << dp[50][50] << endl;
	return 0;
}