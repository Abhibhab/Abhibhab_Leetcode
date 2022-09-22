class Solution {
public:
    string hi(string str){
        string bro;
        bro=str;
        reverse(bro.begin(),bro.end());
        
        return bro;
    }
    string reverseWords(string s) {
        string ji=" ";
        string ans="";
        for(int i=0;i<s.size();i++){
           
            if(s[i]==' '){
                ans+=hi(ji);
                ji=' ';
                                
            }else{
                 ji+=s[i];
            }
            
        }
        ans+=hi(ji);
        return ans.substr(0,ans.size()-1);
        
        
    }
};