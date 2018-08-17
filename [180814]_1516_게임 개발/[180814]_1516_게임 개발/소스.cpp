#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

int main() {

	ifstream in("tst.txt");
	vector<vector<int> > graph;
	queue<int> q;

	int n = 0;
	int m = 0;
	int t[501] = { 0, };
	int ind[501] = { 0, };
	int ans[501] = { 0, };
	in >> n;
	graph.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		in >> t[i];
		while(true){
			in >> m;
			if (m == -1) break;
			graph[m].push_back(i);
			ind[i]++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			ans[i] = t[i];
		}
	}

	while (!q.empty()){

		int here = q.front();
		q.pop();
		
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			ind[there]--;

			if (ans[there] < ans[here] + t[there])
				ans[there] = ans[here] + t[there];

			if (ind[there] == 0) {
				q.push(there);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;

	getchar();
	return 0;
}