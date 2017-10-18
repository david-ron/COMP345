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
#include "document.h"


using namespace std;


class stopword{




private:

    string name;
    vector<string> sWord;


public:

    stopword();
    stopword(string fileName);
    const bool operator()(string word);
    void display();
    vector<string> compare (document dict, vector<string> swords);




};
#endif //COMP345ALMOND_MILK_STOPWORD_H
