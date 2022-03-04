#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int strcmpRec(char* arr1, char* arr2);

void main()
{
	// user inputs strings
	char arr1[21] = "aaa";
	char arr2[20] = "aaa";
	printf("Please enter two strings for comparison (up to 21 characters):\n");

	// enter string 1
	printf("Please enter string 1: ");
	fseek(stdin, 0, SEEK_END);
	scanf("%s", arr1);

	// enter string 2
	printf("Please enter string 2: ");
	fseek(stdin, 0, SEEK_END);
	scanf("%s", arr2);
	
	// show result of comparisson
	int result = strcmpRec(arr1, arr2);

	switch (result)
	{
	case 0:
		printf("The strings are equal\n");
		break;
	case 1:
		printf("String 1 is greater\n");
		break;
	case -1:
		printf("String 2 is greater\n");
		break;
	}
}

/// <summary>
/// A recursive function that compares two strings
/// </summary>
/// <param name="arr1">string 1</param>
/// <param name="arr2">string 2</param>
/// <returns>1 if the first string is greater, -1 if the second string is greater, 0 if they are both equal</returns>
int strcmpRec(char* arr1, char* arr2)
{
	// if first array has finished and second hasn't then return 1
	// meaning array 1 is greater
	if ((*arr1) != '\0' && (*arr2) == '\0')
	{
		return 1;
	}

	// if second array has finished and first hasn't then return -1
	// meaning array 2 is greater
	if ((*arr1) == '\0' && (*arr2) != '\0')
	{
		return -1;
	}

	// both arrays finished then all is well, retun 0 they are equal
	if ((*arr1) == '\0' && (*arr2) == '\0')
	{
		return 0;
	}

	// if char in arr 1 is greater return 1
	if ((*arr1) > (*arr2))
	{
		return 1;
	}

	// if char in arr 2 is greater return -1
	if ((*arr1) < (*arr2))
	{
		return -1;
	}

	// if current char of both arrays is equal then check the next char
	if ((*arr1) == (*arr2))
	{
		return strcmpRec(arr1 + 1, arr2 + 1);
	}

}