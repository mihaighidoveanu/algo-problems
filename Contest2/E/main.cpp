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
typedef vector<vi> vvi;
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

void run() {
    int N;
    while(cin >> N){
        std::stack<int> s;
        std::queue<int> q;
        std::priority_queue<int> pq;
        int type, x;
        std::cerr << __LINE__ << ": " << "#N" << " = " << N << std::endl;
        bool is_q = true, is_s = true, is_pq = true;
        for (int i = 0; i < N; ++i) {
            std::cin >> type >> x;
            std::cerr << __LINE__ << ": " << "#i" << " = " << i << std::endl;
            switch (type) {
                case 1:
                    {
                        s.push(x);
                        q.push(x);
                        pq.push(x);
                        break;
                    }
                case 2:
                    {
                        if (s.empty()) {
                            std::cout << "impossible" << std::endl;
                            continue;
                        }
                        if (pq.empty()) {
                            std::cout << "impossible" << std::endl;
                            continue;
                        }
                        if (q.empty()) {
                            std::cout << "impossible" << std::endl;
                            continue;
                        }
                        std::array<int, 3> vals = {s.top(), q.front(), pq.top()};
                        bool can_be_s = (vals[0] == x);
                        bool can_be_q = (vals[1] == x);
                        bool can_be_pq = (vals[2] == x);

                        is_q = is_q && can_be_q;
                        is_s = is_s && can_be_s;
                        is_pq = is_pq && can_be_pq;


                        s.pop();
                        q.pop();
                        pq.pop();

                        break;
                    }
                default:
                    std::cout << "impossible" << std::endl;
                    continue;
                    
            }
        }
        if ((is_s && is_q) || (is_q && is_pq) || (is_s && is_pq)) {
           std::cout << "not sure" << std::endl;
           continue;
        }
        if (is_s) {
           std::cout << "stack" << std::endl; 
           continue;
        }
        if (is_q) {
           std::cout << "queue" << std::endl; 
           continue;
        }
        if (is_pq) {
           std::cout << "priority queue" << std::endl; 
           continue;
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
