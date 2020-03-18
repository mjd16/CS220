/** mathematicalFunctions.c
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* ===========================================================
*/
#include "PEX3_mathematicalFunctions.h"

double bigMath(double num1, double num2, char operation) {
	switch(operation) {
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2; 
		case '/':
			return num1 / num2;
		case '^':
			int ret = 0;
			int mult = num1;
			for (int i = 0; i < num2; i++)
				num1 = num1 * mult;
			return num1;
		default:
			return 0;
	}
	return 0;
}

