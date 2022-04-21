#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Calculate(int arr[],int n){
    int lis[n];
    for(int i=0;i<n;i++){
        lis[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=i-1;j++){
            if((arr[i]>arr[j]) and ((lis[j]+1)>lis[i])){
            lis[i] = lis[i] +1;
            }
        }
    }
    return *max_element(lis,lis+n);

}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    cout<<Calculate(arr,n)<<endl;
    return 0;
}
