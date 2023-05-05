#include<iostream>
#include <stdlib.h>
#include <vector>
#include<algorithm>
FILE* read_file;
FILE* write_file;
#pragma warning(disable : 4996)
using namespace std;

int num = 0;

int n = 0;
int m = 0;
int k = 0;
int temp = 0;
int tempn = 0;
int tempm = 0;
bool a = false;
bool ed1 = false;
bool ed2 = false;
int sl = 0;

vector<int> v;

int main() {

    read_file = fopen("grid.inp", "r+");
    write_file = fopen("grid.out", "w+");


    fscanf(read_file, "%d", &num); //È½¼ö ÀÐ±â

    for (int j = 0; j < num; j++) {

        fscanf(read_file, "%d", &n);
        tempn = n;
        fscanf(read_file, "%d", &m);
        tempm = m;
        fscanf(read_file, "%d", &k);

        for (int i = 0; i < k; i++) {
            fscanf(read_file, "%d", &temp);
            v.push_back(temp);
        }
        sort(v.begin(), v.end());

        for (int i = k - 1; i > -1; i--) {

            if (2 * n <= v[i]) {
                sl = v[i] / n;

                if (sl > 2) {
                    a = true;
                }
                if (sl > 2) {
                    if (sl <= tempm) {
                        tempm = tempm - sl;
                    }
                    else tempm = 0;
                }

                if (sl == 2) {
                    if (tempm == 1 && a == true) {
                        tempm = 0;
                        ed1 = true;
                        break;
                    }

                    if (tempm >1) {
                        tempm = tempm - sl;
                    }
                }
                
                if (tempm == 0) {
                    ed1 = true;
                    break;
                }
            }

            else break;

            
        }

        a = false;

        for (int i = k - 1; i > -1; i--) {

            if (2 * m <= v[i]) {
                sl = v[i] / m;

                if (sl > 2) {
                    a = true;
                }
                if (sl > 2) {
                    if (sl <= tempn) {
                        tempn = tempn - sl;
                    }
                    else tempn = 0;
                }

                if (sl == 2) {
                    if (tempn == 1 && a == true) {
                        tempn = 0;
                        ed1 = true;
                        break;
                    }

                    if (tempn > 1) {
                        tempn = tempn - sl;
                    }
                }

                if (tempn == 0) {
                    ed1 = true;
                    break;
                }
            }

            else break;


        }


        if (ed1 == true||ed2==true) {
            fprintf(write_file, "Yes");
        }
        else fprintf(write_file, "No");

        fprintf(write_file, "\n");
        v.clear();

      n = 0;
      m = 0;
      k = 0;
      temp = 0;
      tempn = 0;
      tempm = 0;
      a = false;
      ed1 = false;
      ed2 = false;
    }

    fclose(read_file);
    fclose(write_file);
    return 0;
}