#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rsz resize
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7; //998244353
const int maxn=1e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int K, N, pos;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	cin >> K;
	N = 1;
	while (N < K) { N <<= 1; ++pos; }
	cout << N << " ";
	F0R(i,pos+1) if ((1<<i)&K) { cout << pos - i; break; }
	return 0;
}
