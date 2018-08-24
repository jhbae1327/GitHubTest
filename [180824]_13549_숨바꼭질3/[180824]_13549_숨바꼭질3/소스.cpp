#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

#define MAX 200002

int main() {

	ifstream in("tst.txt");

	int n = 0;
	int m = 0;
	int dist[MAX] = { 0, };
	bool visited[MAX] = { false, };
	queue<int> q;

	in >> n >> m;

	q.push(n);
	visited[n] = true;
	dist[n] = 0;

	while (!q.empty()) {

		int here = q.front();
		q.pop();

		if (here == m) {
			cout << dist[here] << endl;
			break;
		}


		int there = here * 2;
		if (there <= MAX && !visited[there]) {
			q.push(there);
			visited[there] = true;
			dist[there] = dist[here];
		}

		there = here - 1;
		if (there > -1 && !visited[there]) {
			q.push(there);
			visited[there] = true;
			dist[there] = dist[here] + 1;
		}

		there = here + 1;
		if (there <= MAX && !visited[there]) {
			q.push(there);
			visited[there] = true;
			dist[there] = dist[here] + 1;
		}
	}

	getchar();
	return 0;
}