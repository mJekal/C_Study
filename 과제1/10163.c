#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int box[1001][1001] = {0};

    int color = 1;
    for (int i = 0; i < N; i++) {
        int c, r, w, h;
        scanf("%d %d %d %d", &c, &r, &w, &h);
        r = 100 - r;
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                box[r - j][c + k] = color; 
            }
        }
        color++;
    }

    int ans[N];
    for (int i = 0; i < N; i++) {
        ans[i] = 0;
    }

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            for (int k = 1; k <= N; k++) {
                if (box[i][j] == k) {
                    ans[k - 1]++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
