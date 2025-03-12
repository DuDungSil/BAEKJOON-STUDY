// 10775 공항
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int G, P;
    cin >> G >> P;

    vector<int> planes(P);
    for (int i = 0; i < P; i++)
    {
        int g;
        cin >> g;
        planes[i] = g;
    }

    vector<int> go(G + 1);
    for (int i = 1; i <= G; i++)
    {
        go[i] = i;
    }

    int count = 0;
    for (int i = 0; i < planes.size(); i++)
    {
        int now = planes[i];

        while(now > 0)
        {
            if(go[now] == now)
            {
                count++;
                go[now]--;
                break;
            }
            else
            {
                int next = go[now]--;
                now = next;
            }
        }
        
        if(now == 0)
            break;
    }

    cout << count;

    return 0;
}