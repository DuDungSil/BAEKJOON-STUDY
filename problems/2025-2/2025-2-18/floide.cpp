// 11404 플로이드
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 999999999;

// 한 도시 출발 다른 도시 도착 m개 버스
// 모든 도시의 쌍 ( A, B ) 에 대해서 도시 A에서 B로 가는 최소비용

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(graph.size(), INF);

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        pair<int, int> info = pq.top();
        pq.pop();

        int cost = info.first;
        int now = info.second;

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next_cost = graph[now][i].second;
            int next = graph[now][i].first;

            if(cost + next_cost < dist[next])
            {
                dist[next] = cost + next_cost;
                pq.push({cost + next_cost, next});
            }
        }
    }

    return dist;
}

int main(void) 
{

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++)
    {
        vector<int> v = dijkstra(i, graph);

        for (int j = 1; j <= n; j++)
        {
            if(v[j] == INF) cout << 0 << " ";
            else cout << v[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}