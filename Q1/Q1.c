#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int calcDividedDigits(int number, int digit);

void main()
{ 
	int mainNumber = 0;
	int digit = 0;  

	// get the number from the user
	printf("Please enter the main number:\n");
	scanf("%d", &mainNumber);

	// get the digit to divide by from the user
	printf("Please enter the dividing digit:\n");
	scanf("%d", &digit);

	// print the result
	printf("The result is: %d", calcDividedDigits(mainNumber, digit));
}

/// <summary>
/// The function is a recursion that returns the amount of numbers that are divided cleanly by the digit supplied
/// </summary>
/// <param name="number">The number to check</param>
/// <param name="digit">The dividing digit</param>
/// <returns>The amount divided cleanly</returns>
int calcDividedDigits(int number, int digit)
{
	// The stopping condition of the recursion
	if (number <= 0)
	{
		return 0;
	}

	// if the digit is divided cleanly add 1 to the return amount
	if ((number % 10) % digit == 0)
	{
		return calcDividedDigits(number / 10, digit) + 1;
	}
	// if the digit is not divided cleanly return the amount
	else 
	{
		return calcDividedDigits(number / 10, digit);
	}
}