// 奇偶排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a[10];
	for (int i = 0;i < 10;i++) {
		cin >> a[i];
	}
	int l = 0, r = 9;//首先我们把奇数放在左方，偶数放在右方
	while (l <= r) {
		bool LeftIsOdd = a[l] % 2 == 1;//"=="是关系比较符，判断符号两端是否相等，该式的返回值是bool类型，也就是true或者false 
		bool RightIsEven = a[r] % 2 == 0;
		if (LeftIsOdd) {
			l++;//保证从a[0]开始，都为奇数
		}
		else if (RightIsEven) {
			r--;//保证从a[9]倒数，都为偶数
		}
		else if (!LeftIsOdd && !RightIsEven) {//当a[l]为偶,a[r]为奇，两个互换
			int temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
	}
	int start = 0, end = l;
	for (int i = start; i < end; i++) {
		for (int j = start + 1; j < end + start - i; j++) {//注意体会start-i的含义，本质还是用于计算已经得出多少个最大数
			if (a[j - 1] > a[j]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	start = l, end = 10;
	for (int i = start;i < end - 1; i++) {
		for (int j = start + 1;j < end + start - i; j++){
		  if (a[j - 1] > a[j]){
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
         }
		}
	} 
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
return 0;
}