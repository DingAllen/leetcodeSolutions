class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int res = 0;
        for (int i = 0; i < n; i++) {

            if (height[i] == 0) continue;

            int r = i, h = 0;
            for (int j = i + 1; j < n; j++) {
                if (height[j] >= height[i]) {
                    r = j;
                    h = height[i] < height[j] ? height[i] : height[j];
                    break;
                }
            }
            if (r == i) {
                for (int j = i + 1; j < n; j++) {
                    if (height[j] >= h) {
                        h = height[j];
                        r = j;
                    }
                }
            }
            if (r > i) {
                for (int j = i + 1; j < r; j++) {
                    res += h - height[j];
                }
                i = r - 1;
            }
        }
        return res;
    }
};