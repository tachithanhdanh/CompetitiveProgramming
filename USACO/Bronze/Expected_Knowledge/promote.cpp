#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cstring>
#include <fstream>
#include <vector>
#include <iterator>
#include <typeinfo>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <utility>

#define endl "\n"
#define pub push_back
#define pob pop_back
#define ins insert
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef short int si;

int a,b,c,d,e,f,g,h;

void solve(){ //http://www.usaco.org/index.php?page=viewproblem2&cpid=591
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    cout << h-g+f-e+d-c << endl << h-g+f-e << endl << h-g;
    return;
}

int main(){
    //Read input from STDIN, then print the output to STDOUT.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);
    //cin >> t; 
    //while (t--) {
        //cout << "Case #" << ++cnt << ": "; 
        solve();
    //}
    return 0;
}

