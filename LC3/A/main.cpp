#include <bits/stdc++.h>
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <iterator>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

template<class T> ostream& operator<<(ostream &os, vector<T> v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

template<class T> ostream& operator<<(ostream &os, pair<T, T> x) {
    os << x.first << "_" << x.second << " ";
    return os;
}

ll mod(ll a, ll b) { return (a%=b) < 0 ? a+b : a; }

/* // a^b % m for m <= 2e9 in O(log b) */
/* ll mod_pow(ll a, ll b, ll m) { */
/*     ll r = 1; */
/*     while(b) { */
/*         if (b & 1) r = (r * a) % m; // mod_mul */
/*         a = (a * a) % m; // mod_mul */
/*         b >>= 1; */
/*     } */
/*     return r; */
/* } */

// ab % m for m <= 4e18 in O(log b)
ll mod_mul(ll a, ll b, ll m) {
    ll r = 0;
    while(b) {
        if (b & 1) r = mod(r+a,m);
        a = mod(a+a,m); b >>= 1;
    }
    return r;
}

ll findr(ll a, ll n){
    if (a == n + 1) {
        return 1;
    }
    if (n % a == 0) {
        return -1;
    }
    std::unordered_map<ll, ll> lds;
    int r = 2;
    ll x = mod_mul(a, a, n);
    while(true){
        /* ll ld = x % 10; // last digit */
        ll ld = x;
        /* std::cerr << __LINE__ << ": " << "#r" << " = " << r << std::endl; */
        /* std::cerr << __LINE__ << ": " << "#x" << " = " << x << std::endl; */
        /* std::cerr << __LINE__ << ": " << "#ld" << " = " << ld << std::endl; */
        if (ld == 1) {
            return r;
        }
        // if we got the same digit as before, we found a cycle
        if(lds.count(ld) != 0){
            return -1;
        }
        else{
            lds[ld] = r;
        }
        r++;
        x = mod_mul(x, a, n);
    }
    return -1;
}

void run() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        ll a, n;
        std::cin >> a >> n;
        /* std::cerr << __LINE__ << ": " << "#a" << " = " << a << std::endl; */
        /* std::cerr << __LINE__ << ": " << "#n" << " = " << n << std::endl; */
        ll r = findr(a, n);
        if (r == -1) {
            std::cout << "impossible" << std::endl;
        }
        else {
            std::cout << r << std::endl;
        }
    }
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}
