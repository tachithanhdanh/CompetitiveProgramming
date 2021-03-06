#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vector
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

//http://www.usaco.org/index.php?page=viewproblem2&cpid=711
int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif // LOCAL
	freopen("crossroad.in","r",stdin);
	freopen("crossroad.out","w",stdout);
	int N; cin >> N;
	int state[11], ans = 0;;
	memset(state,-1,sizeof(state));
	F0R(i,N) {
		int id, side;
		cin >> id >> side;
		if (state[id]!=-1 && state[id]!=side) ++ans;
		state[id] = side;
	}
	cout << ans;
	return 0;
}
