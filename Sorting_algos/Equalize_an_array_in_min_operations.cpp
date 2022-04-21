    int M=1e9+7;
    
    int equalizeArray(int n, int k, int a[]){
        // code here
        sort(a,a+n);
        int sm=0;
       
    
        int val=a[n/2];
        
    for(int i=0;i<n;++i)
        {
            if((a[i] - a[0]) % k !=0)
            return -1;
            else{
                sm+= (abs(val-a[i])/k);
                sm= sm%M;
            }
        }
        return sm;
    }
