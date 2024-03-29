class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(mp.count(nums[i])>0 && i-mp[nums[i]]<=k)
                    return true;
            mp[nums[i]]=i;
        }
        return false;
    }
};