#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Client{
    int cost, time;

    Client(int cost, int time){
        this->cost = cost;
        this->time = time;
    }


    bool operator <(const Client other){
        if(this->cost == other.cost){
            return this->time < other.time;
        }
        else{
            return this->cost < other.cost;
        }
    }

    bool operator >(const Client other){
        return !((*this) < other);
    }
};

struct compare_costs{
    bool operator()(const Client &a, const Client &b){ 
        if(a.cost == b.cost){
            return a.time <= b.time;
        }
        else{
            return a.cost > b.cost;
        };
    };

};

struct compare_times{
    bool operator()(const Client &a, const Client &b){ 
        if(a.time == b.time){
            return a.cost > b.cost;
        }
        else{
            return a.time < b.time;
        };
    };
};

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
        Client x(cost, time);
        clients.push_back(x);
    }
    for(auto client : clients){
        cerr << client.cost << " " << client.time << "\n";
    }
    // sort clients
    cerr<<"sorted\n";
    sort(clients.begin(), clients.end(), compare_costs());
    for(auto client : clients){
        cerr << client.cost << " " << client.time << "\n";
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
        if(check_if_fits(counter, client.time + 1) == false){
            cerr << "Skipping " << client.cost << " " << client.time << "\n";
            continue;
        }
        counter[client.time]++;
        cerr << "Taking " << client.cost << " " << client.time << "\n";
        for(int i = 0; i < t; ++i){
            cerr<<counter[i]<< " ";
        }
        cerr << endl;
        sum += client.cost;
        time_spent++;
    }
    cout << sum << endl;
    return 0;
}
