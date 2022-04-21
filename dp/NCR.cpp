ll ncr(int n, int k)
{
	ll C[n + 1][k + 1];
	int i, j;

	// Caculate value of Binomial Coefficient
	// in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= min(i, k); j++)
		{
			// Base Cases
			if (j == 0 || j == i)
				C[i][j] = 1;

			// Calculate value using previosly
			// stored values
			else
				C[i][j] = C[i - 1][j - 1] +
				          C[i - 1][j] + 0ll;
		}
	}

	return C[n][k];
}
