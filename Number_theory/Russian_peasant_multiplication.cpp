#include<bits/stdc++.h>
using namespace std;

int russian_peasant(int a,int b){
	int ans=0;
	while(b>0)
	{
		if(b&1)
			ans += a;
		a = a<<1;
		b = b>>1;
	}
	return ans;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<russian_peasant(a,b);
}