#define _CRT_SECURE_NO_WARNINGS 1

////��ά����������ָ��ʹ��
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
//void test3(int arr[][5]) {}//int arr[][]���У�
//void test3(int (*p)[5]) {}//int** p����
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
//    //    int ret = (*pf)(2, 3);�Ǻſ��Բ�д
//    int ret = pf(2, 3);
//    printf("%d\n", ret);
//    return 0;
//}
//��������˼�Ĵ���
//(*(void (*)())0)()	�˴���Ϊһ�κ����ĵ��ã��Ƚ�0ǿ������ת��Ϊ����ָ�룬�ڵ�����0�����ַ�ĺ���
//void (* signal( int, void (*)(int) ) )(int)	����һ�κ���������������Ϊsignal����������Ϊint �ͺ���ָ�룬����ֵΪ����Ϊvoid (*)(int) �ĺ���ָ��


//#include <stdio.h>
//
//void menu(void)
//{
//	printf("***********************************\n");
//	printf("***********************************\n");
//	printf("****  1.�ӷ�     2.����  ***********\n");
//	printf("****  3.�˷�     4.����  ***********\n");
//	printf("************0.�˳�*****************\n");
//	printf("***********************************\n");
//	printf("��ѡ��:>");
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
////�ص�����
//void calc(int (*pf)(int, int))
//{
//	int a = 0;
//	int b = 0;
//	printf("����������������:>");
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
//			printf("�˳�����\n");
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			calc(pfArr[input]);
//		}
//		else
//		{
//			printf("�������\n");
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















