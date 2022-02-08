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
int a[(int)1e6] = {0};
void sievePrime () {
    a[0]=1, a[1]=1;
    for (long long i=2; i<=sqrt(1000000); i++)
        for (long long j=i*i; j<=1000000; j+=i)
            if (a[i]==0)
                a[j] = 1;
}
int n;
void test () {
    cin >> n;
    if (n%2 == 1) 
        (a[n-2] == 0) ? cout << "2 " << n-2 << endl : cout << "-1\n";
    else { 
        for (int i = 2; i <= n/2; i++) 
            if (a[i] == 0 && a[n-i] == 0)   {
                cout << i << " " << n-i << endl;
                return;
            }    
        cout << "-1\n";
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    sievePrime();
    int t;
    cin >> t;
    while (t--) 
        test();
    return 0;
}