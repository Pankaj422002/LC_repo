#include<bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &arr, int x){
    int n=arr.size(),ans=-1;
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;

        if(arr[mid] == x){
            ans=mid;
            e=mid-1;
        }else if(arr[mid] > x){
            e=mid-1;
        }else if(arr[mid] < x){
            s=mid+1;
        }
    
    }
    return ans;
}

int lastOccurence(vector<int> &arr, int x){
    int n=arr.size(),ans=-1;
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;

        if(arr[mid] == x){
            ans=mid;
            s=mid+1;
        }else if(arr[mid] > x){
            e=mid-1;
        }else if(arr[mid] < x){
            s=mid+1;
        }
    
    }
    return ans;
}

vector<int> find(vector<int>& arr, int x) {
    // code here
    int n=arr.size();
    vector<int> ans(2,-1);
    
    ans[0]=firstOccurence(arr,x);
    ans[1]=lastOccurence(arr,x);

    return ans;
}

int main(){

    int n,x;cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int> ans=find(arr,x);

    for(auto it: ans)cout<<it<<" ";
    cout<<endl;

    return 0;
}
