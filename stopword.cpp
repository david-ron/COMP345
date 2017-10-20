
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
 * @param fileName
 * Parametrized constructor
 */
stopword::stopword(string fileName)
{
    name = fileName;
    Tokenizer *t = new Tokenizer(fileName);
    sWord = t->tokentoDocument();
}
/*!
 * @param word
 * @return boolean
 * Overloading the operator () so that if it finds the given word within the vector <string>,
 * it returns true, else false.
 * To do so, it iterates through the vector.
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

