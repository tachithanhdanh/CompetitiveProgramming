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
const int MX = 2e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int N, nodes[MX], relorder[MX], inputorder[MX], ans[MX], index;
vi adj[MX];
bool visited[MX];

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < N; ++i) {
		cin >> inputorder[i];
		relorder[inputorder[i]] = i;
	}
	for (int i = 1; i <= N; ++i) {
		sort(all(adj[i]),[](const int& u, const int& v){
			return relorder[u] < relorder[v];
		});
	}
	queue<int> q;
	q.push(1);
	ans[index++] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		visited[node] = true;
		for (int& u : adj[node]) {
			if (!visited[u]) {
				ans[index++] = u;
				q.push(u);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		if (inputorder[i] != ans[i]) return cout << no, 0;
	}
	cout << yes;
	return 0;
}
// Problem statment: https://codeforces.com/contest/1037/problem/D
// Official Editorial: https://codeforces.com/blog/entry/61606