 string add_strings(string &ans1,string &ans2){
        int carry = 0;
        int sm=0;
        int l1=ans1.size(),l2=ans2.size();
        int i=0,j=0;
        
        
        while(i<l1 and j<l2){
            int add = (ans1[i]-'0') + (ans2[j]-'0') + carry;
            carry = add/10;
            sm = add%10;
            ans1[i] = sm + '0';
            i++;
            j++;
        }
        return ans1;
    }
    
  
    string multiplyStrings(string a, string b) {
       int i,j;
       int carry=0,sm=0;
       
       bool flag = true;
       if(a[0] == '-' and b[0]!='-'){
           a.erase(0,1);
           flag = false;
       }else if(a[0]!='-' and b[0]=='-')
       {
           b.erase(0,1);
           flag = false;
       }else if(a[0] == '-' and b[0] == '-'){
           a.erase(0,1);
           b.erase(0,1);
       }
       reverse(a.begin(),a.end());
       reverse(b.begin(),b.end());
       
       int l1=a.size();
       int l2=b.size();
       
       string ans1(l1+l2+10,'0');
       
       for(j=0;j<l2;++j){
           string ans2(l1+l2+10,'0');
           for(i=0;i<l1;i++){
               
               int pro = (b[j]-'0')*(a[i]-'0') + carry;
               carry = pro/10;
               sm = pro%10;
               ans2[i+j] = sm + '0';
           }
           ans2[i+j] = carry+'0';
           ans1 = add_strings(ans1,ans2);
           carry = 0;
       }
    reverse(ans1.begin(),ans1.end());
    string final = "";
    int d=0;
    
    while(d<ans1.size() and ans1[d]<=48 or ans1[d]>=58)
    d++;
    
    if(d==ans1.size())
    return "0";
    
    if(flag == false)
    final +="-";
    
    for(int j=d;j<ans1.size();++j)
    final += ans1[j];
    
    return final;
    }


//Code 2




    string multiplyStrings(string s1, string s2) {
       //Your code here
       if(s1 == "0" or s2 == "0")
       return "0";
       bool flag=true;
       if(s1[0]=='-' && s2[0]!='-'){
           s1.erase(0,1);
           flag=false;
       }
       else if(s1[0]!='-' && s2[0]=='-'){
           s2.erase(0,1);
           flag=false;
       }
       else if(s1[0]=='-' && s2[0]=='-'){
           s1.erase(0,1);
           s2.erase(0,1);
       }
      
       int n1=s1.length();
       int n2=s2.length();
       string s3;
       vector<int> ans(n1+n2,0);
       
       for(int i=n1-1;i>=0;i--){
           for(int j=n2-1;j>=0;j--){
               ans[i+j+1] += (s1[i]-'0')*(s2[j]-'0');
               int carry=ans[i+j+1];
               ans[i+j] += carry/10;
               ans[i+j+1]=carry%10;
           }
       }
       int i=0;
       
      while(ans[i]==0)i++;
      if(flag==false){
          s3 += '-';
      }
      
       while(i<ans.size())s3+=to_string(ans[i++]);
       return s3;
       
    }
