#include <iostream> 
#include <vector>

using namespace std;

void detectPoint(vector<vector<char> > &city, int n, int ii, int jj, bool &finish,vector<vector<bool> > &detected, int &count) {
    if (ii >= 0 && ii < n && jj >= 0 && jj < n){
        if (city[ii][jj] == '+') {
            city[ii][jj] = '*';
            count += 1;
            detected[ii][jj] = true;
            finish = false;
        }
    }
}

int main() {
    int nTest;
    cin >> nTest;
    for (int i = 0; i < nTest; i++) {
        int n;
        cin >> n;
        vector<vector<char> > city;
        vector<vector<bool> > detected; // need to be detected
        for (int j = 0; j < n; j++) {
            vector<char> cityLine;
            vector<bool> detectedLine;
            for (int k = 0; k < n; k++) {
                char people;
                cin >> people;
                cityLine.push_back(people);
                if (people == '*') {
                    detectedLine.push_back(true);
                } else {
                    detectedLine.push_back(false);
                }
            }
            city.push_back(cityLine);
            detected.push_back(detectedLine);
        }
    
        bool finish = false;

        int count = 0;
        while (!finish) {
            finish = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (city[i][j]=='*' && detected[i][j] == true) {
                        detected[i][j] = false;
                        detectPoint(city, n, i-1, j-1, finish, detected, count);
                        detectPoint(city, n, i-1, j, finish, detected, count);
                        detectPoint(city, n, i-1, j+1, finish, detected, count);
                        detectPoint(city, n, i, j-1, finish, detected, count);
                        detectPoint(city, n, i, j+1, finish, detected, count);
                        detectPoint(city, n, i+1, j-1, finish, detected, count);
                        detectPoint(city, n, i+1, j, finish, detected, count);
                        detectPoint(city, n, i+1, j+1, finish, detected, count);
                    }
                }
            }
        }
        cout << count << endl;
    }

}
