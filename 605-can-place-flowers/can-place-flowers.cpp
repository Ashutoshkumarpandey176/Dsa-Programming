class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int low = 0;
        while (low < flowerbed.size()) {
            if (flowerbed[low] == 0) {
                bool left = (low == 0 || flowerbed[low - 1] == 0);
                bool right = (low == flowerbed.size() - 1 || flowerbed[low + 1] == 0);

                if (left && right) {
                    flowerbed[low] = 1;
                    n--;
                }
            }

            low++;
        }

        return n <= 0;
    }
};