#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

int main() {
	ifstream in("tst.txt");
	int s = 0;
	in >> s;
	queue<pair<int, int> > q;
	bool visited[2002][2002] = {0, };

	q.push(make_pair(1,0));
	visited[1][0] = true;
	int cnt = 0;

	while (!q.empty()) {
		int here = q.front().first;
		int clip = q.front().second;
		q.pop();

		if (here == s) {
			cout << cnt << endl;
			break; // monitor�� ��ǥ �̸�Ƽ�� ���� ������..
		}
		// 1. ȭ�鿡 �ִ� �̸�Ƽ�� ���� �� Ŭ������ ����.
			int c = here;
			q.push(make_pair(here, c));
			cnt++;
		// 2. Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �Ѵ�.
			if(clip != -1){
				int there = clip + here;
				if (!visited[there][clip] && there < 1001){
					q.push(make_pair(there, clip));
					cnt++;
				}
				visited[there][clip] = true;
			}
		// 3. ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� �����Ѵ�.
			int there = here - 1;
			if (!visited[there][clip] && there > 1){
				q.push(make_pair(there, clip));
				cnt++;
			}
			visited[there][clip] = true;
	}
	
	getchar();
	return 0;
}