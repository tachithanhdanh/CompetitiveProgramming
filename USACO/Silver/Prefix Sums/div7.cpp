#include <bits/stdc++.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <iterator>
#include <ctime>
#include <tuple>
#include <numeric>
 
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;

#define ar array
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map

//vector
#define vt vector
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pf push_front
#define ft front()
#define bk back()
#define ins insert
#define lb lower_bound
#define up upper_bound

//pairs and tuples
#define f first
#define s second
#define mp make_pair
#define mtp make_tuple

void setIO(string name =""){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifdef LOCAL1 
		freopen("input.txt", "r", stdin);  
		freopen("output.txt", "w", stdout); 
		freopen("error.txt", "w", stderr);
		#endif 
	}
	return;
}

int pre[50050],n,cur,ans; map<int,int> a;

void solve(){
	cin >> n;
	for (int i=1;i<=n;++i){
		cin >> cur;
		pre[i]=(pre[i-1]%7+cur%7)%7;
	}
	for (int i=1;i<=n;++i){
		if (a.count(pre[i])==0){
			a[pre[i]]=i;
		}
		else{
			ans=max(ans,i-a[pre[i]]);
		}
	}
	cout << ans;
	//cout << 0;
}
// you should actually read the stuff below
// read!read!read!read!read!read!read!read!read!
// ll vs. int!
 
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
*/
int main(){
	//string name="rental";
	string name="div7";
	setIO(name);
	//cout.tie(NULL);
	//generate();
	//cin >> t;
	//while (t--)
	solve();
	#ifdef LOCAL1
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	#endif
	return 0;
}