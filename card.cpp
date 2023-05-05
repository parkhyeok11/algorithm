#include<iostream>
#include<fstream>
#include<algorithm>
#pragma warning(disable : 4996)
int max_arr[1005][5]{ 0, };
using namespace std;

class Card
{
public:
	ifstream readFile;
	ofstream outFile;
	int num;
	int n;

	Card(string read, string write)
	{
		init(read, write);
	}

	void init(const string& in, const string& out)
	{
		readFile.open(in);
		outFile.open(out);
		readFile >> num;
		for (int i = 0; i < num; i++)
		{
			readFile >> n; // 배열 크기
			int* arr = new int[n];
			for (int j = 0; j < n; j++)
			{
				int a;
				readFile >> a;
				arr[j] = a;
			}
			for (int i = 0; i < 1005; i++) {
				for (int j = 2; j < 5; j++) {
					max_arr[i][j] = -1111111;
				}
			}
			max_arr[0][2] = arr[0];
			max_arr[1][2] = arr[1];
			max_arr[2][2] = arr[2];
			max_arr[3][3] = arr[3] + arr[0];
			max_arr[3][4] = arr[3] + arr[1];

			outFile << select(arr) << endl;
		}
	}
	int select(int* arr) {
		for (int i = 4; i < n; i++)
		{
			int max_value;
			if (max_arr[i - 4][2] == max(max_arr[i - 4][2], max(max_arr[i - 4][3], max_arr[i - 4][4]))) {
				max_value = max_arr[i - 4][2];
			}
			else if (max_arr[i - 4][3] == max(max_arr[i - 4][2], max(max_arr[i - 4][3], max_arr[i - 4][4]))) {
				max_value = max_arr[i - 4][3];
			}
			else {
				max_value = max_arr[i - 4][4];
			}
			max_arr[i][2] = arr[i] + max_value;
			if (max_arr[i - 3][2] == max(max_arr[i - 3][2], max(max_arr[i - 3][3], max_arr[i - 3][4]))) {
				max_value = max_arr[i - 3][2];
			}
			else if (max_arr[i - 3][3] == max(max_arr[i - 3][2], max(max_arr[i - 3][3], max_arr[i - 3][4]))) {
				max_value = max_arr[i - 3][3];
			}
			else {
				max_value = max_arr[i - 3][4];
			}
			max_arr[i][3] = arr[i] + max_value;
			if (max_arr[i - 2][2] == max(max_arr[i - 2][2], max_arr[i - 2][3])) {
				max_value = max_arr[i - 2][2];
			}
			else {
				max_value = max_arr[i - 2][3];
			}
			max_arr[i][4] = arr[i] + max_value;
		}
		return max(max_arr[n - 1][2], max(max_arr[n - 1][3], max_arr[n - 1][4]));
	}

};

int main() {
	Card card("card.inp", "card.out");
	return 0;
}