#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

int main() {

	int n	= 0;
	int t	= 0;
	int k	= 0;
	int tmp = 0;
	int ret = 0;
	int ans[10001] = { 0, };
	int ind[10001] = { 0, };
	int time[10001] = { 0, };

	vector<vector<int> > graph;
	queue<int> q;
	ifstream in("tst.txt");

	in >> n;
	graph.resize(n + 1);
	
	for (int i = 1; i <= n; i++){
		in >> time[i];
		in >> k;
		for (int j = 0; j < k; j++) {
			in >> tmp;
			graph[i].push_back(tmp);
			ind[tmp]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0){
			q.push(i);
			ans[i] = time[i];
		}
	}

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i];
			ind[there]--;

			if (ans[there] < ans[here] + time[there])
				ans[there] = ans[here] + time[there];
			
			if (ind[there] == 0){
				q.push(there);
			}

		}
	}
	for (int i = 1; i <= n; i++)
		if (ans[i] > ret)
			ret = ans[i];

	cout << ret << endl;
	getchar();
	return 0;
}