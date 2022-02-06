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
typedef struct {
    db c, v;
} data;
vector<data> bag;
int n;
db max_v;
void init () {
    cin >> n >> max_v;
    bag.resize(n);
    for (auto &i : bag) cin >> i.v;
    for (auto &i : bag) cin >> i.c;
}
bool cmp (data a, data b) {
    return (a.c / a.v) > (b.c / b.v);
}
int value (int pos, db val, db volume) {
    if (volume > max_v) return 0;
    else if (pos == n)  return val;
    int choose = value(pos + 1, val + bag[pos].c, volume + bag[pos].v);
    int not_choose = value(pos + 1, val, volume);
    return max(choose, not_choose);
}
void solution () {
    init();
    sort(bag.begin(), bag.end(), cmp);
    cout << value(0, 0, 0) << endl;
    bag.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}