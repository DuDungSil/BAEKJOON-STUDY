// 14938 서강그라운드
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 다익스트라

int n, m, r;
int max_items = 0;
vector<int> items;
vector<vector<pair<int, int>>> roads;

vector<int> dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n+1, 999999999);

    pq.push({0, start});
    dis[start] = 0;

    while (!pq.empty())
    {
        pair<int, int> info = pq.top();
        pq.pop();

        int cost = info.first;
        int now = info.second;

        for (int i = 0; i < roads[now].size(); i++)
        {
            pair<int, int> next_info = roads[now][i];
            int next_cost = next_info.second;
            int next = next_info.first;

            if(cost + next_cost < dis[next])
            {
                dis[next] = cost + next_cost;
                pq.push({cost + next_cost, next});
            }
        }
    }

    return dis;
}

int main(void) 
{

    cin >> n >> m >> r;

    items = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> items[i];
    }

    roads = vector<vector<pair<int, int>>>(n + 1);
    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        roads[a].push_back({b, l});
        roads[b].push_back({a, l});
    }

    // 탐색 + 다익
    for (int i = 1; i <= n; i++)
    {
        vector<int> dis = dijkstra(i);

        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if(dis[j] <= m)
            {
                sum += items[j];
            }
        }
        max_items = max(max_items, sum);
    }

    cout << max_items;

    return 0;
}