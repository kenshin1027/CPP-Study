#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> v;
int isPrime(int n) {
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    if(n == 1){ // 1位数
        cout << "4\n2 3 5 7";
    }else if(n == 2){ // 2位数
        cout << "1\n11";
    }else if(n == 3 || n == 5 || n == 7 || n == 9){// 奇数位数
        double d = pow(10, (n-1) / 2); // 得到n位数对称轴前面的数（包括对称轴）
        int i = (int)d; // C++中直接转int，会舍弃小数点后面的数，所以用了两步。
        for(; i < d * 10; i++) { // 遍历n位数
            int sum = i;
            int ii = i;
            ii /= 10;
            while(ii != 0) { // sum 生成的回文数
                sum = sum * 10 + ii%10;
                ii /= 10;
            }
			cout << sum << endl;
            if(sum % 2 != 0){ // sum的末位不是偶数，同时也表明首位不是偶数
                if(isPrime(sum)){ // 是否为素数
                    v.push_back(sum);
                }
            }
        }
        printf("%d\n", (int)v.size());
        for(int i = 0; i < (int)v.size(); i++) {
            printf("%d ", v[i]);
        }
    }else{ // 偶数位数是不存在回文质数的，除了11。
        printf("0");
    }
    return 0;
}