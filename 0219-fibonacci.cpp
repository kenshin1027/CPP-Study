#include <iostream>
#include <ctime>
using namespace std;


// int fibonacci(int n)
// {
//     int a = 0,b=1;
//     int sum;
//     if (n == 1)  
//     {
//         return 1;
//     }

//     for (int i = 2;i<=n;i++)
//     {
//         sum = a + b;
//         a = b;
//         b = sum;
//     }
//     return sum;
// }
int fibonacci(int first,int second,int n)
{
    if (n <= 0)
    {
        return 0;    
    }
    if (n < 3 )
    {
        return 1;
    }
    else if (n == 3)
    {
        return first + second;
    }
    else
    {
        return fibonacci(second,second + first,n-1);
    }
}

void time_consumption()
{
	
	clock_t startTime,endTime;  

	int n,result;

	cin>>n;

	startTime = clock();//计时开始
    
    result = fibonacci(1,1,n);

    endTime = clock();//计时结束
	cout<<result<<endl;
	cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;


   
}
int main()
{
    time_consumption();


    return 0;
}