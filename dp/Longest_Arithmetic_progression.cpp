//The problem faced in 1D Dp for the above problem was : - 
/*
Let's say the sequence is 1 7 10 13 
In this 1 7 13 can also be a sequence with common difference 6 and 
7 10 13 can also be sequence with common difference 3
so in 1D dp we are not sure whether dp at index of 7 is storing the length with respect to common difference 6 or 3.
So we need a 2D dp such that for 7 13 it will now check for the cell of 7 with column as 13's index which indicates the length 
when it forms a progression with 13 and similairly for 10 the other column.


Note  : - The above solution also works for duplicates and non-sorted array.
*/

int lengthOfLongestAP(int A[], int n) {
        // code here

	if (n < 3) return n;

	vector<vector<int> > dp(n, vector<int>(n, -1));

	map<int, int> pos;

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			dp[i][j] = 2;

			int dif = A[j] - A[i];

			int need = 2 * A[i] - A[j];

			if (pos.count(need) == 0) continue;

			dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);

		}
		pos[A[i]] = i;
	}

	int ans = 2;
	
// 	for(int i=0;i<n;++i)
// 	{
// 	    for(int j=0;j<n;++j)
// 	    cout<<dp[i][j]<<"   ";
	    
// 	    cout<<"\n";
// 	}
	

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			ans = max(ans, dp[i][j]);

		}

	}

	return ans;
   }
