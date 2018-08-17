#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 100001

int bfs(int n, int m) {
	int visited[MAX] = { 0, };
	int dist[MAX] = { 0, };
	queue<int> q;
	
	q.push(n);
	visited[n] = n;
	dist[n] = 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();
	
		if (here == m) {
			int pre = m;

			vector<int> root;

			cout << dist[m] << endl;
			while(pre != n){
				root.push_back(pre);
				pre = visited[pre];
			}
			root.push_back(n);
			reverse(root.begin(), root.end());
			for (int i = 0; i < root.size(); i++)
				cout << root[i] << " ";
			cout << endl;
			root.clear();
			break;
		}
		
		int there = here + 1;
		if (!visited[there] && there < MAX) {
			q.push(there);
			visited[there] = here;
			dist[there] = dist[here] + 1;
		}

		there = here - 1;
		if (!visited[there] && there >= 0) {
			q.push(there);
			visited[there] = here;
			dist[there] = dist[here] + 1;
		}
		
		there = here * 2;
		if (!visited[there] && there < MAX) {
			q.push(there);
			visited[there] = here;
			dist[there] = dist[here] + 1;
		}
	}

	return 0;
}



int main() {
	
	int n = 0;
	int m = 0;

	ifstream in("tst.txt");

	in >> n >> m;

	bfs(n, m);

	getchar();
	return 0;
}