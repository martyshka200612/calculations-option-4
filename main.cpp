 #include <iostream>
 #include <cmath>
#include <iomanip>

int main() {
    double x=0.7;
    int k;
    std::cin >> k;
    int i= 0; //счетчик
    int p;

    if (x>=-1&x<1) {
        double ln = log(1.0-x);
        std::cout << ln << std::endl;
    }
int n = 1;
    double u=0;
    while(i<=p){
       i ++;

       double y=pow(x, n)/n;
       u=u-y;
       n+=1;
        std::cout << u << std::endl;





    }

//цикл должен повторяться 25 раз, чтобы получилось точное число

    return 0;
}
