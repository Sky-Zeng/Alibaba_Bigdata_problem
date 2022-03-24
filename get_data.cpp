#include <ctime>
#include <fstream>
#include <cstdlib>
#include <random>
#include <iostream>

using namespace std;

const int N = 1e7;

int main()
{
	ofstream out[11];
	for(int i = 1; i <= 10; i++)
		out[i].open("data" + to_string(i) + ".txt");
	
	srand((unsigned)time(0));
	for(int t = 0; t < 10 * N; t++)
	{	    
		
		out[t / N + 1] << rand() << endl;
	}
	
	for(int i = 1; i <= 10; i++)
		out[i].close();
	return 0;
}


