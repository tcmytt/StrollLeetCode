class Solution {
public:
    int strStr(string haystack, string needle) {
        int x = haystack.size();
        int y = needle.size();
        
        for(int i =0;i<x;i++){
            int check =0;
            while(haystack[i+check] == needle[check] && check< y){
                check++;
            }
            if(check == y) return i;
        }
        
        return -1;
    }
};