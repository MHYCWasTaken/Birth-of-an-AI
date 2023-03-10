// Author MHYC133
#include <iostream>
using namespace std;
int main() {
    float data[10][3] = {
        {340, 360, 1},
        {460, 465, 1},
        {400, 160, 1},
        {316, 137.5, 1},
        {150, 36, 1},
        {150, 1.1, 0},
        {170, 2.3, 0},
        {359, 6, 0},
        {695, 59, 0},
        {521, 97.5, 0},
    };
    float w1 = 1, w2 = 1;
    float deltaw = 0.01;
    cin >> w1 >> w2;
    int b = 100;
    for (int i = 0; i < 10; i++) {
        float x1 = data[i][0], x2 = data[i][1];
        int ans = data[i][2];
        float f = x1 * w1 + x2 * w2;
        int result = f > b;
        bool correct = result == ans;
        cout << result << ", " << correct << endl;
        // result是计算结果，correct是布尔值，表示计算是否正确
        if (!correct) {
            if (result == 1) {
                w1 -= deltaw;
                w2 -= deltaw;
            } else {
                w1 += deltaw;
                w2 += deltaw;
            }
        }
    }
    cout << w1 << " " << w2;
    return 0;
}