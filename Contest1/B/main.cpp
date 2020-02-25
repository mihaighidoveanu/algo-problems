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
            return a.time < b.time;
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
    int sum_times = 0;
    for(int i = 0; i <= time_to_leave; i++){
        sum_times += counter[i];
    }
    int MAX = 0;
    // a client who leaves at time T fits 
    // if we have taken less than T clients who leave before T
    bool condition = (sum_times <= time_to_leave );
    return condition;

}

int main(){
    // read data
    int n, t;
    cin >> n >> t;
    vector<Client> clients;
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
    for(int i = 0; i < t; ++i){
        if(time_spent == t){
            break;
        }
        // we can choose at most 1 client who leaves at 0
        // at most 2 clients who leave at 1
        // at most 3 clients who leave at 2
        int time_to_leave = clients[i].time;
        cerr << "Counting\n";
        if(check_if_fits(counter, time_to_leave) == false){
            cerr << "Skipping " << clients[i].cost << " " << clients[i].time << "\n";
            continue;
        }
        counter[time_to_leave]++;
        cerr << "Taking " << clients[i].cost << " " << clients[i].time << "\n";
        for(int i = 0; i < t; ++i){
            cerr<<counter[i]<< " ";
        }
        cerr << endl;
        sum += clients[i].cost;
        time_spent++;
    }
    cout << sum << endl;
    return 0;
}
