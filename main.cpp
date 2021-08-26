#include <SolveSquare.h>

int main()
{
    double a = NAN, b = NAN, c = NAN;
    double root1 = NAN, root2 = NAN;

    InputCoeffitients(&a, &b, &c);
    int nRoots = SolveSquare(a, b, c, &root1, &root2);
    OutputSolution(nRoots, root1, root2);

    Test();
}
