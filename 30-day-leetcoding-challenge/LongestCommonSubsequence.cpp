class Solution {
public:
    // shamelessly adapted from geeksforgeeks
    int longestCommonSubsequence(string text1, string text2) {
       return lcs(text1, text2, text1.size(), text2.size()); 
    }
    int lcs( string &X, string &Y, int m, int n )  
    {  
        int memo[m + 1][n + 1];  
        int i, j;  

        for (i = 0; i <= m; i++)  
        {  
            for (j = 0; j <= n; j++)  
            {  
            //fill the edge with zeros
            if (i == 0 || j == 0)  
                memo[i][j] = 0;  

            //if the ending chars match, take value from up/left diagonal and add 1
            else if (X[i - 1] == Y[j - 1])  
                memo[i][j] = memo[i - 1][j - 1] + 1;  

            //otherwise, take the best of the top and the left
            else
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);  
            }  
        }  

        return memo[m][n];  
    }  
};