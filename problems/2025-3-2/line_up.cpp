// 2252 줄 세우기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 위상정렬

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    vector<int> inDegree(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        cout << now << " ";

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            inDegree[next]--;
            if(inDegree[next]==0)
            {
                q.push(next);
            }
        }
    }

    return 0;
}