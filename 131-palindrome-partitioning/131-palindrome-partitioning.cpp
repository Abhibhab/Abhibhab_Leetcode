class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
        vector<string>vec;
        helper(s,0,vec,s.size());
        return ans;
        
        
        
    }
    void helper(string s,int index,vector<string>vec,int size){
        if(index==size){
            ans.push_back(vec);
        }
        for (int i = index; i < size; ++i) {
      if (ispalindrome(s, index, i)) {
        vec.push_back(s.substr(index, i - index + 1));
       helper(s,i+1,vec,size);
        vec.pop_back();
      }
    }
    }
    bool ispalindrome(string s,int start,int end){
       while(start<=end){
           if(s[start++]!=s[end--]) return false;
       }
        return true;
    }
    
};