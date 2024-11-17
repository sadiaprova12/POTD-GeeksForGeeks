class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        //Code Here
        int j=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                arr[j]=arr[i];
                j++;
            }
        }
        for(;j<arr.size();j++) arr[j]=0;
    }
};