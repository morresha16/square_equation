#include <SolveSquare.h>

double LinearEquation(double coef1, double coef2)
{
    return -coef1/coef2;
}

bool IsZero(double number)
{
    if (BORDER >= fabs(number))
        return 1;
    else
        return 0;
}

bool IsEqual(double number1, double number2)
{
    if (fabs(number1 - number2) <= BORDER)
        return 1;
    else
        return 0;

}

int SolveSquare(double a, double b, double c, double* root1, double* root2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(root1 != NULL);
    assert(root2 != NULL);
    assert(root1 != root2);


    if (IsZero(a))              //проверка, квадратное ли уравнение//
    {
        if (IsZero(b))
        {
            if (IsZero(c))
            {
                return INF_ROOTS;
            }
            else
            {
                return NO_ROOTS;
            }
        }
        else
        {
             *root1 = LinearEquation(c, b);
             return ONE_ROOT;
        }
   }
   else                                         //если уравнение квадратное//
   {
        double discriminant = b*b - 4*a*c;

        if (discriminant < 0)
        {
             return NO_ROOTS;
        }
        else
        {
             if (IsZero(discriminant))
             {
                  *root1 = LinearEquation(b, 2*a);
                  return ONE_ROOT;
             }
             else
             {
                  *root1 = (-b + sqrt(discriminant)) / (2 * a);
                  *root2 = (-b - sqrt(discriminant)) / (2 * a);
                  return TWO_ROOTS;
             }
        }
   }
}

void OutputSolution(int nRoots, double root1, double root2)
{
    switch(nRoots)
    {
        case ONE_ROOT:
            printf(" Answer: x1 = %lg\n", root1);
            break;
        case TWO_ROOTS:
            printf(" Answer: x1 = %lg, x2 = %lg\n", root1, root2);
            break;
        case NO_ROOTS:
            printf(" Answer: No roots\n");
            break;
        case INF_ROOTS:
            printf(" Answer: Infinity number of roots\n");
            break;
        default:
            printf(" Answer: Error\n");
            break;
        }
}

void InputCoeffitients(double* a, double* b, double* c)
{
    int counter = 0;
    printf(" Enter coefficients of square equation: ");
    int number_succesful_inputs = scanf("%lg %lg %lg", a, b, c);
    printf("\n");

    while (number_succesful_inputs != 3)
    {
        fflush(stdin);
        printf(" Wrong enters!\n Please enter three coefficients again: ");
        number_succesful_inputs = scanf("%lg %lg %lg", a, b, c);
        printf("\n");
        counter++;
        if (counter == 5 && number_succesful_inputs != 3)
        {
            printf(" You're tired! Go to sleep:)\n");
            exit(1);
        }
    }
}

struct testData
{
    double a;
    double b;
    double c;
    int number_roots;
    double root1;
    double root2;
};

void Test()
{
    testData test_data[5] =
       {{1,      1,       -2,     TWO_ROOTS, 1, -2},
        {1,      1,       1,      NO_ROOTS,  0,  0},
        {1e-100, 1e-100,  1e-100, INF_ROOTS, 0,  0},
        {1,      -2,      1,      ONE_ROOT,  1,  0},
        {1e-100, 1,       -2,     ONE_ROOT,  2,  0}};

    int i = 1, nRoots = 1, counter = 0;
    double root1 = NAN, root2 = NAN;
    printf(" Test:\n");

    for(i = 0; i < 5; i++)
    {
        nRoots = SolveSquare(test_data[i].a, test_data[i].b, test_data[i].c, &root1, &root2);
        if (nRoots == test_data[i].number_roots)
        {
            switch(nRoots)
            {
                case ONE_ROOT:
                    if (IsEqual(root1, test_data[i].root1))
                    {
                        printf("  OK\n");
                        counter++;
                    }
                    else
                        printf("  Error\n");
                    break;
                case TWO_ROOTS:
                    if (IsEqual(root1, test_data[i].root1) && IsEqual(root2, test_data[i].root2))
                    {
                        printf("  OK\n");
                        counter++;
                    }
                    else
                        printf("  Error\n");
                    break;

                case NO_ROOTS:
                    printf("  OK\n");
                    counter++;
                    break;

                case INF_ROOTS:
                    printf("  OK\n");
                    counter++;
                    break;

                default:
                    printf(" Answer: Error\n");
                    break;
            }
        }
        else
            printf("Number of roots didn't match");
    }
    if (counter == i)
        printf(" ALL TESTS COMPLETED\n");
}
