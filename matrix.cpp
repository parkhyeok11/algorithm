#include <iostream>
#include<algorithm>
#pragma warning(disable : 4996)
using namespace std;

int main() {
	int num[9];
	for (int i = 0; i < 9; i++) {
		cin >> num[i];
	}
	
	sort(num, num + 9);
	
	if (num[0] + num[8] == num[1] + num[7] && num[1] + num[7]== num[2] + num[6]&& num[2] + num[6]== num[3] + num[5]){
		cout << "YES";
	}

	else cout << "NO";
}