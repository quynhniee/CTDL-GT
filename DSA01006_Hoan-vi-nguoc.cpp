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

vector<int> a;
int n;

void init () {
    cin >> n ;
    a.resize(n);
    for (int i = 0; i < n; i++)    a[i] = n - i;
}
void output () {
    for (auto i : a)    cout << i;
    cout << " ";
}
void test () {
    do  output();   
    while (prev_permutation(a.begin(), a.end()));
    a.clear();
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        init();
        test();
    }
    return 0;
}