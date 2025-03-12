#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void) 
{

    int start, end;
    cin >> start >> end;

    queue<pair<int, int>> q;
    vector<bool> visited(300000, false);

    int min_time = 0;
    int min_count = 0;

    q.push({0, start});
    visited[start] = true;

    while(!q.empty())
    {
        pair<int, int> info = q.front();
        int time = info.first;
        int now = info.second;
        q.pop();

        visited[now] = true;

        if(now == end)
        {
            if(min_time == 0) 
            {
                min_time = time;
                min_count++;
            }
            else
            {
                if(min_time != time)
                    break;
                min_count++;
            }
        }

        if(min_time == 0)
        {
            int next1 = now - 1;
            if(next1 >= 0 && !visited[next1])
            {
                q.push({time + 1, next1});
            }
    
            int next2 = now + 1;
            if(next2 <= 300000 && !visited[next2])
            {
                q.push({time + 1, next2});
            }
            
            int next3 = now * 2;
            if(next3 <= 300000 && !visited[next3])
            {
                q.push({time + 1, next3});
            }
        }

    }

    cout << min_time << "\n" << min_count;

    return 0;
}