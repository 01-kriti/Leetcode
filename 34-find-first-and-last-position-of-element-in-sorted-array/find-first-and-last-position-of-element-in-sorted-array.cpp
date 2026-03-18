class Solution {
public:
int lowerBound(vector<int> arr, int n, int x) {
	int low=0,high=n-1;
	int ans=n;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]>= x){
			ans=mid;
			high=mid-1;
		}
		else low=mid+1;
	}
	return ans;
	
}
int upperBound(vector<int> &arr, int n, int x){
	int low=0,high=n-1;
	int ans=n;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]>x){
			ans=mid;
			high=mid-1;
		}
		else low=mid+1;
	}
	return ans;
}
    vector<int> searchRange(vector<int>& arr, int x) {
        int n=arr.size();
        int lb=lowerBound(arr,n,x);
        if(lb==n || arr[lb]!=x)return {-1,-1};
        return {lb,upperBound(arr,n,x)-1};
    }
};