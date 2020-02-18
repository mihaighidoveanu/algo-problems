#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct Client{
    int cost, time;

    Client(int cost, int time){
        this->cost = cost;
        this->time = time;
    }


    bool operator <(Client other){
        return this->time < other.time;
    }
};

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
    // sort clients
    vector< vector<int> > index(t);
    for(int i = 0; i < n; ++i){
        Client x = clients[i];
        index[x.time].push_back(i);
    }
    // compute total sum
    int sum = 0;
    int time_spent = 0;
    for(int i = 0; i < t; ++i){
        if(time_spent == 0){
            break;
        }
        if(index[i].size() == 0){
            continue;
        }
        // get the most optimum client. What happens if we can take more than one client that leave at the same moment ?
    }
    return 0;
}
