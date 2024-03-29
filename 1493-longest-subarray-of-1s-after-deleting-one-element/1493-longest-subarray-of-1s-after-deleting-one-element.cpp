class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len=nums.size();
        int zero=0;
        int ans=0;
        int start=0;
        int temp=0;
        for(int i=0;i<len;i++){
            zero+=(nums[i]==0);
            while(zero>1){
                zero-=(nums[start]==0);
                start++;
            }
            temp=i-start;
            if(temp>ans)
                ans=temp;
        }
        return ans;
    }
};