class Solution {
public:
vector<int> prefixSums;
vector<vector<int>>rectangles;

    Solution(vector<vector<int>>& rects) {
        rectangles=rects;
        int numRectangles = rectangles.size();
        prefixSums.resize(numRectangles + 1, 0);

        for(int i=0;i<numRectangles;i++){
             prefixSums[i + 1] = prefixSums[i] + 
                                (rectangles[i][2] - rectangles[i][0] + 1) * 
                                (rectangles[i][3] - rectangles[i][1] + 1);
        }
        srand(static_cast<unsigned int>(time(nullptr)));
    }
    
    vector<int> pick() {
         int target = 1 + rand() % prefixSums.back();
          // Find the rectangle that will contain the point.
        int idx = static_cast<int>(lower_bound(prefixSums.begin(), prefixSums.end(), target) - prefixSums.begin()) - 1;
         // Get the rectangle information.
        auto& rect = rectangles[idx];
      
        // Pick a random point within the chosen rectangle.
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);
      
        return {x, y}; // Return the random point as a 2D vector.
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */