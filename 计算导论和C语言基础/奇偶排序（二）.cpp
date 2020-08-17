// 奇偶排序（二）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int a[10];
	for (int i = 0;i < 10;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < 9;i++) {
		for (int j = 1;j < 10 - i;j++) {
			bool LeftIsEven = a[j - 1] % 2 == 0;
			bool RightIsEven = a[j] % 2 == 0;
			if ((LeftIsEven && !RightIsEven) || (LeftIsEven == RightIsEven && a[j - 1] > a[j])) {//右边为奇数,左边是偶数，调换；左右奇偶性一致且左边大于右边，调换
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	for (int i = 0;i < 10;i++)
	{
		cout << a[i] << ' ';
	}
    return 0;
}

