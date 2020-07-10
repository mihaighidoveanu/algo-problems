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

ll f(vii stones, int height){
    ll error = 0;
    /* std::cerr << __LINE__ << ": " << "#height" << " = " << height << std::endl; */
    for (auto stone : stones) {
        ll H = stone.first;
        ll W = stone.second;
        /* std::cerr << __LINE__ << ": " << "#H" << " = " << H << std::endl; */
        /* std::cerr << __LINE__ << ": " << "#W" << " = " << W << std::endl; */
        ll tmp = abs(height - H) * W;
        /* std::cerr << __LINE__ << ": " << "#tmp" << " = " << tmp << std::endl; */
        error += tmp;
    }
    return error;
}

ll ternary_search(vii stones, int l, int r){
    while(r - l > 0){
        /* std::cerr << __LINE__ << ": " << "#l" << " = " << l << std::endl; */
        /* std::cerr << __LINE__ << ": " << "#r" << " = " << r << std::endl; */
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = f(stones, m1);
        ll f2 = f(stones, m2);
        /* std::cerr << __LINE__ << ": " << "#m1" << " = " << m1 << std::endl; */
        /* std::cerr << __LINE__ << ": " << "#f1" << " = " << f1 << std::endl; */
        /* std::cerr << __LINE__ << ": " << "#m2" << " = " << m2 << std::endl; */
        /* std::cerr << __LINE__ << ": " << "#f2" << " = " << f2 << std::endl; */
        if(f1 > f2){
            /* std::cerr << __LINE__ << ": " << "Cutting left" << std::endl; */
            l = m1 + 1;
        }
        else {
            /* std::cerr << __LINE__ << ": " << "Cutting right" << std::endl; */
            r = m2 - 1;
        }
    }
    /* std::cerr << __LINE__ << ": " << "#l" << " = " << l << std::endl; */
    return f(stones, l);
}

ll solve(vii stones, int ll, int rr){
    /* std::cerr << __LINE__ << ": " << "#ll" << " = " << ll << std::endl; */
    /* std::cerr << __LINE__ << ": " << "#rr" << " = " << rr << std::endl; */
    return ternary_search(stones, ll, rr );
}

void run() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        std::cin >> N;
        vii stones;
        int max_height = 0;
        int min_height = INT_MAX;
        for (int i = 0; i < N; ++i) {
            ll H, W;
            std::cin >> H >> W;
            ii stone;
            stone.first = H;
            stone.second = W;
            stones.push_back(stone);
            if (H > max_height) {
                max_height = H;
            }
            if (H < min_height) {
               min_height = H; 
            }
        }
        /* std::cout << stones << std::endl; */
        /* ll cost = f(stones, 5); */
        ll cost = solve(stones, min_height, max_height + 1);
        std::cout << cost << std::endl;
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
