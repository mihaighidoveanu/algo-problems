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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<ii> vii;

#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int) (v).size())
#define rs resize

template<class T> ostream& operator<<(ostream &os, vector<T> v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

template<class T> ostream& operator<<(ostream &os, pair<T, T> x) {
    os << x.first << "_" << x.second << " ";
    return os;
}

vii find_infected(const  vector<string> & m){
    vii v;
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
        
            if (m[i][j] == '*') {
                ii coords(i, j);
                v.push_back(coords);
            }
        }
    }
    return v;
}

vii find_neighbors(const vector<string> & m, const ii & start){
    int row = start.first, col = start.second;
    std::cerr << "Checking neighbors for " << "m[" << row << "]["<< col << "] = " << m[row][col] << std::endl;
    vii neighbors;
    ii idx[8] = {
        ii(row + 1, col + 1), ii(row + 1, col), ii(row + 1, col - 1), 
        ii(row, col + 1), ii(row , col - 1),
        ii(row - 1, col + 1), ii(row - 1, col), ii(row - 1, col - 1)
    };
    int n = m.size();
    for (auto neighbor : idx) {
        int i = neighbor.first, j = neighbor.second;
        if ((i < 0 || i >= n) || (j < 0 || j >= n)){
           continue;
        }
        std::cerr << "Checking " << "m[" << i << "]["<< j << "] = " << m[i][j] << std::endl;
        if (m[i][j] == '+') {
            std::cerr << "Found neighbor !" << std::endl;
            neighbors.push_back(neighbor);
        }
    }
    return neighbors;
}

int bfs(const vector<string> & m, const ii & start, vvb & visited){
    int count = 0;
    std::queue<ii> q;
    q.push(start);
    while(q.empty() == false){
        ii coords = q.front();
        std::cerr << "Search from " << coords << std::endl;
        q.pop();
        vii neighbors = find_neighbors(m, coords);
        cerr << "Found neighbords " << neighbors;
        for (auto neighbor : neighbors) {
            int row, col;
            row = neighbor.first;
            col = neighbor.second;
            if (visited[row][col]) {
               continue; 
            }
            q.push(neighbor);
            std::cerr <<  neighbor << std::endl;
            visited[row][col] = true;
            count += 1;
        }
    }
    return count;
}

void run() {
    int T, n;
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        // read matrix
        std::cin >> n;
        std::vector<string> m(n);
        for (int i = 0; i < n; ++i) {
            string tmp;
            std::cin >> tmp;
            m[i] = tmp;
        }
        // find infected
        vii infected = find_infected(m);
        std::cerr << infected << std::endl;
        // bfs 
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(n));
        for (auto infection : infected) {
           int newlyInfected = bfs(m, infection, visited); 
           count += newlyInfected;
        }
        // report result
        std::cout << count << std::endl;
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
