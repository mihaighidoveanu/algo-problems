#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int t;
	long long n;
	string tmp;
	cin >> t;
	while(t--){
		cin >> n;
		getline(cin, tmp);
		bool x;
		string input;
		for(int i = n - 1; i >= 0; i-- ){
			cout << "READ " << i << "\n";
			getline(cin, input);
			//cout << "Value " << input << "\n";
			if(input.compare("true") == 0){
				cout << "OUTPUT " << i << "\n";
				break;
			}
		}
	}
	return 0;
}
