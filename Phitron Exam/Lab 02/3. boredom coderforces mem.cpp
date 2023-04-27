#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];

int boredom(int n)
{
    if(n == 0) return 0;
    if(n == 1) return dp[1];

    return max( boredom(n-1), boredom(n-2) + n * dp[n]); 
}

int main()
{
    int n, maxx = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        dp[b]++;

        maxx = max(maxx,b);
    }

    cout << boredom(maxx) << endl;
    return 0;
}
