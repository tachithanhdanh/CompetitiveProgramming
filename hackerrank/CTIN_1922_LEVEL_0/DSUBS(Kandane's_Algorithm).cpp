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
#define trav(a,x) for (auto& a : x)

void setIO(string name = "") { 
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
	else{
		#ifdef LOCAL
		freopen("input.txt", "r", stdin);  
		freopen("output.txt", "w", stdout); 
		freopen("error.txt", "w", stderr);
		#endif 
	}
}

//constant initialization
const string yes="YES",no="NO";
const int mod=1e9+7;
const int maxn=2e5+10;
const ll INF = 1e18;

//variables used for the current problem
int n; ll a[maxn],best=-INF,sum=-INF;
int start,finish,temp_start,temp_finish;
//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
void solve(){
	cin >> n;
	F0R(i,n) {
		cin >> a[i]; //a[i]+=a[i-1];
	}
	F0R(i,n) {
		if (sum+a[i]<a[i]){
			sum = a[i];
			temp_start=temp_finish=i;
		}
		else{
			++temp_finish; sum+=a[i];
		}
		if (sum>best){
			best=sum; start=temp_start; finish=temp_finish;
		}
	}
	cout << ++start << " " << ++finish << endl << best;
	return;
}

int main() {
	setIO();
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}
