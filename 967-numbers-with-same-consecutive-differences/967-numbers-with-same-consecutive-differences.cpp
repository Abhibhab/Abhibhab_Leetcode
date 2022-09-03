class Solution {
public:
    vector<int>ans;
    vector<int> numsSameConsecDiff(int n, int k) {
        //choosing the first digit
        for(int i=1;i<=9;i++){
            make_Nnum(n,k,1,i,i);            
        }
        return ans;
        
        
    }
    void make_Nnum(int n,int k,int digit,int num,int last){
        if(digit==n){
            ans.push_back(num);
            return;
        }
        //choosing the remaining digits
        for(int i=0;i<=9;i++){
            if(abs(last-i)==k) {
                make_Nnum(n,k,digit+1,num*10+i,i);
            }
            
        }
    }
};