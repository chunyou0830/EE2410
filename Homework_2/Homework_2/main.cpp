/* EE2410 Data Structure
* Homework 2 - Solving a system of linear equations
* Yang, Chun You 103061142 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Def
#define LEVEL 5
double matrix[LEVEL][LEVEL+1];
float x[LEVEL];

void print(){
    for(int i=0; i<LEVEL; i++){
        for(int j=0; j<=LEVEL; j++){
            cout << setw(4) << fixed << setprecision(0) <<
                    matrix[i][j] << " ";
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


    //Upper triangle calculate-----
    for(int element=0; element<LEVEL; element++){
        if(matrix[element][element]==0){
            swap(matrix[element],matrix[element+1]);
        }
        for(int row=element+1; row<LEVEL; row++){
            double times=-
                    (matrix[row][element]/matrix[element][element]);
            for(int col=element; col<=LEVEL; col++){
                matrix[row][col] +=
                        (matrix[element][col]*times);
            }
        }
        print();
    }

    x[4]=(matrix[4][5])/matrix[4][4];
    x[3]=(matrix[3][5]-matrix[3][4]*x[4])/matrix[3][3];
    x[2]=(matrix[2][5]-matrix[2][4]*x[4]-
            matrix[2][3]*x[3])/matrix[2][2];
    x[1]=(matrix[1][5]-matrix[1][4]*x[4]-
            matrix[1][3]*x[3]-matrix[1][2]*x[2])/matrix[1][1];
    x[0]=(matrix[0][5]-matrix[0][4]*x[4]-
            matrix[0][3]*x[3]-matrix[0][2]*x[2]-
            matrix[0][1]*x[1])/matrix[0][0];
    for(int i=0; i<LEVEL; i++){
        cout << "x[" << i+1 << "]=" << x[i] << endl;
    }

    return 0;
}
