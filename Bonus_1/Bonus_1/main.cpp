/* EE2410 Data Structure
 * Bonus Homework #1 Haoni Tower
 * Yang, Chun You 103061142 */

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//Defs
vector<int> tower[3];
void MovePile(int disk, int from, int tar, int tmp);
void print();

int main()
{
    //Def
    int disk;
    clock_t start, stop;
    double usedtime;

    //Get number
    cout << "Input the number of disks:";
    cin >> disk;

    //Initialize
    for(int i=disk; i>0; i--){
        tower[1].push_back(i);
    }

    //Move
    start=clock();
    MovePile(disk,1,2,3);
    stop=clock();

    //Time Calculation
    usedtime=((double)stop-(double)start)/CLOCKS_PER_SEC;
    cout << "\n---FINISH---\n" << usedtime << " sec." << endl;
    return 0;
}

void MovePile(int disk, int from, int tar, int tmp){
    if(disk==1){
        tower[tar].push_back(1);
        tower[from].pop_back();
        cout << "Move disk " << disk << " from tower " << from << " to " << tar << endl;
    }
    else{
        MovePile(disk-1,from,tmp,tar);
        tower[tar].push_back(disk);
        tower[from].pop_back();
        cout << "Move disk " << disk << " from tower " << from << " to " << tar << endl;
        MovePile(disk-1,tmp,tar,from);
    }
}

void print(){
    cout << "\nA:";
    for(unsigned int i=0; i<tower[1].size(); i++)
        cout << " " << tower[1][i];
    cout << "\nB:";
    for(unsigned int i=0; i<tower[2].size(); i++)
        cout << " " << tower[2][i];
    cout << "\nC:";
    for(unsigned int i=0; i<tower[3].size(); i++)
        cout << " " << tower[3][i];
    cout << endl;
}

