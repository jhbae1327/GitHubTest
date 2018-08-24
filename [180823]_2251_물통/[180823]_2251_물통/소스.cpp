#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

#define MAX 201
/*
	a : A번 물통에 남은 양
	b : B번 물통에 남은 양
	c : C번 물통에 남은 양
	A : A 물통 부피
	B : B 물통 부피
	C : C 물통 부피

*/

int main() {
	int A = 0;
	int B = 0;
	int C = 0;

	bool visited[MAX][MAX] = { 0, };
	ifstream in("tst.txt");

	in >> A >> B >> C;
	
	queue<pair<int, int> >q;

	q.push(make_pair(0, 0));
	visited[0][0] = true;
	
	while (!q.empty()) {
		
		int y = q.front().first;
		int x = q.front().second;
		int z = C - x - y;
		q.pop();


		int ny, nx, nz = 0;

		ny = y; nx = x; nz = z;
		// y -> x;
		ny += nx; nx = 0;
		if (ny >= A) {
			ny = nx - A;
			nx = A;
		}

		
		ny = y; nx = x; nz = z;
		// y -> z;
		ny += nz; nz = 0;
		if (ny >= C) {
			ny = nz - C;
			nz = C;
		}

		// x -> y;
		nx += ny; ny = 0;
		if (nx >= B) {
			nx = ny - B;
			ny = B;

		}



	}

	getchar();
	return 0;
}