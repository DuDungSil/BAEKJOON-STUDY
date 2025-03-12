// 15681 트리와 쿼리
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> sub;

int count_sub(int now) {
    sub[now] = 1;  // 자기 자신 포함
    for (int next : graph[now]) {
        if (!visited[next]) {
            visited[next] = true;
            sub[now] += count_sub(next);
        }
    }
    return sub[now];
}


int main(void) 
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R, Q;
    cin >> N >> R >> Q;

    graph = vector<vector<int>>(N+1);
    visited = vector<bool>(N + 1, false);
    sub = vector<int>(N + 1, 0);
    for (int i = 0; i < N-1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited[R] = true;
    count_sub(R);

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;

        cout << sub[q] << "\n";
    }

    return 0;
}