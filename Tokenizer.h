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
friend std::ostream & operator << (ostream & os, Tokenizer & t);

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
