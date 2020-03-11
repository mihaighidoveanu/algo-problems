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

bool sort_boxes(const ii & a, const ii & b){
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

void run() {
    int T;	
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        // read all 
       int N, B, M; 
       std::cin >> N >> B >> M;
       vs movies;
       for (int i = 0; i < N; ++i) {
           string movie;
           std::cin >> movie;
           movies.push_back(movie);
       }
       vii boxes;
       for (int i = 0; i < B; ++i) {
           int box_size;
           std::cin >> box_size;
           ii box(box_size, i + 1);
           boxes.push_back(box);
       }
       vs queries;
       for (int i = 0; i < M; ++i) {
           string movie;
           std::cin >> movie;
           queries.push_back(movie);
       }
       std::cerr << __LINE__ << ": " << "#boxes" << " = " << boxes << std::endl;
       // search movies and boxes
       sort(movies.begin(), movies.end());
       std::cerr << __LINE__ << ": " << "#movies" << " = " << movies << std::endl;
       sort(boxes.begin(), boxes.end(), sort_boxes);
       std::cerr << __LINE__ << ": " << "#boxes" << " = " << boxes << std::endl;
       // put movies in boxes
       unordered_map<string, int> h;
       auto box_it = boxes.begin();
       ii box = *box_it;
       std::cerr << __LINE__ << ": " << "#box" << " = " << box << std::endl;
       ll box_size = box.first;
       ll box_idx = box.second;
       std::cerr << __LINE__ << ": " << "#box_size" << " = " << box_size << std::endl;
       std::cerr << __LINE__ << ": " << "#box_idx" << " = " << box_idx << std::endl;
       for(auto i = movies.rbegin(); i != movies.rend(); ++i){
           string movie = *i;
           if (box_size == 0) {
                // move to the next box
                box_it ++;    
                box = *box_it;
                box_size = box.first;
                box_idx = box.second;
                std::cerr << __LINE__ << ": " << "#box_idx" << " = " << box_idx << std::endl;
                std::cerr << __LINE__ << ": " << "#box_size" << " = " << box_size << std::endl;
           }
           if (box_size > 0) {
                pair<string, int> x(movie, box_idx);
                h.insert(x);
                box_size --;
           }
        }
       for (auto const & i : h) {
           cerr << i.first << " _ " << i.second << endl;
           
       }
       // solve queries
       for (auto query : queries) {
            auto result = h.find(query);
            if (result == h.end()) {
                std::cout << -1 << std::endl;
            }
            else {
                std::cerr << __LINE__ << ": " << "#result -> first" << " = " << result -> first << std::endl;
                std::cout << (result -> second) << std::endl;
            }
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
