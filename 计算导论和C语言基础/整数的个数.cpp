// 整数的个数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;


int main()
{
	int k;
	cin >> k;
	int n1 = 0, n5 = 0, n10 = 0;
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		if (n == 1) n1++;
		if (n == 5) n5++;
		if (n == 10) n10++;
	}
	cout << n1 << endl;
	cout << n5 << endl;
	cout << n10 << endl;
    return 0;
}

