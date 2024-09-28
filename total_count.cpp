class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        // code here
        int total = 0;
        
        for (int num : arr){
            total += (num + k -1 ) / k;
        }
        return total;
    }
};