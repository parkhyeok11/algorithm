#include <iostream>
#include <string.h>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;

FILE* read_file;
FILE* write_file;


int getlen(int a, int b, int c);
void getdp();

int leno;
int lent;
int dp[5002][5002];
int dpo[5002][26];
int dpt[5002][26];
char arf[5002];
char ars[5002];

void getdp() {
    for (int i = 1; i < leno; i++) {
        for (int j = 0; j < 26; j++) dpo[i][j] = dpo[i - 1][j];
        dpo[i][arf[i] - 'A']++;
    }
    for (int i = 1; i < lent; i++) {
        for (int j = 0; j < 26; j++) dpt[i][j] = dpt[i - 1][j];
        dpt[i][ars[i] - 'A']++;
    }

    dp[0][0] = 0;
    for (int i = 0; i < leno; i++) {
        for (int j = 0; j < lent; j++) {
            int fc = (arf[i + 1] - 'A');
            int sc = (ars[j + 1] - 'A');

            int reto = getlen(i + 1, j, fc);
            int rett = getlen(i, j + 1, sc);

            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + reto);
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + rett);
        }
    }
}

int getlen(int a, int b, int c) {
    int temp1 = 0, temp2 = 0;
    if (dpo[a][c] + dpt[b][c] == dpo[leno - 1][c] + dpt[lent - 1][c]) temp1 = a + b;
    if (dpo[a][c] + dpt[b][c] == 1) temp2 = a + b;
    return temp1 - temp2;
}

int main() {
    read_file = fopen("color.inp", "r+");
    write_file = fopen("color.out", "w+");

    int num;
    fscanf(read_file, "%d", &num);
    for (int i = 0; i < num; i++) {
        fscanf(read_file, "%s", arf + 1);
        fscanf(read_file, "%s", ars + 1);

        ars[0] = '!';
        arf[0] = '!';
        leno = strlen(arf);
        lent = strlen(ars);
        memset(dp, 63, sizeof(dp));
        memset(dpo, 0, sizeof(dpo));
        memset(dpt, 0, sizeof(dpt));

        getdp();
        fprintf(write_file, "%d", dp[leno - 1][lent - 1]);
        fprintf(write_file, "\n");
    }

    return 0;
}