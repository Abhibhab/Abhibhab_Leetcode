//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char,int>mp;
	    for(auto it:pat){
	        mp[it]++;
	        
	    }
	    int count=mp.size();
	    int j=0,i=0;
	    int size=txt.size();
	    int length=pat.size();
	    int ans=0;
	    while(j<size){
	       if(mp.find(txt[j])!=mp.end()){
	           mp[txt[j]]--;
	           if(mp[txt[j]]==0){
	               count--;
	           }
	       }
	       if(j-i+1<length){
	           j++;
	       }else if(j-i+1==length){
	           if(count==0){
	               ans++;
	           }
	           if(mp.find(txt[i])!=mp.end()){
	               if(mp[txt[i]]==0){
	                    mp[txt[i]]++;
	                    count++;
	                   
	               }else{
	                   mp[txt[i]]++;
	               }
	              
	           }
	           i++;
	           j++;
	       }
	    }
	    return ans;
	   
	   // string helo=pat;
	   // sort(helo.begin(),helo.end());
	   // int j=0,i=0,size=txt.size(),length=pat.size();
	   // string wow="";
	   // int count=0;
	   // while(j<size){
	   //     wow+=txt[j];
	        
	   //     if(j-i+1<length){
	   //         j++;
	   //     }else if(j-i+1==length){
	   //        string hi=wow;
	   //        sort(hi.begin(),hi.end());
	   //        if(hi==helo){
	   //            count++;
	   //        }
	   //        wow.erase(0,1);
	   //        i++;
	   //        j++;
	   //     }
	   // }
	   // return count;
	    // code here
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends