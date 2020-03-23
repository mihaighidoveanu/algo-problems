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

unsigned  char dohash(string s){
     unsigned  char result = 0;
    for ( unsigned  char c : s) {
        /* std::cerr << __LINE__ << ": " << "#int(c)" << " = " << int(c) << std::endl; */
        result = result ^ c;
        /* std::cerr << __LINE__ << ": " << "# New int(result)" << " = " << int(result) << std::endl; */
    }
    return result;
}

void run() {
    int n;
    do {
        std::cin >> n;
        if (n == 0) {
           break; 
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        unordered_map< unsigned char, std::vector<string>> h;
        ll ccount = 0;
        ll ucount = 0;
        for (int i = 0; i < n; ++i) {
           string file;
           getline(cin, file);
           std::cerr << __LINE__ << ": " << "#file" << " = " << file << std::endl;
            char key = dohash(file);
           std::cerr << __LINE__ << ": " << "#key" << " = " << key << std::endl;
           std::cerr << __LINE__ << ": " << "#int(key)" << " = " << static_cast< unsigned int>(key) << std::endl;
           auto search = h.find(key);
           if (search == h.end()) {
                // if the key was not yet found, increment unique numbers;
               std::cerr << __LINE__ << ": " << "Unique Value Found" << std::endl;
               h[key].push_back(file);
               ucount ++;
           }
           else{
               // check if hash collision or files are identical
               bool identical = false;
               bool collision = false;
               for (auto file2 : h[key]) {
                  if(file.compare(file2) == 0) 
                  {
                    std::cerr << __LINE__ << ": " << "Identical" << std::endl;
                    identical = true;
                  }
                  else{
                    std::cerr << __LINE__ << ": " << "Colision " << std::endl;
                      ccount ++;
                  }
               }
               if (identical == false) {
                    std::cerr << __LINE__ << ": " << "Unique Value Found" << std::endl;
                    ucount ++; // count unique value
                    h[key].push_back(file);
               }
           }
        }
        std::cerr << __LINE__ << ": " << "Final output :" << std::endl;
        std::cout << ucount << " " << ccount << std::endl;
    } while (n != 0);
}


void test() {
     char r = 127 ^ 128;
    char c = 128;
    std::cerr << __LINE__ << ": " << "#int(r)" << " = " << static_cast< int>(r) << std::endl;
     char x = ( char)(128);
    std::cerr << __LINE__ << ": " << "#int(x)" << " = " << static_cast< int>(x) << std::endl;

}

bool TEST = false;
signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
    if (TEST) {
       test() ;
    }
    else{
	    run();
    }
	return 0;
}
