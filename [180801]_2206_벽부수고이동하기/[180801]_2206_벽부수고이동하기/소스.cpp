#include<iostream>
#include<fstream>
#include<algorithm>
#include<string.h>
using namespace std;

#define INF 987654321

int n = 0, m = 0;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
int map[1001][1001] = { 0, };
int tmp[1001][1001] = { 0, };
bool visited[1001][1001] = { false, };
int ans = INF;

int dfs(int y, int x, int ret) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!visited[ny][nx] && tmp[ny][nx] == '0' && 0 <= ny && ny < n && 0 <= nx && nx < m) {
			dfs(ny, nx, ret+1);
		}
	}

	if (y == n - 1 && x == m - 1)
		ans = ret;
		return ans;

	return INF;
}

int dfsAll() {
	int ans = INF;
	
	// 벽을 지우지 않고 최단거리 구하기
	memcpy(tmp, map, sizeof(map));
	ans = dfs(0, 0, 1);
	
	// 방문한 곳 초기화
	memset(visited, false, sizeof(visited));

	// 벽을 한개 지우고 최단거리 구하기
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '1') {
				memcpy(tmp, map, sizeof(map));
				tmp[i][j] = '0';
				ans = min(ans, dfs(0, 0, 1));
			}
		}
	
	if (ans == INF)
		ans = -1;

	return ans;
}

int main() {
	
	FILE *in;
	fopen_s(&in,"tst.txt", "r");

	fscanf_s(in, "%d","%d", n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fscanf_s(in,"%1d", &map[i][j]);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << map[i][j] << " ";
		}cout << endl;
	}
	//cout << dfsAll() << endl;
	//cout << "end" << endl;

	getchar();
	return 0;
}