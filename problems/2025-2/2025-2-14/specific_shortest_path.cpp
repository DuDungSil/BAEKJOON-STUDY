// 1504 특정한 최단 경로
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 무방향 그래프
// 1번 정점 -> N번 정점 최단거리
// 임의의 주어진 두 정점 반드시 통과 ( 순서 없음 )
// 한번 이동했던 정점, 간선 다시 이동 가능

// 최단 경로의 길이는? 없으면 -1

// 출발지 -> v1 -> v2 -> 도착지
// 출발지 -> v2 -> v1 -> 도착지

int N, E;
int v1, v2;

int dijkstra(int start, int destination, vector<vector<pair<int, int>>>& graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N+1, 99999999);

    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty())
    {
        pair<int, int> info = pq.top();
        int cost = info.first;
        int now = info.second;
        if(now == destination)
        {
            return cost;
        }
        pq.pop();

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

    return -1;
}

int main(void) 
{

    cin >> N >> E;

    vector<vector<pair<int, int>>> graph(N+1);
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    int cost1 = dijkstra(1, v1, graph);
    if(cost1 == -1)
    {
        cout << -1;
        return 0;
    } 
    int cost2 = dijkstra(v2, N, graph);
    if(cost2 == -1)
    {
        cout << -1;
        return 0;
    } 
    int cost3 = dijkstra(1, v2, graph);
    if(cost3 == -1)
    {
        cout << -1;
        return 0;
    } 
    int cost4 = dijkstra(v1, N, graph);
    if(cost4 == -1)
    {
        cout << -1;
        return 0;
    } 
    int cost5 = dijkstra(v1, v2, graph);
    if(cost5 == -1)
    {
        cout << -1;
        return 0;
    } 

    int min_cost = min(cost1 + cost2, cost3 + cost4);
    cout << min_cost + cost5;


    return 0;
}