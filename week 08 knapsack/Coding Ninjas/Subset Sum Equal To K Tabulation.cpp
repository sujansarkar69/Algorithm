#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<bool>prev(k + 1, 0), cur(k + 1, 0);

   prev[0] = cur[0] = true;
   prev[arr[0]] = true;

   for(int i = 1; i < n ; i++) {
       for(int target = 1; target <= k; target++) {
            bool not_take = prev[target];
            bool take = false;
            if(arr[i] <= target) take = prev[target - arr[i]];
            cur[target] = take | not_take;
       }
       prev = cur;
   }

   return prev[k];
}

int main() {
    
}