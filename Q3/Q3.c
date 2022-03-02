#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int strcmpRec(char* arr1, char* arr2);

void main()
{
	char arr1[15] = "aaa";
	char arr2[15] = "aaa";
	printf("result is: %d", strcmpRec(arr1, arr2));
}

int strcmpRec(char* arr1, char* arr2)
{
	if ((*arr1) != '\0' && (*arr2) == '\0')
	{
		return 1;
	}
	if ((*arr1) == '\0' && (*arr2) != '\0')
	{
		return -1;
	}
	if ((*arr1) == '\0' && (*arr2) == '\0')
	{
		return 0;
	}

	if ((*arr1) == (*arr2))
	{
		return strcmpRec(arr1 + 1, arr2 + 1);
	}
}