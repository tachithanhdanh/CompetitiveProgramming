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
int LIS[MX], maxlen;

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	//LIS DP (Easy version)
	//Time complexity: O(N^2)
	//Recursion formula: dp[i] = max(dp[i],dp[j]+1) for all j < i such that a[j] < a[i]
	int N;
	cin >> N;
	vi A(N);
	for (int& i : A) cin >> i;
	fill(all(LIS),1); //Initially, all value of LIS ending at i-th position is 1.
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j)
			if (A[j] < A[i]) ckmax(LIS[i],LIS[j]+1);
		ckmax(maxlen,LIS[i]);
	}
	cout << maxlen;
	return 0;
}
