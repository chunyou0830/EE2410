/* EE2410 Data Structure
 * Homework 4 - Building a dictionary
 * Yang, Chun You  103061142 */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

void process_a_line(string, map<string, int>&);

int main(int argc, char **argv)
{
    if(argc<2){
        cout << "Too few arguments" << endl; return(-1);
    }

    ifstream in_fp(argv[1], ios::in);
    if(! in_fp){
        cout << "Input file " << argv[1] << " is not valid\n" << endl;
        return(0);
    }

    // create a map
    map<string,int> book;
    string cpp_line;
    int line_count=0;

    // Building dictionary
    getline(in_fp, cpp_line);
    while(!cpp_line.empty()){
        process_a_line(cpp_line, book);
        line_count++;
        getline(in_fp, cpp_line);
    }
    cout << "Total no. of lines: " << line_count << endl;

    cout << "*** Word Count ***" << endl;
    map<string,int>::iterator it;
    int max_count=atoi(argv[2]);
    string most_freq_word[max_count];
    int most_freq_word_times[max_count];
    for(auto &i : book){
        // word and its count
        for(int n=0; n<max_count; n++){
            if(i.second > most_freq_word_times[n]){
                for(int x=max_count-1; x>n; x--){
                    most_freq_word[x] = most_freq_word[x-1];
                    most_freq_word_times[x] = most_freq_word_times[x-1];
                }
                most_freq_word[n] = i.first;
                most_freq_word_times[n] = i.second;
                break;
            }
        }
    }
    for(int n=1; n<max_count; n++){
        cout << most_freq_word[n] << " " << most_freq_word_times[n] << endl;
    }
}
/*----------- process a line -------------*/
void process_a_line(string cpp_line, map<string, int>& book)
{

    char c_line[1000000], *word;
    string cpp_word;
    map<string,int>::iterator it;

    strcpy(c_line, cpp_line.c_str());
    word = strtok(c_line, "\"-,:;.() ");
    while(word != 0){
        /************************************/
        /*        Process a word here      */
        /************************************/
        cpp_word = word;
        it = book.find(cpp_word);
        if(it != book.end()){
            // An existing word
            it->second = (it->second)+1;
        }
        else {// A new word
            book[cpp_word]=1;
        }
        word = strtok(NULL, "\"-,:;.() ");
    }
}
