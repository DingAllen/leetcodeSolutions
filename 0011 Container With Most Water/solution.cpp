class Solution {
public:
    int maxArea(vector<int>& height) {

        int res = 0;
        int temp;

        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                temp = height[j] < height[i] ? height[j] : height[i];
                temp = temp * (j - i);
                if (temp > res) {
                    res = temp;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {

        int res = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int area = (j - i) * min(height[i], height[j]);
            res = max(res, area);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};