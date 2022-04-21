  vector <int> bottomView(Node *root) {
      // Your Code Here
    
      //Your code here
    queue<pair<Node *,int>>q;
    vector<int>v;
    map<int,int>m;
    if(root == NULL)
    return v;
    q.push({root,0});
    
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;++i)
        {
            pair<Node *,int> deleted = q.front();
            q.pop();
            
            Node *cur = deleted.first;
            int hd = deleted.second;
            //cout<<i<<"   ";
            //if(m.find(hd) == m.end())
            m[hd] = cur->data;
             
            if(cur->left)
            q.push({cur->left,hd-1});
            
            if(cur->right)
            q.push({cur->right,hd+1});
        }
    }
    
    for(auto i:m)
    v.push_back(i.second);
    return v;
  }