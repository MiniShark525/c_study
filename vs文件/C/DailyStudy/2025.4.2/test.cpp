#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);//输入指针不能为空指针，否则对空指针解引用后程序会崩溃
//	char* ret = dest;
//	while (*dest++ = *src++);
//	return ret;
//}
//
//int main(void)
//{
//	char arr1[] = "abcdef";
//	char arr2[20] = "xxxxxxxxx";
//	my_strcpy(NULL, arr1);
//	printf("%s\n", my_strcpy(arr2, arr1));//abcdef
//	return 0;
//}

//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest)
//	{
//		dest++;
//	}
//
//	while (*dest++ = *src++);
//	return ret;
//}
//
//int main(void)
//{
//	char arr[20] = "Hello ";
//	my_strcat(arr, "World");
//	printf("%s\n", arr);
//
//	return 0;
//}

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1++ == *str2++ && *str1 != '\0');
	return *str1 - *str2;
}

int main(void)
{
	char arr1[] = "abcd";
	char arr2[] = "abc";
	int ret = my_strcmp(arr1, arr2);
	if (ret > 0)
		printf(">\n");
	else if (ret < 0)
		printf("<\n");
	else
		printf("==\n");

	return 0;
}


