#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning (disable: 4996)

using namespace std;

int map[100][100];
bool visit[100][100];
int dist[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int BFS(int N, int M) {
	queue<pair<int, int>> que;
	que.push(pair<int, int>(0, 0));
	visit[0][0] = true;
	dist[0][0] = 1;

	while (!que.empty()) {
		int ax = que.front().first;
		int ay = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = ax + dx[i];
			int ny = ay + dy[i];

			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M)) {
				if ((visit[nx][ny] == false) && (map[nx][ny] == 1)) {
					que.push(pair<int, int>(nx, ny));
					dist[nx][ny] = dist[ax][ay] + 1;
					visit[nx][ny] = true;
				}
			}
		}
	}
	int result = dist[N - 1][M - 1];

	return result;
}

int main(void) {
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	cout << BFS(N, M);
	return 0;
}
