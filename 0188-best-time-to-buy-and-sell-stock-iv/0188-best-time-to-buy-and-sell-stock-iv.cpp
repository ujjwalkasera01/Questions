class Solution {
public:
    int len;
    int limit;
    //Memoziation
    // int solveMem(vector<int>& prices,int index,int buy,vector<vector<int>> &dp){
    //     if(index>=len || buy>=limit){
    //         return 0;
    //     }
    //     if(dp[index][buy]!=-1)
    //         return dp[index][buy];
    //     int profit1,profit2;
    //     if(!(buy&1)){
    //         profit1=-prices[index]+solveMem(prices,index+1,buy+1,dp);
    //         profit2=solveMem(prices,index+1,buy,dp);
    //     }
    //     else{
    //         profit1=prices[index]+solveMem(prices,index+1,buy+1,dp);
    //         profit2=solveMem(prices,index+1,buy,dp);
    //     }
    //     return dp[index][buy]=max(profit1,profit2);
    // }
    
    // Tabulation
    // int solveTab(vector<int> &prices){
    //     vector<vector<int>>dp(len+1,vector<int>(limit+1,0));
    //     for(int index=len-1;index>=0;index--){
    //         for(int buy=limit-1;buy>=0;buy--){
    //             int profit1,profit2;
    //             if(!(buy&1)){
    //                 profit1=-prices[index]+dp[index+1][buy+1];
    //                 profit2=dp[index+1][buy];
    //             }
    //             else{
    //                 profit1=prices[index]+dp[index+1][buy+1];
    //                 profit2=dp[index+1][buy];
    //             }
    //             dp[index][buy]=max(profit1,profit2);
    //         }
    //     }
    //     return dp[0][0];
    // }
    
    // Space Optimisation
    int solveSpace(vector<int> &prices){
        vector<int>curr(limit+1,0);
        vector<int> next(limit+1,0);
        for(int index=len-1;index>=0;index--){
            for(int buy=limit-1;buy>=0;buy--){
                int profit1,profit2;
                if(!(buy&1)){
                    profit1=-prices[index]+next[buy+1];
                    profit2=next[buy];
                }
                else{
                    profit1=prices[index]+next[buy+1];
                    profit2=next[buy];
                }
                curr[buy]=max(profit1,profit2);
            }
            next=curr;
        }
        return curr[0];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        limit=2*k;
        len=prices.size();
        // vector<vector<int>> dp(len,vector<int>(limit,-1));
        // return solveMem(prices,0,0,dp);
        // return solveTab(prices);
        return solveSpace(prices);
    }
};