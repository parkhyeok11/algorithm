#include<iostream>
#include<memory.h>
FILE* read_file;
FILE* write_file;
#pragma warning(disable : 4996)
using namespace std;

char bd;
char btemp;
int n;
int m;
int dtemp = 0;
char dctemp;
char temp;
char b[200][200];
char d[40000];
int check = 0;

void maked(char b[200][200], int s, int e);
bool equalb(char b[200][200]);
void makeb(char d[40000], int s, int e);

int main() {
    read_file = fopen("bitmap.inp", "r+");
    write_file = fopen("bitmap.out", "w+");
    while (1) {
        if (dctemp == '#') break;

        if (check == 1) {
            bd = dctemp;
            check = 0;
        }
        else fscanf(read_file, "%c", &bd);

        if (bd == '#') break; //#읽으면 종료

        fscanf(read_file, "%d", &n);
        fscanf(read_file, "%d", &m);

        if (bd == 'B') {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    fscanf(read_file, "%c", &btemp);
                    if(btemp=='\n')
                    fscanf(read_file, "%c", &btemp);
                    b[i][j] = btemp;
                    cout << b[i][j];
                    
                }
            }
            fprintf(write_file, "D");
            fprintf(write_file, " ");
            fprintf(write_file,"%d",n);
            fprintf(write_file, " ");
            fprintf(write_file, "%d", m);
            fprintf(write_file, "\n");
            maked(b,n,m);
            

        }
        if (bd == 'D') {

            while (1) {
                fscanf(read_file, "%c", &dctemp);
                if(dctemp=='\n')
                fscanf(read_file, "%c", &dctemp);

                if (dctemp == '#' || dctemp == 'B' || dctemp == 'D' && dtemp < 50) {
                    check = 1;
                    break;
                }
                d[dtemp] = dctemp;
                cout << d[dtemp];
                cout << " ";
                dtemp++;
                if (dtemp == 50) {
                    dtemp = 0;
                }
            }

            fprintf(write_file, "B");
            fprintf(write_file, " ");
            fprintf(write_file, "%d", n);
            fprintf(write_file, " ");
            fprintf(write_file, "%d", m);
            fprintf(write_file, "\n");
            makeb(d, n, m);
        }
        memset(d, NULL, sizeof d);
        memset(b, NULL, sizeof b);
    }
    fclose(read_file);
    fclose(write_file);
    return 0;
}

void maked(char b[200][200], int s, int e) {
    
    if (equalb(b) == true) {
        fprintf(write_file, "%c", b[0][0]);
        fprintf(write_file, "\n");
    }

}

void makeb(char d[40000], int s, int e) {

    if (d[1] == NULL) {
        for (int i = 0; i < n * m; i++) {
            fprintf(write_file, "%c", d[0]);
        }
        fprintf(write_file, "\n");
    }

}

bool equalb(char b[200][200]) {
    int first = b[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (first != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}
