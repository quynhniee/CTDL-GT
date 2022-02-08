#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, m;
void output (set<int> x) {
    for (auto i : x)  cout << i << " ";
    cout << endl;
}
void test () {
    set<int> uni, inter;
    cin >> n >> m;
    int i;
    while (n--) {
        cin >> i;
        uni.insert(i);
    }
    int size;
    while (m--) {
        cin >> i;
        size = uni.size();
        uni.insert(i);
        if (size == uni.size()) inter.insert(i);
    }
    output(uni), output(inter);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        test();
    }
    return 0;
}