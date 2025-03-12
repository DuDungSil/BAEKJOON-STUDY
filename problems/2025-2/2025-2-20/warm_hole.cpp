// 1865 웜홀
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 밸만 포드?
// 음의 사이클 체킹

int const INF = 999999999;
vector<vector<pair<int, int>>> roads;
vector<int> dis;

bool vellman_ford(int start, int N, vector<vector<pair<int, int>>>& roads)
{

    dis = vector<int>(N + 1, INF);
    dis[start] = 0;

    bool flag = true;
    for (int i = 1; i <= N; i++)
    {
        bool updated = false;
        for (int j = 1; j <= N; j++)
        {
            vector<pair<int, int>>& road = roads[j];
            // 간선
            for (int k = 0; k < road.size(); k++)
            {
                pair<int, int> info = road[k];
                int next_cost = info.second;
                int next = info.first;

                if( dis[j] != INF && dis[j] + next_cost < dis[next])
                {
                    dis[next] = dis[j] + next_cost;
                    updated = true;
                }
            }
        }

        if(!updated)
        {
            flag = false;
            break;
        }
    }

    return flag;
}


int main(void) 
{

    int TC;
    cin >> TC;

    bool success = false;
    for (int i = 0; i < TC; i++)
    {
        int N, M, W;
        cin >> N >> M >> W;

        roads = vector<vector<pair<int, int>>>(N+1);
        for (int j = 0; j < M; j++)
        {
            int S, E, T;
            cin >> S >> E >> T;
 
            roads[S].push_back({E, T});
            roads[E].push_back({S, T});
        }

        for (int j = 0; j < W; j++)
        {
            int S, E, T;
            cin >> S >> E >> T;

            roads[S].push_back({E, T * -1});

        }

        bool success = false;
        for (int j = 1; j <= N; j++)
        {
            if(vellman_ford(j, N, roads))
            {
                success = true;
                break;
            }
        }

        if(success)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }

    }


    return 0;
}