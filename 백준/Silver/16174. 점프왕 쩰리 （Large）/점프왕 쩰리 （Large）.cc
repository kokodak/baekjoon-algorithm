/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int mmap[65][65];
bool visited[65][65];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

struct A {
    int x;
    int y;
};

bool isOK(int n) {
    queue<A> que;
    que.push({0, 0});
    
    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        if (mmap[x][y] == -1) return true;
        que.pop();
        int cost = mmap[x][y];
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i] * cost;
            int ny = y + dy[i] * cost;
            if (visited[nx][ny]) continue;
            if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
            que.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    
    return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mmap[i][j];
        }
    }
    if (isOK(n)) {
        cout << "HaruHaru";
    } else {
        cout << "Hing";
    }
    return 0;
}
