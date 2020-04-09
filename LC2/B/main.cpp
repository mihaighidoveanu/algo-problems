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

string solve(string s){
    std::array<int, 26> h = {};
    string result;
    std::cerr << __LINE__ << ": " << "New word" << std::endl;
    std::cerr << __LINE__ << ": " << "#s" << " = " << s << std::endl;
    for (char c : s) {
        int idx = c - 'a';
        h[idx] ++;
    }
    int i = 0;
    bool go_back = false;
    int go_back_i = 27;
    while(i < 26){
        /* std::cerr << __LINE__ << ": " << "#char" << " = " << (char)(i + 'a') << std::endl; */
        /* std::cerr << __LINE__ << ": " << "#h[i]" << " = " << h[i] << std::endl; */
        // check for peak
        int peak_i = 27;
        int has_peak = false;
        int sum = 0;
        for (int j = 0; j < h.size(); ++j) {
            if (sum < h[j]) {
                result.push_back('a' + j);
                has_peak = true;
                peak_i = j;
                break;
            }
           sum += h[i]; 
        }
        if(h[i] > 0){
            result.push_back('a' + i);
            h[i] = h[i] - 1;
            if(go_back == false){
                if (h[i] > 0) {
                    go_back = true;
                    if (i < go_back_i) {
                       go_back_i = i; 
                       std::cerr << __LINE__ << ": " << "#go_back_i" << " = " << (char)(go_back_i + 'a') << std::endl;
                    }
                }
            }
            else{
               std::cerr << __LINE__ << ": " << "#going back_i" << " = " << (char)(go_back_i + 'a')<< std::endl;
               go_back = false;
               i = go_back_i - 1;
            }
        }
        i++;
    }
    if (go_back) {
       return "IMPOSSIBLE";
    }
    
    return result;
}

void run() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        string x;
        std::cin >> x;
        std::cout << solve(x) << std::endl;
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
