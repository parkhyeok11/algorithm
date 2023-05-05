#include<iostream>
#include <stdlib.h>
FILE* read_file;
FILE* write_file;
#pragma warning(disable : 4996)
using namespace std;

int num = 0;



int main() {

    read_file = fopen("stairs.inp", "r+");
    write_file = fopen("stairs.out", "w+");

    int t=0;
    int f=0;
    int s=0;
    int r = 0;

    fscanf(read_file, "%d", &num); //È½¼ö ÀÐ±â

    for (int i = 0; i < num; i++) {
        fscanf(read_file, "%d", &t);
        fscanf(read_file, "%d", &f);
        fscanf(read_file, "%d", &s);
        r = s / (t - 1);
        if (s % (t - 1) != 0) r = r + 1;



        fprintf(write_file,"%d", r);
        fprintf(write_file, "\n");
    }

    long long a = 10610209857723;
    long long b = 10610209857723 % 11;

    printf("%d", &b);



    fclose(read_file);
    fclose(write_file);
    return 0;
}