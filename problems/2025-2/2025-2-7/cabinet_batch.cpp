#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<long long> &v1, vector<long long> &v2) {
    if (v1[1] == v2[1]) return v1[0] < v2[0];  
    return v1[1] < v2[1];
}
int main(void) 
{

    int N;
    cin >> N;

    vector<vector<long long>> info(N);

    for (int i = 0; i < N; i++){
        long long a, b;
        cin >> a >> b;
        info[i].push_back(a);
        info[i].push_back(b);
    }

    // 시작시간 끝나는시간 0 ~ 2^31 - 1
    // 회의 안겹치게 하면서 회의실 사용할 수 있는 최대개수
    // 그리디

    sort(info.begin(), info.end(), cmp);

    int count = 0;
    int last = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if(last <= info[i][0])
        {
            count++;
            last = info[i][1];
        }
    }

    cout << count;

    return 0;
}