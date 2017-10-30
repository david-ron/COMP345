/*
 * tokenizer.h
 *
 *  Created on: Oct 14, 2017
 *      Author: David
 */

#ifndef TOKENIZER_H_
#define TOKENIZER_H_


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
//input stream of <char> type to string and formatting of words &&count chars
class Tokenizer{
private:
	string fileName;
public:
Tokenizer();
Tokenizer(string fileName);
vector<string> tokentoDocument();
vector<string> stringTokenize(string word);
};
#endif /* TOKENIZER_H_ */
