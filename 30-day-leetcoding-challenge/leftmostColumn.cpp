/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        int rows = dims[0];
        int cols = dims[1];
        
        int leastVal = 999;
        for (int i = 0; i < rows; i++)
        {
            int start = 0;
            int end = cols - 1;
            int furthestVal = 999;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                // If the element is present at the middle 
                int midVal = binaryMatrix.get(i, mid);

                // If element is smaller than mid, then 
                // it can only be present in left subarray 
                if (midVal == 1)
                {
                    end = mid - 1;
                    furthestVal = mid;
                }
                else
                {
                    start = mid + 1;
                }
                // Else the element can only be present 
                // in right subarray 
            }

            if (leastVal > furthestVal)
                leastVal = furthestVal;
        }
        return leastVal == 999 ? -1 : leastVal;
    }
};