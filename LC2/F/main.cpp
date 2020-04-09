#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <string>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

	int Find(vector<int>& parent, int x) {
        if ( x!= parent[x])
            parent[x] = Find(parent,parent[x]);        
        return parent[x];
        // if (parent[x] == x)
		// 	return x;
		// return parent[x]=Find(parent, parent[x]);
	}

	bool Union (vector<int>& parent, vector<int>& rank, int x, int y, set<int> &freakySet, int& freaky, int& unfreaky ) {
        int x_parent = Find(parent, x);
        int y_parent = Find(parent, y);
		if (x_parent == y_parent) {
            if(freakySet.find(x_parent) == freakySet.end()) {
                freakySet.insert(x_parent);
                freaky += 1;
            }
            return false;
		}
        if (freakySet.find(x_parent) != freakySet.end() && freakySet.find(y_parent) != freakySet.end() ) {
            freaky -= 1;
            unfreaky -= 1;
            parent[y_parent] = x_parent;
            for (int k = 1; k <= parent.size(); k++) {
                if(parent[k] == y_parent) {
                    parent[k] = x_parent;
                }
            }
            return false;
        }
        unfreaky -= 1;
		if (rank[x_parent] < rank[y_parent])
        {
			parent[x_parent] = y_parent;
        }
		else {
			if (rank[x_parent] > rank[y_parent])
				parent[y_parent] = x_parent;
			else {
				parent[y_parent] = x_parent;
				rank[x_parent]++;
			}
		}
		return true;
	}

int main() {
    int num;
    cin >> num;
    while (num--) {
            int photo, connects;
            cin >> photo >> connects;
            vector <vector<int> > adjancey;
            vector<int> adjanceyLine(photo+1, 0);
            for (int i = 0; i <= photo; i++) {
                adjancey.push_back(adjanceyLine);
            }
            
            int freaky = 0;
            int freaky_uni = 0;
            int unfreaky = photo;
            set<int> freakytrees;
            set<int> unfreakytrees;
            vector<int> parents(photo+1, 0);
            vector<int> ranks(photo+1, 0);

            for (int i = 1; i<=photo; i++) {
                parents[i] = i; 
            }

            for (int i = 0; i < connects; i++ ) {
                int line, row;
                cin >> line >> row;
                Union (parents, ranks, line, row, freakytrees, freaky, unfreaky);

            }
            for (int i = 1; i <= photo; i++) {
                unfreakytrees.insert(parents[i]);
                //cout << parents[i] << endl;
            }
            cout << unfreaky - freaky <<" "<< freaky << endl;

    }
    return 0;
}
