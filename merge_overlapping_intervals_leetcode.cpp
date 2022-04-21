static bool compare(const vector<int>&a,const vector<int>&b){
    return a[0] < b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n=intervals.size();
    sort(intervals.begin(),intervals.end(),compare);
    vector<vector<int>>ans;
    vector<int>tmp;
    tmp = intervals[0];
    ans.push_back(tmp);
    for(int i=1;i<n;++i)
    {
        if(intervals[i][0] > ans[ans.size()-1][1])
            ans.push_back(intervals[i]);
        else
            ans[ans.size()-1][1] = max(intervals[i][1],ans[ans.size()-1][1]);
    }
    return ans;
}