#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long
#define endl "\n"

ll x[4],y[4],a,b,c,d,ans;

void solve(){
	for (int i=0;i<4;++i){
		cin >> x[i] >> y[i];
	}
	a=min(x[0],x[2]); b=min(y[0],y[2]); c=max(x[1],x[3]); d=max(y[1],y[3]);
	ans=max((c-a)*(c-a),(d-b)*(d-b));
	cout << ans;
}

int main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    solve();
    return 0;
}
