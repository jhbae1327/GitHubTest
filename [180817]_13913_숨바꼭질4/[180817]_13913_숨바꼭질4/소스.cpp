#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 100001

vector<int> root;
int visited[MAX] = { 0, };
int dist[MAX] = { 0, };
int parents[MAX] = { 0, };

int bfs(int a, int b) {


	queue<int> q;
	
	q.push(a);
	visited[a] = a;
	dist[a] = 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();
	
		if (here == b) {
			int pre = b;

			while(pre != a){
				root.push_back(pre);
				pre = parents[pre];
			}
			root.push_back(a);

			return dist[b];
		}
		
		if (here + 1 < MAX && !visited[here+1]) {
			q.push(here + 1);
			visited[here + 1] = true;
			parents[here + 1] = here;
			dist[here + 1] = dist[here] + 1;
		}


		if (here - 1 >= 0 && !visited[here - 1]) {
			q.push(here - 1);
			visited[here - 1] = true;
			parents[here - 1] = here;
			dist[here - 1] = dist[here] + 1;
		}
		
	
		if (here * 2< MAX && !visited[here * 2]) {
			q.push(here * 2);
			visited[here * 2] = true;
			parents[here * 2] = here;
			dist[here * 2] = dist[here] + 1;
		}
	}
	return 0;
}



int main() {
	
	int n = 0;
	int m = 0;

	ifstream in("tst.txt");

	in >> n >> m;

	cout << bfs(n, m) << endl;

	reverse(root.begin(), root.end());
	for (int i = 0; i < root.size(); i++)
		cout << root[i] << " ";
	cout << endl;

	getchar();
	return 0;
}