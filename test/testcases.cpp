#define BOOST_TEST_MODULE roots test
#define _USE_MATH_DEFINES
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <cmath>
#include <exception>
#include "../src/roots.hpp"

double f1(double x) { return x; } 		// Line with positive slope
double f2(double x) { return -x; } 		// Line with negative slope
double f3(double x) { return x*x; }		// Parabel
double f4(double x) { return x*x-2; }	// Roots +-sqrt(2)
double f5(double x) { return x*x*x*x-2*x*x+x;}	// Roots ~-1.618, 0 0.61803, 1
double f6(double x) { return M_E * x+x*x*x*x*x*x*x*x-5*x;} // Root ~0.259177 ~1.12371

double eps = 1e-6;

BOOST_AUTO_TEST_CASE(Bisection01){
	BOOST_CHECK(abs(bisection(f1, -1, 1, eps, 1000)) <= eps);
	BOOST_CHECK(abs(bisection(f2, -1, 1, eps, 1000)) <= eps);
	BOOST_CHECK(abs(bisection(f3, 0, 1, eps, 1000)) <=  eps);
	BOOST_CHECK(abs(bisection(f4, 0, 3, eps, 1000)) - 1.1412 <= eps);
	BOOST_CHECK(abs(bisection(f4, -3, 0, eps, 1000)) - 1.1412 <=  eps);
	BOOST_CHECK(abs(bisection(f5, -2, -1, eps, 1000)) - 1.618 <= eps);
	BOOST_CHECK(abs(bisection(f5, -0.5, 0.5, eps, 1000)) <= eps);
	BOOST_CHECK(abs(bisection(f5, 0.5, 0.99, eps, 1000)) - .618 <= eps);
	BOOST_CHECK(abs(bisection(f5, 0.7, 2, eps, 1000)) -1 <= eps);
	BOOST_CHECK(abs(bisection(f5, 0.7, 1, eps, 1000)) - 1 <= eps);
	BOOST_CHECK(abs(bisection(f6, 0, 1, eps, 1000)) - 0.25977 <= eps);
	BOOST_CHECK(abs(bisection(f6, 1, 2, eps, 1000)) - 1.12371 <= eps);
}

BOOST_AUTO_TEST_CASE(Bisection02){
	BOOST_CHECK(abs(bisection(f1, -1, 1)) <= eps);
	BOOST_CHECK(abs(bisection(f2, -1, 1)) <= eps);
	BOOST_CHECK(abs(bisection(f3, 0, 1)) <=  eps);
	BOOST_CHECK(abs(bisection(f4, 0, 3)) - 1.1412 <= eps);
	BOOST_CHECK(abs(bisection(f4, -3, 0)) - 1.1412 <=  eps);
	BOOST_CHECK(abs(bisection(f5, -2, -1)) - 1.618 <= eps);
	BOOST_CHECK(abs(bisection(f5, -0.5, 0.5)) <= eps);
	BOOST_CHECK(abs(bisection(f5, 0.5, 0.99)) - .618 <= eps);
	BOOST_CHECK(abs(bisection(f5, 0.7, 2)) -1 <= eps);
	BOOST_CHECK(abs(bisection(f5, 0.7, 1)) - 1 <= eps);
	BOOST_CHECK(abs(bisection(f6, 0, 1)) - 0.25977 <= eps);
	BOOST_CHECK(abs(bisection(f6, 1, 2)) - 1.12371 <= eps);
}

BOOST_AUTO_TEST_CASE(Secant02){
	double root = secant(f3, -3, -2);
	std::cout << root << std::endl;
}
