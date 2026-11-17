#include <stdio.h>
int main(void) {
    int a[] = {10, 20, 30, 40, 50}, key = 30, n = 5, found = -1;
    for (int i = 0; i < n; i++)
        if (a[i] == key) { found = i; break; }
    if (found >= 0) printf("Found at index %d\n", found);
    else printf("Not found\n");
    return 0;
}
