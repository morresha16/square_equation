#ifndef SOLVESQUARE_H_INCLUDED
#define SOLVESQUARE_H_INCLUDED

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double LinearEquation(double coef1, double coef2);
bool IsZero(double number);
bool IsEqual(double number1, double number2);
int SolveSquare(double a, double b, double c, double* root1, double* root2);
void OutputSolution(int nRoots, double root1, double root2);
void InputCoeffitients(double* a, double* b, double* c);

struct testData
{
    double a;
    double b;
    double c;
    int number_roots;
    double root1;
    double root2;
};

void Test();

const int INF_ROOTS = -1;
const int NO_ROOTS  = -2;
const int ONE_ROOT  = 1;
const int TWO_ROOTS = 2;
const double BORDER = 1e-100;

#endif // SOLVESQUARE_H_INCLUDED
