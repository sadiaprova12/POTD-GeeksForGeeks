class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        int count = 1;
        int maxHeight = height[0];
        
        for (int i =1; i<height.size(); i++){
            if(height[i] > maxHeight){
                count++;
                maxHeight = height[i];
            }
        }
        return count;
    }
};