    void merge(int arr[], int l, int mid, int h)
    {
        // Your code here
        //have been given two arrays from l to mid and mid + 1 to h
        int tmp[h-l + 1];
        //merge from mid + 1 to h and l to mid
        int i=l,j=mid+1;
        int k=0;
        
        while(i<=mid and j<=h)
        {
            if(arr[i] <= arr[j])
            tmp[k++] = arr[i++];
            else
            tmp[k++] = arr[j++];
        }
        
        while(i<=mid){
            tmp[k++] = arr[i++];
        }
        
        while(j<=h){
            tmp[k++] = arr[j++];
        }
        
        //store from l to h in arr
        for(int i=l;i<=h;++i)
        arr[i] = tmp[i-l];
        
        //printArray(arr,h+1);
    }
    public:
    void mergeSort(int arr[], int l, int h)
    {
        //code here
        if(l<h){
            int mid = (l+h)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,h);
            merge(arr,l,mid,h);
        }
    }
