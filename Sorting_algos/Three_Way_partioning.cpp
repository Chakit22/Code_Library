    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int cnt_less_a,cnt_rangeab,cnt_gretb;
        int n=arr.size();
        for(int i=0;i<n;++i)
        {
            if(arr[i]<a)
            cnt_less_a++;
            else if(arr[i]>=a && arr[i]<=b)
            cnt_rangeab++;
            else
            cnt_gretb++;
        }
        
        int j=n-1;
        int i=0;
        while(i<j)
        {
            while(i<n && arr[i]<a)
            ++i;
            
            while(j>=0 && arr[j]>=a)
            j--;
            
            if(i<j)
            {
                swap(arr[i],arr[j]);
            }
        }
        
        i=cnt_less_a;
        j=n-1;
        while(i<j)
        {
            while(i<n && arr[i]>=a && arr[i]<=b)
            i++;
            
            while(j>=0 && arr[j]>b)
            j--;
            
            if(i<j)
            {
            swap(arr[i],arr[j]);
            }
        }
    }

//LInk https://practice.geeksforgeeks.org/problems/three-way-partitioning/1/?page=1&status[]=solved&category[]=Sorting&sortBy=submissions
