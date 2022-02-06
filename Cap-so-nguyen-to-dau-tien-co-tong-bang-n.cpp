
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
const int max_i = 1e6 + 5;
int a[max_i] = {0};
void sievePrime () {
    a[0]=1, a[1]=1;
    for (long long i=2; i<=sqrt(100000); i++)
        for (long long j=i*i; j<=100000; j+=i)
            if (a[i]==0)
                a[j] = 1;
}
void test () {
    int n;
    cin >> n;
    if (n == 4) cout << "2 2\n";
    else if (n%2 == 1) 
        (!a[n - 2]) ? cout << "2 " << n-2 << endl : cout << "-1\n";
    else 
        for (int i = 3; i <= n/2; i++) 
            if (!a[i]) {
                cout << i << " " << n - i << endl;
                return;
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
        test ();
    return 0;
}