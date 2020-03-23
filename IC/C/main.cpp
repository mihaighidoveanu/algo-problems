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
typedef vector<pair<char, ll>> vci;
typedef pair<char, ll> ci;

template<class T> ostream& operator<<(ostream &os, vector<T> v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

template<class T> ostream& operator<<(ostream &os, pair<T, T> x) {
    os << x.first << "_" << x.second << " ";
    return os;
}

ostream& operator<<(ostream &os, ci x) {
    os << x.first << "_" << x.second << " ";
    return os;
}

void run() {
    int T;
    std::cin >> T;

    vci cuts;
    for (int i = 0; i < T; ++i) {
        int C;
        std::cin >> C;
        char type;
        ll value;
        for (int i = 0; i < C; ++i) {
            std::cin >> type >> value;
            ci cut(type, value);
            cuts.push_back(cut);
        }
    }
    std::cerr << __LINE__ << ": " << "#cuts" << " = " << cuts << std::endl;
    // ALGORITHM HERE
    // Plan is to transform the moves from the (x,y,z) space to a 2d matrix coordinate space. 
    // Using the matrix, we can save the location of triangles. 
    // So after simulating the cut, we can count the locations.
    vvi m;
}


signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}
