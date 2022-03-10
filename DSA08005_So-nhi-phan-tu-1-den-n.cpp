
#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <bitset>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string decimalToBinary (int n) {
    string s = bitset<64> (n).to_string();
    auto pos = s.find("1");
    if (pos != string::npos)
        return s.substr(pos);  // cắt chuỗi từ pos đến hết
    return "0";
}
    
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FOR(i, 1, n) 
            cout << decimalToBinary(i) << " ";
        cout << endl;
    }

    return 0;
}