#pragma warning(disable : 4996)
#include<iostream>
using namespace std;


int main() {
    int K;  //�����Ҽ�
    int M; //�ڵ�����
    int temp;
    int sum=0;
    int lastgas;
    int gas[1001] = {0,}; //������ �迭
    int asum[100] = { 0, };
    int asumtemp = 0;

    cin >> K >> M;

    for (int i = 0; i < K; i++) {
        cin >> temp;
        gas[i] = temp;
        lastgas = temp;
    }

    for (int i = 0; i < M; i++) {
        int car;
        int re;
        cin >> car >> re;

        for (int j = 0; j < K; j++) {
            if (gas[j] <= car && gas[j] >= car - re) {
                sum++;
            }

            else if (gas[j] >= car && gas[j] <= car + re) {
                sum++;
            }

            else;
        }

        asum[asumtemp] = sum;
        asumtemp++;
        sum = 0;

    }

    for (int i = 0; i < M; i++) {
        cout << asum[i];
        cout << "\n";
    }


    return 0;
}