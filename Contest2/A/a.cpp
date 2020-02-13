#include <iostream>
using namespace std;
#include <vector>


/* #define DEBUG 1 */
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
// compute first stage for all
    for(int i = 1; i < n; i ++){
        matrix[i][0] += matrix[i - 1][0];
    }
#ifdef DEBUG
    cout<<"1 stage" << "\n";
    print(matrix);
#endif
// compute first machine fully
    for(int j = 1; j < m; j++){
        matrix[0][j] += matrix[0][j - 1];
    }
#ifdef DEBUG
    cout<<"2 stage" << "\n";
    print(matrix);
#endif
// run algorithm
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if( matrix[i - 1][j] <= matrix[i][j - 1]){
                // current stage ended on previous machine
               matrix[i][j] += matrix[i][j - 1];
            }
            else{
                // wait for the current stage to end on previous machine
                int wait = matrix[i - 1][j] - matrix[i][j - 1];
                matrix[i][j] += matrix[i][j - 1] + wait;
            }
        }
    }
#ifdef DEBUG
    cout<<"3 stage" << "\n";
    print(matrix);
#endif
// collect results
    vector<int> result(n, 0);
    for(int i = 0; i < n; i++){
        result[i] = matrix[i].back();
    }

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
    vector<int> times = solve(matrix);
    for(int i = 0; i < times.size(); i++){
        cout << times[i] << " ";
    }
    return 0;
}
