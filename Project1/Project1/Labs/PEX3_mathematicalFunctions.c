/** PEX3_mathematicalFunctions.c
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* Documentation:
*	- C3C Phillips and I discussed methods for handling mixed numbers. I still have yet to figure
*	out how to do it.
*	- I  used stackoverflow to help me through the process of reducing fractions to their simplest forms
* ===========================================================
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "PEX3_mathematicalFunctions.h"

/** bigMath() - handles mathematical operations based on input
 * @param - num1 and num 2 are the doubles to be operated on
 * @param - op is the character representing the operation to be done
 * @return the double value of the result of the operation*/
double bigMath(double num1, double num2, char operation) {
	switch (operation) {
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	case '^':
		return pow(num1, num2);
	default:
		return 1;
	}
	return 1;
}

/** bigMathTwoFrac() - handles mathematical operations for two fractions
 * @param - num1 and num3 are the numerators of the fractions and 2/4 are denominators
 * @param - op is the character representing the operation to be done
 * @return character pointer to string of the resulting fraction*/
char* bigMathTwoFrac(int num1, int num2, int num3, int num4, char op) { //nums 1 and 3 are numerators and 2 and 4 are denoms
	char* ret;
	int place1 = 0; //numerator of first fraction when operating
	int place2 = 0; //numerator of second fraction when operating
	int numerator = 0; //numerator of resulting fraction
	int denominator = 0; //denominator of resulting fraction
	int reduced = 0;
	double frac = 0;
	switch (op) {
	case '+':
		place1 = num1 * num4;
		place2 = num2 * num3;
		numerator = place1 + place2;
		denominator = num2 * num4;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '-':
		place1 = num1 * num4;
		place2 = num2 * num3;
		numerator = place1 - place2;
		denominator = num2 * num4;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '*':
		numerator = num1 * num3;
		denominator = num2 * num4;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '/':
		numerator = num1 * num4;
		denominator = num2 * num3;
		ret = reduceFrac(numerator, denominator);
		return ret;
	//case '^':
	//	frac = pow((double)(num1)/num2, (double)num3/num4); 

	default:
		ret = "No result";
		return ret;
	}
}

/** bigMathOneFrac() - handles mathematical operations for a fraction and normal number
 * @param - num and denom are the numerator and denominator of the fraction and number is the normal number
 * @param - op is the character representing the operation to be done
 * @return character pointer to string of the resulting fraction*/
char* bigMathOneFrac(int num, int denom, int number, char op) {
	char* ret;
	int numerator = 0; //numerator of resulting fraction
	int denominator = 0; //denominator of resulting fraction
	int reduced = 0;
	double frac = 0;
	switch (op) {
	case '+':
		numerator = num + denom * number;
		denominator = denom;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '-':
		numerator = num - denom * number;
		denominator = denom;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '*':
		numerator = num * number;
		denominator = denom;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '/':
		numerator = num;
		denominator = denom * number;
		ret = reduceFrac(numerator, denominator);
		return ret;
		//case '^':
		//	frac = pow((double)(num1)/num2, (double)num3/num4); 

	default:
		ret = "No result";
		return ret;
	}
}

/** reduceFrac() - reduces an inputted fraction to its simplest form
 * @param - num1 and num2 are the numerator and denominator of the fraction
 * @return character pointer to string of the resulting fraction*/
char* reduceFrac(int numer, int denom) {
	int num1 = 0;
	int num2 = 0;
	int greatDenom = gcd(abs(numer), abs(denom));
	num1 = numer / greatDenom;
	num2 = denom / greatDenom;
	char ret[22];
	if (ret != '\0' && ret != '0') {
		sprintf(ret, "%d", num1);
		strcat(ret, " / ");
	}
	char ret2[22];
	if (ret2 != '\0' && ret2 != '0') {
		sprintf(ret2, "%d", num2);
	}
	strcat(ret, ret2);
	return ret;
}

/** gcd() - finds the greatest common denominator of two numbers
 * @param - num1 and num2 are the numerator and denominator of a fraction
 * @return greatest common denominator of a numerator and denominator*/
int gcd(int one, int two) {
	int remain = 0;
		while (one != 0) {
		remain = two % one;
		two = one;
		one = remain;
	}
		return two;
}

/** isMixedNum determines if a number inputted is a mixed number or not
* @param - num is the number to be checked
* @return is a boolean indicating whether it is a mixed number or not */
bool isMixedNum(char* num) {
	if (num[0] == '-') {
		num++;
	}
	//getting passed the first number and checking that the next character is a space
	int i = 0;
	while (num[i] != ' ') {
		i++;
	}
	//checking the next is a digit
	i++;
	if (!isdigit(num[i])) {
		return false;
	}
	i++;
		//checking the next is a space
		if (num[i] != ' ')
			return false;
		i++;
		//Checking next is a slash
			if (num[i] != '/')
				return false;
	//anything after that is irrelevant, it must be a mixed number
	i += 2;
	if (!isdigit(num[i])) {
		printf("Improper number entered");
	}
}

/** convertMixedToFraction takes a mixed number and returns the equivalent number in fraction form
* @param - mixedNum is the number to convert
* @return - the number in equivalent fraction form*/
//char* convertMixedToFraction(char* mixedNum) {
//	bool neg = false;
//	int count = 0;
//	if (mixedNum[0] == '-') {
//		neg = true;
//		count++;
//	}
//
//	char* coeff = malloc(sizeof(char)*22); //making copies in order to use strtok three times to get all numbers
//	strcpy(coeff, mixedNum);
//	char* numerator = malloc(sizeof(char) * 22);
//	strcpy(numerator, mixedNum);
//	char* denominator = malloc(sizeof(char) * 22);
//	strcpy(denominator, mixedNum);
//	
//	strtok(coeff, " "); //getting big num
//	numerator += strlen(coeff) + 1; //updating both other character pointers to use strtok again
//	denominator += strlen(coeff) + 1;
//
//	strtok(numerator, "/");
//	denominator += strlen(denominator) + 1;
//	
//	strtok(denominator, " ");
//
//	int coe = 0;
//	int numer = 0;
//	int denom = 0;
//	sprintf(coeff, "%d", coe);
//	sprintf(numerator, "%d", numer);
//	sprintf(denominator, "%d", denom);
//
//	numer = coe * denom + numer;
//	char* finalFrac = reduceFrac(numer, denom);
//
//	return finalFrac;
//}