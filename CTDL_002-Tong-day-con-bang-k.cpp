#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<int> a, vs;
vector< vector<int> > ans;
int n, k;
void calculate () {
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (vs[i])  sum += a[i];
    if (sum == k)   ans.push_back(vs);
}
void backtracking (int i) {
    for (int j = 0; j <= 1; j++) {
        vs[i] = j;
        if (i == n - 1) calculate();
        else    backtracking(i + 1);
    }
}
void solution () {
    cin >> n >> k;
    a.resize(n);
    vs.resize(n);
    for (auto &i : a)   cin >> i;
    backtracking(0);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++)
            if (ans[i][j])  cout << a[j] << " ";
        cout << endl;
    }
    cout << ans.size() << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}