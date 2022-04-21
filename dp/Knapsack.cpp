#include<bits/stdc++.h> 
using namespace std; 
int go(int index,int Wk,vector<pair<int,int>>& items)
{
 if(index== items.size() || Wk <=0)
{
 return 0;
 }
 int exclude=go(index+1,Wk,items); 
int include=INT_MIN; 
if(items[index].second <= Wk)
{ 
include=items[index].first + go(index+1,Wk-items[index].second,items); 
} 
return max(include,exclude); 
}

 int main()
{
 vector<pair<int,int>> items={{40,5},{35,2},{20,3},{76,6}}; 
int Wk=7; 
cout<<go(0,Wk,items)<<"\n"; 
return 0; 
} 

//The space can be optimized to O(Weight) as we need just the previous one row.
