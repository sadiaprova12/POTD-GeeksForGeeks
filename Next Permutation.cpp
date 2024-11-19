class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int peak=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                peak=i;
                break;
            }
        }
        if(peak==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>peak;i--){
            if(nums[peak]<nums[i]){
                swap(nums[peak],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+peak+1,nums.end());
        return;
    }
};