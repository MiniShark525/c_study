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
//	void* p = &a;//void*���޾������͵�ָ�룬���Խ����������͵ĵ�ַ�����ᱨ���棬���Բ��ܽ��н����ã�Ҳ���ܽ���+-��������
//
//	return 0;
//}
//



////���Ը��������͵���������
//void qsort(void* base,//���������ݵ���ʼλ��
//	size_t num,//����������Ԫ�ظ���
//	size_t size,//����������Ԫ�ش�С
//	int (*cmp)(const void* e1, const void* e2)//Ԫ��֮��ıȽϷ�ʽ	e1,e2ΪҪ�Ƚϵ����������ĵ�ַ��e1>e2��������������Ϊ0����֮Ϊ����
//);

typedef struct {
	char name[20];
	int age;
}Stu;
/*******************test1ʹ��qsort����������������***************/
//��������
int cmp_int(const void* e1, const void* e2)
{
	return -*(int*)e1 + *(int*)e2;
}
//����ʹ��qsort����������������
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
/******************test2��qsort�ȽϽṹ����������***********************/
//�ȽϽṹ���е�name
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((Stu*)e1) -> name,((Stu*)e2) -> name);
}
//�ȽϽṹ���е�age
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((Stu*)e1)->age - ((Stu*)e2)->age;
}
//����ʹ��qsort������ṹ��
void test2(void)
{
	Stu s[] = {{"zhangsan", 13}, {"lisi", 14}, {"wangwu", 15}};
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof (s[0]), cmp_stu_by_name);
}

/***************ģ��qsort����д��дð������***************/
/*
*	@brief	�������������������͵�����
*	*buf1������1�ĵ�ַ
*	*buf2������2�ĵ�ַ
*	width������ռ�ռ��ֽ���
*/
void Swap(char* buf1, char* buf2, int width)//���ڲ���������������������ͣ��м�����޷����������õ�ַ��С����charһ�ֽ�һ�ֽڵĽ���
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
 *  @brief   ð�����򣬲�������������
 *  *base���������������ʼλ��
 *  size:  ���鳤��
 *  width������Ԫ����ռ�ռ��ֽ���
 *	*cmp���Զ�����������ͱȽϺ�����e1 > e2����������=����0��<���ظ���
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
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//cmp������õ�ַ������Ϊ����Ҫ�������ַ�е�Ԫ���������Ԫ��Ҳ���õ�ַ����ʽд��
			{
				//����
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);//��Ҫ�������������ĵ�ַ���������ݵĳ���
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
//����ð������
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


