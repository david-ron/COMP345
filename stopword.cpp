//
// Created by Sai Shan on 2017-10-16.
//

#include "stopword.h"
#include"tokenizer.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*!
 *default constructor
 */
stopword::stopword() {
    name  = " ";
}

/*!
 *
 * @param fileName
 */
stopword::stopword(string fileName)
{
    name = fileName;
    tokenizer *t = new tokenizer(fileName);
    sWord = t->tokentoDocument();
}
/*!
 *
 * @param word
 * @return
 */
const bool stopword:: operator()(string word)
{
    for(vector<string>::const_iterator it = sWord.begin(); it != sWord.end(); ++it)
    {
        if(*it == word)
            return true;
    }
    return false;
}

