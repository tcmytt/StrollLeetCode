class Solution {
    public:
    string longestPalindrome(string s) {
    int index = 0;
    int nhieu = 0;
    int n = s.size();

    if (n == 1) {
        return s;
    }

    int check = 0;
    for (int i = 1; i < n; i++) {
        int l = i, r = i, tmp = 0;

        if (l >= 0 && r + 1 < n && s[l] == s[r + 1]) {
            while (l >= 0 && r + 1 < n && s[l] == s[r + 1]) {
                l--;
                r++;
                tmp += 1;
            }
            if (tmp > nhieu) {
                nhieu = tmp;
                index = i;
                check = 1;
                cout<<"check 1"<<endl;
            }
        }

		l = i, r = i, tmp = 0;
        if (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1]) {
            while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1]) {
                l--;
                r++;
                tmp += 1;
            }

            if (tmp >= nhieu) {
                nhieu = tmp;
                index = i;
                check = 2;
                cout<<"check 2"<<endl;
            }
            continue;
        }

    }
    string result;
    if (check == 1) {
        result = s.substr(index - nhieu + 1, nhieu + nhieu);
    } else if (check == 2) {
        result = s.substr(index - nhieu, nhieu + nhieu + 1);
    } else if (check == 0) {
        int c = 1;
        for (int x = 0; x < n - 1; x++) {
            if (s[x] == s[x + 1]) {
                c++;
            }
            if (s[x] != s[x + 1]) {
                break;
            }
        }
        result = s.substr(0, c);
    }

    return result;
}
};