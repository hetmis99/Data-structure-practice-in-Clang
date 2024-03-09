#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "PostCalculator.h"
#include "InfixToPostfix.h"

int EvalInfixExp(char exp[]) {
	int len = strlen(exp);
	int ret;
	char* tmp = (char*)malloc(len + 1);
	strcpy(tmp, exp);

	ConvToRPNEXP(tmp);
	ret = EvalRPNExp(tmp);

	free(tmp);
	return ret;
}