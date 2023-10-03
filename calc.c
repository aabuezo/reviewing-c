#include <stdio.h>
#include <stdlib.h>


int main()
{
    char op;
    double  op_a = 0.0, 
            op_b = 0.0, 
            result = 0.0;

    printf("Enter operator: ");
    scanf("%c", &op);
    printf("Enter first operand: ");
    scanf("%lf", &op_a);
    printf("Enter second operand: ");
    scanf("%lf", &op_b);

    int error = 0;

    switch (op)
    {
    case '+':
        result = op_a + op_b;
        break;
    case '-':
        result = op_a - op_b;
        break;
    case '*':
        result = op_a * op_b;
        break;
    case '/':
        result = op_a / op_b;
        break;
    default:
        error = 1;
        break;
    }

    if (error)
    {
        printf("\nBad operator: %c\n", op);
        return EXIT_FAILURE;
    }

    printf("\n%.1f %c %.1f = %.1f\n", op_a, op, op_b, result);

    return EXIT_SUCCESS;
}