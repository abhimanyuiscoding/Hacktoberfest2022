// Statement
You have been given a number of stairs. Initially, you are at the oth stair, and 
you need to reach the Nth stair. Each time you can either climb one step or two steps. 
You are supposed to return the number of distinct ways in which you can climb from the 
0th step to Nth step.

// Example 
n=3;
We can climb one step at a time i.e. {(@, 1),(1, 2),(2,3)} or we can climb the first 
two-step and then one step i.e. {(0,2),(1, 3)} or we can climb first one step and then 
two step i.e. {(0,1), (1,3)}.

// Space Complexity - O(n)
int countDistinctWays(int nStairs) {
    if(nStairs<0){
        return 0;
    }
    if(nStairs==0){
        return 1;
    }
    int ans=countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
    return ans;
}
