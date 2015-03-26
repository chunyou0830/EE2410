/* EE2410 Data Structure
 * Homework 2 - Solving a system of linear equations
 * Yang, Chun You  103061142 */

#include <iostream>
#include <fstream>

using namespace std;

//Def
#define LEVEL 5
double matrix[LEVEL][LEVEL+1];
double matrix2[LEVEL][LEVEL+1];

void print(){
    for(int i=0; i<LEVEL; i++){
        for(int j=0; j<=LEVEL; j++){
            cout << matrix2[i][j]<< " ";
        }
        cout << endl;
    }
    cout << "---------------------------------\n";
}

int main()
{
    //Def----------
    fstream read;
    char buffer;

    //Read file----------
    read.open("equations.data.txt", ios::in);

    /*if(!read){
        cout << "Open file failure!";
        exit(1);
    }*/

    for(int i=0; i<LEVEL; i++){
        for(int j=0; j<LEVEL; j++){
            read >> matrix[i][j] >> buffer;
            cout << matrix[i][j] << " ";
        }
        read >> matrix[i][LEVEL];
        cout << matrix[i][LEVEL] << endl;
    }

    read.close();

    cout << "---------------------------------\n";

    //Upper triangle calculate-----
    for(int element=0; element<LEVEL; element++){
        for(int row=element; row<LEVEL; row++){
            double times=-(matrix[row][element]/matrix[element][element]);
            for(int col=0; col<=LEVEL; col++){
                matrix2[row][col] = matrix[row][col]+(matrix[element][col]*times);
                //cout << matrix2[row][col]<< " ";
            }
            cout << endl;
        }
        cout << endl;
        print();
        system("pause");
    }
    return 0;
}

