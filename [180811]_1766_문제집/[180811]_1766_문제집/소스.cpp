#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main() {
	ifstream in("tst.txt");
	int n = 0;
	int m = 0;
	int a = 0;
	int b = 0;
	int ind[32001] = { 0, };
	vector<vector<int> > graph;
	vector<int> ans;
	//queue<int> q;
	priority_queue<int, vector<int>, greater<int> > q;
	
	in >> n >> m;
	graph.resize(n + 1);

	for (int i = 0; i < m; i++) {
		in >> a >> b;
		graph[a].push_back(b);
		ind[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if(ind[i] == 0){
			q.push(i);
		}
	}

	while (!q.empty()) {
		int here = q.top();
		q.pop();

		if(!ind[here])
			ans.push_back(here);
		
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			ind[there]--;
			if (ind[there] == 0){
				q.push(there);
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}cout << endl;

	getchar();
	return 0;
}