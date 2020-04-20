#include<bits/stdc++.h>
/**/
#include <random>
using namespace std;



int main() {
	long long int testCaseNum = 0;
	cin >> testCaseNum;

	vector<vector<long long int>>input;
	for(long long int testCase = 1; testCase <= testCaseNum; testCase++) {

		long long int R, S;
		cin >> R >> S;

		vector<pair<long long int, long long int>>ans;
		for(long long int i = 0; i < S - 1; i++) {
			for(long long int j = 0; j < R - 1; j += 2) {
				long long int num1 = R - j - 2;
				long long int num2 = (S - i - 2) * R;
				long long int num3 = (j + 1) * (i + 2)-1;

				ans.push_back(make_pair(2, num1 + num2 + num3));
			}
			if(R % 2 == 1) {
				ans.push_back(make_pair(1, R * S - 2));
			}
		}

		cout << "Case #" << testCase << ": ";
		cout << ans.size() << endl;
		for(auto now : ans) {
			cout << now.first << " " << now.second << endl;
		}
	}
}
