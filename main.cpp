#include <iostream>
#include <cmath>

int main() {
    double x=0.7;
    int k = 6;
    int i= 0; //счетчик
    int p;
    std::cin >> p;
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



    return 0;
}
