#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main(void)
//{
//	int (*pArr[5])(int, int) = {0};
//	int (*(*ppArr)[5])(int, int) = &pArr;
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	void* p = &a;//void*是无具体类型的指针，可以接收任意类型的地址，不会报警告，但以不能进行解引用，也不能进行+-整数操作
//
//	return 0;
//}
//



////可以给任意类型的数据排序
//void qsort(void* base,//待排序数据的起始位置
//	size_t num,//待排序数据元素个数
//	size_t size,//待排序数据元素大小
//	int (*cmp)(const void* e1, const void* e2)//元素之间的比较方式	e1,e2为要比较的两个参数的地址，e1>e2返回正数，等于为0，反之为负数
//);

typedef struct {
	char name[20];
	int age;
}Stu;
/*******************test1使用qsort来给整形数组排序***************/
//降序排列
int cmp_int(const void* e1, const void* e2)
{
	return -*(int*)e1 + *(int*)e2;
}
//测试使用qsort来给整形数组排序
void test1(void)
{
	int arr[] = { 0,3,6,5,9,8,7,2,1,4 };

	int sz = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, sz, sizeof(arr[0]), cmp_int);

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
/******************test2用qsort比较结构体类型数据***********************/
//比较结构体中的name
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((Stu*)e1) -> name,((Stu*)e2) -> name);
}
//比较结构体中的age
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((Stu*)e1)->age - ((Stu*)e2)->age;
}
//测试使用qsort来排序结构体
void test2(void)
{
	Stu s[] = {{"zhangsan", 13}, {"lisi", 14}, {"wangwu", 15}};
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof (s[0]), cmp_stu_by_name);
}

/***************模拟qsort函数写法写冒泡排序***************/
/*
*	@brief	交换两个随意数据类型的数据
*	*buf1：数据1的地址
*	*buf2：数据2的地址
*	width：数据占空间字节数
*/
void Swap(char* buf1, char* buf2, int width)//由于不清楚待交换量的数据类型，中间变量无法创建，就用地址最小步长char一字节一字节的交换
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
/*
 *  @brief   冒泡排序，不限制数据类型
 *  *base：待排序数组的起始位置
 *  size:  数组长度
 *  width：排序元素所占空间字节数
 *	*cmp：自定义的数据类型比较函数，e1 > e2返回正数，=返回0，<返回负数
 */
void bubble_sort(void* base, int size, int width, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		int flag = 0;
		int j = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//cmp里参数用地址，是因为我们要对数组地址中的元素排序，这个元素也是用地址的形式写的
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);//需要两个待交换量的地址，还有数据的长度
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
//测试冒泡排序
void test3(void)
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9 };

	int sz = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main(void)
{
	//test1();
	//test2();
	test3();

	return 0;
}


