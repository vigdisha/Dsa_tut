//min number of coins

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of elements needed to form the target sum
int minimumElements(vector<int>& arr, int T) {
    int n = arr.size();
    
    // Create a 2D DP (Dynamic Programming) table with n rows and T+1 columns
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));
    
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9; // Set it to a very large value if not possible
    }
    
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            // Calculate the minimum elements needed without taking the current element
            int notTake = dp[ind - 1][target];
            
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];
                
            // Store the minimum of 'notTake' and 'take' in the DP table
            dp[ind][target] = min(notTake, take);
        }
    }
    
    // The answer is in the bottom-right cell of the DP table
    int ans = dp[n - 1][T];
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    
    return ans; // Return the minimum number of elements needed
}

int main() {
    vector<int> arr = {200,100,50,20,10,5,2,1};
    int T = 153;
    
    // Call the function to find the minimum number of elements needed
    int result = minimumElements(arr, T);
    
    // Output the result
    cout << "The minimum number of coins required to form the target sum is " << result << endl;
    
    return 0; // Return 0 to indicate successful program execution
}
