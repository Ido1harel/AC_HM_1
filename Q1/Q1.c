#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int calcDividedDigits(int number, int digit);

void main()
{
	int mainNumber = 0;
	int digit = 0;

	printf("Please enter the main number:\n");
	scanf("%d", &mainNumber);
	printf("Please enter the dividing digit:\n");
	scanf("%d", &digit);
	printf("The result is: %d", calcDividedDigits(mainNumber, digit));

}

int calcDividedDigits(int number, int digit)
{
	int static counter = 0;
	if (number <= 0)
	{
		return counter;
	}

	if ((number % 10) % digit == 0)
	{
		counter++;
	}
	calcDividedDigits(number / 10, digit);
}