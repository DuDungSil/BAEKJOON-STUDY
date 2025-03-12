#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int z(int depth, int r, int c)
{
    if(depth == 0)
        return 0;

    int line = pow(2, depth);
    int threshold = line / 2;

    int addiction = line * line;

    if( r < threshold && c < threshold)
    {
        return z(depth - 1, r, c) + 0;
    }
    if( r < threshold && c >= threshold)
    {
        return z(depth - 1, r, c - threshold) + addiction / 4;
    }    
    if( r >= threshold && c < threshold)
    {
        return z(depth - 1, r - threshold, c) + addiction / 4 * 2;
    }
    if( r >= threshold && c >= threshold)
    {
        return z(depth - 1, r - threshold , c - threshold ) + addiction / 4 * 3;
    }

}

int main(void) 
{

    // 2 3 1    11
    // 3 7 7    63

    int N, r, c;

    cin >> N >> r >> c;

    int depth = N;

    cout << z(depth, r, c);

    

    return 0;
}