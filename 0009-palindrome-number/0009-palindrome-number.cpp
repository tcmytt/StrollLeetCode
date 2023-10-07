class Solution {
public:
    bool isPalindrome(int x) {
        int l , y=x;
        long kq = 0;

        if(x < 0){
            return false;
        }
        while(y){
            l = y % 10;
            kq = kq*10 + l;
            y= y/10;
        }

        if(x == int(kq)){
            return true;
        }else{
            return false;
        }
    }
};