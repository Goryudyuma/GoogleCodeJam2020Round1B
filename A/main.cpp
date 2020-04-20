#include<bits/stdc++.h>
/**/
#include <random>
using namespace std;


const string IMPOSSIBLE = "IMPOSSIBLE";

map<pair<pair<long long int, long long int>, long long int>, string> memo;

string solve(long long int X, long long int Y, long long int now) {
	string ans = IMPOSSIBLE;
	//cout << X << " " << Y << " " << now << endl;
	if(X == 0 && Y == 0) {
		return "";
	}
	if(X != 0 && abs(X) < now || Y != 0 && abs(Y) < now || abs(X) > 1e10 || abs(Y) > 1e10)return IMPOSSIBLE;

	if(memo.count(make_pair(make_pair(X, Y), now)) != 0) {
		return memo[make_pair(make_pair(X, Y), now)];
	}

	{
		string ret = solve(X + now, Y, now * 2);
		if(ret != IMPOSSIBLE && (ans == IMPOSSIBLE || (ans != IMPOSSIBLE && ans.size() > ret.size() + 1))) {
			memo[make_pair(make_pair(X, Y), now)] = ans = "W" + ret;
		}
	}
	{
		string ret = solve(X - now, Y, now * 2);
		if(ret != IMPOSSIBLE && (ans == IMPOSSIBLE || (ans != IMPOSSIBLE && ans.size() > ret.size() + 1))) {
			memo[make_pair(make_pair(X, Y), now)] = ans = "E" + ret;
		}
	}
	{
		string ret = solve(X, Y + now, now * 2);
		if(ret != IMPOSSIBLE && (ans == IMPOSSIBLE || (ans != IMPOSSIBLE && ans.size() > ret.size() + 1))) {
			memo[make_pair(make_pair(X, Y), now)] = ans = "S" + ret;
		}
	}
	{
		string ret = solve(X, Y - now, now * 2);
		if(ret != IMPOSSIBLE && (ans == IMPOSSIBLE || (ans != IMPOSSIBLE && ans.size() > ret.size() + 1))) {
			memo[make_pair(make_pair(X, Y), now)] = ans = "N" + ret;
		}
	}

	return memo[make_pair(make_pair(X, Y), now)] = ans;
}


int main() {
	long long int testCaseNum = 0;
	cin >> testCaseNum;

	vector<vector<long long int>>input;
	for(long long int testCase = 1; testCase <= testCaseNum; testCase++) {

		long long int X, Y;
		cin >> X >> Y;

		string ans = solve(X, Y, 1);

		cout << "Case #" << testCase << ": ";
		cout << ans;
		cout << endl;
	}
}
