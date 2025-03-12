// 1202 보석 도둑
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// dp
// 배낭 알고리즘?

// 고려 대상
// 배낭 개수 300000
// 배낭의 최대 크기 100000000
// 보석 개수 300000
// 보석의 무게 1000000
// 보석의 가치 1000000

// 보석 가치 최대화

// n번째 보석을 k번째 배낭에 넣을지 안넣을지 고르는 문제?
// 문제점 : 꽉차있는 배낭에서 보석을 빼면 다시 그 보석에대해 배낭을 골라야함

// !! 배낭 한개에 보석 한개밖에 못넣는다는 제약조건
// 크기가 작은 배낭부터 그리디하게 넣는다면 ?

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> gem_info(N);
    for (int i = 0; i < N; i++)
    {
        int M, V;
        cin >> M >> V;
        gem_info[i] = {M, -1 * V};
    }

    vector<int> bag;
    for (int i = 0; i < K; i++)
    {
        int C;
        cin >> C;
        bag.push_back(C);
    }
    sort(gem_info.begin(), gem_info.end());
    sort(bag.begin(), bag.end());

    // 그리디하게 보석을 가방에 배정
    vector<int> bag_value(K, 0);

    int idx = 0;
    priority_queue<int> pq;
    for (int i = 0; i < bag.size(); i++)
    {
        int bag_weight = bag[i];
        while(idx < N && gem_info[idx].first <= bag_weight)
        {
            pq.push(gem_info[idx].second * -1);
            idx++;
        }

        if(!pq.empty())
        {
            int value = pq.top();
            pq.pop();
    
            bag_value[i] = value;
        }
    }

    long long sum = 0;
    for (int i = 0; i < K; i++)
    {
        sum += bag_value[i];
    }
    cout << sum;

    return 0;
}