#include<iostream>
#include<fstream>
#include<algorithm>
#include<string.h>
using namespace std;

int	n = 0;
int	map[101][101] = { 0, };
bool visit[101][101] = { false, };
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

int dfs(int y, int x, int h) {

	visit[y][x] = true;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < n && 0 <= nx && nx < n && !visit[ny][nx] && map[ny][nx] > h) {
			visit[ny][nx] = true;
			dfs(ny, nx, h);
		}
	}

	return 0;
}

int dfsAll(int h) {

	int ans = 0;
	memset(visit, false, sizeof(visit));

	for(int i = 0; i < n; i++)
		for(int j = 0; j <n; j++)
			if (!visit[i][j]&& map[i][j] > h) {
				dfs(i, j, h);
				ans++;
			}
	//cout << ans <<" "<< h << endl;
	return ans;
}

int main() {

	int h = 0;
	int ans = 0;

	ifstream in("tst.txt");
	in >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			in >> map[i][j];
			if (map[i][j] > h)
				h = map[i][j];
		}

	for(int i = 0; i <= h; i++){
		ans = max(ans, dfsAll(i));
	}
	cout << ans << endl;
	getchar();
	return 0;
}