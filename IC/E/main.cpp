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
typedef vector<pair<string, ll>> vsi;

template<class T> ostream& operator<<(ostream &os, vector<T> v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

template<class T> ostream& operator<<(ostream &os, pair<T, T> x) {
    os << x.first << "_" << x.second << " ";
    return os;
}

ostream& operator<<(ostream &os, pair<int, char> x) {
    os << x.first << "_" << x.second << " ";
    return os;
}

bool check_run(vector<pair<int, char>> cards){

    // create buckets for all colors
    unordered_map<char, set<int>> buckets;
    for (auto const & card : cards) {
       int value = card.first; 
       char color = card.second;
       buckets[color].insert(value);
    }
    // check if there is at least one bucket with 3 consecutive elements
    char colors[4] = {'r', 'y', 'g', 'b'};
    for (char color : colors) {
        auto search = buckets.find(color);
        if (search == buckets.end()) {
            continue;
        }
        const set<int> & bucket = buckets[color];
        if (bucket.size() < 3) {
           continue; 
        }
        auto it1 = bucket.begin();
        auto it2 = next(it1, 1);
        auto it3 = next(it1, 2);
        while(it3 != bucket.end()){
            int v1 = *it1;
            int v2 = *it2;
            int v3 = *it3;
            std::cerr << __LINE__ << ": " << "#v1" << " = " << v1 << std::endl;
            std::cerr << __LINE__ << ": " << "#v2" << " = " << v2 << std::endl;
            std::cerr << __LINE__ << ": " << "#v3" << " = " << v3 << std::endl;
            if (v1 + 1 == v2 && v2 + 1 == v3) {
                return true;
            }
            ++it1;
            ++it2;
            ++it3;
        }
    }
    return false;
}

bool check_group(vector<pair<int, char>> cards){
    // create buckets for all int values
    std::array<set<char>, 100> buckets;
    for (auto const & card : cards) {
       int value = card.first; 
       char color = card.second;
       buckets[value].insert(color);
    }
    // check if there is at least one bucket with 3 elements
    for (auto const & bucket : buckets) {
        if (bucket.size() == 3) {
           return true ;
        }
    }
    return false;
}

void run() {
    int T;	
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        int M;
        vi values;
        // read elements
        std::cin >> M;
        std::vector<pair<int, char>> cards;
        for (int i = 0; i < M; ++i) {
            string s;
            std::cin >> s;
            int value = s[0] - '0';
            char color = s[1];
            pair<int, char> card(value, color);
            cards.push_back(card);
        }
        std::cerr << __LINE__ << ": " << "#cards" << " = " << cards << std::endl;
        if (check_run(cards) || check_group(cards)) {
            std::cout << "YES" << std::endl;
        }
        else{
            std::cout << "NO" << std::endl;
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
