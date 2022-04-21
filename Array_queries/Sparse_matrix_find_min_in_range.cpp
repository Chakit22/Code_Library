#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>
//For some number of queries
int dp[2000000][25];


int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //SPARSE MATRIX
    int n, q;
    scanf("%d %d", &n, &q);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    int col = ceil(log2(n));
    for (int i = n; i < 2 * n; ++i)
    {
        for (int j = 0; j < col; ++j)
            dp[i][j] = INT_MAX;
    }

    for (int cl = 0; cl < col; ++cl) {
        for (int row = 0; row < n; ++row) {
            if (cl == 0)
                dp[row][cl] = a[row];
            else {
                dp[row][cl] = min(dp[row][cl - 1], dp[row + (1 << (cl - 1))][cl - 1]);
            }
        }
    }
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        //find minimum in range l to r

        int min_val = INT_MAX;
        int no_ele = r - l + 1, cur = l;
        for (int bit = col - 1; bit >= 0; bit--) {
            if ((no_ele & (1 << bit)) != 0) {
                min_val = min(min_val, dp[cur][bit]);
                cur += (1 << bit);
            }
        }

        printf("%d\n", min_val);
    }
    return 0;
}
