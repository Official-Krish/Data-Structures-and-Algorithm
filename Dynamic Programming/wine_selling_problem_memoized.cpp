/*
    Given n wines in a row, with integers denoting the cost of each wine respectively. 
    Each year you can sale the first or the last wine in the row. However, the price 
    of wines increases over time. Let the initial profits from the wines be P1, P2, P3…Pn. 
    On the Yth year, the profit from the ith wine will be Y*Pi.
    Calculate the maximum profit from all the wines.

    Input  : 5
           : 2 4 6 2 5
    Output : 64 
*/
// Memoized Approach TC : O(N^2)
// Program Author :  Abhisek Kumar Gupta

#include<bits/stdc++.h>
using namespace std;
int memoized[1000][1000];
int find_max_profit(int *A, int start, int end, int year){
    if(start > end)
        return 0;
    if(memoized[start][end] != -1)
        return memoized[start][end];
    int r1 = A[start] * year + find_max_profit(A, start + 1, end, year + 1);
    int r2 = A[end] * year + find_max_profit(A, start, end - 1, year + 1);
    int answer = max(r1, r2); ;
    memoized[start][end] = answer;
    return memoized[start][end];    
}
int main(){
    memset(memoized, -1, sizeof(memoized));
    int n;
    cin >> n;
    int *A;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    int start = 0;
    int end = n - 1; 
    int year = 1;   
    int result = find_max_profit(A, start, end, year);    
    cout << result;
    return 0;
}