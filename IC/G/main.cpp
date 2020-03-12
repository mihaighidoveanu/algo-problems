#include <bits/stdc++.h>
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <climits>
#include <limits>
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

void mp(vvi m, int i, int j){
    std::cerr << __LINE__ << ": " << "#m[" << i << "][" << j << "]" << " = " << m[i][j] << std::endl;
}

void run() {
    int N;
    std::cin >> N;
    vi dims(N + 1);
    for (int i = 0; i <= N ; ++i) {
        ll dim;
        std::cin >> dim;
        dims[i] = dim;
    }
    std::cerr << __LINE__ << ": " << "#dims" << " = " << dims << std::endl;
    // check for corner case
    if (N <= 1) {
        std::cout << 0 << std::endl;
    }
    // create the recurrence matrix
    vvi m(N, vi(N));
    // compute the recurrence matrix
    for (int diff = 1; diff <= N - 1; ++diff) {
        std::cerr << __LINE__ << ": " << "#diff" << " = " << diff << std::endl;
        for (int i = 0; i + diff < N; ++i) {
            int j = i + diff;
            std::cerr << __LINE__ << ": " << "#i" << " = " << i << std::endl;
            // compute the min
            ll min = LONG_LONG_MAX;
            for (int k = i; k < j; ++k) {
                std::cerr << __LINE__ << ": " << "#k" << " = " << k << std::endl;
                mp(m, i, k);
                mp(m, k + 1, j);
                std::cerr << __LINE__ << ": " << "#dims[i]*dims[k+1]*dims[j+1]" << " = " << dims[i]*dims[k+1]*dims[j+1] << std::endl;

                ll multiplications = m[i][k] + m[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                std::cerr << __LINE__ << ": " << "#multiplications" << " = " << multiplications << std::endl;
                if (multiplications < min) {
                    min = multiplications;
                }
            }
            std::cerr << __LINE__ << ": " << "#min" << " = " << min << std::endl;
            m[i][j] = min;
        }
    }
    std::cout << m[0][N - 1] << std::endl;
}


signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}
