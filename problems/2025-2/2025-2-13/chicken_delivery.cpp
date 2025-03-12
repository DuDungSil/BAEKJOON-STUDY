// 15686 치킨 배달
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 치킨 거리 : 가장 가까운 치킨집과의 거리
// 도시의 치킨 거리 : 모든 집의 치킨 거리의 합
// 치킨집 폐업할거임
// 가장 수익을 많이 낼 수 있는 치킨집의 개수 M

// 1 : 집
// 2 : 치킨집
// 집의 개수는 2N을 넘지않음, 적어도 1개 존재
// 치킨집의 개수는 M보다 크거나 같고 13보다 작거나 같음

// 도시의 치킨 거리를 가장 작게 만들어라

// 무조건 빼야하는 치킨집의 개수를 구하기

// 치킨집과 가까운 집이 하나라도 존재한다면 -> 치킨집을 제거시 무조건 도시의 치킨 거리는 증가

// 치킨집과 가까운 집이 하나도 없다면? 제거가능

// 그리디 ?


vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int min_dis = 999999999;

void DFS(vector<pair<int, int>>& comb, int start, int depth)
{
    if(comb.size() == depth)
    {
        int chicken_dis = 0;
        for (int i = 0; i < house.size(); i++)
        {
            pair<int, int> pos1 = house[i];
            int min_chicken_dis = 999999999;
            for (int j = 0; j < comb.size(); j++)
            {
                pair<int, int> pos2 = comb[j];
                int dis = abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
                min_chicken_dis = min(min_chicken_dis, dis);
            }
            chicken_dis += min_chicken_dis;
        }
        min_dis = min(min_dis, chicken_dis);

        return;
    }

    for (int i = start; i < chicken.size(); i++)
    {
        comb.push_back(chicken[i]);
        DFS(comb, i+1, depth);
        comb.pop_back();
    }
}

int main(void) 
{

    int N, M;
    cin >> N >> M;

    // 입력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            if(num == 1)
                house.push_back({i, j});
            else if(num == 2)
                chicken.push_back({i, j});
        }
    }

    // 폐업할 M 
    vector<pair<int, int>> comb;
    DFS(comb, 0, M);

    cout << min_dis;

    return 0;
}