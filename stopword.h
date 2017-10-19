//
// Created by Sai Shan on 2017-10-16.
//

#ifndef COMP345ALMOND_MILK_STOPWORD_H
#define COMP345ALMOND_MILK_STOPWORD_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <list>


using namespace std;


class stopword{

    ///Overloading Operator()

    friend bool & operator<<(std::ostream & os, stopword & sw);


private:

    string name;
    list<string> sWord;

public:

    stopword();
    stopword(string fileName);

    bool isEmpty(string name);
    void display();



};
#endif //COMP345ALMOND_MILK_STOPWORD_H
