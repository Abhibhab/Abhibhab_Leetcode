class Solution {
public:
        double myPowo(double x, int n) {
        if(n==0)  return 1;        
        if(n==1) return x;        
        double small=myPow(x,n/2);
        if(n%2==0) return small*small;
        else return small*small*x;           
            
        }  

    double myPow(double x, int n) {        
        double ans=myPowo(x,abs(n));
        if(n>0) return ans;
        else return 1.0/ans;       
        
        
        
    }
};