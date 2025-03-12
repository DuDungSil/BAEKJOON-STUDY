// 1916 최소비용 구하기
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>

using namespace std;

int main(void) 
{

    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> bus(N+1);
    for (int i = 0; i < M; i++)
    {
        int s, d, cost;
        cin >> s >> d >> cost;
        pair<int, int> info(d, cost);
        bus[s].push_back(info);
    }
    int start, destination;
    cin >> start >> destination;

    // 다익스트라
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int dist[1001];
    for (int i = 1; i <= N; i++)
    {
        dist[i] = 2000000000;
    }
    pq.push({0, start});

    while(!pq.empty())
    {
        pair<int, int> now_info = pq.top();
        int now_cost = now_info.first;
        int now = now_info.second;
        
        if(now == destination)
        {
            break;
        }

        pq.pop();

        for (int i = 0; i < bus[now].size(); i++)
        {
            pair<int, int> next_info = bus[now][i];
            int next_node = next_info.first;
            int next_cost = next_info.second;

            if(now_cost + next_cost < dist[next_node])
            {
                pq.push({ now_cost + next_cost, next_node});
                dist[next_node] = now_cost + next_cost;
            }
        }

    }

    cout << pq.top().first;

    return 0;
}