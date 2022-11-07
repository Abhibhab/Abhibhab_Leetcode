class Solution {
public:
    int maximum69Number (int num) {
       string helo=to_string(num);
        for(int i=0;i<helo.size();i++){
            if(helo[i]=='6'){
                helo[i]='9';
                break;
            }
            
}
        return stoi(helo);
        
    }
};