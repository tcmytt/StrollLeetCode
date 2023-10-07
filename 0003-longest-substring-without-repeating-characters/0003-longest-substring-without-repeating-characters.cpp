
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> check;
        int x=0;
        int maxnow =0;
        int j=0;
        for(int i=0;i<s.size();i++){
            
            // Khong tim thay
            if(check.find(s[i]) == check.end()){
                check.insert(s[i]);
                x=x+1;
                 maxnow=max(maxnow,x);
                continue;
            }
                
            //Tim thay
            if(check.find(s[i]) != check.end()){

                while( check.find(s[i]) != check.end() ){
                    check.erase(s[j]);
                    x=x-1;
                    j++;
                }
                check.insert(s[i]);
                x=x+1;
                 maxnow=max(maxnow,x);
            }

           

        }

        return maxnow;
    }
};