#include<iostream>
#include<fstream>
#include<queue>
#include<string>
using namespace std;

int D(int num) {
	int ret = -1;

	ret = (2 * num)%10000;

	return ret;
}

int S(int num) {

	if (num-1 < 0)
		return 9999;
	
	return num - 1;
}

int L(int num) {
	/*
	int ret = -1;
	string tmp = "0";
	string snum = "0";

	snum = to_string(num);
	tmp = snum;

	snum[snum.size() - 1] = tmp[0];
	for (int i = 0; i < snum.size()-1; i++)
		snum[i] = tmp[i+1];
	
	ret = stoi(snum);
	return ret;
	*/
	int num1 = num / 1000;
	int ret = (num % 1000) * 10 + num1;

	return ret;
	
}

int R(int num) {
	/*
	int ret = -1;
	string tmp = "0";
	string snum = "0";

	snum = to_string(num);
	tmp = snum;

	snum[0] = tmp[snum.size() - 1];
	for (int i = 1; i < snum.size() - 1; i++)
		snum[i] = tmp[i - 1];

	ret = stoi(snum);
	return ret;
	*/
	int num1 = num % 10;
	int ret = (num / 10) + (num1*1000);

	return ret;
	
}

string bfs(int s, int e) {
	queue<int> q;
	while (!q.empty())q.pop();
	bool visited[10005] = { false, };
	string dist[10005] = {"",};

	q.push(s);
	dist[s] = "";
	visited[s] = true;

	while (!q.empty()) {
		
		int here = q.front();

		q.pop();

		if (here == e) {
			//cout << dist[e] << endl;
			break;
		}
			

		int there = D(here);
		if (!visited[there]){
			visited[there] = true;
			dist[there] = dist[here] + "D";
			q.push(there);
		}

		there = S(here);
		if (!visited[there]) {
			visited[there] = true;
			dist[there] = dist[here] + "S";
			q.push(there);
		}

		there = L(here);
		if (!visited[there]) {
			visited[there] = true;
			dist[there] = dist[here] + "L";
			q.push(there);
		}

		there = R(here);
		if (!visited[there]) {
			visited[there] = true;
			dist[there] = dist[here] + "R";
			q.push(there);
		}
	}
	return dist[e];
}

int main() {

	ifstream in("tst.txt");
	int tc = 0;

	in >> tc;


	while (tc--) {
		int s = 0;
		int e = 0;

		in >> s >> e;
		cout << bfs(s, e) << endl;
	}

	getchar();
	return 0;
}