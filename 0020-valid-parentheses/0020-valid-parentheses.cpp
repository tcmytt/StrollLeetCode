class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;  // Nếu gặp dấu đóng mà không có dấu mở tương ứng, trả về false
                } else if ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[')) {
                    st.pop();  // Loại bỏ dấu mở tương ứng
                } else {
                    return false;  // Nếu dấu đóng không tương ứng với dấu mở, trả về false
                }
            }
        }
        
        return st.empty();  // Nếu vẫn còn dấu mở chưa được đóng, trả về false
    }
};
