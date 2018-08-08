#include<iostream>
#include<fstream>
#include<queue>
#include<string>
using namespace std;

int change(int num, int index, int cnt) {
	int ret = 0;
	if (index == 0 && cnt == 0) return -1;
	string tmp = to_string(num);
	tmp[index] = cnt +'0';
	ret = stoi(tmp);

	return ret;
}

bool check(int num) {
	bool ret = true;

	for(int i = 2; i <= sqrt(num); i++)
		if (num % i == 0) {
			ret = false;
			break;
		}

	return ret;
}



int bfs(int s, int e) {
	queue<int> q;
	bool visited[10000] = { false, };
	int dist[10000] = { 0, };
	
	q.push(s);
	visited[s] = true;
	dist[s] = 0;

	while (!q.empty()) {
		
		int here = q.front();  
		q.pop();
		
		if (here == e){
			return dist[here];
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				int there = change(here, i, j);
				//if(there != -1)
				if (check(there) && !visited[there]) {
					visited[there] = true;
					dist[there] = dist[here] + 1;
					q.push(there);
				}
			}
		}
	}
	return -1;
}


int main() {

	int tc = 0;
	ifstream in("tst.txt");

	in >> tc;

	while (tc--) {
		int n = 0;
		int m = 0;

		in >> n >> m;

		if (bfs(n, m) == -1)
			cout << "Impossible" << endl;
		else
			cout << bfs(n, m) << endl;
	}

	getchar();
	return 0;
}