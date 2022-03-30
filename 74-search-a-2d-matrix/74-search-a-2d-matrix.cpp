class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int right = m*n -1;
        int left = 0;
        int mid;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(matrix[mid/n][mid%n] == target) return true;
            if(matrix[mid/n][mid%n]<target)
            {
                left = mid+1;
            }else if(matrix[mid/n][mid%n]>target)
            {
                right = mid-1;
            }
        }
        return false;
    }
};