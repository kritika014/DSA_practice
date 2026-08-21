class Solution {
public:
    int t[50005][2];
    int solve(int day,vector<int>& prices, int fee, bool buy){
        if(day>=prices.size()){
            return 0;
        }
        if(t[day][buy]!=-1){
            return t[day][buy];
        }
        int profit=0;

        if(buy){
            int consider=solve(day+1,prices,fee,false)-prices[day];
            int not_buy=solve(day+1,prices,fee,true);

            profit=max(consider,not_buy);
        }
        else{
            int sell=solve(day+1,prices,fee,true)+prices[day]-fee;
            int not_sell=solve(day+1,prices,fee,false);

            profit=max(sell,not_sell);
        }

        return t[day][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(t,-1,sizeof(t));
        return solve(0,prices,fee,true);
    }
};