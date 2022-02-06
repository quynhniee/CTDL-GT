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
void solution () {
    string s;
    cin >> s;
    int i = s.size() - 1;
    while (s[i] == '1') 
        --i;
    if (i >= 0) s[i] = '1';
    for (int j = i + 1; j < s.size(); j++)
        s[j] = '0';
    cout << s << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solution ();
    return 0;
}