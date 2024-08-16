#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int Color) {
        int m = image.size(), n = image[0].size();
        Helper(image, sr, sc, m, n, image[sr][sc], Color);
        return image;
    }
    
private:
    void Helper(vector<vector<int>>& image, int r, int c, int m, int n, int target, int newColor) {
        if (r < 0 || c < 0 || r == m || c == n || image[r][c] == newColor || image[r][c] != target)
            return;

        image[r][c] = newColor;

        Helper(image, r + 1, c, m, n, target, newColor);
        Helper(image, r - 1, c, m, n, target, newColor);
        Helper(image, r, c + 1, m, n, target, newColor);
        Helper(image, r, c - 1, m, n, target, newColor);
    }
};

int main() {
    Solution solution;
    
    // Example image: 2D vector of integers
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    // Starting point (row, column) and new color
    int sr = 1, sc = 1, newColor = 2;
    
    // Perform flood fill
    vector<vector<int>> result = solution.floodFill(image, sr, sc, newColor);
    
    // Output the result
    cout << "Resulting Image:" << endl;
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
