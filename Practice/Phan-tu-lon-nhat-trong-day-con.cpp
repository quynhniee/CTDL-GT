#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <deque>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<int> a;
int n, k;
void input () {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
}
void solution () {
    deque<int> pos;
    FOR (i, 0, n-1) {
        while (!pos.empty() && a[pos.back()] < a[i])
            pos.pop_back();
        pos.push_back(i);
        while (i - pos.front() >= k)    pos.pop_front();
        if (i >= k-1)   cout << a[pos.front()] << " ";
    }
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester() {
        input();
        solution();
    }
    return 0;
}