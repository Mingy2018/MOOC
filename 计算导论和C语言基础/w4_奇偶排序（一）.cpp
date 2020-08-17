// w4_奇偶排序（一）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	int l = 0,r = 9;//设定判定开始的元素位置
	while (l <= r) {//保证没有进行重复判定
		bool LeftIsOdd = a[l] % 2 == 1;//若判定为真，则布尔值为真
	    bool RightIsEven = a[r] % 2 == 0;
		if (LeftIsOdd)l++;
		else if (RightIsEven)r--;
		else if (!LeftIsOdd && !RightIsEven) {
			int temp = a[r];
			a[r] =a[l];
			a[l] = temp;
		}
	}

	for (int i = 0; i < l - 1; i++) {
		for (int j = 1; j <l-i ; j++) {
			if (a[j - 1] > a[j]) {
				int temp_1 = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp_1;
			}
		}
	}
	for (int i = l; i < 9; i++) {
		for (int j = l + 1; j <9; j++) {
			if (a[j - 1] > a[j]) {
				int temp_2 = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp_2;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << a[i]<<" ";
	}
	return 0;
}

