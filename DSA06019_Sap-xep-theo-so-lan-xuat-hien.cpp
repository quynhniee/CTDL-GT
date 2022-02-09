#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;

int n;
vector<int> a;
vector<int> mark;
bool cmp (int x, int y) {
    if (mark[x] == mark[y])  return x < y;
    return mark[x] > mark[y];
}
void test () {
    cin >> n;
    int x;
    a.resize(n);
    mark.resize(1e5 + 5, 0);
    for (auto &i : a) {
        cin >> i;
        mark[i]++;
    }
    sort (a.begin(), a.end(), cmp);
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
    a.clear();
    mark.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        test ();
    return 0;
}