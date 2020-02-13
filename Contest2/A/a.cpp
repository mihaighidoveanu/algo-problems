#include <iostream>
using namespace std;
#include <vector>
/* #include <bits/stdc++> */

int print(vector<vector<int>> matrix){
    int n = matrix.size();
    if(n == 0){
        return -1;
    }
    int m = matrix[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n";
}

vector<int> solve(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
// compute first stage first
    for(int i = 1; i < n; i ++){
        matrix[i][0] += matrix[i - 1][0];
    }
    cout<<"First stage" << "\n";
    print(matrix);
// compute second stage
    for(int j = 1; j < m; j++){
        matrix[0][j] += matrix[0][j - 1];
    }
    cout<<"Second stage" << "\n";
    print(matrix);
// run algorithm
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            

        }
    }


    vector<int> result(n, 0);
    return result;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector< vector<int> > matrix(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            matrix[i][j] = x;
        }
    }
    print(matrix);
    vector<int> times = solve(matrix);
    cout << "Result size " << times.size() << "\n";
    return 0;
}
