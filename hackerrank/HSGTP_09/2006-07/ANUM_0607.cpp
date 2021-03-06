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

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7; //998244353
const int maxn=2e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    auto check = [](const int &n){
        int sum = 0;
        for (int i = 1; i*i <= n; ++i) {
            if (n%i==0) {
                sum += i;
                if (i*i != n) sum += n/i;
            }
        }
        return sum > n + n;
    };
    while (check(n) == false) ++n;
    cout << n;
    return 0;
}
