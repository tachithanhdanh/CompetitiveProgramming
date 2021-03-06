#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x) 
#define sz(x) (int)(x).size()
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name =""){
//Compile with those flags and to get the fastest performance
//g++.exe -std=c++11 -DLOCAL ${file} -o ${file_base_name}.exe -Wl,--stack,268435456 -O2 && ${file_base_name}.exe
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	return;
}

//variables used for the current problem
int N,M,D,S,m,p,t,sick[51],possible[51],cnt,ans,badmilk; 
vector<vector<pair<int,int>>> v;
bool flag,milkflag[51];

int main(){
	setIO("badmilk");
	cin >> N >> M >> D >> S;
	v.resize(N+1);
	for (int i=0;i<D;++i){
		cin >> p >> m >> t;
		v[p].pb(mp(t,m));
	}
	for (int i=1;i<=N;++i){
		sort(all(v[i]));
	}
	for (int i=0;i<S;++i){
		cin >> p >> t;
		sick[p]=t;
	}
	for (int i=1;i<=N;++i){
		if (sick[i]){
			for (int j=1;j<=M;++j) milkflag[j]=false;
			for (int j=0;j<sz(v[i]);++j){
				if (v[i][j].f>=sick[i]) break;
				else {
					milkflag[v[i][j].s]=true;
				}
			}
			for (int j=1;j<=M;++j){
				possible[j]+=milkflag[j];
			}
		}
	}
	for (int i=1;i<=M;++i){
		if (possible[i]==S) {
			badmilk=i; break;
		}
	}
	for (int i=1;i<=N;++i){
		if (!sick[i]){
			flag=false;
			for (int j=0;j<sz(v[i]);++j){
				flag = (v[i][j].s == badmilk) || flag;
			}
			cnt+=flag;
		}
	}
	ans=max(ans,cnt);
	cout << S+ans;
	return 0;
}
