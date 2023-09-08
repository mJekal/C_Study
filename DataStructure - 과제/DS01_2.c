#include <stdio.h>

int sum(int x) {
    int cnt = 0;
    for (int i = 1; i < x; i++) {
        if (x % i == 0) {
            cnt += i;
        }
    }
    return cnt;
}

int main(void) {
    int first, second;
    int cnt;
    scanf("%d %d", &first, &second);

    cnt = sum(first);

    if (cnt == second) {
        cnt = sum(second);
        
        if (cnt == first) {
            printf("Amicable\n");
        }
    } else {
        printf("Not Amicable\n");
    }

    return 0;
}
