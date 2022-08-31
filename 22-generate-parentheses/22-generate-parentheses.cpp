class Solution {
public:
    vector<string>vec;
    vector<string> generateParenthesis(int n) {
        
         helper(n,n,"");  
        return vec;
        
        
    }
    void helper(int right,int left,string str){
        if(right==0){
            while(left--){
                str+=')';               
                
            }
            vec.push_back(str);
            return;
        }
        
            helper(right-1,left,str+'(');
            if(left>right){
                helper(right,left-1,str+')');
            }   
                
        
        
        
    }
    
};