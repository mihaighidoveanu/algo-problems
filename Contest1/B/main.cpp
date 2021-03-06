#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstdio>

using namespace std;

bool check_if_fits(array<int, 47> counter, int time_to_leave){
    int seconds_passed = 0;
    for(int i = 0; i < time_to_leave; i++){
        seconds_passed += counter[i];
    }
    // a client who leaves at time T fits 
    // if we have taken less than T clients who leave before T
    cerr << "Time to leave " << time_to_leave << "\n";
    cerr << "Seconds passed " << seconds_passed << "\n";
    bool condition = (seconds_passed < time_to_leave );
    return condition;

}

bool sortbycost(const pair<int, int> &a, const pair<int, int> &b){
    return a.first > b.first;
}

int main(){
    // read data
    int n, t;
    cin >> n >> t;
    cerr << "N " << n << " T " << t << "\n";
    vector<pair<int, int> > clients;
    /* vector<Client> clients; */
    for(int i = 0; i < n; ++i){
        int cost, time;
        cin >> cost >> time;
        clients.push_back(make_pair(cost, time));
    }
    for(auto client : clients){
        cerr << client.first << " " << client.second << "\n";
    }
    // sort clients
    cerr<<"sorted\n";
    sort(clients.begin(), clients.end(), sortbycost );
    for(auto client : clients){
        cerr << client.first << " " << client.second << "\n";
    }
    // compute total sum
    int sum = 0;
    int time_spent = 0;
    cerr << "computing\n";
    // count how many clients with the same time limit we got
    array<int, 47> counter = {};
    for(auto client : clients){
        // we can choose at most 1 client who leaves at 0
        // at most 2 clients who leave at 1
        // at most 3 clients who leave at 2
        cerr << "Counting\n";
        if(check_if_fits(counter, client.second + 1) == false){
            cerr << "Skipping " << client.first << " " << client.second << "\n";
            continue;
        }
        counter[client.second]++;
        cerr << "Taking " << client.first << " " << client.second << "\n";
        for(int i = 0; i < t; ++i){
            cerr<<counter[i]<< " ";
        }
        cerr << endl;
        sum += client.first;
        time_spent++;
    }
    cout << sum << endl;
    return 0;
}
