#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;

typedef struct {
	int fi, se, w;
} data; 

vector<data> E;
vector<int> parent;
int n, e, dH;
void init () {
	cin >> n >> e; dH = 0;
	E.assign (e, {0, 0, 0}); 
	for (auto &i:E) 
		cin >> i.fi >> i.se >> i.w;
}
bool cmp (data a, data b) {
	if (a.w == b.w)	
		if (a.fi == b.fi)	return a.se < b.se;
		else	return a.fi < b.fi;
	return a.w < b.w;
}
int root (int u) {
	while (parent[u] != -1)
		u = parent[u];
	return u;
}
void Kruskal () {
	parent.assign (n+1, -1);
	sort (E.begin(), E.end(), cmp);
	for (auto i:E) {
		int u = root(i.fi), v = root(i.se);
		if (u != v) {
			dH += i.w;
			(u < v) ? parent[v] = u : parent[u] = v;
		}
	}
	cout << dH << endl;
}
void test_case () {
	init ();
	Kruskal();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()	test_case();
    return 0;
}

