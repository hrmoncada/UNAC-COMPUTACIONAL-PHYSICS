// Buffon Needle Experiment
// https://cplusplus.com/forum/beginner/271513/
// 9.1.7 Example: Buffon’s needle (con’t)
//https://smac-group.github.io/ds/high-performance-computing.html
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
int main()
{
	double start = 0;
	double angle = 0;
	double ylow = 0;
	double yhigh = 0;
	double hits = 0;
	double tries = 0;
	srand(time(0));
	const double PI = 3.141592653589793238;
	for (int i = 0; i < 10000; i++)
	{
		ylow = rand() % 2;
		angle = rand() % 180;
		yhigh = ylow + sin(angle);
		tries++;

		if (yhigh >= 2)
		{
			hits++;
		}
	}
	cout << tries / hits;
	return 0;
}
