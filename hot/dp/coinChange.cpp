#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount+1);
        f[0] = 0;

        for(int i = 1; i <= amount; i++){

            int cnt = INT_MAX;
            for(int j = 0; j < coins.size(); j++){
                if(coins[j] > i || f[i-coins[j]] == -1) continue;
                cnt = min(f[i-coins[j]]+1, cnt);
            }
            if(cnt == INT_MAX)
                f[i] = -1;      
            else
                f[i] = cnt;
        }

        return f[amount];
    }
};

int main(){
    Solution so;
    vector<int> con = {474,83,404,3};
    cout << so.coinChange(con, 264) ;
}