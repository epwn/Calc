#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {ADD, SUBTRACT, MULTIPLY, DIVIDE} operators;

int isOperator(char *arg);
operators determineOperation(char operation);


struct Expression{
	int operandLeft;
	int operandRight;
	operators operator; 
};

struct Expression *Expression_create(int operandLeft, int operandRight, operators operator)
{
	struct Expression *expression = malloc(sizeof(struct Expression));
	expression->operandLeft = operandLeft;
	expression->operandRight = operandRight;
	expression->operator = operator;

	return expression;
}

void Expression_destroy(struct Expression *expression){
	assert(expression != NULL);
	free(expression);
}

int Expression_operate(struct Expression *expression)
{
	switch(expression->operator) {
		case ADD:
			return(expression->operandLeft + expression->operandRight);
			break;
		case SUBTRACT:
			return(expression->operandLeft - expression->operandRight);
			break;
		case MULTIPLY:
			return(expression->operandLeft * expression->operandRight);
			break;
		case DIVIDE:
			return(expression->operandLeft / expression->operandRight);
			break;
		default:
			return(0);
	}	
}

int main(int argc, char *argv[])
{
	int i = 1;
	char operation = ' ';
	int opFlag = 0;
	int left = 0;
	int right = 0;
	int result = 0;

	for(i = 1; i < argc; i++) {
		opFlag = isOperator(argv[i]);
		if(opFlag == 1) {
			operation = *argv[i++];
			right = atoi(argv[i]);
			struct Expression *expression = Expression_create(left, right, determineOperation(operation));
			result = Expression_operate(expression);
			printf("%d\n", result);
			Expression_destroy(expression);
		} else {
			left = atoi (argv[i]);
		}
	}
	return 0;
}

int isOperator(char *arg)
{
	if(*arg == 43 || *arg == 45 || *arg == 120 || *arg == 47) {
		return 1;
	} else {
		return 0;
	}
}

operators determineOperation(char operation)
{
	switch(operation) {
		case '+':
			return(ADD);
			break;
		case '-':
			return(SUBTRACT);
			break;
		//Cannot use '*' because shells reserve that character. There might be a workaround?
		case 'x':
			return(MULTIPLY);
			printf("Made it here");
			break;
		case '/':
			return(DIVIDE);
			break;
		default:
			return(ADD);
	}			
}
