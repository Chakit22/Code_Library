    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    long long min = a[n-1] - a[0];
    
    for(long long i = 0;i<=n-m;++i)
    {
        long long j = i+m-1;
            if(a[j]-a[i]<min)
            min = a[j]-a[i];
    }
    return min;
    } 
//Link https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1/?page=1&status[]=solved&category[]=Sorting&sortBy=submissions
