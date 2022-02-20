#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string gray;
// Eg: b2=g2, b1=g1⊕g2, and b0=g0⊕g1⊕g2.
// bn=gn, b(n-1)=g(n-1)⊕gn, …. b1=g1⊕g2⊕g3...⊕gn and b0=g0⊕g1⊕g2⊕g3...⊕gn.
void GrayToBin () {
    cin >> gray;
    int bin = stoi (gray, 0, 2);
    int val = bin;
    FOR (i, 1, gray.size()-1) 
        bin = (bin ^ (val >> i));
    cout << bitset<32>(bin).to_string().substr(32-gray.size()) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        GrayToBin();
    return 0;
}
