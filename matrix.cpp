#include <iostream>
#include <vector>
using namespace std;
int main() {
    int i, j, n, m, k, counter, maxind ;
    cout << "Write the number of columns :  ";
    cin >> m;
    cout << "The number of lines : ";
    n = m * 2;
    cout << " " << n << endl;
    cout << "\n The matrix elements: \n\n " << endl;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            matrix[i][j] = rand() %  9;
            cout << "matrix[" << i << "][" << j << "]= " << matrix[i][j] << endl;

        }
    }
    for (i = 0; i < n; i++ ) {
        for (j = 0; j < n; j++) {
            matrix[i, j] = matrix[i + m, j];
        }
    }


    k = m;
    for (j = 0; j < m; j++) {
        //просмотр столбцов


        for (i = 0; i < n; i++)//анализ элементов столбцов
            if (matrix[i][j] == 0) {

                k--;
                break;  //выход из цикла
            }
    }

    //проверка нашла программа столбец с нулевым числом

    cout << " The number of columns is " << k << endl;


   vector<int>temp(n,0);
   for(int i=0; i<n; i++)
   {
       counter=1;
       for(int j=0; j<n-1; j++)
       {
           if(matrix[i][j+1]>matrix[i][j]){
               counter++;
           }
           else
           {
               if(temp[i]<counter)
                   temp[i]=counter;
               counter=1;

           }
       }
       if(temp[i]<counter)
           temp[i]=counter;

   }
   maxind=0;
   for(i=0;i<n; i++)
       if(temp[i]>temp[maxind])
           maxind=i;
           cout<< " The number of the row "<< maxind << endl;


        return 0;
}
