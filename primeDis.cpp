#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

bool primenumberJudge(int n)
{

	for (int i =2;i< sqrt(n);i++)
	{
		if (n % i ==0)
		{
			if (n != i)
			{
				
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	return true;
}

int main()
{
	int n,counter = 0,list[10000];

	// clock_t start, end;

	cin>>n;

	int looptime = n/2;

	// memset(list,0,sizeof(list));

	// start= clock();

	for(int i=2;i< looptime;i++)
	{
		if (n % i == 0)
		{
			if (primenumberJudge(i))
			{
				list[counter] = i;

				n = n / i;

				counter++;i--;
			}
		}
	}
	for(int i=0;i < counter;i++)
	{
		cout<<list[i]<<" ";
	}

	// end = clock();

	// cout<<endl<<"Run time: "<<(double)(end - start) / CLOCKS_PER_SEC<<"s"<<endl;

	// return 0;
	system("pause");

}