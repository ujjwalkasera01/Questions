class Solution {
public:
    // Same code as below But Better TC 
    vector<vector<int>>ans;
    void solve(int index,int k,int n,vector<int> &vec){
        if(!k || !n){
            if(!k && !n)
            ans.push_back(vec);
            return;
        }
        for(int i=index;i<10;i++){
            if(i>n)
                return;
            vec.push_back(i);
            solve(i+1,k-1,n-i,vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        solve(1,k,n,tmp);
        return ans;
    }

    // void solve(int index,int k,int n,vector<int> vec){
    //     if(k==0 ||  n==0){
    //         if(k==0 && n==0)
    //         ans.push_back(vec);
    //         return;
    //     }
    //     for(int i=index;i<10;i++){
    //         if(i>n)
    //             return;
    //         vec.push_back(i);
    //         solve(i+1,k-1,n-i,vec);
    //         vec.pop_back();
    //     }
    // }
    // vector<vector<int>> combinationSum3(int k, int n) {
    //     solve(1,k,n,{});
    //     return ans;
    // }
};