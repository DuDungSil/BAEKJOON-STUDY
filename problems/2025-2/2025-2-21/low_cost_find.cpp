// 11779 최소비용 구하기 2
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 999999999;

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
    int start, destination;
    cin >> start >> destination;

    priority_queue<tuple<int, int, vector<int>>, vector<tuple<int, int, vector<int>>>, greater<tuple<int, int, vector<int>>>> pq;
    vector<int> dis(n+1, INF);
    vector<int> tracking;
    tracking.push_back(start);
    pq.push({0, start, tracking});
    dis[start] = 0;

    while(!pq.empty())
    {
        int cost, now;
        vector<int> history;
        tie(cost, now, history) = pq.top();
        if(now == destination)
        {
            break;
        }
        pq.pop();

        for (int i = 0; i < graph[now].size(); i++)
        {
            pair<int, int> next_info = graph[now][i];
            int next_cost = next_info.second;
            int next = next_info.first;

            if(cost + next_cost < dis[next])
            {
                dis[next] = cost + next_cost;
                vector<int> next_history(history);
                next_history.push_back(next);
                pq.push({cost + next_cost, next, next_history});
            }
        }
    }

    int cost, now;
    vector<int> history;
    tie(cost, now, history) = pq.top();

    cout << cost << "\n"
         << history.size() << "\n";
    for(int node : history)
    {
        cout << node << " ";
    }

    return 0;
}