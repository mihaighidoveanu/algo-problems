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

long long recursion (vector<vector<long long> > & objs, int index) {
    vector<long long> & obj = objs[index - 1];
    long long precomputed = obj.back();
    if (precomputed == -1) {
        std::cerr << __LINE__ << ": " << "computing #index" << " = " << index << std::endl;
        long long ans = 0;
        ans += obj[0];
        int required = obj[1];
        if (required > 0) {
            for (int k = 1; k <= required; k++) {
                ans += recursion(objs, obj[k+1]);
            }
        }
        obj[obj.size() - 1] = ans;
        std::cerr << __LINE__ << ": " << "#After" << " = " << objs[index - 1] << std::endl;
        return ans;
    }
    else{
        std::cerr << __LINE__ << ": " << "precomputed #index" << " = " << index << std::endl;
        return precomputed;
    }
}

void run() {
    long long n, q;
    cin >> n >> q;
    vector<vector<long long> > objs;
    //vector<int> objs_for_sort;
    //input 
    for (int i = 0; i < n; i++) {
        vector <long long> obj;
        long long time, amount;
        cin >> time >> amount;
        obj.push_back(time);
        obj.push_back(amount);
        for (int j = 0; j < amount; j++) {
            long long pre;
            cin >> pre;
            obj.push_back(pre);
        }
        obj.push_back(-1); // precomputed marker
        objs.push_back(obj);
        //objs_for_sort.push_back(obj[1]);
        //objs_for_sort.push_back(i);
    }

    //sort(objs_for_sort.begin(), objs_for_sort.end());
    //sort

    //query
    for (int i = 0; i < q; i++) {
        char ins;
        cin >> ins;
        if (ins == 'Q') {
            int index;
            cin >> index;
            std::cerr << __LINE__ << ": " << "Q #index" << " = " << index << std::endl;
            long long ans;
            ans = recursion(objs, index);
            cout << ans << endl;
        }
        if (ins == 'M') {
            long long num, new_time;
            cin >> num >> new_time;
            std::cerr << __LINE__ << ": " << "M #num" << " = " << num << std::endl;
            vector<long long> & obj = objs[num - 1];
            if (obj.back() == -1) {
                std::cerr << __LINE__ << ": " << "not precomputed" << std::endl;
                std::cerr << __LINE__ << ": " << "#obj[0]" << " = " << obj[0] << std::endl;
                obj[0] = new_time; 
            }
            else{
                std::cerr << __LINE__ << ": " << "precomputed" << std::endl;
                if (new_time > obj[0]) {
                   obj[obj.size() -1] += (new_time - obj[0]); 
                   std::cerr << __LINE__ << ": " << "#obj[0]" << " = " << obj[0] << std::endl;
                }
                else{
                    obj[obj.size() - 1] -= (obj[0] - new_time);
                   std::cerr << __LINE__ << ": " << "#obj[0]" << " = " << obj[0] << std::endl;
                }
            }
            std::cerr << __LINE__ << ": " << "#objs[num - 1]" << " = " << objs[num - 1] << std::endl;
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
