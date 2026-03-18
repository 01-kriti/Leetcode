// class Solution {
// public:
// int lowerBound(vector<int> arr, int n, int x) {
// 	int low=0,high=n-1;
// 	int ans=n;
// 	while(low<=high){
// 		int mid=(low+high)/2;
// 		if(arr[mid]>= x){
// 			ans=mid;
// 			high=mid-1;
// 		}
// 		else low=mid+1;
// 	}
// 	return ans;
	
// }
// int upperBound(vector<int> &arr, int n, int x){
// 	int low=0,high=n-1;
// 	int ans=n;
// 	while(low<=high){
// 		int mid=(low+high)/2;
// 		if(arr[mid]>x){
// 			ans=mid;
// 			high=mid-1;
// 		}
// 		else low=mid+1;
// 	}
// 	return ans;
// }
//     vector<int> searchRange(vector<int>& arr, int x) {
//         int n=arr.size();
//         int lb=lowerBound(arr,n,x);
//         if(lb==n || arr[lb]!=x)return {-1,-1};
//         return {lb,upperBound(arr,n,x)-1};
//     }
// };

int first(vector<int>&arr,int n,int x){
	int ans=-1;
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==x){
			ans=mid;
			high=mid-1;
		}
		else if(arr[mid]<x) low=mid+1;
		else high=mid-1;
	}
	return ans;
}
int last(vector<int>&arr,int n,int x){
	int ans=-1;
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==x){
			ans=mid;
			low=mid+1;
		}
		else if(arr[mid]<x) low=mid+1;
		else high=mid-1;
	}
	return ans;
}

class Solution{
public:

    vector<int>searchRange(vector<int>&arr,int k){
        int n=arr.size();
        int f=first(arr,n,k);
	    if(f==-1)return{-1,-1};
	    int l=last(arr,n,k);
	    return{f,l};
    }

};