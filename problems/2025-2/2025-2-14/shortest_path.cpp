// 1753 최단경로
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 방향 그래프

int V, E, K;
const int INF = 999999999;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph)
{
    // 다익스트라
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V+1, INF);
    pq.push({0, K});
    dist[K] = 0;

    while(!pq.empty())
    {
        pair<int, int> info = pq.top();
        pq.pop();
        int cost = info.first;
        int now = info.second;

        for (int i = 0; i < graph[now].size(); i++)
        {
            pair<int, int> next_info = graph[now][i];
            int next = next_info.first;
            int next_cost = next_info.second;

            if(cost + next_cost < dist[next])
            {
                pq.push({cost + next_cost, next});
                dist[next] = cost + next_cost;
            }
        }
    }

    return dist;
}

int main(void) 
{

    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V+1);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> dis = dijkstra(K, graph);

    for (int i = 1; i <= V; i++)
    {
        int cost = dis[i];
        if(cost == INF)
        {
            cout << "INF" << "\n";
        }
        else
        {
            cout << cost << "\n";
        }
    }


    return 0;
}