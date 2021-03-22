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
const int MX = 1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int N, a[MX], b[MX], c;
set<int> inc;
set<int,greater<int>> dcr;

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i] >> b[i];
	}
	cin >> c;
	for (int i = 0; i < N; ++i) {
		if (a[i] > 0) inc.insert((c - b[i]) / a[i]);
		else dcr.insert((c - b[i]) / a[i]);
	}
	for (int i = 0; i < N; ++i) if (a[i]) {
		int root = (c - b[i]) / a[i];
		auto it1 = inc.upper_bound(root);
		auto it2 = dcr.upper_bound(root);
		if (it1 != inc.end() || it2 != dcr.end()) continue;
		else { cout << root; return 0; }
	}
	cout << "NO SOLUTION";
	return 0;
}