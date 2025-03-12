// 1043 거짓말
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 지민 : 진실을 과장함

// 몇몇 사람은 진실을 앎

// 진실을 아는 사람이 있는 파티에서는 과장을 하면 안됨

// + 진실을 말한 파티와 과장을 한 파티에 같은 사람이 존재하면 안됨

// 지민이가 거짓말쟁이로 알려지지 않으면서, 과장된 이야기를 할 수 있는 파티의 개수

// 진실만 말해야하는 파티 -> 진실만 들어야하는 사람 

int main(void) 
{

    int N, M;
    cin >> N >> M;

    int truth_num;
    cin >> truth_num;

    vector<bool> truth(N+1, false);
    for (int i = 0; i < truth_num; i++)
    {
        int num;
        cin >> num;
        truth[num] = true;
    }

    vector<vector<int>> parties;
    for(int i = 1; i <= M; i++)
    {
        int party_num;
        cin >> party_num;
        vector<int> party;
        for (int j = 0; j < party_num; j++)
        {
            int num;
            cin >> num;
            party.push_back(num);
        }
        parties.push_back(party);
    }

    // 탐색
    vector<bool> truth_parties(M, false);
    queue<vector<int>> q;
    for (int i = 0; i < parties.size(); i++)
    {
        vector<int> party = parties[i];
        for (int j = 0; j < party.size(); j++)
        {
            if(truth[party[j]])
            {
                truth_parties[i] = true;
                q.push(party);
                break;
            }
        }
    
    }

    while (!q.empty())
    {
        vector<int> party = q.front();
        q.pop();

        for (int j = 0; j < party.size(); j++)
        {
            truth[party[j]] = true;
        }

        for (int i = 0; i < parties.size(); i++)
        {
            if(truth_parties[i])
                continue;

            vector<int> party = parties[i];

            for (int j = 0; j < party.size(); j++)
            {
                if(truth[party[j]])
                {
                    truth_parties[i] = true;
                    q.push(party);
                    break;
                }
            }
        }

    }

    int count = 0;
    for (int i = 0; i < parties.size(); i++)
    {

        if(!truth_parties[i])
        {
            count++;
        }
    }

    cout << count;

    return 0;
}