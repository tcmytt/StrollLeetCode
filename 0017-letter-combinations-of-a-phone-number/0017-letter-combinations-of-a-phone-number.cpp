class Solution {
public:
    vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> result ;
    
    void dequy (int pos, int n,string digits, string sum){
        int index = digits[pos] -'2';
        int x = mapping[index].size();
        for(int i=0;i<x;i++){
            sum+=mapping[index][i];
            if(sum.size()==n){
                result.push_back(sum);
            }else{
                dequy(pos+1, n,digits, sum);
            }
            sum.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        
        if (digits.empty()) {
            return {};
        }
        
        dequy(0,n,digits,"");
        
        return result;
    }
};