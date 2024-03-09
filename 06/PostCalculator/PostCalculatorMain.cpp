#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int main() {
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	ConvToRPNEXP(exp1);
	ConvToRPNEXP(exp2);
	ConvToRPNEXP(exp3);

	printf("%s\n", exp1);
	printf("%s\n", exp2);
	printf("%s\n", exp3);
	printf("\n");

	int result1 = EvalRPNExp(exp1);
	int result2 = EvalRPNExp(exp2);
	int result3 = EvalRPNExp(exp3);

	printf("%d\n", result1);
	printf("%d\n", result2);
	printf("%d\n", result3);
	printf("\n");

}