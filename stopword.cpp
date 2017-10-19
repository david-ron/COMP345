//
// Created by Sai Shan on 2017-10-16.
//

#include "stopword.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


//Default constructor
stopword::stopword() {
    name  = " ";
}

//Paramterized constructor
stopword::stopword(string name) {
    ifstream ifs(name.c_str());
    string word;
    string newWord;
    if(!ifs){
        cerr << "Error! File not Found" << endl;
    }
    while(ifs>>word){
        newWord = "";
        remove_copy_if(word.begin(), word.end(),
                       back_inserter(newWord),
                       ptr_fun<int, int>(ispunct));

        //Algorithm that converts everything to lower case
        transform(newWord.begin(), newWord.end(), newWord.begin(),::tolower);

        sWord.push_back(newWord);
    }
}
/*
bool operator << (ostream & os, stopword & sw, list<string> lst)
{

        if (find(std::begin(lst), std::end(lst), sw) != std::end(lst)){
            return true;
        }
    return false;

}
*/

//Displays the elements of the stopword function
void stopword::display() {
    for (list<string>::const_iterator it = sWord.begin(); it != sWord.end(); ++it) {
        cout<<*it<<endl;
    }
}