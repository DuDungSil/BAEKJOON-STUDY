// 1766 문제집
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 위상 정렬

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    vector<int> indegree(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++)
    {
        if(indegree[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int now = pq.top();
        pq.pop();

        cout << now << " ";

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            indegree[next]--;
            if(indegree[next] == 0)
                pq.push(next);
        }
    }
    
    return 0;
}