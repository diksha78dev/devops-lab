#include <stdio.h>
int main(void) {
    FILE *fp = fopen("sample.txt", "w");
    if (fp == NULL) { perror("sample.txt"); return 1; }
    fprintf(fp, "File handling in C\n");
    fclose(fp);

    fp = fopen("sample.txt", "r");
    if (fp == NULL) { perror("sample.txt"); return 1; }
    char line[100];
    if (fgets(line, sizeof line, fp)) printf("%s", line);
    fclose(fp);
    return 0;
}
