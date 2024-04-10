#include "LSM.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>

// Constructor
LSM::LSM(const std::vector<double>& xy, int degree) {
    coefficients = leastSquaresMethod(xy, degree);
}

// Function to calculate coefficients of the polynomial using the least squares method
std::vector<double> LSM::leastSquaresMethod(const std::vector<double>& xy, int degree) {
    int n = xy.size() / 2;

    std::vector<double> coefficients(degree + 1, 0.0);
    std::vector<double> sumX(2 * degree + 1, 0.0);
    std::vector<double> sumY(degree + 1, 0.0);

    // Extract x and y coordinates from vector
    std::vector<double> x, y;
    for (int i = 0; i < n; ++i) {
        x.push_back(xy[2 * i]);
        y.push_back(xy[2 * i + 1]);
    }

    // Calculate the sums of powers of x
    for (int i = 0; i < 2 * degree + 1; ++i) {
        for (int j = 0; j < n; ++j) {
            sumX[i] += pow(x[j], i);
        }
    }

    // Calculate the sums of powers of x*y
    for (int i = 0; i < degree + 1; ++i) {
        for (int j = 0; j < n; ++j) {
            sumY[i] += pow(x[j], i) * y[j];
        }
    }

    // Create the normal equations matrix
    std::vector<std::vector<double>> A(degree + 1, std::vector<double>(degree + 1, 0.0));
    for (int i = 0; i < degree + 1; ++i) {
        for (int j = 0; j < degree + 1; ++j) {
            A[i][j] = sumX[i + j];
        }
    }

    // Solve the equations
    for (int i = 0; i < degree + 1; ++i) {
        for (int j = i + 1; j < degree + 1; ++j) {
            double ratio = A[j][i] / A[i][i];
            for (int k = 0; k < degree + 1; ++k) {
                A[j][k] -= ratio * A[i][k];
            }
            sumY[j] -= ratio * sumY[i];
        }
    }

    // Back substitution
    coefficients[degree] = sumY[degree] / A[degree][degree];
    for (int i = degree - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < degree + 1; ++j) {
            sum += A[i][j] * coefficients[j];
        }
        coefficients[i] = (sumY[i] - sum) / A[i][i];
    }

    return coefficients;
}

// Function to generate a string representation of the polynomial equation
std::string LSM::polynomialString() {
    std::stringstream ss;
    int degree = coefficients.size() - 1;

    for (int i = degree; i >= 0; --i) {
        if (coefficients[i] != 0.0) {
            if (i < degree) {
                ss << " + ";
            }
            ss << std::fixed << std::setprecision(2) << coefficients[i];
            if (i > 0) {
                ss << "x";
                if (i > 1) {
                    ss << "^" << i;
                }
            }
        }
    }

    return ss.str();
}

// Function to print coefficients
void LSM::printCoefficients() {
    std::cout << "Coefficients: ";
    for (double coefficient : coefficients) {
        std::cout << coefficient << " ";
    }
    std::cout << std::endl;
}

std::vector<double> LSM::getCoefficients()
{
    return coefficients;
}