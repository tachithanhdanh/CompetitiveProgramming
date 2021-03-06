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
const int prime[] = {2, 3, 5, 7}; // prime numbers below 10.

//variables used for the current problem
int N;
ll num;
vector<ll> ans;

bool primality_check() {
	if (num < 2) return false;
	if (num == 2 || num == 3 || num == 5 || num == 7) return true;
	if (!(num&1) || num%3 == 0) return false;
	for (ll i = 5, t = 2; i * i <= num; i += t, t = 6 - t)
		if (num % i == 0) return false;
	return true;
}

void dfs(int k) {
	if (k == N) {
		if (primality_check()) {
			ans.pb(num);
		}
		return;
	}
	if (k && !primality_check()) return;
	for (int i = 1; i <= 9; i += 2) {
		num *= 10;
		num += i;
		dfs(k+1);
		num /= 10;
	}
	return;
}

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	for (int i = 0; i < 4; ++i) {
		num = prime[i];
		dfs(1);
	}
	cout << sz(ans) << endl;
	for (ll& res : ans) cout << res << " ";
	//cout << endl;
	/*
	for (int i = 1; i <= (int)1e6; ++i) {
		int n = i;
		while (primality_check(n)) {
			n /= 10;
		}
		if (!n) cout << i << " ";
	}
	*/
	return 0;
}
