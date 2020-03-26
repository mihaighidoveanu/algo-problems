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
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
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

vi movetrees(vii  trees){
    set<int> h;
    vi new_dists;
    for (auto tree : trees) {
        int distance = tree.first;
        int move = tree.second;
        int new_dist = 0;
        if(move < distance){
            new_dist = distance - move;
        }
        while(h.count(new_dist) == 1 && new_dist < INT_MAX){
            // watch for overflow ? 
            new_dist ++;
        }
        h.insert(new_dist);
        new_dists.push_back(new_dist);
    }
    return new_dists;
}

void run() {
    int n;
    std::cin >> n;
    vii trees;
    for (int i = 0; i < n; ++i) {
        int distance, move;
        std::cin >> distance >> move;
        ii tree(distance, move);
        trees.push_back(tree);
    }
    std::cerr << __LINE__ << ": " << "#trees" << " = " << trees << std::endl;
    vi distances = movetrees(trees);
    int d = distances.size();
    for (int i = 0; i < d; ++i) {
       if (i < d - 1) {
          std::cout << distances[i] << " "; 
       } 
       else{
           std::cout << distances[i] << std::endl;
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
