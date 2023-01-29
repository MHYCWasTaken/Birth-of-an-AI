// Author MHYC133
#include <iostream>
#include <cstdio>
using namespace std;

float w1, w2;
float b;
float _data[10][3] = {
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
int dataCnt = 10;

// 从w.txt读取W1 W2
void readW() {
    freopen("w.txt", "r", stdin);
    cin >> w1 >> w2;
    fclose(stdin);
    return;
}

// 记录W1 W2到w.txt
void writeW() {
    freopen("w.txt", "w", stdout);
    cout << w1 << " " << w2;
    fclose(stdout);
    return;
}

// 展示W1 W2到控制台
void showW() {
    cout << "Value of W: ";
    cout << w1 << " " << w2 << endl;
    return;
}

// 计算ΔW
float getDeltaW(float x, float Y, float y) {
    /* 
     * 对于鳄鱼与蛇的例子，结果只有0（蛇）和1（鳄鱼）
     * 当判断错误，结果为蛇时，期望值Y为1F，现值y为0F，Y-y为1，即W+=ΔW
     * 当判断错误，结果为鳄鱼时，期望值Y为0F，现值y为1F，Y-y为-1，即W-=ΔW
     */
    return (Y - y) * x;
}

// 计算f
float getf(float x1, float w1, float x2, float w2, float b) {
    return x1 * w1 + x2 * w2 - b;
}

// 激活函数
float active(float f) {
    // 当f大于0输出1，小于等于0输出0
    return f > 0;
}

int main() {
    readW();
    for (int i = 0; i < dataCnt; i++) {
        float x1 = _data[i][0], x2 = _data[i][1], ans = _data[i][2];
        float f = getf(x1, w1, x2, w2, b);
        float actived = active(f);
        cout << "Data No." << i <<  "; actived: " << actived << "; answer: " << ans << "; is correct: " << (actived == ans) << endl;
        // result是计算结果，correct是布尔值，表示计算是否正确
        if (actived != ans) {
            w1 += getDeltaW(x1, ans, actived);
            w2 += getDeltaW(x2, ans, actived);
        }
    }
    showW();
    writeW();
    return 0;
}