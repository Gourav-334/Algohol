#include "ml.cpp"

using namespace regressions;

int main()
{
	SimLinReg slr;

	slr.add(45.981,34.567);
	slr.add(54.887,21.223);
	slr.add(52.091,44.547);

	slr.extract("new.txt");

	return 0;
}