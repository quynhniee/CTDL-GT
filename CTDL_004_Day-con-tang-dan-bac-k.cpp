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
int n, k, cou;
vector<int>a, ans;
void input () {
    cin >> n >> k;
    a.resize(n + 1);
    ans.resize(k + 1);
    for (int i = 1; i <= n; i++)   cin >> a[i];
}
void output () {
    for (auto i : ans)  cout << i << " ";
        cout << endl;
}
bool check () {
    for (int i = 1; i < k; i++)
        if (ans[i + 1] < ans[i])    return false;
    return true;
}
// sinh tổ hợp chập k của n phần tử
void backtrack (int start, int i) {
    if (i > k) {
        if (check())    ++cou;
        return;
    }
    for (int j = start + 1; j <= n - k + i; j++) {
        start = j;
        ans[i] = a[j];
        backtrack(start, i + 1);  
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cou = 0;
    input();
    backtrack(0, 1);
    cout << cou << endl;
    return 0;
}