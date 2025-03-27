#define _CRT_SECURE_NO_WARNINGS 1

////三维数组中数组指针使用
//#include <stdio.h>
//void print(int (*p)[5][2], int r, int c, int z)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			for (int k = 0; k < z; k++)
//			{
//				printf("%d ", *(*(*(p + i) + j) + k));
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
//}
//int main(void)
//{
//	int arr[3][5][2] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
//	print(arr, 3, 5, 2);
//	return 0;
//}

//void test1(int* p) {}//int arr
//void test2(int** p) {}//int* arr[]
//void test3(int arr[][5]) {}//int arr[][]不行！
//void test3(int (*p)[5]) {}//int** p不行
//int main(void)
//{
//	int arr1[10] = {0};
//	int* arr2[5] = {0};
//	int arr3[3][5] = {0};
//	test1(arr1);
//	test2(arr2);
//	test3(arr3);
//}

//#include <stdio.h>
//int Add(int x, int y)
//{
//    return x + y;
//}
//
//int main(void)
//{
//    int (*pf)(int, int) = Add;
//    //    int ret = (*pf)(2, 3);星号可以不写
//    int ret = pf(2, 3);
//    printf("%d\n", ret);
//    return 0;
//}
//两个有意思的代码
//(*(void (*)())0)()	此代码为一次函数的调用，先将0强制类型转换为函数指针，在调用在0这个地址的函数
//void (* signal( int, void (*)(int) ) )(int)	这是一次函数声明，函数名为signal，参数类型为int 和函数指针，返回值为类型为void (*)(int) 的函数指针


//#include <stdio.h>
//
//void menu(void)
//{
//	printf("***********************************\n");
//	printf("***********************************\n");
//	printf("****  1.加法     2.减法  ***********\n");
//	printf("****  3.乘法     4.除法  ***********\n");
//	printf("************0.退出*****************\n");
//	printf("***********************************\n");
//	printf("请选择:>");
//}
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//int Mul(int a, int b)
//{
//	return a * b;
//}
//
//int Div(int a, int b)
//{
//	return a / b;
//}
////回调函数
//void calc(int (*pf)(int, int))
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入两个操作数:>");
//	scanf("%d %d", &a, &b);
//	int ret = pf(a, b);
//	printf("%d\n", ret);
//}
//
//int main(void)
//{
//	int input = 0;
//	int (*pfArr[5])(int, int) = {0, Add, Sub, Mul, Div};
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("退出程序\n");
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			calc(pfArr[input]);
//		}
//		else
//		{
//			printf("输入错误\n");
//		}
//	} while (input);
//	
//	return 0;
//}


#include <stdio.h>

int main(void)
{
	int arr[20][2] = { {1,2} };
	printf("%d %d\n", arr[0][0], arr[0][1]);
	printf("%d %d\n", arr[1][0], arr[1][1]);
	return 0;
}















