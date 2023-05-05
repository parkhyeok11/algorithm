#include<iostream>
#include<vector>
FILE* read_file;
FILE* write_file;
#pragma warning(disable : 4996)
using namespace std;

int n, m, temp;
int arrayn[200][200] = { 0, };
vector<int>v1;
vector<int>v2;
void findback(int n, int m);

int main() {
    read_file = fopen("gridpath.inp", "r+");
    write_file = fopen("gridpath.out", "w+");

    fscanf(read_file, "%d", &n);
    fscanf(read_file, "%d", &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(read_file, "%d", &temp);
            arrayn[i][j] = temp;
        }
    }

    for (int i = 1; i < m; i++) {
        if (arrayn[0][i - 1] == -1) {
            arrayn[0][i] = -1;
        }

        if (arrayn[0][i] != -1 && arrayn[0][i - 1] != -1) {
            arrayn[0][i] = arrayn[0][i] + arrayn[0][i - 1];
        }
    }

    for (int i = 1; i < n; i++) {
        if (arrayn[i - 1][0] == -1) {
            arrayn[i][0] = -1;
        }

        if (arrayn[i][0] != -1 && arrayn[i - 1][0] != -1) {
            arrayn[i][0] = arrayn[i][0] + arrayn[i - 1][0];
        }
    }

for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
        int temp = 0;

        if (arrayn[i - 1][j] == -1 && arrayn[i][j - 1] == -1) {
            arrayn[i][j] = -1;
        }

        if (arrayn[i][j] != -1 && arrayn[i - 1][j] != -1 && arrayn[i][j - 1] == -1) {
            arrayn[i][j] = arrayn[i][j] + arrayn[i - 1][j];
        }

        if (arrayn[i][j] != -1 && arrayn[i - 1][j] == -1 && arrayn[i][j - 1] != -1) {
            arrayn[i][j] = arrayn[i][j] + arrayn[i][j - 1];
        }

        if (arrayn[i][j] != -1 && arrayn[i - 1][j] != -1 && arrayn[i][j - 1] != -1) {
            if (arrayn[i - 1][j] <= arrayn[i][j - 1]) {
                temp = arrayn[i - 1][j];
            }

            else temp = arrayn[i][j - 1];

            arrayn[i][j] = arrayn[i][j] + temp;
        }

    }
}

if (arrayn[n - 1][m - 1] == -1) {
    fprintf(write_file, "No path.");
}

else {
    findback(n - 1, m - 1);

    v1.pop_back();
    v2.pop_back();

    fprintf(write_file, "%d", arrayn[n - 1][m - 1]);
    fprintf(write_file, "\n");

    for (int i = v2.size() - 1; i > -1; i--) {
        fprintf(write_file, "(");
        fprintf(write_file, "%d", v1[i]);
        fprintf(write_file, " ");
        fprintf(write_file, "%d", v2[i]);
        fprintf(write_file, ")");
        fprintf(write_file, "\n");
    }

    fprintf(write_file, "(");
    fprintf(write_file, "%d", n - 1);
    fprintf(write_file, " ");
    fprintf(write_file, "%d", m - 1);
    fprintf(write_file, ")");
    fprintf(write_file, "\n");


    fclose(read_file);
    fclose(write_file);
}
}

void findback(int x, int y) {
    if (x == 0) {
        v1.push_back(x);
        v2.push_back(y - 1);
    }

    else if (y == 0) {
        v1.push_back(x - 1);
        v2.push_back(y);
    }

    else if (arrayn[x - 1][y] == -1) {
        v1.push_back(x);
        v2.push_back(y - 1);
    }

    else if (arrayn[x][y - 1] == -1) {
        v1.push_back(x - 1);
        v2.push_back(y);
    }

    else if (arrayn[x - 1][y] != -1 && arrayn[x - 1][y] != -1) {

        if (arrayn[x - 1][y] <= arrayn[x][y - 1]) {
            v1.push_back(x - 1);
            v2.push_back(y);
        }

        else {
            v1.push_back(x);
            v2.push_back(y-1);
        }
    }

    else;



        if (x > 0 || y > 0) {
            findback(v1.back(), v2.back());
    }
}