#define _CRT_SECURE_NO_WARNINGS 1
//��һ�������������������е�ż��ǰ��������ӡ������
//#include <stdio.h>
//int main(void)
//{
//	int input[10] = {0};
//	int i = 0;
//	//��������
//	int sz = sizeof(input) / sizeof(input[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", input + i);
//	}
//	//�������顪������ռ���ڴ�̫���ұ�����������Ч�ʵ�
//		//���ҳ�������ŵ���һ������
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
//		//���ҳ������������
//	for (i = 0; i < sz; i++)
//	{
//		if (input[i] % 2 == 0)
//		{
//			tmp[num] = input[i];
//			num++;
//		}
//	}
//		//��input��ֵΪtmp
//	for (i = 0; i < sz; i++)
//	{
//		input[i] = tmp[i];
//	}
//	//��ӡ����
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", input[i]);
//	}
//	return 0;
//}

////�Ż���������ֻ�鲼��һ������
//#include <stdio.h>
////����L��R����ָ�룬L������ҵ�ż��ʱ��R���ұ߿�ʼ�ң�R�ҵ�����ʱ���໥������ַ���ݣ���ע��L<R
//void adjust_arr(int input[], int sz)
//{
//	int* left = input;
//	int* right = &input[sz - 1];
//	while (left < right)
//	{
//		while ((*left % 2 == 1) && (left < right))//ʱ��ע��L<R���������inputȫ�������ᵼ�����
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
//	//��������
//	int sz = sizeof(input) / sizeof(input[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", input + i);
//	}
//	//��������
//	adjust_arr(input, sz);
//	//��ӡ����
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", input[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main(void)
//{
//	const char* p = "abcdef";//vs2022��"abcdef"�������ص��Ǳ�const���ε����ַ���ַ�����ֱ�Ӹ�ֵ,�ڶ�p�����͸ı���ԭ�ַ�����Υ����const
//	char arr[] = "abcdef";//��ʾ�������ַ�����ֵ�������У�����������ǰ��ַ����׵�ַ��ֵ��ָ��
//	printf("%s\n", p);
//	return 0;
//}

//#include <stdio.h>
//int main(void)
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = {2,3,4,5,6};
//	int arr3[] = {3,4,5,6,7};
//	int* parr[3] = {arr1, arr2, arr3};//ģ���ά����
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