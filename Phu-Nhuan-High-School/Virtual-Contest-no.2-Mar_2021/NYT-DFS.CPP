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
		freopen((name+".INP").c_str(), "r", stdin); // see /general/io
		freopen((name+".OUT").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 3e4+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
vi adj[MX];
bool visited[MX];

void dfs(int node) {
	visited[node] = true;
	for (int& u : adj[node]) {
		if (!visited[u]) dfs(u);
	}
	return;
}

int main() {
	setIO("NYT");
	int N, T;
	cin >> N >> T;
	for (int i = 1; i <= N - 1; ++i) {
		int a;
		cin >> a;
		adj[i].pb(a+i);
	}
	dfs(1);
	cout << (visited[T] ? yes : no);
	return 0;
}
