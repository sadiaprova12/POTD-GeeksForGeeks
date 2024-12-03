class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        //code here
        if(s1.size()!=s2.size()) return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        return freq1==freq2;
    }
};