class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> m;

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int kq= 0;

        for(int i =s.size()-1 ; i >= 0 ; i-- ){
            if(m[s[i]] < m[s[i+1]]){
                kq = kq -m[s[i]];
            }else{
                kq = kq + m[s[i]];
            }
        }

        return kq;
    }
};