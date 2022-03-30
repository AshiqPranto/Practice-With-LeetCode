class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>a;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                a.push_back(matrix[i][j]);
        return binary_search(a.begin(),a.end(),target);
    }
};