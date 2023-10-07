class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j =height.size()-1;
        priority_queue <int> pq;
        int x;
        while(i != j){
            if(height[i] >= height[j]){
                x= height[j] *(j - i );
                pq.push(x);
                j--;
            }
            if(height[i] < height[j]){
                x= height[i] *(j - i );
                pq.push(x);
                i++;                
            }
        }
        return pq.top();
    }
};