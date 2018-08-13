#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;

int n = 0;
int m = 0;
vector<vector<int>> a;
vector<int> ans;
int ind[32001] = { 0, };

int main() {

	ifstream in("tst.txt");
	queue<int> q;

	int tmp1 = 0;
	int tmp2 = 0;

	in >> n >> m;
	a.resize(n+1);
	for (int i = 0; i < m; i++) {
		in >> tmp1 >> tmp2;
		a[tmp1].push_back(tmp2);
		ind[tmp2]++;
	}

	for (int i = 1; i <= n; i++) 
		if (ind[i] == 0) {
			q.push(i);
			ans.push_back(i);
		}
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < a[here].size(); i++) {
			int there = a[here][i];
			ind[there]--;
			if (ind[there] == 0){
				q.push(there);
				ans.push_back(there);
			}
		}

	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] <<  " ";
	getchar();
	return 0;
}