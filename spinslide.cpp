#include<iostream>
#include <stdlib.h>
#include <string.h>
FILE* read_file;
FILE* write_file;
#pragma warning(disable : 4996)
using namespace std;

int num;
int spin;
int rsize;

int main() {

    read_file = fopen("spinslide.inp", "r+");
    write_file = fopen("spinslide.out", "w+");


    fscanf(read_file, "%d", &num); //���� �� �б�
    fscanf(read_file, "%d", &rsize); //���� �� �б�
    fscanf(read_file, "%d", &spin); // ����

    cout << num;
    cout << " ";
    cout << rsize;
    cout << " ";
    cout << spin;

    fclose(read_file);
    fclose(write_file);
    return 0;
}