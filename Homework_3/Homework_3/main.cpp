/* EE2410 Data Structure
 * Homework 3 - Finding equivalence classes
 * Yang, Chun You  103061142 */

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>
#include <stdio.h>

using namespace std;

class ListNode {
public:
    int data;
    ListNode *link;
    ListNode(int d){
        data = d;
        link = 0;
    }
};

typedef ListNode *ListNodePtr;

int total=0;

void equivalence(ListNodePtr *seq, bool *out, int n){
    for(int k=0; k<n; k++){
        if(out[k]==false){
            cout << endl << "A new class " << k;
            out[k] = true;
            ListNode *x = seq[k];
            ListNode *top = 0;
            while(1){
                while(x){
                    int j = x->data;
                    if(out[j]==false){
                        cout << "," << j;
                        out[j] = true;
                        ListNode *y = x->link;
                        x->link = top;
                        top = x;
                        x = y;
                    }
                    else{
                        x= x->link;
                    }
                }
                if(!top){
                    break;
                }
                else{
                    x=seq[top->data];
                    top = top->link;
                }
            }
            total++;
        }
    }
}

int main()
{
        int n;

        // process i=j relation
        int i, j, k;
        ifstream in_file("equivalence.data.txt");
        string line;
        const char	*c_line;
        int		line_count = 0;
        if (!in_file.is_open()){
            return(0);
        }

        getline (in_file,line);
        c_line = line.c_str();
        sscanf(c_line, "%d\n", &n);
        ListNodePtr *seq = new ListNodePtr[n];
        bool *out = new bool[n];

        for(int k=0; k<n; k++){
            seq[k] = 0;
            out[k] = false;
        }

        while ( getline (in_file,line) ){
            c_line = line.c_str();
            sscanf(c_line, "(%d, %d)\n", &i, &j);
            ListNode *x = new ListNode(j);
            x->link = seq[i];
            seq[i] = x;
            ListNode *y = new ListNode(i);
            y->link = seq[j];
            seq[j] = y;
        }
        in_file.close();

        equivalence(seq, out, n);

        cout << endl;

        cout << "THERE ARE IN TOTAL " << total << " Equiv.Classes" << endl;

}
