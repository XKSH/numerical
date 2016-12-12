#define BOOST_TEST_MODULE roots test
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "../src/roots.hpp"

double f1(double x) { return x; } 		// Line with positive slope
double f2(double x) { return -x; } 		// Line with negative slope
double f3(double x) { return x*x; }		// Parabel
double f4(double x) { return x*x-2; }	// Roots +-sqrt(2)
double f5(double x) { return x*x*x*x-2*x*x+x;}	// Roots ~-1.618, 0 0.61803, 1

double eps = 1e-6;

BOOST_AUTO_TEST_CASE(roots){
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


}
