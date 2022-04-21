    vector<int> merge(vector<int>&ans,int i,int k,vector<vector<int>>&arr){
        if(i==k)
        return ans;
        
        vector<int>tmp;
        //merge arr[i] and arr[i-1] 1-d vectors
        int x=0,y=0;
        while(x<ans.size() and y<k){
            if(ans[x] <= arr[i][y]){
                tmp.push_back(ans[x++]);
            }
            else{
               tmp.push_back(arr[i][y++]); 
            }
        }
        
        while(x<ans.size())
        tmp.push_back(ans[x++]);
        
        while(y<k)
        tmp.push_back(arr[i][y++]);
        
        return merge(tmp,i+1,k,arr);
        
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
       vector<int>ans;
       for(int i=0;i<k;++i)
       ans.push_back(arr[0][i]);
       
       return merge(ans,1,k,arr);
    }
