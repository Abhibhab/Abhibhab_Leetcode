class Solution {
public:
    int bagOfTokensScore(vector<int>& arr, int power) {
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        int score=0;
        while(i<j){
            if(power>=arr[i]){
                power-=arr[i++];
                score++;
            }else if(score>=1 && power+arr[j]>=arr[i]){
                power+=arr[j--];
                score--;
                
            }else{
                break;
            }
            
        }
        while(i<j+1 && arr[i]<=power){
            score++;
            power-=arr[i++];
        }
        return score;
        
    }
};