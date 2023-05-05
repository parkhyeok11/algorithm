#include<iostream>
#include<string>
#include <stdlib.h>
FILE* read_file;
FILE* ftemp;
FILE* write_file;
#pragma warning(disable : 4996)
using namespace std;
int fsize = 0;
int bsize = 0;
int fkey = 0;
int skey = 0;
int temp[50] = { 0, };
int add = 0;
int addli = 0;
int dtemp[50] = { 0, };
int atemp = 0;

int linearf(int k, int n);

struct element {
    int key = 0;
    int empty = 0;
};

int main() {

    read_file = fopen("hash_input.txt", "r+");
    write_file = fopen("hash_output.txt", "w+");
    fscanf_s(read_file, "%d", &fsize);
    for (int y = 0; y < fsize; y++) {
        fscanf_s(read_file, "%d", &bsize);
        fscanf_s(read_file, "%d", &fkey);
        fscanf_s(read_file, "%d", &skey);
        struct element* li = (struct element*)malloc(sizeof(struct element) * bsize); // 구조체 동적할당
        for (int i = 0; i < bsize; i++) {
            memset(&li[i], 0, sizeof(struct element));
        }

        struct element* tp1 = (struct element*)malloc(sizeof(struct element) * bsize);
        for (int i = 0; i < bsize; i++) {
            memset(&tp1[i], 0, sizeof(struct element));
        }

        struct element* dh = (struct element*)malloc(sizeof(struct element) * bsize);
        for (int i = 0; i < bsize; i++) {
            memset(&dh[i], 0, sizeof(struct element));
        }


        for (int i = 0; i < fkey; i++) {  //txt값 가져오기
            fscanf_s(read_file, "%d", &temp[i]);
        }
        for (int i = fkey; i < skey+fkey; i++) {  //txt값 가져오기
            fscanf_s(read_file, "%d", &temp[i]);
        }


        for (int i = 0; i < bsize; i++) { //linear
            addli = linearf(temp[i], bsize);

            if (li[addli].empty == 0) {
                li[addli].key = temp[i];
                li[addli].empty = 1;
                continue;
            }
            else{
                while (1) {
                    if (addli == bsize) addli = 0;
                    if (li[addli].empty == 0) {
                        li[addli].key = temp[i];
                        li[addli].empty = 1;
                        break;
                    }
                    addli++;
                }
            }
        }

        for (int i = 0; i < bsize; i++) {
            fprintf_s(write_file, "%d ", li[i].key);
        }
        fprintf_s(write_file, "\n");

        int count = 0;
        for (int i = 0; i < fkey; i++) {      //first pass
            addli = linearf(temp[i], bsize);
            if (tp1[addli].empty == 0) {
                tp1[addli].key = temp[i];
                tp1[addli].empty = 1;
                continue;
            }
            else {
                dtemp[count] = temp[i];
                count++;
            }

        }

        skey = skey + count;

        for (int i = 0; i < skey; i++) {
            dtemp[count + i] = temp[fkey + i];
        }



        for (int i = 0; i < skey; i++) { // second pass
            addli = linearf(dtemp[i], bsize);

            if (tp1[addli].empty == 0) {
                tp1[addli].key = dtemp[i];
                tp1[addli].empty = 1;
                continue;
            }
            else {
                while (1) {
                    if (addli == bsize) addli = 0;
                    if (tp1[addli].empty == 0) {
                        tp1[addli].key = dtemp[i];
                        tp1[addli].empty = 1;
                        break;
                    }
                    addli++;
                }
            }
        }
        for (int i = 0; i < bsize; i++) {
                fprintf_s(write_file, "%d ", tp1[i].key);
        }
        fprintf_s(write_file, "\n");

        for (int i = 0; i < bsize; i++) {  // double hashing

            addli = linearf(temp[i], bsize);
            atemp = addli;
            if (dh[addli].empty == 0) {
                dh[addli].key = temp[i];
                dh[addli].empty = 1;
                continue;
            }
            addli = (atemp + (temp[i] % (bsize - 2) + 1)) % bsize;

            if (dh[addli].empty == 0) {
                dh[addli].key = temp[i];
                dh[addli].empty = 1;
                continue;
            }

            addli = (atemp + (2 * (temp[i] % (bsize - 2) + 1))) % bsize;
            if (dh[addli].empty == 0) {
                dh[addli].key = temp[i];
                dh[addli].empty = 1;
                continue;
            }
            else {
                while (1) {
                    if (addli == bsize) addli = 0;
                    if (dh[addli].empty == 0) {
                        dh[addli].key = temp[i];
                        dh[addli].empty = 1;
                        break;
                    }
                    addli++;
                }
            }
        }

        for (int i = 0; i < bsize; i++) {
            fprintf_s(write_file, "%d ", dh[i].key);
        }
        fprintf_s(write_file, "\n");


        
        memset(dtemp, 0, sizeof(dtemp));
        memset(temp, 0, sizeof(temp));
        free(li);
        free(dh);
        free(tp1);
        count = 0;
    }
    fclose(read_file);
    fclose(write_file);
    return 0;
}

int linearf(int k, int n) {   //linear
    add = k % n;
    return add;
}