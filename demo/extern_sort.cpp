#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

#define pb push_back

const int M = 10;  //��ʼ�ļ�ÿ��10�� --���� 
const int N = 5;  //ÿ���ļ�5�� --���� 

int cnt = 0;
vector<int> nums;
int number;
int deviation[50]={0};

void extern_sort(int k)
{
    int j = 2 * (k - 1); 
    ifstream in("data" + to_string(k) + ".txt"); 
    if (!in) {
        cerr << "the file does not exist";
    }

    while (in >> number) {
    	cnt++;
    	nums.pb(number);
    	
    	if(cnt % N == 0){
			sort(nums.begin(), nums.end());
			j++;
			ofstream out("small" + to_string(j) + ".txt");
	    	for (auto& num: nums) {
	        	out << num << endl;
	    	}
	    	out.close();
	    	nums.clear();
    	}
    }
    in.close();
}

int main()
{
	for(int i = 1; i <= 2; i++)
		extern_sort(i);
	
	ifstream in[51];
	for(int i = 1; i <= 4; i++)
	{
		in[i].open("small" + to_string(i) + ".txt");
		in[i] >> number;
		nums.push_back(number);
	}
	
	for(int k = 1; k <= 2 * M; k++)
	{
		int min_pos = min_element(nums.begin(), nums.end()) - nums.begin();
		
		string file_name = "out" + to_string((k - 1) / M) + ".txt";
		ofstream out(file_name, fstream::app);
		out << nums[min_pos] << endl;

		deviation[min_pos + 1]++;
		
		if(deviation[min_pos + 1] < N)
		{
			in[min_pos + 1] >> nums[min_pos];
		}
		else
		{
			nums[min_pos] = INT_MAX;
		}	                              
	}
	
	for(int i = 1; i <= 4; i++)
	{
		in[i].close();
	}

    return EXIT_SUCCESS;
}