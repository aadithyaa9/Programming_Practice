#include <iostream>
#include <vector>

using namespace std ;


int knapsack(vector <int> &profit , vector <int> &weight , int capacity) ;

int main(){
    int capacity;
    cout << "Enter Your Capacity:" <<endl;
    cin >> capacity ;
    int total_coins;
    cout << "Enter Total Coins:" <<endl;
    cin >> total_coins;

    vector<int> weight(total_coins);

    vector <int> profit(total_coins);


    for (int i = 0 ; i < total_coins ; i++){
        cout << "Enter The weight and profit for item" << i+1 <<":";
        cin >> weight[i] >>profit[i];
    }


    cout << "Maximum Profit :" <<knapsack(profit ,weight , capacity)<<endl;
}

int knapsack(vector <int> &profit , vector <int> &weight , int capacity) {
    int n =  profit.size();
    vector<vector<int>> dp(n+1 , vector<int>(capacity+1 , 0));

    for (int i =1; i<=n ; i++){
        for (int w = 0 ; w <= capacity ; w++){
            if (weight[i-1] <= w){
                dp[i][w] = max(profit[i-1] + dp[i-1][w - weight[i-1]] , dp[i-1][w]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
    }
    
}
return dp[n][capacity];

}
