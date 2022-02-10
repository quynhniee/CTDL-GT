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
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;

vector<int> a;
int n, k;
void input () {
    cin >> n >> k;
    a.resize(n);
    for (auto &i : a)   cin >> i;
}
void test () {
    input ();
    deque <int> pos;
    for (int i = 0; i < n; i++) {
        while (!pos.empty() && a[pos.back()] < a[i])   
            pos.pop_back();
        pos.push_back(i);
        while (i - pos.front() >= k) pos.pop_front();
        if (i >= k - 1)  cout << a[pos.front()] << " ";
    }
    cout << endl;
    a.clear();
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