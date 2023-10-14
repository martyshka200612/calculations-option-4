 #include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


#include <iostream>
#include <iomanip>
#include <cmath>
 using namespace std;


 int main()
 {
     int n;
     cin >> n; //количество элементов в массиве
     double arr[n];
     double sum=0;
     double min;
     int i,j,first,last,x,index;


     for(i=0; i<n; i++) {
         cout << "arr[" << i << "]=";
         cin >> arr[i];
     } //формирование массива и каждого элемента

     //поиск минимального элемента
     index=0;
     min = arr[0];
     for (int i = 0; i < n; i++)
     {
         if (arr[i] < min)
         {
             min = arr[i];
             index = i;
         }
     }

 // поиск первого отрицательного элемента


     cout << "Minimal element number is "<< index << endl;


     for (i=0; i<n; i++)
         if(arr[i]<0){
             first=i;
             break; }
     cout << "Fist negative element is (" << first << ")" << endl;

     //поиск последнего отрицательного элемента

     for (i=n-1; i >= 0; i--)
         if(arr[i]<0)
         {
             last=i;
             break; }
     cout << "Last negative element is (" << last << ")" << endl;

     //поиск суммы

     for(i=first+1; i<last; i++)
         sum+=arr[i];
     cout << "Sum = " << sum << endl;

     //изменение расположения элементов массива

     cout << "Write module :" << endl;
     cin>>x;
     for(i=0; i<n; i++) {
         if(abs(arr[i]) <= x)


             continue;
         for(j = i + 1; j<n ; j++) {
             if (abs(arr[j]) <= x) {
                 int tmp =arr[j];
                 arr[j] = arr [i];
                 arr [i] = tmp;
                 break;

             }
         }
     }

     for (i=0; i<n; i++)
     {
         cout << "Element n" ;
         cout << i << ":" << setprecision(3) << arr[i] << endl;
     }

     return 0;
 }