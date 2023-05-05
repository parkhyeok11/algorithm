#include<iostream> 
#include<vector>
#include<fstream>
#pragma warning(disable : 4996)
FILE* read_file;
FILE* write_file;

using namespace std;


void quick(vector<int> &v, int start, int end,int deep=0) {

	int max = 0;
	int pivot = -1;
	for (int i = start; i <= end; i++) {
		if (max < v[i]) {
			max = v[i];
			pivot = i;
		}
	}

	v[pivot] = deep;
	deep++;

	if(start!=pivot)
		quick(v, start, pivot-1,deep);

	if (end != pivot) 
		quick(v, pivot+1, end, deep);
	

	
}


int main(){

	read_file = fopen("permutation.inp", "r+");
	write_file = fopen("permutation.out", "w+");
	int num;
	int arr;
	int temp;


	fscanf(read_file, "%d", &num);
	for (int i = 0; i < num; i++) {
		fscanf(read_file, "%d", &arr);
		vector<int>v;
		for (int j = 0; j < arr; j++) {
			fscanf(read_file, "%d", &temp);
			v.push_back(temp);
		}

		quick(v, 0, v.size()-1);
		
		for (int j = 0; j < arr; j++) {
			fprintf(write_file, "%d", v[j]);
			fprintf(write_file, " ");
		}
		fprintf(write_file, "\n");
		
	}

	return 0;
}
