


#include <iostream>
using namespace std;


int main()
{
	int n,a[1000];//一共n个数，n不超过1000，因此用a[1000]保存这些数
	cin >> n;// 输入n个数
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}//输入并保存这些数
	for (int i = 0;i < n - 1;i++) {
		for (int j = 1;j < n - i;j++) {
			if (a[j - 1] > a[j]){
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			}//把最大的元素移到a[i]
		}
	}//(n-i)还有多少个待对比的数
	for (int i = 0;i < n - 1;i++) {
		cout << a[i] << endl;
	}//依次输出数
    return 0;
	
}

