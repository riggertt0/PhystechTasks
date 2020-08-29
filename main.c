#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int NOT_QUADRATIC_CODE = -1;
const double MINIMUM_DIFFERENCE = 1E-6;
const int MAX_LENGTH_OF_DOUBLE = 25;

//------------------------------------------------
//! Raises a number to a power
//!
//! @param [in] number Number
//! @param [in] power Power
//!
//! @return Raised to a power number
//!
//! @note If power lower that 2, returns number
//!       without changes.
//------------------------------------------------
double power (double number, int power);

//------------------------------------------------
//! Checks if number is equal to zero
//!
//! @param [in] number Number
//!
//! @return Is this number equal to zero
//------------------------------------------------
bool numberIsNearZero(double number);

//------------------------------------------------
//! Solves a square equation
//!
//! @param [in]   a     a-coefficient
//! @param [in]   b     b-coefficient
//! @param [in]   c     c-coefficient
//! @param [out]  root1 Pointer to the first root
//! @param [out]  root2 Pointer to the second root
//!
//! @return Number of roots
//!
//! @note If a-coefficient equal to 0, returns
//!       NOT_QUADRATIC_CODE
//------------------------------------------------
int solveQuadraticEquation (double a ,double b ,double c, double* root1, double* root2);

//------------------------------------------------
//! Checks if char can be a symbol of double
//!
//! @param [in] symbol Symbol
//!
//! @return If char can be a symbol of double
//------------------------------------------------
bool thisSymbolIsNumber(char symbol);

//------------------------------------------------
//! Performs safe input of double
//!
//! @return Double from input
//------------------------------------------------
double getNumberFromUser();

#include "tests.c"

int main()
{
    doTest(4,3,-1);
    doTest(2,0,0);
    doTest(4,3,5);
    doTest(0,9,8);

    doTestWithRandomValues(100.0, 200.0);
    doTestWithRandomValues(100.0, 200.0);
    doTestWithRandomValues(-100.0, 200.0);
    doTestWithRandomValues(-200.0, -100.0);

    printf("%s\n", "Write coefficient a:");
    double a = getNumberFromUser();

    printf("%s\n", "Write coefficient b:");
    double b = getNumberFromUser();

    printf("%s\n", "Write coefficient c:");
    double c = getNumberFromUser();

    double root1 = 0;
    double root2 = 0;
    int numberOfRoots = solveQuadraticEquation (a ,b ,c, &root1, &root2);

    switch(numberOfRoots) {

        case 0:
        printf("%s\n", "There are no roots.");
        break;

        case 1:
        printf("%s\n%.2lf", "There is one root:", root1);
        break;

        case 2:
        printf("%s\n%.2lf\n%.2lf", "There are two roots:", root1, root2);
        break;

        case NOT_QUADRATIC_CODE:
        printf("%s\n", "The a coefficient cannot be equal to 0!");
        break;

    }

    return 0;
}

double power (double number, int power) {
    for(int i=1; i<power; i++) {
        number = number*number;
    }
    return number;
}

bool numberIsNearZero(double number){
    return (abs(number) - MINIMUM_DIFFERENCE < 0);
}

int solveQuadraticEquation (double a ,double b ,double c, double* root1, double* root2) {

    if(numberIsNearZero(a)) {
        return NOT_QUADRATIC_CODE;
    }

    double discriminant = power(b, 2) - 4*a*c;
    if(discriminant >= 0) {
        if(numberIsNearZero(discriminant)){
            *root1 = (-b / (2*a));
            *root2 = *root1;
            return 1;
        } else {
            double sqrtOfDiscriminant = sqrt(discriminant);
            *root1 = ((-b + sqrtOfDiscriminant) / (2*a));
            *root2 = ((-b - sqrtOfDiscriminant) / (2*a));
            return 2;
        }
    } else {
        return 0;
    }
}

bool thisSymbolIsNumber(char symbol) {

    char possibleSymbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '-'};

    bool thisIsNumber = false;

    for(int i = 0; i < sizeof(possibleSymbols); i++){
        if(possibleSymbols[i] == symbol){
            thisIsNumber = true;
            break;
        }
    }

    return thisIsNumber;
}

double getNumberFromUser(){

    char str[MAX_LENGTH_OF_DOUBLE] = { 0 };
    int length = 0;

    while(true){
        char newChar = getchar();

        if(newChar == '\n'){
            return atof(str);
        }

        if(thisSymbolIsNumber(newChar)){
            str[length] = newChar;
            length++;
        }
    }
}
