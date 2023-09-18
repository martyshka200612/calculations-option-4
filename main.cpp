#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x=0.7;

    int i= 0; //счетчик
    int p;
    double ln;
    std::cin >> p;
    if (x>=-1&x<1) {
         ln = log(1.0-x);
        std::cout << std::setprecision(p+1) << ln << std::endl;

    }
    int n = 1;
    double u=0;
    long long u1=u*pow(10,p+1);
    long long ln1=ln*pow(10,p+1);
    while(u1!= ln1){
        i ++;

        double y=pow(x, n)/n;
        u=u-y;
        n+=1;



        u1=u*pow(10,p+1);





    }


    std::cout << std::setprecision(p+1) << u << std::endl;
    return 0;
}
