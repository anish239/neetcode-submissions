class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 1;

        int maxLen = INT_MIN,currLen = 0;

        for(int i = 1; i<n; i++){
            if(arr[i-1] == arr[i]){
                currLen = 1;
            }
            else if(i > 1 && arr[i-2] < arr[i-1] != arr[i-1] < arr[i]){
                currLen++;
            }
            else{
                currLen = 2;
            }
            maxLen = max(maxLen,currLen);
        }
        return maxLen;
    }
};