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
            cout << matrix[i][j]<< " ";
        }
        cout << endl;
    }
    cout << "---------------------------------\n";
    system("pause");
}

int main()
{
    //Def----------
    fstream read;
    char buffer;

    //Read file----------
    read.open("equations.data.txt", ios::in);

    if(!read){
        cout << "Open file failure!";
        exit(1);
    }

    for(int i=0; i<LEVEL; i++){
        for(int j=0; j<LEVEL; j++){
            read >> matrix[i][j] >> buffer;
        }
        read >> matrix[i][LEVEL];
    }

    read.close();

    //print();

    //Upper triangle calculate-----
    for(int element=0; element<LEVEL; element++){
        for(int row=element; row<LEVEL; row++){
            double times=-(matrix[row][element]/matrix[element][element]);
            cout << "ELEMENT: " << matrix[element][element] << endl;
            for(int col=0; col<=LEVEL; col++){
                //cout << "(" << row << "," << col << "):" << matrix[row][col]+(matrix[element][col]*times) << "!" << endl;
                matrix[row][col] += (matrix[element][col]*times);
            }
        }
    }
    //print();

    return 0;
}

