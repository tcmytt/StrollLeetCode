class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result ;
        int i=0, j=0;
        int n= nums1.size();
        int m =nums2.size();
        while(i<n && j<m){
            if(nums1[i] <  nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }else{
                result.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n) {
            result.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            result.push_back(nums2[j]);
            j++;
        }
        float z = result.size()%2;
        float x = 0;
        if(z==0){
            z = result.size() /2;
            x = (result[z] + result[z-1] )*1.0 /2;
            return x;
        }else{
            return result[result.size() /2];
        }
    }
};