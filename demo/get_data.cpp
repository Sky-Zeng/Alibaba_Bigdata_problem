#include <ctime>
#include <fstream>
#include <cstdlib>
#include <random>
#include <iostream>

using namespace std;

const int N = 10;

int main()
{
	ofstream out[10];
	for(int i = 1; i <= 2; i++)
		out[i].open("data" + to_string(i) + ".txt");
	
	srand((unsigned)time(0));
	for(int t = 0; t < 2 * N; t++)
	{	    
		
		out[t / N + 1] << rand() % 100 << endl;
	}
	
	for(int i = 1; i <= 2; i++)
		out[i].close();
	return 0;
}


