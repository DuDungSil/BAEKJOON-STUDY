// 1238 파티
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// N개의 마을
// x번 마을에서 파티
// 각각의 학생이 파티에 참여 후 다시 마을로 돌아옴
// 최단시간으로
// 도로가 단방향임

// 다익 두번?

const int INF = 999999999;
int N, M, X;
vector<vector<pair<int, int>>> graph;

int dijkstra(int start, int destination)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(N+1, INF);

    pq.push({0, start});
    dis[start] = 0;

    while(!pq.empty())
    {
        pair<int, int> info = pq.top();
        pq.pop();

        int cost = info.first;
        int now = info.second;

        if (now == destination)
        {
            break;
        }

        for (int i = 0; i < graph[now].size(); i++)
        {
            pair<int, int> next_info = graph[now][i];
            int next = next_info.first;
            int next_cost = next_info.second;

            if(cost + next_cost < dis[next])
            {
                dis[next] = cost + next_cost;
                pq.push({cost + next_cost, next});
            }
        }

    }

    return dis[destination];
}

int main(void) 
{

    cin >> N >> M >> X;

    graph = vector<vector<pair<int, int>>>(N+1);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    // 다익
    int time_max = 0;
    for(int i = 1; i <= N; i++)
    {
        int time_sum = 0;
        time_sum += dijkstra(i, X);
        time_sum += dijkstra(X, i);
        time_max = max(time_max, time_sum);
    }

    cout << time_max;

    return 0;
}