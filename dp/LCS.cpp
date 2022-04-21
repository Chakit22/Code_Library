#include<bits/stdc++.h>
using namespace std;

pair<int, int> lcs(int x, int y, string s1, string s2)
{
    vector<vector<pair<int, int>>>dp(x + 1, vector<pair<int, int>>(y + 1));
    int dp[x + 1][y + 1];
    string ans;

    for (int i = 0; i <= y; ++i)
        dp[0][i] = 0;

    for (int i = 1; i <= x; ++i)
        dp[i][0] = 0;

    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = x, j = y;
    string idx;
    while (i >= 1 and j >= 1) {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            char c = i - 1 + '0';
            idx += c;
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] == dp[i][j - 1]) {
                i--;
            } else if (dp[i][j - 1] > dp[i - 1][j]) {
                j--;
            } else
                i--;
        }
    }
    return dp[x][y];
}

int main() {
    string a;
    string b;
    cin >> a >> b;
    // cout << lcs(a.size(), b.size(), a, b);
}
