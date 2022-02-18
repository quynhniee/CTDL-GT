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
vector<int> c;
vector<string> name;
int n, k;
void init () {
    cin >> n >> k;
    set<string> a;
    string temp;
    FOR (i, 0, n-1) {
        cin >> temp;
        a.insert(temp);
    }
    for (auto i : a)    {
        name.push_back(i);
    }
    n = a.size();
    c.resize(k + 1);
    FOR (i, 1, k)   c[i] = i;
}
void output () {
    FOR (i, 1, k) cout << name[c[i] - 1] << " ";
    cout << endl;
}
void combination (int i) {
    FOR (j, c[i-1] + 1, n - k + i) {
        c[i] = j;
        if (i == k) {
            output();
        } 
        else    combination(i + 1);
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    combination(1);
    c.clear();
    name.clear();
    return 0;
}