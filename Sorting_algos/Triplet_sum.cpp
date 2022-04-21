    bool find3Numbers(int a[], int n, int X)
    {
        //Your Code Here
        sort(a,a+n);
    
    if(X<a[0])
    return 0;
    
    for(int i=0;i<n-2;++i)
    {
        int s = X - a[i];
        int l=i+1;
        int h=n-1;
        
        while(l<h)
        {
            if(s == a[l] + a[h])
            return 1;
            else if(a[h]+a[l]<s)
            l++;
            else if(a[h]+a[l]>s)
            h--;
        }
    }
    return 0;
    }
