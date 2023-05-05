#include <iostream>
FILE* read_file;
FILE* write_file;
#define bignum 111111111;
#pragma warning(disable : 4996)
using namespace std;

int cube[201][201][201];
int main() {

	read_file = fopen("cube.inp", "r+");
	write_file = fopen("cube.out", "w+");

	for (int w = 1; w <= 200; w++) {
		for (int l = 1; l <= 200; l++) {
			for (int h = 1; h <= 200; h++) {
				if (cube[w][l][h]==NULL) {
					if (w == 1) cube[w][l][h] = l * h;
					else if (l == 1) cube[w][l][h] = w * h;
					else if (h == 1) cube[w][l][h] = w * l;
					else if (w % h == 0 && l % h == 0) cube[w][l][h] = (w / h) * (l / h);
					else if (l % w == 0 && h % w == 0) cube[w][l][h] = (l / w) * (h / w);
					else if (w % l == 0 && h % l == 0) cube[w][l][h] = (w / l) * (h / l);
					else {
						cube[w][l][h] = bignum;

						for (int i = 1; i <= w / 2; i++) {
							if (cube[i][l][h] + cube[w - i][l][h] < cube[w][l][h]) {
								cube[w][l][h] = cube[i][l][h] + cube[w - i][l][h];
							}
						}
						for (int i = 1; i <= l / 2; i++) {
							if (cube[w][i][h] + cube[w][l - i][h] < cube[w][l][h]) {
								cube[w][l][h] = cube[w][i][h] + cube[w][l - i][h];
							}
						}
						for (int i = 1; i <= h / 2; i++) {
							if (cube[w][l][i] + cube[w][l][h - i] < cube[w][l][h]) {
								cube[w][l][h] = cube[w][l][i] + cube[w][l][h - i];
							}
						}
					}
					cube[w][h][l] = cube[l][h][w] = cube[l][w][h] = cube[h][l][w] = cube[h][w][l] = cube[w][l][h];
				}
			}
		}
	}

	int w, l, h, num;
	fscanf(read_file, "%d", &num);

	for (int i = 0; i < num; i++) {
		fscanf(read_file, "%d", &w);
		fscanf(read_file, "%d", &l);
		fscanf(read_file, "%d", &h);
		fprintf(write_file, "%d", cube[w][l][h]);
		fprintf(write_file, "\n");
		
	}
	fclose(write_file);
	fclose(read_file);
	return 0;
}