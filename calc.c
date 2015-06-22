#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int readArg(char *arg);

struct Operation{
	int operandLeft;
	int operandRight;
};

struct Operation *Operation_create(int operandLeft, int operandRight)
{
	struct Operation *add = malloc(sizeof(struct Operation));
	add->operandLeft = operandLeft;
	add->operandRight = operandRight;

	return add;
}

void Operation_destroy(struct Operation *add){
	assert(add != NULL);
	free(add);
}

int Operation_add(struct Operation *add)
{
	return add->operandLeft + add->operandRight;	
}

int main(int argc, char *argv[])
{
	int i = 1;
	int op = 0;
	int left = 0;
	int right = 0;
	int result = 0;

	for(i = 1; i < argc; i++) {
		op = readArg(argv[i]);
		if(op == 1) {
			i++;
			right = atoi (argv[i]);
			struct Operation *operation = Operation_create(left, right);
			result = Operation_add(operation);
			printf("%d\n", result);
			Operation_destroy(operation);
		} else {
			left = atoi (argv[i]);
		}
	}
	return 0;
}

int readArg(char *arg)
{
	if(*arg == 43) {
		return 1;
	} else {
		return 0;
	}
}
