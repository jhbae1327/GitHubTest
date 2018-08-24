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
			break; // monitor와 목표 이모티콘 수가 같으면..
		}
		// 1. 화면에 있는 이모티콘 복사 후 클립보드 저장.
			int c = here;
			q.push(make_pair(here, c));
			cnt++;
		// 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
			if(clip != -1){
				int there = clip + here;
				if (!visited[there][clip] && there < 1001){
					q.push(make_pair(there, clip));
					cnt++;
				}
				visited[there][clip] = true;
			}
		// 3. 화면에 있는 이모티콘 중 하나를 삭제한다.
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