#include<iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
FILE* read_file;
FILE* write_file;
#pragma warning(disable : 4996)
using namespace std;

int compare(const void* a, const void* b);

int num=0;

int siz=0;

int a = 0;

vector<int> v;

int main() {

    read_file = fopen("gain.inp", "r+");
    write_file = fopen("gain.out", "w+");

    int end = 0;

    fscanf(read_file, "%d", &num); //횟수 읽기

    for (int i = 0; i < num; i++) {

        fscanf(read_file, "%d", &siz); // 배열 크기 읽기

        for (int i = 0; i < siz; i++) {
            fscanf(read_file, "%d", &a);
            v.push_back(a);
        }

        sort(v.begin(), v.end());

        end = v[siz - 1] + v[siz - 2] - v[0] - v[1];
        v.clear();

        cout << end;
        fprintf(write_file, "%d", end);
        fprintf(write_file, "\n");

    }


    fclose(read_file);
    fclose(write_file);
    return 0;
}
