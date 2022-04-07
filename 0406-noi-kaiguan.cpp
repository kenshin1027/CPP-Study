#include<iostream>
using namespace std;
char orlights[10];    //因为数据是只含0或1，用char的一维数组位运算比用二维数组简单快捷的多
char lights[10];
char result[10];
int GetBit(char c, int i)  //取出字符c第i位的比特
{
	return (c >> i) & 1;  
}
void SetBit(char & c, int i, int v)  //将c第i位改成v其余不变 注意c是引用，因为在C++中用引用可以在函数中修改形参时传进来的实参也跟着改变
{
	if (v)
		c |= (1 << i);
	else
		c &= ~(1 << i);
}
void FlipBit(char & c, int i) //将c的第i位翻转
{
	c ^= (1 << i);  //因为跟0异或不变，跟1异或翻转
}
void OutputResult(int t, char result[])   //输出结果
{
	cout << "Puzzle #" << t << endl;
	for (int i = 0; i != 5; ++i)
	{
		for (int j = 0; j != 6; ++j)
		{
			cout << GetBit(result[i], j);
			if (j != 5)
				cout << " ";
		}
		cout << endl;
	}
}
int main()
{
	int T;
	cin >> T;     //T组数据
	for (int t = 1;t <= T; ++t)
	{
		for (int i = 0; i != 5; ++i)
		{
			for (int j = 0; j != 6; ++j)
			{
				int s;
				cin >> s;
				SetBit(orlights[i], j, s); //将输入的整数s设为i行j列的比特
			}
		}
		for (int n = 0; n != 64; ++n) 
        //二进制枚举法(将一个整数k从0递增到k-1，每个数都可以表示k位二进制的一种情况,因为其二进制所表达的数是从0到2的k-1次方) 枚举第一行可能的情况 因为有6个数所以2的6次方=64
		{
			int switchs = n;
			memcpy(lights, orlights, sizeof(orlights));
			for (int i = 0; i != 5; ++i)
			{
				result[i] = switchs;  //存第i行开关状态
				for (int j = 0; j != 6; ++j)
				{
					if (GetBit(switchs, j))
					{
						if (j > 0)
							FlipBit(lights[i], j - 1);
						FlipBit(lights[i], j);
						if (j < 5)
							FlipBit(lights[i], j + 1);
					}
				}
				if (i < 4)
					lights[i + 1] ^= switchs;   //因为若第i行第j个比特是1则是按下开关则要翻转，而与1异或就是翻转，是0就不用
				switchs = lights[i];  //i行灯的状态与i+1行灯开关的按法是一致的 这样才能熄灭
			}
			if (lights[4] == 0)  //只要最后一行灯是灭的则可说明此种情况是全灭
			{
				OutputResult(t, result); //输出并跳出
				break;
			}
		}
	}
	system("pause");
}