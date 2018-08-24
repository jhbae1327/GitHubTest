#include<iostream>
#include<fstream>
#include<queue>
#include<string>
using namespace std;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1, 0,0 };

struct puzzle{
	int y = 0;
	int x = 0;
	string map;
	int ans = 0;
};

int main() {
	ifstream in("tst.txt");

	puzzle p;
	queue<puzzle> q;
	char tmp;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
			in >> tmp;
			p.map += tmp;
			if (tmp == '0'){
				p.y = i;
				p.x = j;
			}
		}
	q.push(p);

	while (!q.empty()) {
		int k = 0;
		char tmp[3][3] = { 0, };

		int	y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().ans + 1;
		string snum = q.front().map;

		if (snum == "1234567890" && y == 2 && x == 2) {
			cout << cnt << endl;
			break;
		}

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				tmp[i][j] = snum[k++];

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= ny && ny < 3 && 0 <= nx && nx < 3) {
				puzzle np;
				np.y = ny;
				np.x = nx;
				np.ans = cnt;
				
				swap(tmp[y][x], tmp[ny][nx]);

				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						np.map += tmp[i][j];
				
				q.push(np);
			}
		}
	}
	
	cout << "end" << endl;
	getchar();
	return 0;
}