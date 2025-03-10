#define _CRT_SECURE_NO_WARNINGS 1
//将一个整形数组中奇数排列到偶数前方，并打印出数组
//#include <stdio.h>
//int main(void)
//{
//	int input[10] = {0};
//	int i = 0;
//	//输入数组
//	int sz = sizeof(input) / sizeof(input[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", input + i);
//	}
//	//调整数组————占用内存太大且遍历三次数组效率低
//		//先找出奇数存放到另一个数组
//	int tmp[10] = {0};
//	int num = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (input[i] % 2 != 0)
//		{
//			tmp[num] = input[i];
//			num++;
//		}
//	}
//		//在找出奇数继续存放
//	for (i = 0; i < sz; i++)
//	{
//		if (input[i] % 2 == 0)
//		{
//			tmp[num] = input[i];
//			num++;
//		}
//	}
//		//将input赋值为tmp
//	for (i = 0; i < sz; i++)
//	{
//		input[i] = tmp[i];
//	}
//	//打印数组
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", input[i]);
//	}
//	return 0;
//}

////优化————只遍布了一次数组
//#include <stdio.h>
////定义L和R两个指针，L从左边找到偶数时，R从右边开始找，R找到奇数时，相互交换地址内容，并注意L<R
//void adjust_arr(int input[], int sz)
//{
//	int* left = input;
//	int* right = &input[sz - 1];
//	while (left < right)
//	{
//		while ((*left % 2 == 1) && (left < right))//时刻注意L<R，这里如果input全是奇数会导致溢出
//		{
//			left++;
//		}
//		while ((*right % 2 == 0) && (left < right))
//		{
//			right++;
//		}
//		if (left < right)
//		{
//			int tmp = *left;
//			*left = *right;
//			*right = tmp;
//			left++;
//			right++;
//		}
//	}
//}
//
//int main(void)
//{
//	int input[10] = { 0 };
//	int i = 0;
//	//输入数组
//	int sz = sizeof(input) / sizeof(input[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", input + i);
//	}
//	//调整数组
//	adjust_arr(input, sz);
//	//打印数组
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", input[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main(void)
//{
//	const char* p = "abcdef";//vs2022中"abcdef"操作返回的是被const修饰的首字符地址，如果直接赋值,在对p操作就改变了原字符串，违背了const
//	char arr[] = "abcdef";//表示将整个字符串赋值到数组中，而上面的则是把字符串首地址赋值给指针
//	printf("%s\n", p);
//	return 0;
//}

//#include <stdio.h>
//int main(void)
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = {2,3,4,5,6};
//	int arr3[] = {3,4,5,6,7};
//	int* parr[3] = {arr1, arr2, arr3};//模拟二维数组
//	return 0;
//}

#include <stdio.h>
int main(void)
{
	int arr[10] = {0};
	printf("%p\n", &arr);
	printf("%p\n", &arr + 1);
	return 0;
}